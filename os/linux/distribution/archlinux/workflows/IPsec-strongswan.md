



```
strongswan  5.9.13
curl gmp iprout2 openssl sqlite libcap systemd-libs pam
```

## 证书生成

#### root

* 生成私钥

```shell
ipsec pki --gen --type rsa --size 4096 --outform pem > key/pri/ca.pem
```

* 自签证书

```shell
ipsec pki --self --ca --lifetime 365 \
    --dn "C=CN, O=StrongSwan, CN=strongswan.ipsec.cn" \
    --in key/pri/ca.pem \
    --type rsa --outform pem > ca.pem
```

#### Host

* 生成私钥

```shell
ipsec pki --gen --type rsa --size 2048 --outform pem > key/pri/host.pem
```

* 生成公钥

```shell
ipsec pki --pub --in key/pri/host.pem --type rsa --outform pem > key/pub/host.pem
```

* 签发证书

```shell
ipsec pki --issue --lifetime 90 \
    --dn "C=CH, O=StrongSwan, CN=host.strongswan.ipsec.cn" \
    --san host.strongswan.ipsec.cn --flag serverAuth --flag ikeIntermediate \
    --cacert ca/ca.pem \
    --cakey key/pri/ca.pem \
    --in key/pub/host.pem \
    --outform pem > host.pem
```

#### guest

* 生成私钥

```shell
ipsec pki --gen --type rsa --size 2048 --outform pem > key/pri/guest.pem
```

* 生成公钥

```shell
ipsec pki --pub --in key/pri/guest.pem --type rsa --outform pem > key/pub/guest.pem
```

* 签发证书

```shell
ipsec pki --issue --lifetime 90  \
    --dn "C=CH, O=strongSwan, CN=client.strongswan.ipsec.cn" \
    --san client.strongswan.ipsec.cn \
    --cacert ca.pem \
    --cakey key/pri/ca.pem \
    --in key/pub/guest.pem \
    --outform pem > guest.pem
```

* 证书转换

```shell
openssl pkcs12 -export -name "StrongSwan Client Certificate" \
    -in certs/guest.pem -inkey key/pri/guest.pem \
    -caname "StrongSwan Root Certificate" -certfile ca/ca.pem \
    -out guest.p12
```



## 检查证书

```shell
ipsec pki --print --in cert.pem
```