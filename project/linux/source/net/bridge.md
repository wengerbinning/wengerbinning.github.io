


## Files

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



## CallGraph

* br_port_auto
* br_promisc_port
* br_port_exists

* br_printk
* br_warn
* br_notice
* br_info
* br_debug

#### 模块依赖

* linux/rhashtable.h
* linux/export.h
* linux/netfilter.h
* linux/netdevice.h
* linux/if_bridge.h
* linux/netpoll.h
* linux/u64_stats_sync.h
* linux/if_vlan.h

* net/route.h
* net/ip6_fib.h

* br_private.h

#### 数据结构

* struct bridge_id
* struct mac_addr

* struct bridge_mcast_own_query
* struct bridge_mcast_other_query
* struct bridge_mcast_querier

* struct net_bridge_vlan
* struct net_bridge_vlan_group

* struct net_bridge_fdb_entry
* struct net_bridge_port_group
* struct net_bridge_mdb_entry
* struct net_bridge_mdb_htable
* struct net_bridge_port

* struct net_bridge
* struct br_input_skb_cb



#### 函数接口

* br_port_get_rcu
* br_port_get_rtnl

* br_is_root_bridge
* br_vlan_is_master
* br_vlan_is_brentry
* br_vlan_should_use

* br_dev_setup
* br_dev_delete
* br_dev_xmit

* br_netpoll_send_skb
* br_netpoll_enable
* br_netpoll_disable

* br_fdb_init
* br_fdb_fini
* br_fdb_flush
* br_fdb_find_delete_local
* br_fdb_changaddr
* br_fdb_change_mac_address
* br_fdb_cleanup
* br_fdb_delete_by_port
* __br_fdb_get
* br_fdb_test_addr
* br_fdb_fillbuf
* br_fdb_insert
* br_fdb_update
* br_fdb_delete
* br_fdb_add
* br_fdb_dump
* br_fdb_sync_static
* br_fdb_unsync_static
* br_fdb_external_learn_add
* br_fdb_external_learn_del


* br_deliver
* br_dev_queue_push_xmit
* br_forward
* br_forward_finish
* br_flood_deliver
* br_flood_forward

* br_port_carrier_check
* br_add_bridge
* br_del_bridge
* br_add_if
* br_del_if
* br_min_mtu
* br_features_recompute
* br_port_flags_change
* br_manage_promisc

* br_pass_frame_up
* br_handle_frame_finish
* br_handle_frame
* br_rx_handler_check_rcu
* br_port_get_check_rcu

* br_dev_ioctl
* br_ioctl_deviceless_stub

* br_multicast_rcv
* br_mdb_get
* br_multicast_add_port
* br_multicast_del_port
* br_multicast_enable_port
* br_multicast_disable_port
* br_multicast_init
* br_multicast_open
* br_multicast_stop
* br_multicast_dev_del
* br_multicast_deliver

CONFIG_BRIDGE_VLAN_FILTERING

* br_allowed_ingress
* br_allowed_egress
* br_should_learn
* br_handle_vlan
* br_vlan_add
* br_vlan_delete
* br_vlan_flush
* br_vlan_find
* br_recalculate_fwd_mask
* __br_vlan_filter_toggle
* br_vlan_filter_toggle
* __br_vlan_set_proto
* br_vlan_set_proto
* br_vlan_init
* br_vlan_set_default_pvid
* __br_vlan_set_default_pvid
* nbp_vlan_add
* nbp_vlan_delete
* nbp_vlan_flsuh
* nbp_vlan_init
* nbp_vlan_num_vlan_infos
* br_vlan_group
* br_vlan_group_rcu
* nbp_vlan_group
* nbp_vlan_group_rcu
* br_vlan_get_tag
* vlan_eth_hdr
* skb_vlan_eth_hdr
* is_vlan_dev
* vlan_ioctl_set
* __vlan_insert_inner_tag*
* vlan_insert_inner_tag*
* br_port_carrier_check
* br_add_bridge
* br_del_bridge
* br_add_if
* br_del_if
* br_min_mtu
* br_vlan_init
* br_vlan_set_default_pvid
* br_vlan_add
* br_vlan_delete
* br_vlan_flush
* br_vlan_set_proto
* br_vlan_find
* ndp_vlan_init
* ndp_vlan_flush
* ndp_vlan_add
* ndp_vlan_delete
* ndp_get_num_vlan_infos

#### br.o

* br_stp_proto
* br_notify_hook
* br_switchdev_event
* br_net_exit
* br_init
* br_deinit

#### br_device.o

* br_type
* br_dev_setup
* br_dev_xmit

#### br_vlan.o

* br_vlan_set_default_pvid
* br_vlan_init
* br_vlan_get_stats
* br_vlan_get_pvid
* br_vlan_get_pvid_rcu
* br_vlan_fill_forward_path_pvid
* br_vlan_fill_forward_path_mode
* br_vlan_get_info
* nbp_vlan_add
* nbp_vlan_delete
* nbp_vlan_flush

#### br_fdb.o

* br_fdb_init
* br_fdb_fini
* br_fdb_hash_init
* br_fdb_hash_fini


#### br_ioctl.o

* br_ioctl_deviceless_stub



## Build


* br.o
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
