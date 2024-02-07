netfilter是一个用于管理网络数据包的框架，提供网络地址转换、数据包内容修改、数据包过滤等功能。
netfilter框架于2000年合入2.4.x


netfilter在网络数据中提供了5个钩子点

PREROUTING
LOCAL_IN
FORWARD
LOCAL_OUT
POSTROUTING

x_tables是ip_tables, ip6_tables, arp_tables的后端。

每个钩子的返回类型是

NF_DROP
NF_ACCEPT
NF_STOLEN
NF_QUEUE
NF_REPEAT


```c
#define NF_DROP     0
#define NF_ACCEPT   1
#define NF_STOLEN   2
#define NF_QUEUE    3
#define NF_REPEAT   4
#define NF_STOP     5
#define NF_MAX_VERDICT  NF_STOP
```


```c
CONFIG_NETFILTER
CONFIG_NETFILTER_DEBUG
CONFIG_NETFILTER_ADVANCED
CONFIG_BRIDGE_NETFILTER

CONFIG_NETFILTER_INGRESS
CONFIG_NETFILTER_NETLINK
CONFIG_NETFILTER_NETLINK_ACCT
CONFIG_NETFILTER_NETLINK_QUEUE
CONFIG_NETFILTER_NETLINK_LOG
// Netfilter Conntrack
CONFIG_NF_CONNTRACK
CONFIG_NF_CONNTRACK_MARK
CONFIG_NF_CONNTRACK_SECMARK
CONFIG_NF_CONNTRACK_ZONES
CONFIG_NF_CONNTRACK_PROCFS
CONFIG_NF_CONNTRACK_EVENTS
CONFIG_NF_CONNTRACK_RTCACHE
CONFIG_NF_CONNTRACK_TIMEOUT
CONFIG_NF_CONNTRACK_DSCPREMARK_EXT
CONFIG_NF_CONNTRACK_CHAIN_EVENTS
CONFIG_NF_CONNTRACK_TIMESTAMP
CONFIG_NF_CONNTRACK_LABELS
CONFIG_NF_CT_PROTO_DCCP
CONFIG_NF_CT_PROTO_GRE
COFNIG_NF_CT_PROTO_SCTP
CONFIG_NF_CT_PROTO_UDPLITE
CONFIG_NF_CONNTRACK_AMANDA
CONFIG_NF_CONNTRACK_FTP
CONFIG_NF_CONNTRACK_H323
CONFIG_NF_CONNTRACK_IRC
CONFIG_NF_CONNTRACK_BROADCAST
CONFIG_NF_CONNTRACK_NETBIOS_NS
CONFIG_NF_CONNTRACK_SNMP
CONFIG_NF_CONNTRACK_PPTP
CONFIG_NF_CONNTRACK_SANE
CONFIG_NF_CONNTRACK_SIP
CONFIG_NF_CONNTRACK_TFTP
CONFIG_NF_CT_NETLINK
CONFIG_NF_CONNTRACK_TIMEOUT
CONFIG_NF_CT_NETLINK_HELPER
CONFIG_NETFILTER_NETLINK_GLUE_CT
```


```c
enum nf_inet_hooks {
    NF_INET_PRE_ROUTING,
    NF_INET_LOCAL_IN,
    NF_INET_FORWARD,
    NF_INET_LOCAL_OUT,
    NF_INET_POST_ROUTING,
    NF_INET_NUMHOOKS,
};

enum {
    NFPROTO_UNSPEC,
    NFPROTO_INET,
    NFPROTO_IPV4,
    NFPROTO_ARP,
    NFPROTO_NETDEV,
    NFPROTO_BRIDGE,
    NFPROTO_IPV6,
    NFPROTO_DECNET,
    NFPROTO_NUMPROTO,
};

enum nf_ip_hook_priorities {
    NF_IP_PRI_FIRST = INI_MIN,
    NF_IP_PRI_CONNTRACK_DEFRAG = -400,
    NF_IP_PRI_RAW = -300,
    NF_IP_PRI_SELINUX_FIRST = -225,
    NF_IP_PRI_CONNTRACK = -200,
    NF_IP_PRI_MANGLE = -150,
    NF_IP_PRI_NAT_DST = -100,
    NF_IP_PRI_FILTER = 0,
    NF_IP_PRI_SECURITY = 50,
    NF_IP_PRI_NAT_SRC = 100,
    NF_IP_PRI_SELINUX_LAST = 255,
    NF_IP_PRI_CONNTRACK_HELPER = 300,
    NF_IP_PRI_CONNTRACK_CONFIRM = INT_MAX,
    NF_IP_PRI_LAST = INT_MAX,
};
```





nf_register_net_hook
nf_unregister_net_hook
nf_register_net_hooks
nf_unregister_net_hooks
nf_hook_slow
skb_make_writable
nf_ct_attach
nf_conntrack_destroy
net_filter_init



## FILES

include/linux/netfilter.h
include/uapi/linux/netfilter.h

include/linux/netfilter/*

net/netfilter/core.c



### conntrack

连接跟踪(Connection Tracking, Conntrack CT)  维护可跟踪协议的连接状态。该状态跟踪是针对特
定协议的包， 而不是所有协议的包。


conntrack protocol
conntrack helper
conntrack accounting
conntrack expect




CT支持的协议 TCP、UDP、ICMP、DCCP、SCTP、GRE





features
----------------------------------








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
include/net/netns/conntrack.h
-------------------------------------------------------------------------------

net/netfilter/nf_conntrack_core.c
net/netfilter/nf_conntrack_proto.c


net/netfilter/nf_conntrack_acct.c


#### conntrack extend

conntrack extend是基于conntrack的一个扩展模块。

### nfnetlink

```
include/uapi/linux/netfilter/nfnetlink.h
include/linux/netfilter/nfnetlink.h
net/netfilter/nfnetlink.c
net/netfilter/nfnetlink_cthelper.c
```

### nat



nf_nat_ipv4_in
nf_nat_ipv4_out
nf_nat_ipv4_local_fn
nf_nat_inet_fn

### helper

netfilter helper模块是一个netfilter的子模块。

### IP Virtual Server

IPVS实现了传输层的负载均衡，通常称为4层LAN交换，用户可以通过ipvssadm来实现管理配置。


#### IP set


iptable 是netfiler提供的用于组织过滤规则的模块

存在若干个规则表
默认有

raw
filter
nat
mangle
四张表



iptables的前身是ipfirewall（需要工作在内核），后更名为ipchains,可以定义多条规则，现在定义为iptables;用于定义规则，让内核中的netfilter来读取。
在内核空间共有五种位置：
* 网络接口间的转发
* 数据从内核流入用户时
* 数据从用户流入内核时
* 经过本机的外网卡接口
* 经过本机的内网卡接口
在这五个位置有五个钩子函数（五个规则链）
1. prerouting
2. input
3. forward
4. output
5. postrouting

防火墙分为通策略与堵策略，通过路由表来实现

1. filter 定义允许或禁止规则，在2,3,4链上
2. net 定义地址转换的规则， 在1,4,5链上
3. mangle修改包文原数据的规则，一般用于改TTL，在5个链上都可以。