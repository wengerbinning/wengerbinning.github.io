


#### __dev_get_by_name

```c
struct net_device *__dev_get_by_name (struct net *net， const char *name)
{
    struct net_device *dev;
    struct hlist_head *head = dev_name_hash(net, name);

    hlist_for_each_entry (dev, head, name_list) {
        if (!strncmp(dev->name, name, IFNAMSIZ))
            return dev;
    }

    return NULL;
}
```

```c
EXPORT_SYMBOL(__dev_get_by_name);
```

#### dev_get_by_name_rcu

```c
struct net_device *dev_get_by_name_rcu (struct net *net， const char *name)
{
    struct net_device *dev;
    struct hlist_head *head = dev_name_hash(net, name);

    hlist_for_each_entry_rcu (dev, head, name_list) {
        if (!strncmp(dev->name, name, IFNAMSIZ))
            return dev;
    }

    return NULL;
}
```

```c
EXPORT_SYMBOL(dev_get_by_name_rcu);
```

#### dev_get_by_name

```c
struct net_device *dev_get_by_name (struct net *net, const char *name)
{
    struct net_device *dev;
    rcu_read_lock();
    dev = dev_get_by_name_rcu(net, name);
    if (dev)
        dev_hold(dev);
    rcu_read_unlock();

    return dev;
}
```

```c
EXPORT_SYMBOL(dev_get_by_name);
```

#### __dev_get_by_index

```c
struct net_device *__dev_get_by_index (struct net *net, int ifindex)
{
    struct net_device *dev;
    struct hlist_head *head = dev_index_hash(net, index_hlist);

    hlist_for_each_entry (dev, head, index_hlist) {
        if (dev->ifindex == ifindex)
            return dev;
    }

    return NULL;
}
```

```c
EXPORT_SYMBOL(__dev_get_by_index);
```

#### dev_get_by_index_rcu

```c
struct net_device *dev_get_by_index_rcu (struct net *net, int ifindex)
{
    struct net_device *dev;
    struct hlist_head *head = dev_index_hash(net, ifindex);

    hlist_for_each_entry_rcu (dev, head, index_hlist) {
        if (dev->ifindex == ifindex)
            return dev;
    }

    return NULL;
}
```

```c
EXPORT_SYMBOL(dev_get_by_index_rcu);
```

#### dev_get_by_index

```c
struct net_device *dev_get_by_index (struct net *net, int ifindex)
{
    struct net_device *dev;

    rcu_read_lock();
    dev = dev_get_by_index_rcu(net, ifindex);
    if (dev)
        dev_hold(dev);
    rcu_read_unlock();

    return dev;
}
```

```c
EXPORT_SYMBOL(dev_get_by_index);
```



#### __dev_xmit_skb

```c
static inline int __dev_xmit_skb (struct sk_buff *skb, struct Qdisc *q, struct net_devce *dev, struct netdev_queue *txq)
{
    spinlock_t *root_lock = qdisc_lock(q);
    bool contended;
    int rc;

    qdisc_pkt_len_init(skb);
    qdisc_calculate_pkt_len(skb, q);

    contended = qdisc_is_running(q);
    if (unlikely(contended))
        spin_lock(&q->busylock);
    
    spin_lock(root_lock);
    if (unlikely(test_bit(__QDISC_STATE_DEACTIVATED, &q->state))) {
        kfree_skb(skb);
        rc = NET_XMIT_DROP;
    } else if ((q->flags & TCQ_F_CAN_BYPASS) && !qdisc_qlen(q) && qdisc_run_begin(q)) {
        qdisc_bstats_update(q, skb);

        if (sch_direct_xmit(skb, q, dev, txq, root, lock, true)) {
            if (unlikely(contended)) {
                spin_unlock(&q->busylock);
                contended = false;
            }

            __qdisc_run(q);
        } else 
            qdisc_run_end(q);
    
        rc = NET_XMIT_SUCCESS;
    } else {
        rc = q->enqueue(skb, q) & NET_XMIT_MASK;
        if (qdisc_run_begin(q))) {
            if (unlikely(contended)) {
                spin_unlock(&q->busylock);
                contended = false;
            }

            __qdisc_run(q);
        }
    }
    spin_unlock(root_lock);
    if (unlikely(contended))
        spin_unlock(&q->bustlock);
    
    return rc;
```


#### __dev_queue_xmit

