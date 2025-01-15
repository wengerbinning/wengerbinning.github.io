







global section
==============

唯一且没有名称

auth file
---------

default: /etc/l2tpd/l2tp-secrets
指定用于验证L2TP隧道的认证文件,默认

access control
--------------

value: {yes, no}
default: no
该参数用于启动连接控制, 开启后只接受指定连接.

debug avp
----------

value: {yes, no}
default: no
该参数用于启动 L2TP AVP 数据包的日志.

debug network
-------------

value: {yes, no}
default: no
该参数用于启动网络的日志.


debug packet
-------------

value: {yes, no}
default: no
该参数用于启动 L2TP 数据包的日志.

debug state
------------

value: {yes, no}
default: no
该参数用于启动 FSM 的日志.

debug tunnel
------------

value: {yes, no}
default: no
该参数用于启动隧道调试的日志.




lns section
============

format: [lns <name>]

ip range
---------

该参数指定连接的地址范围.

lac section
===========





