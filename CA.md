mkdir -p ./{conf,cert,req,pri}


```
[ ca ]
default_ca = wenger_ca

[ wenger_ca ]
dir = /mnt/labs/self-ca/0
database = $dir/index.txt
private_key = $dir/pri/ca.key
certificate = $dir/ca.crt
new_certs_dir = $dir/cert
serial = $dir/serial
default_days = 365
default_md = sha256
policy = wenger_policy

[ wenger_policy ]
countryName            = match
stateOrProvinceName    = match
localityName           = match
organizationName       = match
organizationalUnitName = optional
commonName             = supplied
emailAddress           = optional

[ req ]
prompt              = no
default_bits        = 2048
string_mask         = utf8only
distinguished_name  = wenger_req

[ wenger_req ]
countryName             = CN
stateOrProvinceName     = Zhejiang
localityName            = Hangzhou
organizationName        = 20260326
organizationalUnitName  = security
commonName              = Wenger Binning
emailAddress            = wengerbinning@163.com
countryName_default            = CN
stateOrProvinceName_default    = Zhejiang
localityName_default           = Hangzhou
organizationName_default       = 20260326
organizationalUnitName_default = IT
commonName_default             = unknown
```





## 根证书


* 创建根证书密钥

```shell
openssl genrsa -out ca.key 4096
```

* 生成证书签名请求(CSR)

```shell
openssl req -new -sha256 -key ca.key -out ca.csr
```

* 自签根证书

```shell
openssl x509 -req -sha256 -days 365 -in private/CA.csr -signkey private/CA.key  -out private/CA.crt
```

* 输出根证书信息

```shell
openssl x509 -in private/CA.crt -text -noout
```

## OPENSSL配置

```config

```

## 客户端证书

* 创建客户端密钥

```shell
openssl genrsa -out examples/client.key 2048
# openssl rsa -in examples/client.key -pubout -out examples/client.key.pub
```

* 生成证书签名请求(CSR)

```shell
openssl req -new -key examples/client.key -days 365 -out examples/client.csr
```

* 签发证书


```shell
openssl ca -config openssl.cnf -in csr/client.csr -days 365 -out crt/client.crt
```
