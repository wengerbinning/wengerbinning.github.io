PPTP(Point-to-Point Tunneling Protocol)点对点隧道协议是PPP协议的⼀种扩展.它将
PPP(Point-to-Point Protocol)帧封装进IP包

service/client


PPTP uses a TCP control channel and a Generic Routing Encapsulation tunnel to encapsulate PPP packets.

A PPTP tunnel is instantiated by communication to the peer on TCP port 1723.
This TCP connection is then used to initiate and manage a GRE tunnel to the same peer.
The PPTP GRE packet format is non standard, including a new acknowledgement number field replacing the typical routing field in the GRE header.
The GRE tunnel is used to carry encapsulated PPP packets, allowing the tunnelling of any protocols that can be carried within PPP, including IP, NetBEUI and IPX.




pppd
accel-pptp-0.8.5

RFC 263
TCP:1723

#### MPPE(Microsoft Point-to-Point Encryption)

MPPE提供对PPP或PPTP网络提供数据加密服务。
MPPE支持40bit、56bit、128bit密钥；



## WorkFlows

###

* C->S:(PPTP) Start Control Connection Request
* S->C:(PPTP) STart Control Connection Reply
* C->S:(PPTP) Outgoing Call Request
* S->C:(PPTP) Outgoing Call Reply
* C->S:(PPTP) Set Link Info

### 数据处理

#### PPTP数据包封装过程

* 应用层数据封装成IP数据包
* 将IP数据包发送到VPN的虚拟接口
* VPN的虚拟接口将IP数据包压缩和加密，并增加PPP头
* VPN的虚拟接口将PPP帧发送给PPTP协议驱动程序
* PPTP协议驱动程序在PPP帧外添加GRE报头
* PPTP协议驱动程序将GRE报头提交给TCP/IP协议驱动程序
* TCP/IP协议驱动程序为GRE驱动添加IP头部
* 为IP数据包进行数据链路层封装后通过物理网卡发送出去

#### PPTP数据包解析过程

* 物理thernet帧
* 剥掉Ethernet帧后交给TCP/IP协议驱动程序
* TCP/IP协议解析剥掉IP头部
* IP协议解析剥掉GRE头部
* 将PPP帧发送给VPN虚拟网卡
* VPN虚拟网卡剥掉PPP头并对PPP有效负载进行解密或者解压缩
* 解密或者解压缩完成后将数据提交给上层应用
* 上层应用对数据进行处理

### 连接流程

1. Create TCP Stream
2. Create GRE Tunnel
3. PPP LCP negotiation
4. PPP Authentication
5. PPP NCP negotiation
6. PPP CCP negotiation

#### Create GRE Tunnel

Start-Control-Connection-Request
Start-Control-Connecton-Reply
Outgoing-Call-Request
Outgoing-Call-Reply
Set-Link-info

#### PPP LCP Negotiation

Configuration Request
Configuration Request
Configuration Reject
Configuration Ack
Configuration Request
Configuration Ack

#### PPP Authentication

Challenge
Response
Success


#### PPP NCP Negotiation
#### PPP CCP Negotiation




## LINKS

* RFC 2637

* <https://en.wikipedia.org/wiki/Point-to-Point_Tunneling_Protocol>
