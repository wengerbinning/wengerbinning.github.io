

## 数据对象

#### br_switchdev_notifier

```c
static struct br_switchdev_notifier = {
    .notifier_call = br_switchdev_event,
};
```

#### br_net_ops

```c
static struct pernet_operations br_net_ops = {
    .exit = br_net_exit,
};
```

#### br_stp_proto

```c
static const struct stp_proto br_stp_proto = {
    .rcv = br_stp_rcv, 
};
```

#### br_notify_hook

```c
br_notify_hook_t __rcu *br_notify_hook __read_mostly;
```

```c
EXPORT_SYMBOL_GPL(br_notify_hook);
```


## 函数接口

<!-- private api -->

#### br_switchdev_event

```c
static int br_switchdev_event (struct noifier_block *unsed, 
    unsgined long event, void *ptr)
{
    struct net_device *dev = switchdev_noifier_info_to_dev(ptr);
    struct net_bridge_port *p;
    struct net_bridge *br;
    struct switchdev_notifier_fdb_info *fdb_info;
    int err = NOTIFY_DONE;

    p = br_port_get_rtnl(dev);
    if (!p)
        goto out;
    
    br = p->br;

    switch (event) {
        case SWITCHDEV_FDB_ADD:
            err = br_fdb_eaternal_learn_add(br, p, fdb_info->addr, fdb_info->vid);
            if (err)
                err = notifier_from_errno(err);
            break;
        case SWITCHDEV_FDB_DEL:
            fdb_info = ptr;
            err = br_fdb_external_learn_del(br, p, fdb_info->addr, fdb_info->vid);
            if (err)
                err = notifier_from_errno(err);
            break;
    }  

out:
    return err;
}
```

#### br_net_exit

```c
static void __net_exit br_net_exit (struct net *net)
{
    struct net_device *dev;
    LIST_HEAD(list);

    rtnl_lock();
    for_each_netdev(net, dev) {
        if (dev->priv_flags & IFF_EBRIDGE)
            br_dev_delete(dev, &list);
    }
    unregitser_netdevice_many(&list);
    rtnl_unlock();
}
```

<!-- module handle api  -->

#### br_init

```c
static int __init br_init (void)
{
    int err;

    err = stp_proto_register(&br_stp_proto);
    if (err < 0) {
        pr_err("bridge: can't register sap for STP\n");
        return err;
    }

    err = br_fdb_init();
    if (err)
        goto err_out;
    
    err = register_pernet_subsys(&br_net_ops);
    if (err)
        goto err_out1;

    err = br_nf_core_init();
    if (err)
        goto err_out2;

    err = register_netdevice_notifier(&br_netdevice_notifier);
    if (err)
        goto err_out3;
    
    err = register_switchdev_notifier(&br_switchdev_notifier);
    if (err)
        goto err_out4;

    err = br_netlink_init();
    if (err)
        goto err_out5;
    
    brioctl_set(br_ioctl_deviceless_stub);

#if IS_ENABLED(CONFIG_ATM_LAME)
    br_fdb_test_addr_hook = br_fdb_test_addr;
#endif /* IS_ENABLED(CONFIG_ATM_LAME) */

    pr_info("bridge: automatic filter via arp/ip/ip6tables has been deprecated."
            "Update your scripts to load br_netfilter if you need this.\n");
    
    return 0;

err_out5:
    unregister_switchdev_notifier(&br_switchdev_notifier);

err_out4:
    unregister_netdevice_notifier(&br_netdevice_notifier);

err_out3:
    br_nf_core_fini();

err_out2:
    unregister_pernet_subsys(&br_net_ops);

err_out1:
    br_fdb_fini();

err_out:
    stp_proto_unregister(&br_stp_proto);
    return err;
}
```

```c
module_init(br_init);
```

#### br_deinit

```c
statc void __exit br_deinit (void)
{
    stp_proto_unregister(&br_stp_proto);
    br_netlink_fini();
    unregister_switchdev_notifier(&br_switchdev_notifier);
    unregister_netdevice_notifier(&br_device_notifier);
    brioctl_set(NULL);
    unregister_pernet_subsys(&br_net_ops);

    rcu_barrier();

    br_nf_core_fini();

#if IS_ENABLED(CONFIG_ATM_LANE)
    br_fdb_test_addr_hook = NULL;
#endif /* CONFIG_ATM_LANE */

    br_fdb_fini();
}
```

```c
module_exit(br_deinit);
```