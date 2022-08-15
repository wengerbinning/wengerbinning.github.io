




```c
struct net;
struct pernet_operations;
```


```c
int register_pernet_subsys (struct pernet_operations *);
int unregisterpernet_subsys (struct pernet_operations *);
``` 


```c
struct net *get_net_ns_by_id (struct net *net, int id);
struct net *get_net_ns_by_pid (pid_t pid);
struct net *get_net_ns_by_fd (int fd);
```


## FILES


include/net/net_namespace.h

net/core/net_namespace.c


