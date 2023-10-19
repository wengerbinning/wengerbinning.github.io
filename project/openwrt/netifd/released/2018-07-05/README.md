

* 处理协议脚本

```txt
proto_shell_init -> netifd_open_subdir
```

将当前工作目录切换到 main_path (/lib/netifd)， 并将proto目录打开后返回文件描述符。

```txt
proto_shell_init -> netifd_init_script_handlers -> netifd_parse_script_handler -> netifd_init_script_handler -> proto_shell_add_handler
```

遍历所有/lib/netifd目录下的*.sh文件， 并执行`*.sh dump`。


* 处理无线脚本

```txt
wireless_init -> netifd_open_suhdir
```

```txt
wireless_init -> netifd_init_script_handers -> netifd_parse_script_handler -> netifs_script_hander -> wireless_add_hander
```


* 系统初始化


* 加载配置




```txt
config_init_all -> config_init_devices
config_init_all -> config_init_interfaces
config_init_all -> config_init_routes
config_init_all -> config_init_rules
config_init_all -> config_init_globals
config_init_all -> config_init_wireless
```






proto_init_interface -> proto_shell_attach




interface_do_reload -> proto_init_interface
interface_update -> proto_init_interface



proto_attach_interface


interface_proto_event -> proto_shell_handler*
--------------------------------------------

interface_set_up -> __interface_set_up -> interface_proto_event -> proto_shell_handler



interface_proto_event



interface_main_dev_cb -> interface_set_link_state


cb_rtnl_event -> device_set_link*

cb_if_check_valid -> device_set_link*



config_parse_interface -> config_parse_bridge_interface

config_parse_interface -> interface_alloc -> interface_add

interface_start_pending -> interface_set_up


interface_set_up -> device_claim
interface_set_up -> __interface_set_up -> interface_proto_event
