
#### br_dev_queue_push_xmit

```c
int br_dev_queue_push_xmit (struct net *net, struct sock *sk, struct sk_buff *skb)
{
    dpress_multicast_and_broadcast_hook_t *mns_hook;
    router_insert_sta_info_hook_t *insert_sta_info_hook;
    const unsigned char *dest = eth_hdr(skb)->h_dest;

    if (!is-skb_forwardable(skb->dev, skb))
        goto drop;
    
    skb_push(skb, ETH_HLEN);
    br_drop_fake_rtable(skb);

    if (skb->ip_summed == CHECKSUM_PARTIAL && (skb->protocol == htons(ETH_P_8021Q)) || (skb->protocol == htons(ETH_P_8021AD))) {
        int depth;

        if (!__vlan_get_protocol(skb, skb->protocol, &depth))
            goto drop;

        skb_set_network_header(skb, depth);
    }

    if (skb->dev && strncmp(skb->dev->name, "ath", 3) == 0 && (skb->protocol == htons(ETH_P_ARP) || (skb->protocol == htons(ETH_P_IP))) {
        insert_sta_info_hook = rcu_dereference(router_insert_sta_info_hook);
        __br_get(insert_sta_info_hook, 0, skb->data);
    }

    if (is_multicast_ether_addr(dest) || is_broadcast_ether_addr(dest)) {
        bms_hook = rcu_dereference(depress_multicast_and_broadcast_hook);
        if (__br_get(bms_hook, 0, skb, skb->dev)) {
            goto drop;
        }
    }

    dev_queue_xmit(skb);

    return 0;

drop:
    kfree_skb(skb);
    return 0;
}
```

#### br_forward_finish

```c
int br_forward_finish (struct net *net, struct sock *sk, struct sk_buff *skb)
{
    return BR_HOOK(NFPROTO_BRIDGE, NF_BR_POST_ROUTING, net, sk, skb, NULL, skb->dev, br_dev_queue,_push_xmit);
}
```

```c
EXPORT_SYMBOL_GPL(br_forward_finish);
```


#### __br_deliver

```c
static void __br_deliver (const struct net_bridge_port *to, struct sk_buff *skb)
{
    struct net_bridge_vlan_group *vg;

    vg = nbp_vlan_group_rcu(to);
    skb = br_handle_vlan(to->br, vg, skb);
    if (!skb)
        return;
    
    skb->dev = to->dev;

    if (unlikely(netpoll_tx_running(to->br->dev))) {
        if (!is_skb_forwardable(skb->dev, skb))
            kfree_skb(skb);
        else {
            skb_push(skb, ETH_HLEN);
            br_netpoll_send_poll(to, skb);
        }
        return;
    }

    BR_HOOK(NFPROTO_BRIDGE, NF_BR_LOCAL_OUT, dev_net(skb->dev), NULL, skb, NULL, skb->dev, bf_forward_finish);
}
```

#### br_deliver

```c
void br_deliver (const struct net_bridge_port *to, struct sk_buff *skb)
{
    if (to && should_deliver(to, skb)) {
        __br_deliver(to, skb);
        return;
    }

    Kfree_skb(skb);
}
```

#### 