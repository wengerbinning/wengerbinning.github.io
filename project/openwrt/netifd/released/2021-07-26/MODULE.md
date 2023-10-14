
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