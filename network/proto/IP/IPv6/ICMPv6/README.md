ICMPv6

* RFC 4443 - Internet Control Message Protocol (ICMPv6) for the Internet Protocol Version 6 (IPv6) Specification
* RFC 4816 - Neighbor Discovery for IP Version 6 (IPv6)
* RFC 2461 - Neighbor Discovery for IP Version 6 (IPv6)
* RFC 3775 - Mobility Support in IPv6
* RFC 4191 - Default Router Preferences and More-Specific Routes
* RFC 4389 - Neighbor Discovery Proxies (ND Proxy)
* RFC 3633
* RFC 8415

* 路由发现
* 地址检测
* 邻居发现
* 重定向


邻居发现协议(NDP, Neighbor Discovery Protocol): icmp133~137
----------

* 路由请求(RS, Router Solictation)
* 路由通告(RA, Router Advertisement)
* 邻居请求(NS, Neighbor Solictation)
* 邻居通道(NA, Neighbor Advertisement)


MLD
----

* MLDv1: 130, 130, 132
* MLDv2: 130, 143

RA
--

* M - 管理地址配置标识。 未设置时标识为有状态地址分配， 设置时标识有状态地址分配
* O - 其他有状态配置标识。
* H


RA Option
----------

* 0x01 - Link Layer Address
* 0x03 - Prefix Information
* 0x05 - MTU





* SLAAC(Stateless Address Autoconfiguration, 无状态地址自动配置)
* DHCPv6 有状态
* DHCPv6 无状态


SLAAC
------

连接到网络的设备基于RA信息自动分配地址的方案。基于EUI64算法。

DHCPv6
-------

有状态自动分配与无状态自动分配两种方式。


DHCPv6 有状态
------------

DHCPv6服务器自动配置地址、前缀、DNS、NTP等网络参数。

DHCPv6 无状态
------------

DHCPv6服务器分配除地址之外的网络参数。


DHCPv6 PD(Prefix Delegation, 前缀代理)
-------------------------------------

一种前缀分配机制，PD Server&Client

*





* DAD(Duplicate Address Detection, 地址重复检查)


邻居表
------

* 未完成(Incomplete)
* 可达(Reachable)
* 失效(Stale)
* 延迟(Delay)
* 探测(Probe)
