

#### 设置变量

* 编辑文件`vars`

```
set_var EASYRSA_DN           "cn_only"
set_var EASYRSA_CA_EXPIRE         360
set_var EASYRSA_CERT_EXPIRE        90
set_var EASYRSA_NO_PASS             1
set_var EASYRSA_RAND_SN          "yes"
```


#### 初始化环境

```shell
easyrsa init-pki
```

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


```shell
certutil -d ~/.pki/nssdb/ -A -i ca.crt  -n "Wenger Binning"  -t C

```