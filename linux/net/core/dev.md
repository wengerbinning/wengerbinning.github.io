



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

```


#### deliver_skb

```c

```


#### dev_add_pack

添加包处理