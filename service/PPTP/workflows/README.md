PPTP采用控制与数据分离的方案, 控制通道采用PPTP协议, 数据通道采用PPP协议.


### 建立控制通道

客户端向服务器的1723(TCP)端口发起连接并通过PPTP协议协商出数据通道的信息.

* > PPTP: Start Control Connection Request
* < PPTP: Start Control Connection Reply
* > PPTP: Outgoing Call Request
* < PPTP: Outgoing Call Reply

### 建立数据通道

* > PPP LCP: Configuration Request
* < PPP LCP: Ack
* < PPP LCP: Configuration Request
* > PPP LCP: Ack

* < PPP CHAP: Challenge
* > PPP CHAP: Response
* < PPP CHAP: Success

### 协商虚拟地址

* > PPP IPCP: Configuration Request
* < PPP IPCP: Configuration Reject
* < PPP IPCP: Configuration Request
* < PPP IPV6CP: Configuration Request
* > PPP IPCP: Configuration Ack

* > PPP IPCP: Configuration Request
* < PPP IPCP: Configuration Nak
* > PPP IPCP: Configuration Request
* < PPP IPCP: Configuration Ack

### 维护数据通道

* PPP LCP: Echo Rquest
* PPP LCP: Echo Reply



### 关闭数据通道

### 关闭控制通道