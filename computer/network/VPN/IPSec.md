# IPSec






封装安全负载(ESP, Encapsulating Security Payload)





IKE
===

密钥交换协议(IKE)是一种混合协议，由Internet安全关联和密钥管理协议(ISAKMP)与两个密钥交换协议OAKLEY与SKEME组成。

两个阶段
-------
* 第一阶段： 通信双方建立一个以通过身份认证和安全保护的通道。

此阶段的交换建立了一个ISAKMP SA（也称为IKE SA），表示通信双方如何使用安全服务进行安全通信

* 第二阶段：利用第一阶段建立的安全通道为IPSec协商安全服务，建立IPSec SA,该SA用于IP数据的安全传输。



安全关联(Security Association)
----------------------------

IPsec在两个端点之间提供安全通信，两个端点称为IPsec ISAKMP网关， SA是IPSec的基础与本职。

 SA是通信对等体对某些要素的约定， 使用哪种协议、协议的模式、加密算法、特定流中保护数据的共享密钥以及SA的生存周期。


SA的匹配方法
-----------

加密方向outbound：策略或者路由驱动

解密方向inbound：目的地址 + 协议 + SPI，实时的流中源端口与目的端口组成SPI。





协商模式
--------

第一阶段：3次交换（共6个报文）。第一、二次交换为明文传输，第三次交换使用第二次协商的加密材料进行加密。

第一次交换协商p1提议。

第二次交换用于生成给后续协商报文和数据报文加密用的加密材料。

第三次交换用来验证对方身份，包含ID与认证载荷




Linux的IPSec的实现
----------------

NETKEY(aka xfrm) IPsec stack


libreswan
---------

KLIPS Ipsec stack