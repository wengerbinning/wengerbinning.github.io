
* core的源码列表

socket

* sock.o
* request_sock.o
* skbuff.o
* datagram.o
* stream.o
* scm.o
* gen_stats.o
* gen_estimator.o
* net_name_space.o
* secure_seq.o
* flow_dissector.o


sys control

```txt
COFNIG_SYSCTL
```

* sysctl_net_core.o

device

* dev.o
* ethool.o
* dev_addr_lists.o
* dst.o
* netevent.o
* neighbour.o
* rtnetlink.o
* utils.o
* link_watch.o
* filter.o
* dev_ioctl.o
* tso.o






枚举类型

```c
enum sock_flags;
```

数据类型

```c
struct sock_common;
struct sock;


struct proto;
```



实例对象

```c
static struct list_head proto_list;

struct net init_net;

```




函数接口



```c


int proto_register(struct *prot, int alloc_slab);
void proto_unregister(struct *prot);



int register_prenet_subsys(struct pernet_operations *ops);
void unregister_pernet_subsys(struct pernet_operations *ops);


```

## FILES


include/net/sock.h

net/core/sock.c
net/core/stream.c

net/core/net_namespace.c






===========================


