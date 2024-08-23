

```shell
./easyrsa gen-dh

openvpn dhparm -out dh2048.pem 2048

openssl dhparam -out dh1024.pem 1024
openssl dhparam -in dh1024.pem -text
openssl dhparam -out dh2048.pem 2048
openssl dhparam -in dh2048.pem -text
```

## Server

```shell


#
#
openvpn --genkey secret secret.key
```

```shell
sudo systemctl restart openvpn-server@.service
```

## Client

```shell
sudo systemctl restart openvpn-client@.service
```