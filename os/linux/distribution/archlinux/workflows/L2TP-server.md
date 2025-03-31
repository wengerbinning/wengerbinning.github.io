
xl2tpd



LNS
LAC


##

* `/etc/xl2tpd/xl2tpd.conf`


```conf
[global]
access control = no
auth file = /etc/ppp/chap-secrets
debug avp = yes
debug state = yes
debug packet = yes
debug tunnel = yes
debug network = yes

[lns default]
pppoptfile = /etc/ppp/options.l2tpd
ppp debug = yes
assign ip = yes
local ip = 172.16.205.1
ip range = 172.16.205.200-172.16.205.250
```

* `/etc/ppp/options.l2tpd`

* `/etc/ppp/chap-secrets`



##



