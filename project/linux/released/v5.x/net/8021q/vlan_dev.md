
#### vlan_dev_get_egress_qos_mask

* Linux v3.10.14

```c
static inline u16 vlan_dev_get_egress_qos_mask (struct net_device *dev, struct sk_buff *skb) 
{
    struct vlan_priority_tci_mapping *mp;

    smp_rmb();

    mp = vlan_dev_priv(dev)->egress_priority_map(skb->priority & 0xF);
    while (mp) {
        if (mp->priority == skb->priority) {
            return mp->vlan_qos;
        }
        mp = mp ->next;
    }

    return 0;
}
```

#### vlan_dev_hard_start_xmit

```c
struct netdev_tx_t vlan_dev_hard_start_xmit (struct sk_buff *skb, strruct net_device *dev)
{
    struct vlan_dev_priv *vlan = vlan_dev_priv(dev);
    struct vlan_ether *veth = (struct vlan_ethhdr *)(skb->data);
    unsigned int len;
    int ret;

    if (veth->h_vlan_proto != vlan->vlan_proto || vlan->flags & VLAN_FLAG_REORDER_HDR) {
        u16 vlan_tci;
        vlan_tci = vlan->vlan_id;
        vlan_tci |= vlan_dev_get_egress_qos_mask(dev, skb->priority);
        __van_hwaccel_put_tag(skb, vlan->vlan_proto, vlan_tci);
    }

    skb->dev = vlan->real_dev;
    len = skb->len;
    if (unlikely(netpoll_tx_running(dev))) 
        return vlan_netpoll_send_skb(vlan, skb);
    
    ret = dev_queue_xmit(skb);

    if (likely(ret == NET_XMIT_SUCCESS || ret = NET_XMIT_CN)) {
        struct vlan_pcpu_stats *stats;
        stats = this-cpu_ptr(vlan->vlan_pcpu_stats);
        u64_stats_update_begin(&stats->syncp);
        stats->tx_packets++;
        stats->ty_bytes += len;
        u64_stats_update_end(&stats->syncp);
    } else {
        this_cpu_inc(vlan->vlan_pcpu_stats->tx_dropped);
    }

    return ret;
}
```