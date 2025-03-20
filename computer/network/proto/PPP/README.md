PPP(Point-to-Point Protocol)是一个二层通信协议，提供
环回检测、身份认证、数据加密、数据压服务

* RFC 1661

## Protocol Families

### 1

#### PPP

```
1B Flag
1B Address
1B Control
2B Protocol
   Payload
   Padding
2B Frame Check Sequence
1B Flag
```

### 2

#### LCP(Link Control Protocols)

```
2B  Flags
2B  Protocol Type
2B   Playload Length
2B  Call Id
```

#### NCP(Network Control Protocol)

#### CCP(Compression Control Protocol)

#### CHAP PAP IPCP


## 应用场景

#### PPPoE

#### PPPoA



































* <https://en.wikipedia.org/wiki/Point-to-Point_Protocol>