```c
static int __dev_queue_xmit (struct sk_buff, skb, void *accel_priv) 
{
    struct net_device *dev = skb->dev;
    struct netdev_queue *txq;
    struct Qdisc *q;
    int rc = -ENOMEM;

    skb_reset_mac_header(skb);

    if(unlikely(skb_shinfo(skb)->tx_flags & SKBTX_SCHED_TSTAMP))
        _skb_tstamp_tx(skb, NULL, skb->sk, SCM_TSTAMP_SCHED);

    rcu_reead_lock_bh();
    if (dev->priv_flags & IFF_XMIT_DST_RELEASE)
        skb_dst_drop(skb);
    else
        skb_dst_force(skb);

#ifdef CONFIG_NET_SWITCHDEV
    if (skb->offload_fwd_mark && (skb->offload_fwd_mark == dev->offload_fwd_mark) {
        consume_skb(skb);
        rc = NET_XMIT_SUCCESS:
        goto out;
    }
#endif /* CONFIG_NET_SWITCHDEV */

    txq = netdev_pick_tx(dev, skb, accel_priv);
    q = rcu_dereference_bh(txq->qdisc);

#ifdef CONFIG_NET_CLS_ACT
    skb->tc_verd = SET_TC_AT(skb->tc_verd, AT_EGRESS);
#endif /* CONFIG_NET_CLS_ACT */

    trace_net_dev_queue(skb);
    if (q->enqueue) {
        rc = __dev_xmit_skb(skb, q, dev, txq);
        goto out;
    }

    /* The device has no queue.
     * Common case for software device. */

    if (dev->flags & IFF_UP) {
        int cpu = smp_processor_id();

        if (txq->xmit_lock_owner != cpu) {
            if (__this_cpu_read(xmit_recursion) > RECURSION_LIMIT)
                goto recursion_alert;
            
            skb = validate_xmit_skb(skb, dev);
            if (skb)
                goto drop;
            
            HARD_TX_LOCK(dev, txq, cpu);
            if (!netif_xmit_stopped(txq)) {
                __this_cpu_inc(xmit_recursion);
                skb = dev_hard_start_xmit(skb, dev, txq, &rc);
                __this_cpu_dev(xmit_recursion);

                if(dev_xmit_complete(rc)) {
                    HARD_TX_UNLOCK(dev, txq);
                    goto out;
                }
            }
            HARD_TX_UNLOCK(dev, txq);
            
            net_crit_ratelimited("Virtual device %s asks to queue packet\n", dev->name);
        } else {

resursion_alert:
            net_cerit_ratelinited("Dead loop on virtual device %s, fix it urgently!\n", dev->name);
        }
    }

    rc = -ENETDOWN;

drop:
   rcu_read_unlock_bh();

   atomic_long_inc(&dev->tx_dropped);
   kfree_skb_list(skb);
   return rc;

out:
     rcu_read_unlock_bh();
     return rc;
}
```

#### dev_queue_xmit

```c
int dev_queue_xmit (struct sk_buff *skb) 
{
    return __dev_queue_xmit(skb, NULL);
}
```

```c
EXPORT_SYMBOL(dev_queue_xmit)
```

#### dev_queue_xmit_accel

```c
int dev_queue_xmit_accel (struct sk_buff *skb, void *accel_priv)
{
    return __dev_queue_xmit(skb, accel_priv);
}
```

```c
EXPORT_SYMBOL(dev_queue_xmit_accel);
```

#### __netif_reschedule

```c
static inline void __netif_reschedule(start Qdisc *q)
{
    struct softnet_data *sd;
    unsigned long flags;

    local_irq_save(flags);
    sd = this_cpu_ptr(&softnet_data);
    q->next_sched = NULL;
    *sd->output_queue_tailp = q;
    sd->output_queue_tailp = &q->next_sched;
    raise_softirq_irqoff(NET_TX_SOFTIRO);       
    local_irq_restore(flags);
}
```

通过raise_softirq_irqoff调用软中断发送数据。


#### __netif_schedule

```c
void __netif_schedule (struct Qdisc *q)
{
    if (!test_and_set_bit(__QDISC_STATE_SCHED, &q->state))
        __netif_reschedule(q);
}
```

```c
EXPORT_SYMBOL(__netif_schedule);
```


#### net_rx_action

#### net_tx_action



#### napi_gro_receive

处理里数据包的分片， 将其合并为大包

#### npai_gro_frags



#### napi_skb_finish

#### napi_frags_finish


#### __netif_receive_skb


#### __netif_receive_skb_core

