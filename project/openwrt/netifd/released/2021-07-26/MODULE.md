
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


#### interface.o
<!-- data type -->
enum interface_attr
<!-- data object -->
* interfaces
* iface_all_users
* iface_attrs
* interface_attr_list
<!-- static -->
* interface_set_main_dev
* interface_event
* interface_error_flush
* interface_force_lonk
* interface_clear_errors
* interface_flush_state
* mark_interface_down
* __set_config_state
* __interface_set_down
* __interface_set_up
* interface_check_state
* interface_set_enabled
* interface_set_link_state
* interface_ext_dev_cb
* interface_main_dev_cb
* interface_l3_dev_cb
* interface_add_assignment_classes
* interface_clear_assignment_classes
* interface_merge_assignment_data
* interface_alias_cb
* interface_set_device_config
* interface_claim_device
* interface_cleanup_state
* interface_cleanup
* interface_do_free
* interface_do_reload
* interface_handle_config_change
* interface_proto_event_cb
* __interface_add
* interface_set_main_dev
* interface_remove_link
* interface_add_link
* interface_init_list

<!-- others -->
* interface_add_error
* interface_data_del
* interface_data-flush
* interface_add_data
* interface_parse_data
* interface_set_available
* interface_add_user
* interface_remove_user
* interface_set_proto_state
* interface_alloc
* interface_add
* interface_add_alias
* interface_set_l3_dev
* interface_handle_link
* interface_set_up
* interface_set_down
* interface_renew
* interface_start_pending
* interface_start_jail
* interface_stop_jail
* set_config_state
* interface_update_start
* interface_update_complete
* interface_replace_dns
* interface_device_config_changed
* interface_change_config
* interface_update


