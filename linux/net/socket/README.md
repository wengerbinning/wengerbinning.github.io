


数据类型

```c
struct proto_ops;
struct sock_shutdown_cmd;
struct socket_wq;
struct socket;
```



函数接口

```c
int sock_wake_async(struct socket_wq *sk_wq, int how, int band);

int sock_register(const struct net_proto_family *fam);
int sock_unregister(int family);


```


## FILES

include/linux/net.h

net/socket.c