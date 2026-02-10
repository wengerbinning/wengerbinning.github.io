

## IPv4 Header

IPv4固定长度为20字节，option最长为40字节

* 0d04b - Version: 值固定为 0b0100
* 0d04b - IHL(IP Header Length): IPv4头部长度，单位4字节
* 0d01B - TOS(Type of Service)： DSCP
* 0d02B - Total Length：单位为1字节
* 0d02B - Identification
* 0d03b - Fragment Flags
* 0d13b - Fragment offset
* 0d01B - TTL(Time to Live): 最大转发次数
* 0d01B - Protocol： 载荷协议
* 0d02B - Header Checksum： 头部校验和
* 0d04B - source addrress
* 0d04B - destination address

### IPv4 Header Option

* xxb - option(maxum 40B)

## IPv4 Payload

* xxb - playload


