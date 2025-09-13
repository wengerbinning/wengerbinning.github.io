PPPoE Service

## 安装软件

* extra/rp-pppoe


## 配置服务

* `/etc/ppp/chap-secrets`

```shell
# Secrets for authentication using PAP
# <client>  <server>    <secret>    <IP addresses>
# Default
test        *   "12345678"      *
demo        *   "12345678"      *
admin       *   "12345678"      *
guest       *   "12345678"      *
wenger      *   "12345678"      *

# PPPoE
pppoe   pppoe   "12345678"      *
# PPTP
pptp     pptp   "12345678"      *
# L2TP
l2tp     l2tp   "12345678"      *
```

* `/etc/ppp/pppoe-server-options`

```conf
# PPP options for the PPPoE server
# SPDX-License-Identifier: GPL-2.0-or-later

name pppoe
#plugin /usr/lib/pppd/2.5.1/pppoe.so


require-pap
#require-chap
auth

debug
#show-password

### IPv6
+ipv6
ipv6cp-use-ipaddr

### Others
defaultroute
netmask 255.255.255.0
ms-dns 223.5.5.5
ms-dns 223.6.6.6

lcp-echo-interval 10
lcp-echo-failure 2
```

* `/etc/ppp/pppoe-server-pools`

```
10.12.0.100-199
```

sudo pppoe-server -X /var/run/pppoe-server1.pid -S ISP -I enp2s0   -L 10.15.0.1 -p /etc/ppp/pppoe-server-pools-1
sudo pppoe-server -X /var/run/pppoe-server2.pid -S ISP -I enp1s0f0 -L 10.16.0.1 -p /etc/ppp/pppoe-server-pools-2

