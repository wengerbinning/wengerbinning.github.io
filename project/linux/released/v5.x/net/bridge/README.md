




```txt
br.c
br_device.c
br_fdb.c
br_forward.c
br_if.c
br_input.c
br_ioctl.c
br_mdb.c
br_multicast.c
br_netfilter_hooks.c
br_netfilter_ipv6.c
br_netlink.c
br_nf_core.c
br_private.h
br_private_stp.h
br_stp_bpdu.c
br_stp.c
br_stp_if.c
br_stp_timer.c
br_sysfs_br.c
br_sysfs_if.c
br_vlan.c
Kconfig
Makefile
modules.builtin
netfilter/
```


## 源码

bridge

* [br.o](./br.md)
* br_device.o
* br_fdb.o
* br_br_forward.o
* br_if.o
* br_input.o
* br_ioctl.o
* br_stp.o
* br_stp_bpdu.o
* br_stp_if.o
* br_stp_timer.o
* br-netlink.o

```txt
CONFIG_SYSFS
```

* br_sysfs_if.o
* br_sysfs_br.o

```txt
CONFIG_BRIDGE_NETIFILTER
```

* br_nf_core.o

bridge netifilter

* br_netfiliter_hooks.o

* br_netfiliter.o
* br_netfiliter_ipv6.o
* 




##

### [br.o](./br.md)


#### 数据对象

* [br_switchdev_notifier](./br.md#br_switchdev_notifier)

* [br_net_ops](./br.md#br_net_ops)

* [br_stp_proto](./br.md#br_stp_proto)

#### 函数接口

* [br_switchdev_event](./br.md#br_switchdev_event)

  
* [br_net_exit](./br.md#br_net_exit)

* [br_init](./br.md#br_init)
* [br_deinit](./br.md#br_deinit)


### [br_device.o](./br_device.md)

#### 函数接口

* [br_dev_setup](./br_device.md#br_dev_setup)

### [br_if.o](./br_if.md)

#### 函数接口

* [br_add_bridge](./br_if.md#br_add_bridge)
* [br_del_bridge](./br_if.md#br_del_bridge)

### [br_ioctl.o](./br_ioctl.md)


#### 函数接口

* [br_ioctl_deviceless_stub](./br_ioctl.md#br_ioctl_deviceless_stub)

### [br_stp_bpdu.o]()



#### 函数接口

* [br_stp_rcv]()
