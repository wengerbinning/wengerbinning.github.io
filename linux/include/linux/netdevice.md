


#### __netdev_start_xmit

```c
static inline netdev_tx_t __netdev_start_xmit (const struct net_device_ops *ops, struct sk_buff *skb, struct net_device *dev, bool more)
{
    skb->xmit_more = more ? 1 : 0;
    return ops->ndo_start_xmit(skb, dev);
}
```

#### netdev_start_xmit

```c
static inline netdev_tx_t netdev_start_xmit (struct sk_buff *skb, struct net_device *dev, struct netdev_queue *txq, bool more)
{
    const struct net_device_ops *ops = dev->netdev_ops;
    int rc;

    rc = __netdev_start_xmit(ops, skb, dev, more);
    if (rc == NETDEV_TX_OK)
        txq_trans_update(txq);

    return rc;
}
```