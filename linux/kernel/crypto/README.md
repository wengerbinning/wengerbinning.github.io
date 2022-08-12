crypto是linux kernel提供一个通用的加密算法架构，在该框架中提供静态算法与动态算法两种管理方案，静
态算法是以模块的形式直接加载进去，动态算法是根据算法模式结合基础算法而动态创建的算法，例如cbc(aes)
表示使用AES算法的CBC模式（该概念在linux kernel中表示为算法模板）；静态算法在密码学上属于算法的范
畴，动态算法在密码学上属于算法应用的范畴。该框架包含对称加密、非对称加密、认证加密、数据摘要、随机数
生成以及压缩算法。

可以通过CPU纯软件实现、ARM-CE、ARM-NEON、SOC crypto engine实现。

在/proc/crypto文件中显示了linux kernel支持的加密算法。其中name表示算法的名称，priority代表
算法的的优先级（数值越大，优先级越高，默认使用高优先级的算法）


在用户空间使用该框架提供的算法可以通过netlink、cryptodev、

crypto core是该框架的基础，提供crypto的核心组件：crypto_alg、crypto_template、cryptd。

SKCIPHER
-------
对称加密算法

AES
DES

AKCIPHER
--------
非对称加密算法

DRBG
----
伪随机数算法

AEAD
----
认证加密算法 (AEAD, Autherticated Encryption with Associated Data)

KPP
---
密钥协商算法，例如ECDH

HASH
----


HMAC
----


COMPRESS
--------
压缩算法



分块加密模式中的对称加密有CBC、ECB、GCM、CTR、XTS，这个模式使用于所有的加密算法。


ECC(Elliptic Curve ciphers)

ECDLP(Elliptic Curve Discrete Logarithm Problem)

ECDH(Elliptic Curve Diffie Hellman)

DH(Diffie Hellman)


---

在用户空间，可以通过/proc/crypto来查看内核支持的算法。


```log
$ cat /proc/crypto
name         : jitterentropy_rng
driver       : jitterentropy_rng
module       : kernel
priority     : 100
refcnt       : 1
selftest     : passed
internal     : no
type         : rng
seedsize     : 0

name         : poly1305
driver       : poly1305-simd
module       : kernel
priority     : 300
refcnt       : 1
selftest     : passed
internal     : no
type         : shash
blocksize    : 16
digestsize   : 16
```



分组加密算法的工作模式
------------------

电码本(ECB, Electronic Codebook Book)

将明文分组，对每一组分别加密


密码分组链接(CBC, Cipher Block Chaining)

将明文分组，在分组加密之前明文先与前一组的密文进行异或后再进行加密。

计算器模式(CTR, Counter)

存在一个自增的算子，这个算子用密钥加密之后的输出和明文异或得到密文

密码反馈模式(CFB, Cipher FeedBack)



输出反馈模式(OFB, Output FeedBack)


Linux内核提供一套丰富

