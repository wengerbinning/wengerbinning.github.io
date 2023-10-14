





```txt
proto_shell_init -> netifd_open_subdir
```

将当前工作目录切换到 main_path (/lib/netifd)， 并将proto目录打开后返回文件描述符。

```txt
proto_shell_init -> netifd_init_script_handlers -> netifd_parse_script_handler
```

遍历所有/lib/netifd目录下的*.sh文件， 并执行`*.sh dump`。
