
#### main.o

单元内部数据对象

* debug_mask
* main_path
* config_path
* resolv_conf
* global_argv
* process_list
* log_level
* log_class
* use_syslog

基础接口

* netifd_delete_process
* netifd_log_message
* netifd_process_log_read_cb
* netifd_process_cb
* netifd_start_process
* netifd_kill_process
* netifd_do_restart
* netifd_reload
* netifd_restart
* usage
* netifd_handle_signal
* netifd_setup_signals
* netifd_kill_processes
* main

#### handler.o

* netifd_dir_push
* 




#### config.o

* config_init_devices
* config_init_interfaces

#### vlan.o

* struct vlan_device
* free_vlan_if

* vlan_set_device_state
* vlan_dev_set_name

* vlan_dev_cb

* get_vlan_device
* split_vlan
* get_vlan_device_chain

#### vlandev.o

* enum __VLAN_ATTR_MAX
* vlandev_attrs
* vlandev_attr_list
* vlandev_device
* vlandev_base_cb
* vlandev_set_down
* vlandev_set_up
* vlandev_set_state
* vlandev_free
* vlandev_qos_mapping_dump
* vlandev_dump_info
* vlandev_config_init
* vlandev_qos_mapping_list_apply
* vlandev_apply_settings
* vlandev_reload
* vlandev_create

* vlan8021ad_device_type
* vlan8021q_device_type
* vlandev_device_type_init



#### device.o

* devtypes
* devices
* dev_attrs
* device_attr_list
* __devlock
* device_type_add
* device_type_get
* device_lock
* device_unlock

* set_device_state
* simple_device_set_state
* simple_device_create
* simple_device_free
* simple_device_type
* device_merge_settings
* device_init_settings
* dev_init


#### bridge.o

* enum __BRIDGE_ATTR_MAX
* bridge_attrs
* bridge_attr_info
* bridge_attr_list

* bridge_create
* bridge_config_init
* bridge_free
* bridge_dump_info
* bridge_reload

* bridge_device_type






#### proto-shell.o

* proto_shell_add_handler




#### proto.o

* handlers
* proto_ip_attributes
* proto_ip_attr_info
* add_proto_handler


#### interface.o

* interface_start_pending


#### system-linux.o

* struct event_socket
* sock_ioctl
* sock_rtnl
* dev_buf

* create_socket


* cb_rtnl_event
* handler_nl_event
* create_event_socket

* handler_hotplug_msg
* handler_hotplug_event
* create_raw_event_socket

* system_init

* system_rtn_aton
* system_tos_aton

<!--  -->


* system_vlan
* system_vlan_add
* system_vlan_del


<!--  -->

* system_rtnl_call

* system_bridge_delbr
* system_bridge_if

* system_is_bridge
* system_get_bridge

* system_bridge_set_wireless

* system_bridge_addif
* system_bridge_delif
* system_if_resolve
* system_if_flags

* system_link_del

* system_veth_add
* system_veth_del



* system_vlandev_add
* system_vlandev_del

<!--  -->

* system_set_sysctl
* system_set_dev_sysctl
* system_get_sysctl
* system_get_dev_sysctl
 
* system_set_disable_ipv6
* system_set_rpfilter
* system_set_acceptlocal
* system_set_igmpversion
* system_set_mldversion
* system_set_neigh4reachabletime
* system_set_neigh6reachabletime



* system_if_get_settings
* system_if_apply_settings



* system_if_down

* tunnel_ioctl
* system_add_ip6_tunnel
* system_add_gre_tunnel
* system_add_vxlan
* system_add_sit_tunnel
* system_add_proto_tunnel

* __system_del_ip_tunnel
* system_del_ip_tunnel
*  system_update_ipv6_mtu
* system_add_ip_tunnel
