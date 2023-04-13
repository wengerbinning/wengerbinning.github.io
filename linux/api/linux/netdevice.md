


## 数据类型

#### struct net_device

## 函数接口


#### register_netdevice

```c
extern int register_netdevice (struct net_device *dev);
```


#### unregister_netdevice_queue

```c
extern void	unregister_netdevice_queue (struct net_device *dev, struct list_head *head);
```

#### netif_wake_queue

```c
static inline void netif_wake_queue(struct net_device *dev);
```

#### netif_stop_queue

```c
static inline void netif_stop_queue(struct net_device *dev);
```