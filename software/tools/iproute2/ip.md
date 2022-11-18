

## 链路管理


```shell
# 启动网卡。
ip link set dev eth0 up

# 关闭网卡。
ip link set dev eth0 down


```


## 地址管理

```shell
# 查看网络地址
ip address
```

```log
wenger@WINDOWS:~$ ip a
1: lo: <LOOPBACK,UP,LOWER_UP> mtu 65536 qdisc noqueue state UNKNOWN group default qlen 1000
    link/loopback 00:00:00:00:00:00 brd 00:00:00:00:00:00
    inet 127.0.0.1/8 scope host lo
       valid_lft forever preferred_lft forever
    inet6 ::1/128 scope host
       valid_lft forever preferred_lft forever
6: eth0: <BROADCAST,MULTICAST,UP,LOWER_UP> mtu 1500 qdisc mq state UP group default qlen 1000
    link/ether 00:15:5d:71:da:e6 brd ff:ff:ff:ff:ff:ff
    inet 172.24.104.212/20 brd 172.24.111.255 scope global eth0
       valid_lft forever preferred_lft forever
    inet6 fe80::215:5dff:fe71:dae6/64 scope link
       valid_lft forever preferred_lft forever

# mtu 1500
# 最大传输单元(MTU, Maximum Transmission Unit)

# qdisc fd_codel
# 排队规则(QDISC, queueing discipline)

# state UP
# 状态(state)

# group
# 

# qlen
#

# link/ether <mac address> brd <>

# inet <ipv4>/<subnet mask> brd <> scope global noprefixroute enp3s0

# inet6 <ipv6>/<network portion> scope global dynamic noprefixroute

```


## 策略管理

```shell
# 查看所有策略。(默认会存在三条默认的策略对应local、mian、default。)
ip rule show
```

添加自定义规则

```shell
# 根据源地址添加路由表处理规则。
ip rule add from 192.168.1.10 table 1

# 根据源地址的网络地址添加路由表处理规则。
ip rule add from 192.168.1/24 table 2

# 根据目的地址添加路由表处理规则。
ip rule add to 192.168.3.1 table 3

# 根据目的地址的网络地址添加路由表处理规则。
ip rule add to 192.168.3.0/24 table 4

# 根据fwmark添加路由表处理规则。
ip rule add fwmark 1 table 1
```

## 路由管理

```shell
# 显示路由。(默认显示主路由表)
ip route show
```

添加默认网管。


```shell
ip route add default via 192.168.3.1 dev eth0
```

刷新路由表。（在设置完路由表之后需要刷新）

```shell
ip route flush cache
```

## 邻居发现

```shell
# 显示邻居表。
ip neigh show
```
