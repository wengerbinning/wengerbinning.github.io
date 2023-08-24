shell中的变量


## 声明

```shell
var="abcdefghijklmnop:QRSTUVWXYZABCDEFGHIJKLMNOP:qrstuvwxyz0123456789"
```


## 变量使用

```shell
echo $var
```

```shell
echo ${var}
```

* 字符替换

```shell
var='br-lan'
echo ${var/-/_} # br_lan
```

```shell
var="DATE:2023-08-21 12:00"

ech o ${var#*:}  # 2023-08-21 12:00
echo ${var##*:} # 00
```

```:q!
shell
var=br-lan.5

echo ${var//[-.]/_}  # br_lan_5
```