

/etc/ipsec.conf



192.168.10.0/24 dev eth1  scope link  src 192.168.80.1  metric 3072



ip route add 192.168.10.0/24 dev eth1 src 192.168.1.1