OpenVPN是基于SSL协议实现的VPN，属于传输层的VPN实现。


通过OpenVPN可以实现客户端访问服务端的子网。











服务端启动后会存在一个接口






```shell
./easyrsa init-pki

# CA
./easyrsa build-ca nopass

# Server
./easyrsa build-server-full server nopass

# Client
./easyrsa build-client-full client nopass

# dh2048.pem
./easyrsa gen-dh

openvpn dhparm -out dh2048.pem 2048


# ta.key

openvpn -genkey tls-auth tk.key

openvpn --genkey --secret secret.key
```