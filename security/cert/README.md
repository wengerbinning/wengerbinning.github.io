
主体证书:
服务证书:
终端证书:
签名证书:代码、文档、合同
邮件证书:
设备证书:

SSL证书：
* 主体(Subject)
* 颁发者(Issuer)

公钥基础设施（PKI）
在线证书状态协议(OCSP,Online Certificate Status Protocol)-> OCSP Stapling
证书吊销列表(CRL, Certificate Revocation List)
信任锚(Trust Anchor)


X.500
X.509是国际电信联盟(ITU-T)制订的PKI标准 - ASN.1编码
* 主体(Subject) - 可分辨名称(DN)
* 版本(Version) - v1, v2, v3
* 扩展(Extensions) - v3引入, SAN（X.509 v3扩展）
* 颁发者(Issuer) - (CA)
* 序列号(Serial Number) - CA分配，用于吊销查询
* 有效期(Validity) -
* 主体标识(Subject Unique ID)
* 颁发标识(Issuer UNique ID)
* 内容签名(Signatore Value)
* 签名算法

# RFC 5280
主体(Subject) - 相对可分辨名称（RDN）
* CN(Common Name) - 通用名称
* C(Country)
* O(Organization)
* OU(Organizational Unit)
* L(Locality)
* ST(State/Province)
* E/Email(Email Address)
* DC(Domain Componment)
* UID(User ID)

扩展(Extensions)
* 基本约束(Basic Constraints)
* 密钥用法(Key Usage)
* 扩展密钥用法(Extended Key Usage)
* 主题备用名称（SAN, Subject Alternative Name）
* 颁发者备用名称（IAN, Issuer Alternative Name）
* CRL分发点（CDP， CRL Distribution Points）
* 授权信息访问（AIA, Authority Information Access）- 该扩展包含 OCSP 服务器的 URL
* (SKI, Subject Key Identifier)
* (AKI, Authority Key Identifier)
