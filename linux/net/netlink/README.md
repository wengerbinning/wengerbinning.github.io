# Netlink Sockets







```c
struct netlink_ring;

struct netlink_sock;

struct netlink_table;

struct listeners;


```


```c
static const struct proto_ops   netlink_ops;
static const struct net_proto_family    netlink_family_ops;
static const struct rhashtable_params   netlink_rhashtable_params;
```










```c
static int __init netlink_proto_init(void);


int netlink_has_listeners(struct sock *sk, unsigned int group);

```


## FILES

net/netlink/af_netlink.h
net/netlink/af_netlink.c
net/netlink/diag.c
