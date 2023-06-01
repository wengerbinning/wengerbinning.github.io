
iptable 是netfiler提供的用于组织过滤规则的模块

存在若干个规则表
默认有

raw
filter
nat
mangle
四张表



iptables的前身是ipfirewall（需要工作在内核），后更名为ipchains,可以定义多条规则，现在定义为iptables;用于定义规则，让内核中的netfilter来读取。
在内核空间共有五种位置：
* 网络接口间的转发
* 数据从内核流入用户时
* 数据从用户流入内核时
* 经过本机的外网卡接口
* 经过本机的内网卡接口
在这五个位置有五个钩子函数（五个规则链）
1. prerouting
2. input
3. forward
4. output
5. postrouting

防火墙分为通策略与堵策略，通过路由表来实现

1. filter 定义允许或禁止规则，在2,3,4链上
2. net 定义地址转换的规则， 在1,4,5链上
3. mangle修改包文原数据的规则，一般用于改TTL，在5个链上都可以。