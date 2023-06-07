




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