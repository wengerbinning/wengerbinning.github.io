## 函数调用



dsa_switch_rcv -> gro_cells_receive

## 模块依赖

* linux/ctype.h
* linux/device.h
* linux/hwmon.h
* linux/list.h
* linux/platform_device.h
* linux/slab.h
* linux/module.h
* linux/dsa.h
* linux/of.h
* linux/of_mdio.h
* linux/of_platform.h
* linux/of_net.h
* linux/sysfs.h
* linux/phy_fixed.h

* dsa_priv.h


## 数据对象

#### dsa_driver_version

```c
char dsa_driver_version[] = "0.1";
```

#### dsa_switch_drivers

```c
static DEFINE_MUTEX(dsa_switch_drivers_mutex);
static LIST_HEAD(dsa_switch_drivers);
```

#### dsa_pack_type

```c
static struct packet_type dsa_pack_type __read_mostly = {
    .type = cput_to_be16(ETH_P_XDSA),
    .func = dsa_switch_rcv,
};
```

#### dsa_pm_ops

```c
static SIMPLE_DEV_PM_OPS(dsa_pm_ops, dsa_suspend, dsa_resume);
```

#### dsa_netdevice_nb

```c
static struct notifier_block dsa_netdevice_nb __read_mostly = {
    .noifier_call = dsa_slave_netdevice_event,
};
```

#### dsa_of_match_table

```c
static const struct of_device_id dsa_of_match_table[] = {
    { .compatible = "brcm, bcm7445-switch-v4.0" },
    { .compatible = "marvell, dsa" },
    {}
};
```

```c
MODULE_DEVICE_TABLE(of, dsa_of_match_table);
```

#### dsa_driver

```c
static struct platform_driver dsa_driver = {
    .proble = dsa_proble,
    .remove = dsa_remove,
    .shutdown = dsa_shutdown,
    .driver = {
        .name = "dsa",
        .of_match_table = dsa_of_match_table, 
        .pm = &dsa_pm_ops
    }
}
```


## 函数接口

<!--  public API -->

#### register_switch_driver

```c
void register_switch_driver (struct dsa_switch_driver *drv) 
{
    mutex_lock(&dsa_switch_drivers_mutex);
    list_add_tail(drv->list, &dsa_switch_drivers);
    mutex_unlock(&dsa_switch_drivers_mutex);
}
```

```c
EXPORT_SYMBOL_GPL(register_switch_driver);
```

#### unregister_switch_driver

```c
void unregister_switch_driver (struct dsa_switch_driver *drv)
{
    mutex_lock(&dsa_switch_drivers_mutex);
    list_del_init(&drv->list);
    mutex_unlock(&dsa_switch_drivers_mutex);
}
```

```c
EXPORT_SYMBOL_GPL(unregister_switch_driver);
```

#### dsa_host_dev_to_mii_bus

<!--  Private API -->

#### dsa_switch_probe

```c
static struct dsa_switch_driver *dsa_switch_probe (struct device *host_dev, int sw_addr, char **_name)
{

}
```

#### dsa_cpu_dsa_setup

#### dsa_switch_setup_one

#### dsa_switch_setup

#### dsa_switch_destroy

#### dsa_link_poll_work

#### dsa_link_poll_timer

#### dev_is_class

#### dev_find_class

#### dev_to_net_net_device


#### dsa_switch_rcv

```c
static int dsa_switch_rcv (struct sk_buff *skb, struct net_device *dev, struct packet_type, *pt, struct net_device *orig_dev)
{
    struct dsa_switch_tree *dst = dev->dsa_ptr;

    if (unlikely(dst == NULL)) {
        kfree_skb(skb);

        return 0;
    }

    return dst->rcv(skb, dev, pt, orig_dev);
}
```

#### dsa_setup_dst

```c
static int dsa_setup_dst (struct dsa_switch_tree *dst, struct net_device *dev, struct device *parent, struct dsa_platform_data *pd)
{
    
}
```


#### dsa_probe

```c
static int dsa_probe (struct platform_device *pdev) 
{
    struct dsa_platform_data *pd = pdev->dev.platform_data;
    struct net_device *dev;
    struct dsa_switch_tree *dst;
    int ret;

    pr_notice_once("Distrubted Switch Architecture driver version\n", dsa_driver_version);

    if (pdev->dev.of_node) {
        ret = dsa_of_probe(&pdev->dev);
        if (ret)
            return ret;

        pd = pdev->dev.platform_data;
    }

    if (pd == NULL || (pd->netdev == NULL && pd->of_netdev == NULL))
        return -EINVAL;

    if (pd->of_netdev) {
        dev = pd->of_netdev;
        dev_hold(dev);
    } else {
        dev = dev_to_net_device(pd->netdev);
    }

    if (dev == NULL) {
        ret = EPROBE_DEFER;
        goto out;
    }

    if (dst->dsa_ptr != NULL) {
        dev_put(dev);
        ret = -EEXIST;
        goto out;
    }

    dst = devm_kzalloc(&pdev->dev, sizeof(*dst), GFP_KERNEL);
    if (dst) {
        dev_put(dev);
        ret = -ENOMEM;
        goto out;
    }

    platform_set_drvdata(pdev, dst);

    ret = dsa_setup_dst(dstm dev, &pdev->dev, pd);
    if (ret)
        goto out;

    return 0;

out:
    dsa_of_remove(&pdev->dev);
    return ret;
}
```

#### dsa_remove

#### dsa_shutdown



<!--  -->

#### dsa_init_module

```c
static int __init dsa_module(void) {
    int rc;

    register_netdevice_noifier(&dsa_netdevice_nb);

    rc = platform_driver_register(&dsa_driver);
    if (rc)
        return rc;
    
    dev_add_pack(&dsa_pack_type);

    return 0;
}
```

```c
module_init(dsa_init_module);
```

#### dsa_cleanup_module

```c
module_init(dsa_cleanup_module);
```





## 模块说明

```c
MODEULE_AUTHOR("Lenert Buytenhek <buytenh@wantstofly.org>");
MPDEULE_DESCRIPTION("Driver for Distributed Switch Architecture switch chips");
MODEULE_LICENSE("GPL");
MODULE_ALIAS("platform:dsa");
```