

ipset支持动态修改。

* 创建一个ipset集

```shell
# net集
ipset create <list name> hash:net max 65536

# IP集
ipset create <list name> hash:ip maxelem 65536
```

* 列举所有的ipset集

```shell
ipset list
```

* 添加元素到存在的ipset集

```shell
ipset add <list name> 10.60.10.xx
```

* 删除ipset集中元素

```shell
ipset del <list name> 10.60.10.xx
```

* 删除ipset集

```shell
ipset destroy <list name>
```

* 导出ipset规则

```shell
ipset save <list name> -f <ipset list file>
```

* 导入ipset规则

```shell
ipset restore -f <ipset list file>
```
