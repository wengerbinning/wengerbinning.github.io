
## 根证书


* 创建根证书密钥

```shell
openssl genrsa -out private/CA.key 4096
```

* 生成证书签名请求(CSR)

```shell
openssl req -new -sha256 -key private/CA.key -out private/CA.csr
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



