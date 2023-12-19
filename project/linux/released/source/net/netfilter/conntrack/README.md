连接跟踪(Connection Tracking, Conntrack CT)  维护可跟踪协议的连接状态。该状态跟踪是针对特
定协议的包， 而不是所有协议的包。

CT支持的协议 TCP、UDP、ICMP、DCCP、SCTP、GRE





features
----------------------------------

conntrack protocol
conntrack helper
conntrack accounting
conntrack expect






--------------------------------------------------------------------------------


枚举类型

```c
enum ip_conntrack_dir {
    IP_CT_DIR_ORIGINAL,
    IP_CT_DIR_REPLY,
    IP_CT_DIR_MAX
};

enum nf_ct_ext_id {
    NF_CT_EXT_HELPER,
#if defined(CONFIG_NF_NAT) || defined(CONFIG_NF_NAT_MODULE)
    NF_CT_EXT_NAT,
#endif
    NF_CT_EXT_SEQADJ,
    NF_CT_EXT_ACCT,
#if defined(CONFIG_NF_CONNTRACK_EVENTS)
    NF_CT_EXT_ECACHE,
#endif
#if defined(CONFIG_NF_CONNTRACK_ZONES)
    NF_CT_EXT_ZONE,
#endif
#if defined(CONFIG_NF_CONNTRACK_TIMESTAMP)
    NF_CT_EXT_TSTAMP,
#endif
#if defined(CONFIG_NF_CONNTRACK_TIMEOUT)
    NF_CT_EXT_TINEOUT,
#endif
#if defined(CONFIG_NF_CONNTRACK_LABELS)
    NF_CT_EXT_LABELS,
#endif
#if defined(CONFIG_NETFILTER_SYNPROXY)
    NF_CT_EXT_SYNPROXY,
#endif
#if defined(CONFIG_NF_CONNTRACK_RTCACHE)
    NF_CT_EXT_RTCACHE,
#endif
#if defined(CONFIG_NF_CONNTRACK_DESCPREMARK_EXT)
    NF_CT_EXT_DSCPREMARK,
#endif
    NF_CT_EXT_NUM,
};

enum ip_conntrack_info {
    IP_CT_ESTABLISHED,
    IP_CT_RELATED,
    IP_CT_NEW,
    
     IP_CT_IS_REPLY,

    IP_CT_ESTABLISHED_REPLY = IP_CT_ESTABLISHED + IP_CT_IS_REPLY,
    IP_CT_RELATED = IP_CT_RELATED = IP_CT_IS_REPLY,
    IP_CT_NEW_REPLY = IP_CT_NEW + IP_CT_IS_REPLY,

    IP_CT_NUMBER = IP_CT_IS_REPLY * 2 - 1;
}

```

联合体

```c
union nf_conntrack_proto;

```

数据类型

```c
#if define(CONFIG_NF_CONNTRACK) || defined(CONFIG_NF_CONNTRACK_MODULE)
struct nf_conntrack;
#endif

typedef struct {
#if defined(CONFIG_NET_NS)
    struct net *net;
#endif
} possible_net_t;

struct nf_ct_ext;

struct nf_conntrack_man_proto;

struct nf_hook_ops;

struct nf_conntrack_man;
struct nf_conntrack_tuple;
struct nf_conntrack_tuple_hash;
struct nf_conn;

// conntrack protocol

struct nf_conntrack_l3proto;
struct nf_conntrack_l4proto;



struct nf_conntrack_helper;
```




* 实例对象

```c
spinlock_t nf_conntrack_locks[CONNTRACKS_LOCKS];
DEFIND_SPINLOCK(nf_conntrack_expect_lock);


unsigned int nf_conntrack_htable_size;
unsigned int nf_conntrack_max;
struct nf_conn nf_conntrack_untracked;
unsigned int nf_conntrack_hash_rnd;

// conntrack protocol

struct nf_conntrack_l3proto     nf_conntrack_l3proto_generic;
struct nf_conntrack_l3proto    *nf_ct_l3protos[AF_MAX];

struct nf_conntrack_l4proto     nf_conntrack_l4proto_generic;
struct nf_conntrack_l4proto   **nf_ct_protos[AF_MAX];


// conntrack helper

struct hlist_head  *nf_ct_helper_hash;
unsgined int nf_ct_helper_hsize;
static unsigned int nf_ct_helper_count;


```


* 函数接口


