
## 数据类型

## 数据对象

#### struct net

```c

```

#### net_namespace_list

```c
extern struct list_head net_namespace_list;
```

#### init_net

```c
extern struct net init_net;
```



## 函数接口

#### net_sysctl_init

```c
extern int net_sysctl_init (void);
```

#### register_net_sysctl

```c
extern struct ctl_table_header *register_net_sysctl (struct net *net, const char *path, struct ctl_table *table);
```

#### unregister_net_sysctl_table

```c
extern void unregister_net_sysctl_table (struct ctl_table_header *header);
```
