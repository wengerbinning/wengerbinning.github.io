IPsec 是一个集合了许多标准的体系结构。

* SA管理
* AH
* ESP

这些表现标准在网络层为IPv4、IPv6以及移动IPv6提供数据源认证、完整性、机密性以及访问控制。
为两个通信的实体提供一种交换密钥的方法、一个加密套件以及一种标记使用压缩的方法。

通信实体可以是一台个人主机、可也能是一个在受保护与不受保护网络区域间提供界限的安全网关(Security Gateway)


* BITS(Bump in the Stack, 协议栈中的块)
* BITW(Bump in the Wire, 线路中的块)




IPsec通信分为两个阶段

* 建立连接 - 负责交换密钥并建立安全关联(Security Association, SA);
* 数据交换 - 使用不同类型封装架构， 有AH与ESP两种类型；并使用在不同的模式中， 有隧道模式与传输模式。



传输模式
-------

用于直接相连的主机， 不支持数据分片。

隧道模式
--------

应用于SG之间。



SA(Security Association)
------------------------

SA是两个通信方之间建立的单工认证关联。双方通信需要一对SA才能有效使用IPsec

* SPD(Security Policy Database, 安全策略数据库)
* SAD(Security Association Database, 安全关联数据库)
* PAD(Peer Authorization Database, 端点认证数据库)






Internet密钥交换协议(IKEv2)
--------------------------

IKE为建立一个SA， 开始于一个简单的请求与响应， IKE首先为自己建立一个SA(IKE-SA)，
之后为ESP或AH建立一个SA(CHILD-SA), IKE消息基于UDP的500或4500端口进行交换·

* IKE_SA_INT
* IKE_AUTH
* CREATE_CHILD_SA



AH(Authentication Header, 认证头)
---------------------------------

* RFC4302

提供一种源认证和保护IP数据完整性的方法。

在传输模式下， AH在IP层协议之后

ESP(Encapsulating Security Payload, 封装安全负载)
-------------------------------------------------

* RFC44303

提供机密性、完整性、原始认证以及IP数据报的反重放保护。