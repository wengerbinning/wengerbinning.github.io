
## 预处理宏

```c
#define BR_HASH_BITS 8
#define BR_HASH_SIZE (1 << BR_HASH_BITS)

#define BR_HOLD_TIME (1 * HZ)

#define BR_PORT_BITS 10
#define BR_MAX_PORTS (1 << BR_PORT_BITS)

#define BR_VERSION "2.3"


#define BR_GROUPFWD_DEFAULT 0
#define BR_GROUPFWD_RESTRICTED 0x0007U
#define BR_GROUDFWD_8021AD 0xB801U

#define BR_STP_PROG "/sbin/bridge-stp"



#define BR_INPUT_SKB_CB(__skb)   ((struct br_input_skb_cb *)(__skb)->cb)
```

## 数据结构

#### typedef

```c
typedef struct bridge_id bridge_id;
typedef struct mac_addr mac_addr;
typedef _u16 port_id;
```

#### struct bridge_id

```c
struct bridge_id
{
    unsigned char prio[2];
    unsigned char addr[ETH_ALEN];
};
```

#### struct mac_addr

```c
struct mac_addr
{
    unsigned char addr[ETH_ALEN];
};
```

#### struct bridge_mcast_own_query

```c
struct bridge_mcast_own_query
{
    struct timer_list timer;
    u32 startup_sent;
};
```

#### struct bridge_mcast_other_query

```c
struct bridge_mcast_other_query
{
    struct timer_list timer;
    unsigned long delay_timer;
};
```

#### struct bridge_mcast_querier

```c
struct bridge_mcast_querier {
    struct br_ip addr;
    struct net_bridge_port __rcu *port;
};
```

#### struct net_bridge_vlan

```c
struct net_bridge_vlan
{
    struct rhash_head vnode;
    u16 vid;
    u16 flags;
    union {
        struct net_bridge *br;
        struct net_bridge_port *port;
    };
    union {
        atomic_t refcnt;
        struct net_bridge_vlan *brvlan;
    }

    struct list_head vlist;
    struct rcu_head rcu;
};
```

#### struct net_bridge_vlan_group

```c
struct net_bridge_vlan_group
{
    struct rhashtable vlan_hash;
    struct list_head vlan_hash;
    u16 num_vlans;
    u16 pvid;
};
```

#### struct net_bridge_fdb_entry

```c
struct net_bridge_fdb_entry
{
    struct hlist_node       hlist;
    struct net_bridge_port *dst;

    unsigned long updated;
    unsigned long used;

    mac_addr addr;
    __u16 vlan_id;
    unsigned char is_local: 1, is_static: 1, 
                  added_by_user: 1, 
                  added_by_external_learn: 1;
    struct rcu_head rcu;
};
```

#### struct net_bridge_mdb_entry

```c
struct net_bridge_mdb_entry {
    struct hlist_node   hlist[2];
    struct net_bridge  *br;
    struct net_bridge_port_group __rcu *ports;
}
```

#### struct net_bridge_mdb_htable

#### struct net_bridge_port

```c
struct net_bridge_port 
{
    struct net_bridge *br;
    struct net_device *dev;
    struct list_head   list;

    u8 priority;
    u8 state;
    u8 port_no;

    unsigned char topology_change_ack;
    unsigned char config_pending;
    port_id port_id;
    port_id desigated_port;
    bridge_id desigated_root;
    bridge_id desigated_bridge;
    u32 path_cost;
    u32 desigated_cost;
    unsigned long designated_age;

    struct timer_list forward_delay_timer;
    struct timer_lsit hold_timer;
    struct timer_list message_age_timer;
    struct kobject kobj;
    struct rcu_head rcu;

    unsigned long flags;

#ifdef CONFIG_BRIDGE_ICMP_SNOOPING
    struct bridge_mcast_own_query ipv4_own_query;
#if IS_ENABLE(CONFIG_IPV6)
    struct bridge_mcast_own_query ipv6_own_query;
#endif 
    unsigned char multicast_router;
    struct timer_list multicast_router_timer;
    struct hlist_head mglist;
    struct hlist_node rlist;
#endif /* CONFIG_BRIDGE_ICMP_SNOOPING */

#ifdef CONFIG_SYSFS
    char sysfs_name[IFNAMESIZ];
#endif /* CONFIG_SYSFS */

#ifdef CONFIG_NET_POLL_CONTROLLER
    struct netpoll *np;
#endif /* CONFIG_NET_POLL_CONTROLLER */

#ifdef CONFIG_BRIDGE_VLAN_FILTERING
    struct net_bridge_vlan_group __rcu *vlgrp;
#endif /* CONFIG_BRIDGE_VLAN_FILTERING */
};
```

```c
#define br_auto_port(p)     ((p)->flags & BR_AUTO_MASK)
#define br_promisc_port(p)  ((p)->flags & BR_PROMISC)
#define br_port_exists(dev) (dev->priv_flags & IFF_BRIDGE_PORT)
```

#### struct net_bridge_port_group

