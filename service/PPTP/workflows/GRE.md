通用路由封装协议(GRE, Geretic Routing Encapsulation)基于IP协议的隧道技术.规定了如何将一
种网络协议下的数据报文封装在另外一种网络协议中，使这些被封装的数据报能够在另一个网络层协议中传输。



RFC 1701
RFC 2784

通用格式(>= 4B):

* 02B - Flags and Version
* 02B - Protocol Type
* 04B - **Checksum and resverd*
* 04B - **Sequence Number*
* 04B - **Acknownledgment Number*
* 04B - **Routing*

### Flags and Version

* 01b - Checksum Bit: 标识包含校验字段
* 01b - Routing Bit: 表示包含路由字段
* 01b - Key Bit: 标识包含关键字段
* 01b - Sequence Number Bit:
* 01b - Strict Source Route Bit:
* 03b - Recursion Control: GRE分装次数
* 01b - Acknowledgment:
* 04b - Flags:
* 03b - Version: 001:Enhanced GRE

### Protocol Type

* 0x880b - PPP

## PPP


* 02B - Flags and Version
* 02B - Protocol Type
* 02B - Playload Length
* 02B - Call ID:
* 04B - **Sequence Number*
* 04B - **Acknownledgment Number*

