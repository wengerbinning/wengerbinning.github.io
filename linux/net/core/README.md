



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