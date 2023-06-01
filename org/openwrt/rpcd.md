rpcd是OpenWRT中基于ubus实现的RPC微型服务，在/usr/libexec/rpcd/下写一个脚本文件，就可以快速扩展出一个ubus对象以及方法供其他服务调用。

```shell
#!/bin/sh

# @file: /usr/libexec/rpcd/test
# @permission: 755

case "$1" in 
    list)
        echo '{ "datetime":{}, "description":{} }'
        ;;
    call)
        case "$2" in
            datatime)
                ;;
            description)
                ;;
        esac
        ;;
esac
```