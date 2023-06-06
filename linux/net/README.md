网络子系统


```txt
CONFIG_NET
```

* [socket.o](socket.md) 实现了sock文件系统并初始化。
* [core/](core/README.md) 实现了网络子系统的核心
* ethernet/
* 802/
* sched/
* netlink/
* ipv6/

```txt
CONFIG_COMPAT
```

* compat.o

```txt
CONFIG_NETFILTER
```

* netifter/


```txt
CONFIG_INET
```

* ipv4/

Linux Birdge 的实现

```txt
CONFIG_BRIDGE
```
   
* [birdge/]()


802.1Q在 Linux 中的实现

```txt
CONFIG_VLAN_8021Q
```

* [8021q/]()

DSA 在 Linux 中的实现

```txt
CONFIG_NET_DSA
```

* [dsa/]()






```c
struct net;
```



## FILES

include/net/net_namespace.h