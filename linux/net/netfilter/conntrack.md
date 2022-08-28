连接跟踪(Connection Tracking, Conntrack CT)  维护可跟踪协议的连接状态。该状态跟踪是针对特定协议的包， 而不是所有协议的包。

CT支持的协议 TCP、UDP、ICMP、DCCP、SCTP、GRE






```c
struct nf_conntrack_man_proto;

/* man is manipulatable. */
struct nf_conntrack_man;

struct nf_conntrack_tuple;

struct nf_conntrack_l4proto;

struct nf_conntrack_tuple_hash;

struct nf_conn;
```


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

