
#### struct sk_buff_data_t

```c
#ifdef NET_SKBUFF_DATA_USER_OFFSET
typedef unsigned int sk_buff_data_t;
#else
typedef unsigned char *sk_buff_data_t;
#endif /* NET_SKBUFF_DATA_USER_OFFSET */
```

#### struct sk_buff 

```c
struct sk_buff 
{
    union {
        struct {
            struct sk_buff *next;
            struct sk_buff *prev;
            union {
                ktime_t tstamp;
                struct skb_mstamp skb_mstamp;
            };
        };
        struct rb_node rbnode;
    };

    struct sock *sk;
    struct net_device *dev;

    char cb[48] __aligned(8);

    unsigned long skb_refdst;
    void (*destructor) (struct sk_buff *skb);

#ifdef CONFIG_XFRM
    struct sec_path *sp;
#endif /* CONFIG_XFRM */

#if defined(CONFIG_NF_CONNTRACK) || defined(CONFIG_NF_CONNTRACK_MODULE)
    struct nf_conntrack *nfct;
#endif /* CONFIG_NF_CONNTRACK || CONFIG_NF_CONNTRACK_MODULE */

#if IS_ENABLE(CONFIG_BRIDGE_NETIFILTER)
    struct nf_bridge_info *nf_bridge;
#endif /* CONFIG_BRIDGE_NETIFILTER */

    unsigned int len, data_len;
    __u16 man_len, hdr_len;

    kmemcheck_bitfield_begin(flags1);
    __u16 queue_mapping;
    __u8 cloned: 1, nohdr: 1, fclone: 2, peeked: 1, head_frag: 1, xmit_more: 1;
    kmemecheck_bitfield_end(flags1);

    __u32 headers_start[0];

#ifdef __BIG_ENDIAN_BITFIELD
#define PKT_TYPE_MAX    (7 << 5)
#else
#define PKT_TYPY_MAX    (7)
#endif /* __BIG_ENDIAN_BITFIELD */

#define PKT_TYPE_OFFSET()   offsetof(struct sk_buff, __pkt_type_offset)

    __u8 __pk_type_offset[0];
    __u8 pkt_type: 3;
    __u8 pfmemalloc: 1;
    __u8 ignore_df: 1;
    __u8 nfctinfo: 3;

    __u8 nf_trace: 1;
    __u8 ip_summed: 2;
    __u8 ooo_okay: 1;
    __u8 l4_hash: 1;
    __u8 sw_hash: 1:
    __u8 wifi_acked_valid: 1;
    __u8 wifi_acked: 1;

    __u8 no_fcs: 1;
    __u8 encapsulation: 1;
    __u8 encap_hdr_csum: 1;
    __u8 csum_valid: 1;
    __u8 csum_complete_sw: 1;
    __u8 csum_level: 2;
    __u8 csum_bad: 1;

#ifdef CONFIG_IPV6_NDISC_NODETYPE
    __u8 ndisc_nodetype: 2;
#endif
    __u8 ipvs_property: 1;
    __u8 inner_protocol_type: 1;
    __u8 remcsum_offload: 1;
    __u8 gro_skip: 1;
    __u8 fast_forwarded: 1;


#ifdef CONFIG_NET_SCHED
    __u16 tc_index;

#ifdef CONFIG_NET_CLS_ACT
    __u16 tc_verd;
#endif
#endif /* CONFIG_NET_SCHED */

    union {
        __wsum csum;
        struct {
            __u16 csum_start;
            __u16 csum_offset;
        };
    };

    __u32 priority;
    int skb_if;
    __u32 hash;
    __be16 vlan_proto;
    __u16   vlan_tci;

#if defined(CONFIG_NET_RX_BUSY_POLL) || defined(CONFIG_XPS)
    union {
        unsigned int napi_id;
        unsigned int sender_cpu;
    };
endif /* CONFIG_NET_RX_BUSY_POLL || CONFIG_XPS */

    union {
#ifdef CONFIG_NETWORK_SECMARK
        __u32 secmark;
#endif
#ifdef CONFIG_NET_SWITCHDEV
        __u32 offload_fwd_mark;
#endif
    };

    union {
        __u32 mark;
        __u32 reserved_tailroom;
    };

    union {
        __be16 inner_protocol;
        __u8 inner_ipproto;
    };

    __u16 inner_transport_header;
    __u16 inner_network_header;
    __u16 inner_mac_header;

    __be16 protocol;
    __u16 transport_header;
    __u16 network_header;
    __16 mac_header;

    __u32 header_end[0];

    sk_buff_data_t tail;
    sk_buff_data_t end;
    unsigned char *head, *data;
    unsigned int truesize;
    atomic_t users;

#ifdef CONFIG_DEBUG_OBJECT_SKBUFF
#define DEBUG_OBJECT_SKBUFF_STACKSIZE 20
    void *free_addr[DEBUG_OBJECT_SKBUFF_STACKSIZE];
    void *alloc_addr[DEBUG_OBJECT_SKBUFF_STACKSIZE];
    u32 sum;
#endif /* CONFIG_DEBUG_OBJECT_SKBUFF */

    __u32 pkt_mark;
};
```