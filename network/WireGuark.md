WireGuard - 简约安全

加密套件(Cryptographic Suite)：WireGuard不使用协商加密套件， 固定为一组最强的算法。
* Curve25519： 用于密钥交换(ECDH)
* ChaCha20:用于对称加密
* Poly1305：用于数据认证(MAC)
* VLAKE2s:用于哈希
* HKDF：用于密钥派生
* SipHash：用于哈希表。

连接模型
* 无状态化的连接：WireGuard采用无状态的Cookie来地域Dos攻击
* 基于公钥的身份验证
*

工作流程

* 配置：Interface/Peer
* 握手：initiation/response
* 传输：
* 会话：


应用场景
* Site-to-Site(服务互联)
* Client-to-Site（远程访问/隐私保护/安全接入）



* 基础协议:UDP/51820（端口可变）
* 数据类型：握手请求/握手响应/Cookie回复/数据传输
* 控制报文/数据报文



* Handshake Initiation
* Handshake Response
* Cookie Reply
* Data

A&B
* A发送握手请求报文，携带A的临时公钥以及B的静态公钥
* B回复握手响应报文，携带B的临时公钥以及一段加密数据
（双方可以根据自己的静态公钥/临时公钥，对方的静态公钥/临时公钥计算出一组唯一的对称加密密钥）
