
## 数据结构



#### struct net_device

```c
struct net_device
{
    char name[IFNAMSIZ];
    struct hlist_node name_hlist;
    char *ifalias;

    unsigned long mem_end;
    unsigned long mem_start;
    unsigned long mem_addr;
    int irq;
    
    atomic_t carrier_carrier_changes;

    unsigned long state;

    struct list_head dev_list;
    struct list_head napi_list;
    struct list_head unreg_list;
    struct list_head close_list;
    struct list_head ptype_list;
    struct list_head ptype_specific;

    // ...

    unsigned int flags;
    unsigned int priv_flags;
    unsigned int priv_flags_ext;

    // ...

    struct timer_list watchdog_timer;

    int __percpu *pcpu_refcnt;
    struct list_head todo_list;

    // ...

}
```

## 函数接口

#### dev_hold

```c
static inline void dev_hold (struct net_device * dev)
{
    this_cpu_inc(*dev->pcpu_refcnt);
}
```

#### dev_put

```c
static inline void dev_put (struct net_device *dev)
{
    this_cpu_dev(*dev->pcpu_refcnt);
}
```

---

#### [__dev_get_by_name](../../net/core/dev.md#__dev_get_by_name)

```c
struct net_device *__dev_get_by_name (struct net *net, const char *name);
```

#### [dev_get_by_name_rcu](../../net/core/dev.md#dev_get_by_name_rcu)

```c
struct net_device *dev_get_by_name_rcu (struct net *net, const char *name);
```

#### [dev_get_by_name](../../net/core/dev.md#dev_get_by_name)

```c
struct net_device *dev_get_by_name (struct net *net, const char *name);
```

#### [__dev_get_by_index](../../net/core/dev.md#__dev_get_by_index)

```c
struct net_device *__dev_get_by_index (struct net *net, int ifindex);
```

#### [dev_get_by_index_rcu](../../net/core/dev.md#dev_get_by_index_rcu)

```c
struct net_device *dev_get_by_index_rcu (struct net *net, int ifindex);
```

#### [dev_get_by_index](../../net/core/dev.md#dev_get_by_index)

```c
struct net_device *dev_get_by_index (struct net *net, int ifindex);
```

---


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