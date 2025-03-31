DHCP Service

## 软件安装

* extra/dhcp

## 服务配置

* `/etc/dhcpd.conf`

```conf
# dhcpd.conf
# dhcpd.conf
#
# Sample configuration file for ISC dhcpd
#

# option definitions common to all supported networks...
#option domain-name "example.org";
#option domain-name-servers ns1.example.org, ns2.example.org;
option domain-name-servers 233.5.5.5, 233.6.6.6;

default-lease-time 600;
max-lease-time 7200;

# No service will be given on this subnet, but declaring it helps the
# DHCP server to understand the network topology.

option routers 10.11.0.1;
option subnet-mask 255.255.255.0;

subnet 10.11.0.0 netmask 255.255.255.0 {
  range 10.11.0.100 10.11.0.199;
}
```

* `/etc/dhcpd6.conf`

```conf

```

## 服务管理


```shell
systemctl start dhcpd4.service
systemctl start dhcpd6.service
```


```shell
#
sudo sysctl -w net.ipv4.ip_forward=1

#
sudo iptables -t nat -A POSTROUTING -s 10.10.0.0/24 -j MASQUERADE
```
