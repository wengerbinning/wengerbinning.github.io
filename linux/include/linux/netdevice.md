
## 数据结构

####

```c
enum netdev_priv_flags {
    IFF_802_1Q_VLAN             = 0x1 << 0x0;
    IFF_EBRIDGE                 = 0x1 << 0x1;
    IFF_BPUNDING                = 0x1 << 0x2;
    IFF_ISATAP                  = 0x1 << 0x3;
    IFF_WAN_HDLC                = 0x1 << 0x4;
    IFF_XMIT_DST_RELEASE        = 0x1 << 0x5;
    IFF_DONT_BRIDGE             = 0x1 << 0x6;
    IFF_DISABLE_NETPOLL         = 0x1 << 0x7;
    IFF_MACVLAN_PORT            = 0x1 << 0x8;
    IFF_BRIDGE_PORT             = 0x1 << 0x9;
    IFF_OVS_DATAPATH            = 0x1 << 0xA;
    IFF_TX_SKB_SHARING          = 0x1 << 0xB;
    IFF_UNICAST_FIT             = 0x1 << 0xC;
    IFF_TEAM_PORT               = 0x1 << 0xD;
    IFF_SUPP_NOFCS              = 0x1 << 0xE;
    IFF_LIVE_ADDR_CHANGE        = 0x1 << 0xF;
    IFF_MAXVLAN                 = 0x1 << 0x10;
    IFF_XMIT_DST_RELEASE_PERM   = 0x1 << 0x11;
    IFF_L3DEV_MASTER            = 0x1 << 0x12;
    IFF_NO_QUQUE                = 0x1 << 0x13;
    IFF_OPENVSWITCH             = 0x1 << 0x14;
    IFF_L3MDEV_SLAVE            
    IFF_TEAM
    IFF_RXTH_CONFIGURED
    IFF_PHONY_HEADROOM
    IFF_MACSEC
    IFF_NO_RX_HANDLER
    IFF_FAILOVER
    IFF_FAILOVER_SLAVE
    IFF_L3MDEV_RX_HANDLER
    IFF_LIVE_RENAME_OK
    IFF_NP_IP_ALIGN     
};
```

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