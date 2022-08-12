systemd is a suite of basic building blocks for a Linux system. It provides a s-
ystem and service manager that runs as PID 1 and starts the rest of the system.




Depends
=======

acl libacl.so=1-64
bash
cryptsetup libcryptsetup.so=12-64
dbus
iptables
kbd

Replaces
========

nss-myhostname

systemd-tools

udev


Tools
=====

**systemctl**

systemctl是一个管理服务的工具。



* 获取默认启动的目标：

```
systemctl get-default
```




Services
========



systemed可以管理所有系统资源，都是通过unit文件来管理，unit文件共有12种类型可以管理：

*.service   系统服务
*.device    硬件设备
*.mount     文件系统
*.automount 自动挂载
*.path      文件路径
*.slice     进程组
*.snapshot  systemd的快照
*.socket    进程间通信的的socket
*.swap      swap文件
*.timer     定时器
*.scope     表示不由systemed启动的外部进程
*.target    有多个unit组成的unit


* 列出所有的的unit

```
# 列出正在运行的的unit
systemctl list-units

# 列出所有的unit
systemctl list-units --all

# 列出所有没有运行的 Unit
$ systemctl list-units --all --state=inactive

# 列出所有加载失败的 Unit
$ systemctl list-units --failed


# 列出所有的service类型的unit
systemctl list-units --type=service

# 显示远程主机的某个 Unit 的状态
$ systemctl -H root@rhel7.example.com status httpd.service


# 显示某个 Unit 是否正在运行
$ systemctl is-active application.service

# 显示某个 Unit 是否处于启动失败状态
$ systemctl is-failed application.service

# 显示某个 Unit 服务是否建立了启动链接
$ systemctl is-enabled application.service

systemctl list-dependencies命令列出一个 Unit 的所有依赖。上面命令的输出结果之中，有些依赖是 Target 类型（详见下文），默认不会展开显示。如果要展开 Target，就需要使用--all参数。
```




