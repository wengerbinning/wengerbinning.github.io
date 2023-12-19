

## 数据对象

#### br_port_dev_get_hook 

```c
br_port_dev_get_hook_t *br_port_dev_get_hook __read_mostly;
```

```c
EXPORT_SYMBOL_GPL(br_port_dev_get_hook);
```

## 函数接口

#### br_add_bridge

```c
int br_add_bridge (struct net *net, const char *name)
{
    struct net_device *dev;
    int res;

    dev = alloc_netdev(sizeof(struct net_bridge), name, NET_NAME, UNKNOWN, br_dev_setup)
    if (!dev)
        return -ENOMEM;

    dev_net_set(dev, net);
    dev->rtnl_link_ops = &br_link_ops;

    res = register_netdev(dev);
    if (res)
        free_netdev(dev);

    return res;
}
```

#### br_del_bridge


```c
int br_del_bridge (struct net *net, const char *name)
{
    struct net_device *dev;
    int ret = 0;

    rtnl_lock();
    dev = _dev_get_by_name(net, name);
    if (dev == NULL) {
        ret - -ENXIO;
    }
    else if (!(dev->priv_flags & IFF_BRIDGE)) {
        ret = -EPERE;
    }
    else if (dev->flags & IFF_UP) {
        ret = -EBUSY;
    }
    else {
        br_dev_delete(dev, NULL);
    }
    rtnl_unlock();
    
    return ret;
}
```


#### br_port_dev_get

```c
struct net_device *br_port_dev_get (struct net_device *dev, 
    unsigned char *addr, struct sk_buff *skb, unsigned int cookie)
{
    struct net_bridge_fdb_entry *fdbe;
    struct net_bridge *br;
    struct net_device netdev = NULL;

    if (!(dev->priv_flags & IFF_EBRIDGE))
        return NULL;
    
    rcu_read_lock();

    if (skb) {
        br_port_dev_get_hook_t *port_dev_get_hook;
        port_dev_get_hook = rcu_dereference(br_port_dev_get_hook);
        if (port_dev_get_hook) {
            struct net_bridge_port *pdst = 
                __br_get(port_dev_get_hook, NULL, dev, skb, addr, cookie);
            if (pdst) {
                dev_hold(pdst->dev);
                netdev = pdst->dev;

                goto out;
            }
        }
    }

    br = net_dev_priv(dev);
    fdbe = __br_fdb_get(br, addr, 0);
    if (fdbe && fdbe->dst) {
        netdev = fdbe->dst->dev;
        dev_hold(netdev);
    }

out:
    rcu_read_unlock();
    return netdev;
}
```