PPPoE Service

## 安装软件

* extra/rp-pppoe


## 配置服务

* `/etc/ppp/chap-secrets`

```shell
# Secrets for authentication using PAP
# client        server  secret                  IP addresses

# PPPoE
test        *   "12345678"      *
guest       *   "12345678"      *
pppoe       *   "12345678"      *
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



```shell
# 1.
sudo pppoe-server -X /var/run/pppoe-server.pid -S ISP -I enp6s0 -L 10.12.0.1 -R 10.12.0.100-199

# 2.
sudo pppoe-server -X /var/run/pppoe-server.pid -S ISP -I vbr0 -L 10.12.0.1 -p /etc/ppp/pppoe-server-pools

# @.
sudo killall pppoe-server
```
