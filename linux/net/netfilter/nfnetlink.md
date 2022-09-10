
```c


#define NFNL_SUBSYS_NONE                0
#define NFNL_SUBSYS_CTNETLINK           1
#define NFNL_SUBSYS_CTNETLINK_EXP       2
#define NFNL_SUBSYS_QUEUE               3
#define NFNL_SUBSYS_ULOG                4
#define NFNL_SUBSYS_OSF                 5
#define NFNL_SUBSYS_IPSET               6
#define NFNL_SUBSYS_ACCT                7
#define NFNL_SUBSYS_CTNETLINK_TIMEOUT   8
#define NFNL_SUBSYS_CTHELPER            9
#define NFNL_SUBSYS_NFTABLES           10
#define NFNL_SUBSYS_NFT_COMPAT         11
#define NFNL_SUBSYS_COUNT              12


#define NFNL_SUBSYS(x)      (x & 0xFF00)
#define NFNL_MSG_TYPE(x)    (x & 0x00FF)

#define nfnl_dereference(p, ss)     rcu_dereference_protected(p, lockep_nfnl_isheld(ss))

#define MODULE_ALIAS_NFNL_SUBSYS(subsys)    MODULE_ALIAS("nfnetlink-subsys-" __stringify(subsys)) 

```


数据类型

```c
struct nfnl_callback;

struct nfnetlink_subsystem；


```


实例对象

```c
struct char nfversion[] = "0.30";

static struct {
    struct mutex    mutex;
    const struct nfnetlink_subsystem   *subsys;
} table[NFNL_SUBSYS_COUNT];

static const int nfnl_group2type[NFNLGRP_MAX+1] = {
    [NFNLGRP_CONNTRACK_NEW] = NFNL_SUBSYS_CTNETLINK,
    [NFNLGRP_CONNTRACK_UPDATE]  = NFNL_SUBSYS_CTNETLINK,
    [NFNLGRP_CONNTRACK_DESTROY] = NFNL_SUBSYS_CTNETLINK,
    [NFNLGRP_CONNTRACK_EXP_NEW] = NFNL_SUBSYS_CTNETLINK_EXP,
    [NFNLGRP_CONNTRCK_EXP_UPDATE] = NFNL_SUBSYS_CTNETLINK_EXP,
    [NFNLGRP_CONNTRACK_EXP_DESTROY] = NFNL_SUBSYS_CTNETLINK_EXP,
    [NFNLGRP_NFTABLES] = NFNL_SUBSYS_NFTABLES,
    [NFNLGRP_ACCT_QUOTA] = NFNL_SUBSYS_ACCT,
};


static const struct nfnl_callback nfnl_cthelper_cb[NFNL_MSG_CTHELPER_MAX];
static const struct nfnetlink_subsystem nfnl_cthelper_subsys;

```



```c
int nf_netlink_subsys_register(const struct nfnetlink_subsystem *n);
int nf_netlink_subsys_unregister(const struct nfnetlink_subsystem *n);


int nfnetlink_has_listeners(struct net *net, unsigned int group);

struct sk_buff *nfnetlink_alloc_skb(struct net *net, unsigned int size, u32 dst_portid, gfp_t gfp_mask);

int nfnetlink_send(struct sk_buff *skb, struct net *net, u32 ported, unsigned int group, int echo, gfp_t flags);
int nfnetlink_set_err(struct net *net, u32 portid, u32 group, int error);
int  nfnetlink_unicast(struct sk_buff *skb, struct net *net, u32 portid, int flags);

void nfnl_lock (__u8 subsys_id);
void nfnl_unlock (__u8 subsys_id);
```



## FILES

include/uapi/linux/netfilter/nfnetlink.h

include/linux/netfilter/nfnetlink.h

net/netfilter/nfnetlink.c
net/netfilter/nfnetlink_cthelper.c