通过easy-rsa来生成CA(Certificate authority)证书， 并自签证书。

## 准备环境

#### 安装软件

```

```

#### 设置变量

* 编辑文件`vars`

```
set_var EASYRSA_DN           "cn_only"
set_var EASYRSA_CA_EXPIRE         360
set_var EASYRSA_CERT_EXPIRE        90
set_var EASYRSA_NO_PASS             1
set_var EASYRSA_RAND_SN          "yes"
```

* 初始化环境

```shell
easyrsa init-pki
```

## 生成证书

#### 生成CA证书

```shell
easyrsa build-ca
```

#### 自签服务证书

```shell
easyrsa build-server-full server
```


#### 自签客户证书

```shell
easyrsa build-client-full client
```


## 证书检查

```shell
openssl x509 -in *.crt -text
```


## 信任证书


#### Personal - NSS(chromium, Firefox)

```shell
certutil -d ${database} -A -i ${cacert} -n ${nickname} -t C
```

> Notes
>   * Chromium and Evolution use the "shared" database at `$HOME/.pki/nssdb`
>   * Firefox, Thunderbird, and SeaMonkey, specify the browser's own profile
>     directory.


#### System

```shell
trust anchor --store ${cacert}
```


## LINKS

* Arch Wiki: <https://wiki.archlinux.org/title/Easy-RSA>
* Easy RSA: <https://easy-rsa.readthedocs.io/en/latest/advanced/#configuration-reference>
* Trusted Cert: <https://wiki.archlinux.org/title/User:Grawity/Adding_a_trusted_CA_certificate>