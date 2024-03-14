

安全关联(Security Association)
----------------------------

IPsec在两个端点之间提供安全通信，两个端点称为IPsec ISAKMP网关， SA是IPSec的基础与本职。

 SA是通信对等体对某些要素的约定， 使用哪种协议、协议的模式、加密算法、特定流中保护数据的共享密钥以及SA的生存周期。


* SA由三元组唯一标识：SPI(Security Parameter Index, 安全参数索引)、目的IP地址和使用的安全协议号

* SPI是为唯一标识SA而生成的一个32位比特的数值


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



#### Site-to-Site

站点到站点的方式，一般用于两个路由器之间， 在两个路由器之间建立一条隧道。

#### Client-to-Site

该方式可以允许外部设备访问内网。

## IKE

密钥交换协议(IKE)是一种混合协议，由Internet安全关联和密钥管理协议(ISAKMP)与两个密钥交换协议OAKLEY与SKEME组成。

两个阶段
-------
* 第一阶段： 通信双方建立一个以通过身份认证和安全保护的通道。

此阶段的交换建立了一个ISAKMP SA（也称为IKE SA），表示通信双方如何使用安全服务进行安全通信

* 第二阶段：利用第一阶段建立的安全通道为IPSec协商安全服务，建立IPSec SA,该SA用于IP数据的安全传输。


* 身份认证：确认通信双方的身份，

    1. PSK(Pre-Shared Key, 预共享密钥)认证
    2. 数字证书RSA认证
    3. 数字信封认证

* 交换密钥（DH算法）


认证算法
--------

* MD5
* SHA1
* SHA2

加密算法
--------

* DES
* 3DES
* AES(128, 192, 256)


DH算法
------

* Group1 - 768bit
* Group2 - 1024bit
* Group5 - 1536bit
* Group14 - 2048bit
* Group19 - 256bit ECP(Elliptic Curve Groups modulo a Prime)
* Group20 - 384bit ECP
* Group21 - 521bit ECP

### IKEv2


## ESP

封装安全负载(ESP, Encapsulating Security Payload)

认证算法
-------

* MD5
* SHA1
* SHA2-256
* SHA2-384
* SHA2-512
* SM3


加密算法
-------

* DES
* 3DES
* AES-128
* AES-192
* AES-256

封装模式
-------

* 隧道模式
* 传输模式

## LINKS

* <https://support.huawei.com/enterprise/zh/doc/EDOC1100033740/c11c5416>        