
# include

## uapi

* uapi/linux/net.h
* uapi/linux/netdevice.h


## linux

* linux/types.h
* linux/ctype.h
* linux/kernel.h
* linux/string.h
* linux/version.h
* linux/init.h
* linux/module.h
* linux/uaccess.h
* linux/btree.h
* linux/cdev.h
* linux/clk.h
* linux/compiler.h
* linux/errno.h
* linux/err.h


### [linux/rcupdate.h](./linux/rcupdate.md)

#### 数据结构

#### 数据对象

#### 函数接口



* RCU_INITIALIZER

* rcu_init

* __rcu_read_lock
* __rcu_read_unlock
* rcu_read_unlock_special
* synchronize_rcu

* rcu_read_lock
* rcu_read_unlock

#### linux/net.h

### linux/netdev_features.h

### [linux/netdevice.h](./linux/netdevice.md)

#### 数据结构

#### 数据对象

#### 函数接口

* netdev_printk
* netdev_emerg
* netdev_alart
* netdev_crit
* netdev_err
* netdev_warn
* netdev_notice
* netdev_info
* netdev_dbg

* netif_prink
* netif_level
* netif_emerg
* netif_alert
* netif_crit
* netif_err
* netif_warn
* netif_notice
* netif_info
* netif_dbg

* netdv_notifier_info_init
* call_netdevice_notifiers

* register_netdevice_notifier
* unregister_netdevice_notifier
* netdev_notifier_info_to_dev


* first_net_device
* first_net_device_rcu
* next_net_device
* next_net_device_rcu

* dev_loopback_xmit
* dev_queue_xmit
* dev_queue_xmit_accel

* [dev_hold](./linux/netdevice.md#dev_hold)

  该接口用于增大接口的引用计数

* [dev_put](./linux/netdevice.md#dev_put)

  该接口用于减小接口的引用计数

* [__dev_get_by_name](./linux/netdevice.md#__dev_get_by_name)

* [dev_get_byname_rcu](./linux/netdevice.md#dev_get_by_name_rcu)

  该接口需要在rcu的读临界区使用

* [dev_get_by_name](./linux/netdevice.md#dev_get_by_name)

  该接口会对增加接口的引用计数，需要自己释放。

* [__dev_get_by_index](./linux/netdevice.md#__dev_get_by_index)

* [dev_get_by_index_rcu](./linux/netdevice.md#dev_get_by_index_rcu)

   该接口需要在rcu的读临界区使用
  
* [dev_get_by_index](./linux/netdevice.md#dev_get_by_index)
  
  该接口会对增加接口的引用计数，需要自己释放。

* register_netdevice
* unregister_netdevice
* unregister_netdevice_queue
* unregister_netdevice_many


* netif_rx
* netif_rx_ni
* netif_receive_skb
* napi_gro_receive

* napi_is_rx_handler_busy
* npai_rx_handler_register
* napi_rx_handler_unregister 

* netif_carrier_on
* netif_carrier_off



* register_netdev
* unregister_netdev

* netdev_start_xmit






### linux/netlink.h
* linux/netpoll.h

* linux/netfilter.h
* linux/netfilter_ipv4.h
* linux/netfilter_ipv6.h
* linux/netfilter_bridge.h
* linux/netfilter_defs.h


### [linux/if_vlan.h](./linux/if_vlan.md)

### [linux/sysctl.h](./linux/sysctl.md)















## kvm

## net

## soc


## trace


# 

