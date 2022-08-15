# iptables

iptables是用户空间。

规则
===

规则包含源地址、目的地址、协议、服务类型等。

当数据包与规则匹配时，按照所定义的方法来处理，有accept、reject、drop等，

iptables就是根据规则所定义的方法来处理这些数据包

**表**

iptables定义了四类表（具有相同功能的规则集合）：filter表、nat表、mangle表以及raw表。

raw关闭nat表上启用的连接追踪机制，内核模块:iptable_raw
mangle负责拆解报文、处理报文， 内核模块：iptable_mangle
nat负责网络地址转换，数据NAT,内核模块：iptable_nat
filter负责过滤功能，属于防火墙，内核模块：iptables_filter





**链**

input是数据进入计算机的规则链，可以存在于mangle、filter三张表的规则。

output是数据从计算机出去的规则链，可以存在于raw、mangle、nat、filter四张表中。

prerouing是路由转发前的规则链，拥有raw、mangle、nat三张表的规则。

forward是路由转发中的规则链，拥有mangle、filter两张表的规则。

postrouting是路由转发后的规则链，拥有mangle、nat两张表的规则。

除了以上的链，还可以有自定义的链，作为以上的链的行为处理。      