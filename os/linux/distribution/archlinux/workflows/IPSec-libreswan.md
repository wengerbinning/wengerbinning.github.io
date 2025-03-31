

##

wenger-libreswan

##



* `/etc/ipsec.conf`


```conf
config setup

#
include /etc/ipsec.d/*.conf
```

* `/etc/ipsec.secrets`

```conf
include /etc/ipsec.d/*.secrets
```


* `/etc/ipsec.d/server1.conf`

```conf

conn l2tp-psk
    left=%any
    leftprotoport=17/1701
    right=%any
    rightprotoport=17/%any

    auto=add
    ikev2=no
    authby=secret
    type=transport


    ike=aes256-sha1-modp1024
    esp=aes256-sha1
    keyingtries=%forever
    ikelifetime=8h
    keylife=1h
    rekeymargin=3m
    rekeyfuzz=100%

    #ikev2=yes


    ; rightsourceip=%config
    ; rightprotoport=17/1701


conn common_secret
    # Authenticate
    authby=secret
    # Phase 1
    ikev2=no
    ike=3des-md5;dh2
    ikelifetime=24h
    # Phase 2
    #phase2=esp
    phase2alg=3des-md5

    # DAD
    dpddelay=30
    dpdtimeout=300
    dpdaction=clear
    # Others


conn l2tp-psk
  auto=add
  leftprotoport=17/1701
  rightprotoport=17/%any
  type=transport
  also=shared

conn xauth-psk
  auto=add
  leftsubnet=0.0.0.0/0
  leftxauthserver=yes
  rightxauthclient=yes
  leftmodecfgserver=yes
  rightmodecfgclient=yes
  modecfgpull=yes
  cisco-unity=yes
  also=shared
```



Phase 1: ISAKMP SA
ike=<cipher-hash;modpgroup, cipher-hash;modpgroup, ...>

cipher: 3des, aes128, aes192, aes256
hash: md5, sh1, sha2_256
modpgroup: dh2, dh5, dh14, dh19, dh20, dh21, modp1024, modp1536


3des-md5;dh2,3des-md5;dh5,3des-md5;dh14,3des-md5;dh19,3des-md5;dh20,3des-md5;dh21
3des-sha1;dh2,3des-sha1;dh5,3des-sha1;dh14,3des-sha1;dh19,3des-sha1;dh20,3des-sha1;dh21
3des-sha2_256;dh2,3des-sha2_256;dh5,3des-sha2_256;dh14,3des-sha2_256;dh19,3des-sha2_256;dh20,3des-sha2_256;dh21

aes128-md5;dh2,aes128-md5;dh5,aes128-md5;dh14,aes128-md5;dh19,aes128-md5;dh20,aes128-md5;dh21,
aes128-sha1;dh2,aes128-sha1;dh5,aes128-sha1;dh14,aes128-sha1;dh19,aes128-sha1;dh20,aes128-sha1;dh21,
aes128-sha2_256;dh2,aes128-sha2_256;dh5,aes128-sha2_256;dh14,aes128-sha2_256;dh19,aes128-sha2_256;dh20,aes128-sha2_256;dh21,

aes192-md5;dh2,aes192-md5;dh5,aes192-md5;dh14,aes192-md5;dh19,aes192-md5;dh20,aes192-md5;dh21,
aes192-sha1;dh2,aes192-sha1;dh5,aes192-sha1;dh14,aes192-sha1;dh19,aes192-sha1;dh20,aes192-sha1;dh21,
aes192-sha2_256;dh2,aes192-sha2_256;dh5,aes192-sha2_256;dh14,aes192-sha2_256;dh19,aes192-sha2_256;dh20,aes192-sha2_256;dh21

aes256-md5;dh2,aes256-md5;dh5,aes256-md5;dh14,aes256-md5;dh19,aes256-md5;dh20,aes256-md5;dh21
aes256-sha1;dh2,aes256-sha1;dh5,aes256-sha1;dh14,aes256-sha1;dh19,aes256-sha1;dh20,aes256-sha1;dh21
aes256-sha2_256;dh2,aes256-sha2_256;dh5,aes256-sha2_256;dh14,aes256-sha2_256;dh19,aes256-sha2_256;dh20,aes256-sha2_256;dh21





ike=
3des-md5;dh2,
3des-md5;dh5,
3des-md5;dh14,
3des-md5;dh19,
3des-md5;dh20,
3des-md5;dh21,

3des-sha1;dh2,
3des-sha1;dh5,
3des-sha1;dh14,
3des-sha1;dh19,
3des-sha1;dh20,
3des-sha1;dh21,

3des-sha2_256;dh2,
3des-sha2_256;dh5,
3des-sha2_256;dh14,
3des-sha2_256;dh19,
3des-sha2_256;dh20,
3des-sha2_256;dh21,

aes128-md5;dh2

cket from 10.11.0.101:500: initial Main Mode message received but no connection has been authorized with authby=PSK and xauth=no


* `/etc/ipsec.d/server1.secrets`

```conf
10.11.0.1 %any : PSK "12345678"
```

##

