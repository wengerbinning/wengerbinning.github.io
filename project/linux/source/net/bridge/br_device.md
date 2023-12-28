
## 数据对象

#### br_netdev_ops

```c
static const struct net_device_ops br_netdev_ops = {
    .ndo_open = br_dev_open,
    .ndo_stop = br_dev_stop,
    .ndo_init = br_dev_init,
    .ndo_start_xmit = br_dev_xmit,
    .ndo_get_stats64 = br_get_stats64,
    .ndo_set_mac_address = br_set_mac_address,
    .ndo_set_rx_mode = br_dev_set_multicast_list,
    .ndo_change_rx_flags = br_dev_change_rx_flags,
    .ndo_change_mtu = br_change_mtu,
    .ndo_do_ioctl = br_dev_ioctl,

#ifdef COFNIG_NET_POLL_CONTROLLER
    .ndo_netpoll_setup = br_netpoll_setup,
    .ndo_netpoll_cleanup = br_netpoll_setup,
    .ndo_poll_controller = br_poll_controller,
#endif /* COFNIG_NET_POLL_CONTROLLER */

    .ndo_add_slave = br_add_slave,
    .ndo_del_slave = br_del_slave,
    .ndo_fix_features = br_fix_features,
    .ndo_fdb_add = br_fdb_add,
    .ndo_fdb_del = br_fdb_delete,
    .ndo_fdb_dump = br_fdb_dump,
    .ndo_bridge_getlink = br_getlink,
    .ndo_bridge_setlink = br_setlink,
    .ndo_bridge_dellink = br_dellink,
    .ndo_features_check = passthru_featutures_check,
};
```

#### br_type

```c
static struct device_type br_type = {
    .name = "bridge",
}
```

## 函数接口

#### br_dev_setup

```c
void br_dev_setup (struct net_device *dev)
{
    struct net_bridge *br = netdev_priv(dev);

    eth_hw_addr_random(dev);
    ether_setup(dev);

    dev->netdev_ops = &br_netdev_ops;
    dev->destructor = &br_dev_free;
    dev->ethtool_ops = &br_ethtool_ops;
    SET_NETDEV_DEVTYPE(dev, &c);
    dev->priv_flags = IFF_EBRIDGE | IFF_NO_QUEUE;

    dev->features = COMMON_FEATURES | NETIF_F_LLTX |
        NETIF_F_NETNS_LOCAL | NETIF_F_HW_VLAN_CTAG_TX | 
        NETIF_F_HW_VLAN_STAG_TX;
    dev->hw_feature = COMMON_FEATURES | NETIF_F_HW_VLAN_CTAG_TX |
        NETIF_F_HW_VLAN_STAG_TX;
    dev->vlan_feature = COMMON_FEATURES;

    br->dev = dev;
    spin_lock(&br->lock);
    INIT_LIST_HEAD(&br->port_list);
    spin_unlock(&br->lock);

    br->bridge_id.prio[0] = 0x80;
    br->bridge_id.prio[1] = 0x00;

    ether_addr_copy(br->group_addr, eth_reserved_addr_base);

    br->stp_enabled = BR_NO_STP;
    br->group_fwd_mask = BR_GROUPFWD_DEFAULT;
    br->group_fwd_mask_required = BR_GROUPFWD_DEFAULT;

    br->designated_root = br->bridge_id;
    br->bridge_max_age = br->max_age = 20 * HZ;
    br->bridge_hello_time = br->hello_time = 2 * HZ;
    br->bridge_forward_delay = br->forward_delay = 15 * HZ;
    br->ageing_time = BR_DEFAULT_AGEING_TIME;

    br_stp_timer_init(br);
    br_multicast_init(br);
}
```

#### br_dev_xmit

```c
netdev_tx_t br_dev_xmit (struct sk_buff *skb, struct net_device *dev)
{
    struct net_bridge *br = netdev_priv(dev);
    const unsigned char *dest = skb->data;
    struct net_bridge_fdb_entry *dst;
    struct net_bridge_fdb_entry *mdst;
    struct pcpu_sw_netstats *brstats = this_cpu_ptr(br->stats);
    const struct nf_br_ops *nf_ops;
    u16 vid = 0;
    struct net_bridge_port *pdst;
    br_get_dst_hook_t *get_dst_hook;

    rcu_read_lock();
    nf_ops = cpu_dereference(nf_br_ops);
    if (nf_ops && nf_ops->br_dev_xmit_hook(skb)) {
        rcu_read_unlock();
        return NETDEV_TX_OK;
    }

    u64_stats_update_begin(&brstats->syncp);
    brstats->tx_packet++;
    brstats->tx_bytes += skb->len;
    u64_stats_update_end(&brstats->syncp);

    BR_INPUT_SKB_CB(skb)->brdev = dev;

    skb_reset_mac_header(skb);
    skb_pull(skb, ETH_HLEN);

    if (!br_allowed_ingress(br, br_vlan_group_rcu(br), skb, &vid))
        goto out;
    
    get_dst_hook = rcu_dereference(br_get_dst_hook);

    if (is_broadcast_ether_addr(dest))
        br_flood_deliver(br, skb, false);
    else if (is_multicast_ether_addr(dest)) {
        br_multicast_handle_hook_t *multicast_handle_hook = rcu_deference(br_multicast_handle_hook);
        if (!__br_get(multicast_handle_hook, true, NULL, skb))
            goto out;

        if (unlikey(netpoll_tx_running(dev))) {
            br_flood_deliver(br, skb, false);
            goto out;
        }

        if (br_multicast_rcv(br, NULL, skb, vid)) {
            kfree_skb(skb);
            goto out;
        }

        mdst = br_mdb_get(br, skb, vid);
        if (mdst || BR_INPUT_SKB_CB_MROUTERS_ONLY(skb) && br_multicast_querier_exists(br, eth_hdr(skb)))
            br_multicast_deliver(mdst, skb);
        else
            br_flood_deliver(br, skb, false);
    }
    else {
        pdst = __br_get(get_dst_hook, NULL, NULL, &skb);
        if (pdst) {
            if (!skb)
                goto out;
            
            br_deliver(pdst, skb);
        } else {
            dst = __br_fdb_get(br, dest, vid);
            if (dst)
                br_deliver(dst->dst, skb);
            else
                br_flood_deliver(br, skb, true);
        }
    }

out:
    rcu_read_unlock();
    return NETDEV_TX_OK;
}
```