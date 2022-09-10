netfilter是一个用于管理网络数据包的框架，提供网络地址转换、数据包内容修改、数据包过滤等功能。

netfilter框架于2000年合入2.4.x




netfilter在网络数据中提供了5个钩子点

PREROUTING
LOCAL_IN
FORWARD
LOCAL_OUT
POSTROUTING


每个钩子的返回类型是

NF_DROP
NF_ACCEPT
NF_STOLEN
NF_QUEUE
NF_REPEAT


## 源码分析

配置

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

### 数据结构

宏
------------------------------

```c
#define NF_DROP     0
#define NF_ACCEPT   1
#define NF_STOLEN   2
#define NF_QUEUE    3
#define NF_REPEAT   4
#define NF_STOP     5
#define NF_MAX_VERDICT  NF_STOP
```



枚举类型

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


数据类型
----------------------------------

```c
struct nf_hook_ops;
struct nf_hook_entry;


(*ip_ct_attach)
(*nf_ct_destroy)


```


### 实例对象

```c
static list_head nf_hhok_list;
struct nfnl_ct_hook *nfnl_ct_hook;



const struct nf_conntrack_zone nf_ct_zone_dflt;

static struct pernet_operations netfilter_net_ops;
```



### 函数接口

```c
nf_register_net_hook
nf_unregister_net_hook

nf_register_net_hooks
nf_unregister_net_hooks


nf_hook_slow


skb_make_writable



nf_ct_attach
nf_conntrack_destroy



net_filter_init
```


```c
static u32 hash_bucket (u32 hash, const struct net *net);
static u32 __hash_bucket (u32 hash, unsigned int size);
```



## FILES

include/linux/netfilter.h
include/uapi/linux/netfilter.h

include/linux/netfilter/*

net/netfilter/core.c



## LINKS






