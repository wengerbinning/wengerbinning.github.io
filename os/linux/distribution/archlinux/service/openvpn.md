

```shell
./easyrsa gen-dh

openvpn dhparm -out dh2048.pem 2048
```

## Server

```shell
openvpn -genkey tls-auth ta.key

openvpn --genkey --secret secret.key
```

```shell
sudo systemctl restart openvpn-server@.service
```

## Client

```shell
sudo systemctl restart openvpn-client@.service
```