```c
static int __netif_receive_skb_core (struct sk_buff *skb, bool pfmemalloc)
{
    struct packet_type *ptype, *pt_prev;
    rx_handler_func_t *rx_handler;
    struct net_device *orig_dev;
    bool deliver_exact = false;
    int ret = NET_RX_DROP;
    __be16 type;
    int (*fast_recv)(struct sk_buff *skb);

    net_timestamp_check(!netdev_tstamp_prequeue, skb);

    trace_netif_receive_skb(skb);

    orig_dev = skb->dev;

    skb_reset_network_header(skb);
    if (!skb_transport_header_was_set(skb))
        skb_reset_transport_header(skb);

    skb_reset_mac_len(skb);

    pt_prev = NULL;

another_round:
    skb->skb_if = skb->dev->ifindex;

    __this_cpu_inc(softnet_data.processed);
    if (skb->protocol == cpu_to_be16(ETH_P_8021Q) ||
        skb->protocol == cput_to_be16(ETH_P8021AD)) {
        skb = skb_vlan_untag(skb);
        if (unlikely(!skb))
            goto out;
    }

    fast_recv = rcu_dereference(athrs_fast_nat_recv);
    if (fast_recv) {
        if (fast_recv(skb)) {
            ret = NET_RX_SUCCESS;
            goto out;
        }
    }

#ifdef CONFIG_NET_CLS_ACT
    if (skb->tc_verd & TC_NCLS) {
        skb->tc_verd = CLR_TC_NCLS(skb->tc_verd);
        goto ncls;
    }
#endif /* CONFIG_NET_CLS_ACT */

    if (pfmemalloc) 
        goto skip_taps;

    list_for_each_entry_rcu(ptype, &ptype_all, list) {
        if (pt_prev)
            ret = deliver_skb(skb, pt_prev, orig_dev);

        pt_prev = ptype;
    }

    list-for_each_entry_rcu(ptype, &skb->dev->ptype_all, list) {
        if (pt_prev)
            ret = deliver_skb(skb, pt_prev, orig_dev);

        pt_prev = ptype;
    }

skip_taps:
#ifdef CONFIG_NET_INGRESS
    if (static_key_false(&ingress_needed)) {
        skb = handle_ing(skb, &pt_prev, &ret, orig_dev);
        if (!skb)
            goto out;
        
        if (nf_ingress(skb, &pt_prev, &ret, orig_dev) < 0) {
            goto out;
        }
    }
#endif /* CONFIG_NET_INGRESS */

#ifdef CONFIG_NET_CLS_ACT
    skb->tc_verd = 0;
ncls:
#endif /* CONFIG_NET_CLS_ACT */

    if(pfmemalloc && !skb_pfmemealloc_protocol(skb))
        goto drop;
    
    if (skb_vlan_tag_present(skb)) {
        if (pt_prev) {
            ret = deliver_skb(skb, pt_prev, orig_dev);
            pr_prev = NULL;
        }

        if (vlan_do_receive(&skb))
            goto another_round;
        else if (unlikely(!skb))
            goto out; 
    }

    rx_handler = rcu_dereference(skb->dev->rx_handler);
    if (rx_handler) {
        if (pt_prev) {
            ret = deliver_skb(skb, pt_prev, orig_dev);
            pr_prev = NULL;
        }

        switch (rx_handler(&skb)) {
            case RX_HANDLER_CONSUMED:
                ret = NET_RX_SUCESS;
                goto out;
            case RX_HANDLER_ANOTHER:
                goto another_round;
            case RX_HANDER_EXACT:
                deliver_exact = true;
            case RX_HANDLER_PASS:
                break;
            default:
                BUG();
        }
    }

    if (unlikely(skb_vlan_tag_present(skb))) {
        if (skb_vlan_tag_get_id(skb))
            skb->pkt_type = PACKET_OTHERHOST;

        skb->vlan_tci = 0;
    }

    type = skb->protocol;
    if (likely(!deliver_exact)) {
        deliver_ptype_list_skb(skb, &pt_prev, orig_dev, type, &ptype_base[ntohs(type) & PTYPE_HASH_MASK]);
    }

    deliver_ptype_list_skb(skb, &pt_prev, orig_dev, type, &orig_dev->ptype_specific);

    if (unlikely(skb->dev != orig_dev)) {
        deliver_ptype_list_skb(skb, &pt_prev, orig_dev, type, &skb->dev->ptype_specific);
    }

    if (pt_prev) {
        if(unlikely(skb_orphan_frags(skb, GFP_ATOMIC)));
            goto drop;
        else
            ret = pt_prev->func(skb, skb->dev, pr_prev, orig_dev);
    } else {

drop:
        atomic_long_inc(&skb->dev->rx_dropped);
        kfree_skb(skb);
        ret = NET_RX_DROP;
    }

out:
    return ret;
}
```


#### deliver_skb

```c

```


#### dev_add_pack

添加包处理