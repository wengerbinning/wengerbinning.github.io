
### config

config setup
    protostack=netkey
    nat_traversal=yes

### conn

```c
conn myvpn
    type=tunnel
    left=%defaultroute
    leftid=@server
    leftsubnet=10.0.0.0/24
    right=%any
    rightid=@client
    rightsubnet=0.0.0.0/0
    authby=secret
    auto=add
```

Local

* left
* leftid
* leftsubnets
* leftsourceip
* leftupdown

Remote

* right
* rightid
* rightsubnets

Phase 2

* phase2
* phase2alg
* type

DAD

* dadaction
* dadelay
* dadtimmeout

IKE

* ikev2
* ike

others

* authby
* auto
* metric
