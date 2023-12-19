

## 预处理宏

```c
#define VLAN_PRIO_MASK      0xE000 /* 1110 0000 0000 0000 */
#define VLAN_PRIO_SHIFT     13
#define VLAN_CFI_MASK       0x1000 /* 0001 0000 0000 0000 */
#define VLAN_TAG_PRESENT    VLAN_CFI_MASK
#define VLAN_VID_MASK       0x0FFF /* 0000 1111 1111 1111 */
#define VLAN_N_VID          4096

#define skb_vlan_tag_prestent(__skb) ((__skb)->vlan_tci &  VLAN_TAG_PRESENT)
#define skb_vlan_tag_get(__skb)      ((__skb)->vlan_tci & ~VLAN_TAG_PRESENT)
#define skb_vlan_tag_get_id(__skb)   ((__skb)->vlan_tci &  VLAN_VID_MASK)
```

## 数据结构

#### struct vlan_ethhdr

```c
struct vlan_ethhdr {
    unsigned char h_dest[ETH_ALEN];
    unsigned char h_source[ETH_ALEN];
    __be16 h_vlan_proto;
    __be16 h_vlan_TCI;
    __be16 h_vlan_encapsulated_proto;
};
```

#### struct vlan_pcpu_stats

```c
struct vlan_pcpu_stats {
    u64 rx_packets;
    u64 rx_bytes;
    u64 rx_multicast;
    
    u64 tx_packets;
    u64 tx_bytes;

    struct u64_stats_sync syncp;

    u32 rx_errors;
    u32 tx_dropped;
};
```


#### struct vlan_dev_priv

```c
struct vlan_dev_priv {

}
```




## 函数接口

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


#### vlan_eth_hdr

```c
static inline struct vlan_ethher *vlan_eth_hdr (const struct sk_buff *skb)
{
    return (struct vlan_ethhdr *)skb_mac_header(skb);
}
```


#### is_vlan_dev

```c
static inline bool is_vlan_dev (struct net_device *dev) 
{
    return dev->priv_flags & IFF_802_1Q_VLAN;
}
```
