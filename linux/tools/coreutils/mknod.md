mknod工具用于创建设备文件。

```shell
mknod <device name> <device type> [<major> <minor>]
```

device name就是设备文件的名称， device type可以是b（块设备）、c（字符设备）、u（无缓存的字符设备）
以及p（命名管道）。在创建块设备与字符设备时必须指定major与minor。

创建块设备
========