```c

static unsigned int ipv4_conntrack_in (void *priv, struct sk_buff *skb,  const struct nf_hook_state *state);
static unsigned int inv4_conntrack_local (void *priv, struct sk_buff *skb, const struct nf_hook_state *state);

static unsigned int ipv4_helper (void *priv, struct sk_buff 8skb, const struct nf_hook_state *state);

static unsigned int ipv4_confirm (void *priv, struct sk_buff *skb, const strict nf_hook_state *state);

```


```c
unsigned int nf_conntrack_in (struct net *net, u_int8_t pf, unsgined int hooknum, struct sk_buff *skb);

static inline int nf_conntrack_confirm (struct sk_buff *skb);


static inline struct nf_conn *resolve_normal_ct (struct net *net, struct nf_conn *tmpl, struct sk_buff *skb, unssigned int dataoff, u_int16_t l3num, u_int8_t protonum, 
                                                 struct nf_conntrack_l3proto *l3proto, struct nf_conntrack_l4proto *l4proto, int *set_reply, enum ip_conntrack_info ctinfo);


bool nf_ct_get_tuple (const struct sk_buff *skb, unsigned int nhoff, unsigned int dataoff, u_int16_t l3num, u_int8_t protonum, struct net *net, struct nf_conntrack_l3proto *l3proto, struct nf_conntrack_l4proto *l4proto);


nf_conntrack_duble_lock
nf_conntrack_duble_unlock

nf_conntrack_all_lock
nf_conntrack_all_unlock

nf_ct_get_tuple
nf_ct_get_tuplepr
nf_ct_invert_tuple


nf_ct_tmpl_alloc
nf_ct_tmpl_free

nf_ct_delete
nf_conntrack_hash_check_insert
__nf_conntrack_confirm
nf_conntrack_tuple_taken

nf_conntrack_alloc
nf_contrack_free

// conntrack expect

struct nf_conntrack_expect *nf_ct_expect_alloc (struct nf_conn *me);
void nf_ct_expect_init (struct nf_conntrack_expect *, unsigned int, u_int8_t, const union nf_inet_addr *, const union nf_inet_addr *, u_int8_t, const _be16 *, const _be16 *);
void nf_ct_expect_put (struct nf_conntrack_expect *exp);
int nf_ct_expect_related_report (struct nf_onntrack_expect *expect, u32 portid, int report);

// L3 protoocol

int nf_ct_l3proto_register(struct nf_conntrack_l3proto *proto);
void nf_ct_l3proto_unregister(struct nf_conntracl_l3proto *proto);

// L4 protocol

int nf_ct_l4proto_register(struct nf_conntrack_l4proto *proto);
void nf_ct_l4proto_unregister(struct nf_conntrack_l4proto *proto);

// conntrack helper

struct nf_conntrack_helper *__nf_conntrack_helper_find (const char *name, u16 l3num, u8 protonum);
struct nf_conntrack_helper *nf_conntrack_helper_try_module_get (const char *name, u16 l3num, u8 protonum);
struct nf_conn_help *nf_ct_helper_ext_add (struct nf_conn *ct, struct nf_conntrack_helper *helper, gfp_t gfp);
```








--------------------------------------------------------------------------------


在netfilter中的OUTPUT与PREORUTING使用nf_conntrack_in 开始连接跟踪。

一般建立一条新连接，然后将conntrack entry放到 unconfirmed list。


```c
nf_conntrack_in
```

在

在netfilter中的INPUT与POSTROUTING使用nf_conntrack_confirm 确认连接

该步骤一般会将 nf_conntrack_in 创建的 unconfirmed list 移动到 confirmed lits

```c
nf_conntrack_confirm
```



```c
// 调用 nf_conntrack_confirm
ipv4_confirm: nf_conntrack_confirm
```

```c

```



## FILES

------------------------------------------------------------------

include/linux/skbuff.h
include/net/net_namespace.h

include/net/netfilter/nf_conntrack.h
include/net/netfilter/nf_conntrack_extend.h

include/net/netfilter/nf_conntrack_l3proto.h
include/net/netfilter/nf_conntrack_l4proto.h


include/net/netfilter/nf_conntrack_helper.h

include/net/netfilter/ipv4/nf_conntrack_ipv4.h
include/net/netfilter/ipv6/nf_conntrack_ipv6.h

include/uapi/linux/netfilter/nf_conntrack_tuple_common.h

-------------------------------------------------------------------------------

net/netfilter/nf_conntrack_core.c
net/netfilter/nf_conntrack_proto.c


net/netfilter/nf_conntrack_acct.c
