



#### vlan_dev_get_egress_qos_mask


* linux v4.4.60

```c
static inline u16 vlan_dev_get_egress_qos_mask (struct net_device *dev, u32 skprio)
{
    return 0;
}
```

#### __vlan_hwaccel_put_tag

```c
static inline void __vlan_hwaccel_put_tag (struct skb_buff *skb, __be16 vlan_proto, u16 vlan_tci)
{
    skb->vlan_proto = vlan_proto;
    skb->vlan_tci = VLAN_TAG_PRESENT | vlan_tci;
}
```