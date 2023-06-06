

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

#### br_net_exit

<!--  -->




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