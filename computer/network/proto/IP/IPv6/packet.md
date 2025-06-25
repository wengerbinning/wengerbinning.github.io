## IPv6 Header

IPv4头部固定为40字节，

* 0d04b - Version： 固定值为 0b0110
* 0d01B - TOS：DSCP：
* 0d20b - Flow Label：
* 0d02B - Playload length： 载荷长度
* 0d01B - Next Header： 载荷协议
* 0d01B - Hop Limit： 最大转发次数
* 0d16B - source address： 源地址
* 0d16B - destination address： 目的地址

## IPv6 Option

* 000 - Hop-by-Hop options
* 043 - Routing
* 044 - Fragment
* 051 - Authentication Header(AH)
* 050 - ESP
* 060 - Destination options

## IPv6 payload