```c
struct net_bridge_port_group
{
    struct net_bridge_port *port;
    struct net_bridge_port_group __rcu *next;
    struct hlist_node mqlist;
    struct rcu_head rcu;
    struct timer_list timer;
    struct br_ip addr;
    unsigned char state;
    unsigned char eth_addr[ETH_ALEN];
    bool unicast; 
};
```

#### struct net_bridge

```c
struct net_bridge
{
    spinlock_t lock;
    struct list_head port_list;
    struct net_device *dev;

    struct pcpu_sw_netstatss __percpu *stats;
    spinlock_t hash_lock;
    struct hlist_head hash[BR_HASH_SIZE];               // FDB ?

#if IS_ENABLE(CONFIG_BRIDGE_NETFILTER)
    union {
        struct rtable fake_rtable;
        struct rt6_info fake_rt6_info;
    };
    bool nf_call_iptables;
    bool nf_call_ip6tables;
    bool nf_call_arptables;
#endif /* CONFIG_BRIDGE_NETFILTER */

    u16 group_fwd_mask;
    u16 group_fwd_mask_required;

    bridge_id designated_root;
    bridge_id bridge_id;
    u32 root_path_cost;
    unsigned long mac_age;
    unsigned long hello_time;
    unsigned long forward_delay;
    unsigned long bridge_max_age;
    unsigned long ageing_time;
    unsigned long bridge_hello_time;
    unsigned long bridge_forward_delay;

    u8 group_addr[ETH_ALEN];
    bool group_addr_set;
    u16 root_port;

    enum {
        BR_NO_STP,
        BR_KERNEL_STP,
        BR_USER_STP,
    } stp_enabled;

    unsigned char topology_change;
    unsigned char topology_change_detected;

#ifdef CONFIG_BRIDGE_IGMP_SNOOPING
    unsigned char multicast_router;

    u8 multicast_disabled: 1;
    u8 multicast_querier: 1;
    u8 multicast_query_use_ifaddr: 1,
    u8 has_ipv6_addr: 1,
    
    u32 hash_elasticity:
    u32 hash_max;

    u32 multicast_last_member_count;
    u32 multicast_startup_query_count;

    unsigned long multicast_last_member_interval;
    unsigned long multicast_membership_interval;
    unsigned long multicast_querier_interval;
    unsigned long multicast_query_interval;
    unsigned long multicast_query_response_interval;
    unsigned long multicast_startup_query_interval;

    spinlock_t multicast_lock;
    struct net_bridge_mdb_htale __rcu *mdb;
    struct hlist_head router_list;

    struct timer_list multicast_router_timer;
    struct bridge_mcast_other_query ipv4_other_query;
    struct bridge_mcast_own_query ipv4_own_query;
    struct bridge_mcast_querier ipv4_querier;
#if IS_ENABLED(CONFIG_IPV6)
    struct bridge_mcast_other_query ip6_other_query;
    struct bridge_mcast_own_query ip6_own_query;
    struct bridge_mcast_querier ip6_querier;
#endif
#endif

    struct timer_list hello_timer;
    struct timer_list tcn_timer;
    struct timer_list_topology_change_timer;
    struct timer_list gc_timer;
    struct kobject *ifobj;
    u32 auto_cnt;

#ifdef CONFIG_BRIDGE_VLAN_FILTERING
    struct net_bridge_vlan_group __rcu *vlgrp;
    u8 vlan_enabled;
    __be16 vlan_proto;
    u16 default_pvid;
#endif
};
```

#### struct br_input_skb_cb

```c
struct br_input_skb_cb
{
    struct net_device *brdev;

#ifdef CONFIG_BRIDGE_IGMP_SNOOPING
    int igmp;
    int mrouters_only;
#endif /* CONFIG_BRIDGE_IGMP_SNOOPING */

    bool proxyarp_replied;

#ifdef CONFIG_BRIDGE_VLAN_FILTERING
    bool vlan_filtered;
#endif /* CONFIG_BRIDGE_VLAN_FILTERING */
};
```

```c
#define BR_INPUT_SKB_CB(__skb) ((struct br_input_skb_cb *)(__skb)->cb)
```

## 函数接口

#### macro func

```c
#define br_printk(level, br, format, args...) \
    printk(level "%s: "format, (br)->dev->name, ##args)

#define br_err(__br, format, args...) \
    br_printk(KERN_ERR, __br, format, ##args)
#define br_warn(__br, format, args...) \
    br_printk(KERN_WARNING, __br, format, ##args)
#define br_notice(__br, format, args...) \
    br_printk(KERN_NOTICE, __br, format, ##args)
#define br_info(__br, format, args...) \
    br_printk(KERN_INFO, __br, format, ##args)
#define br_debug(__br, format, args...) \
    pr_debug("%s: " format, (br)->dev->name, ##args)
```

#### br_port_get_rcu

```c
static inline struct net_bridge_port *br_port_get_rcu (const struct net_device *dev)
{

}
```

#### br_port_get_rtnl

```c
static inline struct net_bridge_port *br_port_get_rtnl (const struct net_device *dev)
{

}
```


#### br_allowed_egress

```c
static inline bool br_allowed_egress (struct net_bridge_vlan_group *vg, const struct sk_buff *skb)
{
    return true;
}
```