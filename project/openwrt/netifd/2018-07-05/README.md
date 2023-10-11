



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









