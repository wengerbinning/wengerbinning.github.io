
### [compiler.h](compiler.md)

#### 预处理宏

* __user
* __kernel
* __safe
* __force
* __nocast
* __iomem
* __must_hold
* __acquires
* __releases
* __acquire
* __release
* __cond_lock
* __percpu
* __pmem
* __rcu

* ___PASTE
* __PASTE 

* notrace

* likely_notrace
* unlikely_notrace
* `__branch_check__`

* likely
* unlikely

* barrier
* barrier_data
* unreachable

#### 模块依赖

* linux/compiler-gcc.h
* linux/compiler-intel.h
* linux/comiler-clang.h


#### 数据结构

* struct ftrace_branch_data

#### 函数接口

* __chk_user_ptr
* __chk_io_ptr

* ftrace_likely_update


### [types.h](types.md)

#### 模块依赖

* uapi/linux/types.h

#### 数据结构

* __kernel_dev_t

* fd_set
* dev_t
* ino_t
* mode_t
* umode_t
* nlink_t
* off_t
* pid_t
* dadder_t
* key_t
* suseconds_t
* timer_t
* clockid_t
* mqd_t

* bool

* uid_t
* git_t
* uid16_t 
* gid16_t
* uintptr_t
* size_t
* ssize_t
* ptrdiff_t
* time_t
* clock_t
* caddr_t

* u_char
* u_short
* u_int
* u_long

* unchar
* ushort
* uint
* ulong

* u_int8_t
* int8_t
* u_int16_t
* int16_t
* u_int32_t
* int32_t

* uint8_t
* uint16_t
* uint32_t

* dma_addr_t


* struct list_head
* struct hlist_head
* struct hlist_node
* struct ustat
* struct net_hdr_word


### [rcupdate.h](rcupdate.md)

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


### [skbuff.h](skbuff.md)

#### 数据结构

* struct sk_buff

### [if_ether.h](if_ether.md)

#### 函数接口

* eth_hdr


### [if_bridge.h](if_bridge.md)

#### 预处理宏

* BR_FDB_EVENT_ADD
* BR_FDB_EVENT_DEL

#### 模块依赖

* linux/bitops.h
* linux/netdevice.h

* uapi/linux/if_bridge.h 

#### 数据结构

* struct br_ip;
* struct br_ip_list;
* struct br_fdb_event;

* br_should_route_hook_t;
* br_port_dev_get_hook_t;
* br_notify_hook_t;
* br_multicast_handle_hook_t;
* br_get_dst_hook_t;
* br_notify_hook_t;

#### 数据对象

* br_should_route_hook;
* br_port_dev_get_hook;
* br_notify_hook;
* br_multicast_handle_hook;
* br_get_dst_hook;
* br_notify_hook;

#### 函数接口

* brioctl_set
* br_port_dev_get
* br_refresh_fdb_entry
* br_dev_update_stats

* br_fdb_hash_entry

* br_fdb_update_register_notify
* br_fdb_update_unregister_notify

* br_is_hairpin_enabled

* br_fdb_register_notify
* br_fdb_unregister_notify

* br_fdb_bridge_dev_get_and_hold
* br_fdb_delete_by_netdev
* br_fdb_add_or_refresh_by_netdev

CONFIG_BRIDGE && CONFIG_BRIDGE_IGMP_SNOOPING

* br_multicast_has_querier_anywhere
* br_multicast_has_querier_adjacent
* br_multicast_list_adjacent








### [if_vlan.h](if_vlan.md)

### [netfilter.h](netfilter.md)

#### 数据结构

* struct nf_hook_state


### [linux/netdevice.h](netdevice.md)

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


### [linux/netlink.h](netlink.md)

* linux/netpoll.h

* linux/netfilter.h
* linux/netfilter_ipv4.h
* linux/netfilter_ipv6.h
* linux/netfilter_bridge.h
* linux/netfilter_defs.h


### [linux/if_vlan.h](if_vlan.md)

### [linux/sysctl.h](sysctl.md)