```shell
# 1.
sudo pppoe-server -X /var/run/pppoe-server.pid -S ISP -I enp6s0 -L 10.12.0.1 -R 10.12.0.100-199

# 2.
sudo pppoe-server -X /var/run/pppoe-server.pid -S ISP -I enp3s0 -L 10.12.0.1 -p /etc/ppp/pppoe-server-pools

<4>[30530.374094] TRACE: mangle:PREROUTING:rule:1 IN=br-lan.12 OUT= MAC=ec:74:d7:61:aa:7a:e0:be:03:9c:dc:b5:08:00 SRC=192.168.120.55 DST=192.168.6.10 LEN=60 TOS=0x00 PREC=0x00 TTL=128 ID=50927 PROTO=ICMP TYPE=8 CODE=0 ID=1 SEQ=10316
<4>[30530.394262] TRACE: mangle:mwan3_hook:rule:1 IN=br-lan.12 OUT= MAC=ec:74:d7:61:aa:7a:e0:be:03:9c:dc:b5:08:00 SRC=192.168.120.55 DST=192.168.6.10 LEN=60 TOS=0x00 PREC=0x00 TTL=128 ID=50927 PROTO=ICMP TYPE=8 CODE=0 ID=1 SEQ=10316
<4>[30530.414424] TRACE: mangle:mwan3_hook:rule:5 IN=br-lan.12 OUT= MAC=ec:74:d7:61:aa:7a:e0:be:03:9c:dc:b5:08:00 SRC=192.168.120.55 DST=192.168.6.10 LEN=60 TOS=0x00 PREC=0x00 TTL=128 ID=50927 PROTO=ICMP TYPE=8 CODE=0 ID=1 SEQ=10316 MARK=0x100
<4>[30530.435538] TRACE: mangle:mwan3_hook:rule:6 IN=br-lan.12 OUT= MAC=ec:74:d7:61:aa:7a:e0:be:03:9c:dc:b5:08:00 SRC=192.168.120.55 DST=192.168.6.10 LEN=60 TOS=0x00 PREC=0x00 TTL=128 ID=50927 PROTO=ICMP TYPE=8 CODE=0 ID=1 SEQ=10316 MARK=0x100
<4>[30530.456651] TRACE: mangle:PREROUTING:rule:2 IN=br-lan.12 OUT= MAC=ec:74:d7:61:aa:7a:e0:be:03:9c:dc:b5:08:00 SRC=192.168.120.55 DST=192.168.6.10 LEN=60 TOS=0x00 PREC=0x00 TTL=128 ID=50927 PROTO=ICMP TYPE=8 CODE=0 ID=1 SEQ=10316 MARK=0x100
<4>[30530.477762] TRACE: mangle:gsdpi_hook_pre:rule:1 IN=br-lan.12 OUT= MAC=ec:74:d7:61:aa:7a:e0:be:03:9c:dc:b5:08:00 SRC=192.168.120.55 DST=192.168.6.10 LEN=60 TOS=0x00 PREC=0x00 TTL=128 ID=50927 PROTO=ICMP TYPE=8 CODE=0 ID=1 SEQ=10316 MARK=0x100
<4>[30530.499224] TRACE: mangle:gsdpi_hook_pre:rule:2 IN=br-lan.12 OUT= MAC=ec:74:d7:61:aa:7a:e0:be:03:9c:dc:b5:08:00 SRC=192.168.120.55 DST=192.168.6.10 LEN=60 TOS=0x00 PREC=0x00 TTL=128 ID=50927 PROTO=ICMP TYPE=8 CODE=0 ID=1 SEQ=10316 MARK=0x108
<4>[30530.520686] TRACE: mangle:PREROUTING:rule:3 IN=br-lan.12 OUT= MAC=ec:74:d7:61:aa:7a:e0:be:03:9c:dc:b5:08:00 SRC=192.168.120.55 DST=192.168.6.10 LEN=60 TOS=0x00 PREC=0x00 TTL=128 ID=50927 PROTO=ICMP TYPE=8 CODE=0 ID=1 SEQ=10316 MARK=0x108
<4>[30530.541817] TRACE: mangle:FORWARD:rule:7 IN=br-lan.12 OUT=eth1 MAC=ec:74:d7:61:aa:7a:e0:be:03:9c:dc:b5:08:00 SRC=192.168.120.55 DST=192.168.6.10 LEN=60 TOS=0x00 PREC=0x00 TTL=127 ID=50927 PROTO=ICMP TYPE=8 CODE=0 ID=1 SEQ=10316 MARK=0x200108
<4>[30530.563279] TRACE: filter:FORWARD:rule:1 IN=br-lan.12 OUT=eth1 MAC=ec:74:d7:61:aa:7a:e0:be:03:9c:dc:b5:08:00 SRC=192.168.120.55 DST=192.168.6.10 LEN=60 TOS=0x00 PREC=0x00 TTL=127 ID=50927 PROTO=ICMP TYPE=8 CODE=0 ID=1 SEQ=10316 MARK=0x200108
<4>[30530.584742] TRACE: filter:forwarding_rule:rule:1 IN=br-lan.12 OUT=eth1 MAC=ec:74:d7:61:aa:7a:e0:be:03:9c:dc:b5:08:00 SRC=192.168.120.55 DST=192.168.6.10 LEN=60 TOS=0x00 PREC=0x00 TTL=127 ID=50927 PROTO=ICMP TYPE=8 CODE=0 ID=1 SEQ=10316 MARK=0x200108
<4>[30530.606898] TRACE: filter:FORWARD:rule:7 IN=br-lan.12 OUT=eth1 MAC=ec:74:d7:61:aa:7a:e0:be:03:9c:dc:b5:08:00 SRC=192.168.120.55 DST=192.168.6.10 LEN=60 TOS=0x00 PREC=0x00 TTL=127 ID=50927 PROTO=ICMP TYPE=8 CODE=0 ID=1 SEQ=10316 MARK=0x200108
<4>[30530.628393] TRACE: filter:zone_zone12_forward:rule:1 IN=br-lan.12 OUT=eth1 MAC=ec:74:d7:61:aa:7a:e0:be:03:9c:dc:b5:08:00 SRC=192.168.120.55 DST=192.168.6.10 LEN=60 TOS=0x00 PREC=0x00 TTL=127 ID=50927 PROTO=ICMP TYPE=8 CODE=0 ID=1 SEQ=10316 MARK=0x200108
<4>[30530.650895] TRACE: filter:forwarding_zone12_rule:rule:1 IN=br-lan.12 OUT=eth1 MAC=ec:74:d7:61:aa:7a:e0:be:03:9c:dc:b5:08:00 SRC=192.168.120.55 DST=192.168.6.10 LEN=60 TOS=0x00 PREC=0x00 TTL=127 ID=50927 PROTO=ICMP TYPE=8 CODE=0 ID=1 SEQ=10316 MARK=0x200108
<4>[30530.673665] TRACE: filter:zone_zone12_forward:rule:2 IN=br-lan.12 OUT=eth1 MAC=ec:74:d7:61:aa:7a:e0:be:03:9c:dc:b5:08:00 SRC=192.168.120.55 DST=192.168.6.10 LEN=60 TOS=0x00 PREC=0x00 TTL=127 ID=50927 PROTO=ICMP TYPE=8 CODE=0 ID=1 SEQ=10316 MARK=0x200108
<4>[30530.718851] TRACE: mangle:POSTROUTING:rule:1 IN= OUT=eth1 SRC=192.168.120.55 DST=192.168.6.10 LEN=60 TOS=0x00 PREC=0x00 TTL=127 ID=50927 PROTO=ICMP TYPE=8 CODE=0 ID=1 SEQ=10316 MARK=0x200108
<4>[30530.735884] TRACE: mangle:gsdpi_hook_mark:rule:1 IN= OUT=eth1 SRC=192.168.120.55 DST=192.168.6.10 LEN=60 TOS=0x00 PREC=0x00 TTL=127 ID=50927 PROTO=ICMP TYPE=8 CODE=0 ID=1 SEQ=10316 MARK=0x200108
<4>[30530.753261] TRACE: mangle:gsdpi_hook_mark:rule:2 IN= OUT=eth1 SRC=192.168.120.55 DST=192.168.6.10 LEN=60 TOS=0x00 PREC=0x00 TTL=127 ID=50927 PROTO=ICMP TYPE=8 CODE=0 ID=1 SEQ=10316 MARK=0x200108
<4>[30530.770636] TRACE: mangle:POSTROUTING:rule:2 IN= OUT=eth1 SRC=192.168.120.55 DST=192.168.6.10 LEN=60 TOS=0x00 PREC=0x00 TTL=127 ID=50927 PROTO=ICMP TYPE=8 CODE=0 ID=1 SEQ=10316 MARK=0x200108


# @.
sudo killall pppoe-server
```


sudo ip link add link enp3s0 veth.621 type vlan id 621
sudo ip link set veth.621 up













* 邻居发现(ND, Neighbor Discovery)

```shell
# 本地链路中的所有主机设备响应
ping ff02::1%enp6s0
# 本地链路中的所有路由设备响应
ping ff02::2%enp6s0
#
ip -6 neigh
```


* 无状态地址自动配置(SLAAC， Stateless address autoconfiguration)： 根据路由器广播(RA, Router Advertisement)