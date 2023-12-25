shell中的变量与环境变量可以相互转换


通过 export 可以将shell变量导出为环境变量
通过 declare 可以将环境变量转为shell变量



#### export

```
export -f
export -n 将环境变量转化为shell变量
export -p
```

#### declare

declare用于设置shell对象的属性

```
declare -r 只读
declare -i 整数类型
declare
```


shell中的变量


## 声明

```shell
var="abcdefghijklmnop:QRSTUVWXYZABCDEFGHIJKLMNOP:qrstuvwxyz0123456789"
```


## 变量应用

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


* 多行打印

```shell

DESCRIPTION=$(cat <<EOF
This is a documents about version>

 dewdwedewdwe

 dwedwedwe

EOF
)

echo "$DESCRIPTION" # 加引号会打印多行，如果其中有转移字符，还需要使用


```

```shell
VERSION="1.0"
```


* export


```shell
VERSION="1.0"
export VERSION
```

```shell
export VERSION="1.0"
```