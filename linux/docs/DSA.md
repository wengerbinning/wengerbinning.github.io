DSA(Distrubuted Switch Architecture)



<!-- The original philosophy behind this design was to be able to use unmodified 
Linux tools such as bridge, iproute2, ifconfig to work transparently whether 
they configured/queried a switch port network device or a regular network device. -->

DSA系统设计的原始理念是能使用未经修改的Linux工具（例如bridge、iproute2， ifconfig）透
明工作。无论是配置、查询交换机端口的网络设备或常规的网络设备。

<!-- An Ethernet switch typically comprises **multiple front-panel ports** and 
**one or more CPU or management ports**. The DSA subsystem currently relies on 
the presence of a management port connected to an Ethernet controller capable of
receiving Ethernet frames from the switch. This is a very common setup for all 
kinds of Ethernet switches found in Small Home and Office products: routers, 
gateways, or even top-of-rack switches. This **host Ethernet controller** will 
be later referred to as "master" and "cpu" in DSA terminology and code. -->

一个以太网交换机通常包含多个前端面板端口和一个或多个管理端口（CPU端口）。DSA系统当前依赖
连接到以太网控制器的管理端口来接收来交换机的以太网帧。对于小型家庭和办公室产品中各种以太网
交换机来说， 这是一种非常常见的设置：路由器、网关、甚至是架顶式交换机。该主以太网控制器
在DSA中将被称为master或CPU。

<!-- The D in DSA stands for Distributed, because the subsystem has been designed 
with the ability to configure and manage cascaded switches on top of each other 
using upstream and downstream Ethernet links between switches. These specific 
ports are referred to as "dsa" ports in DSA terminology and code. A collection 
of multiple switches connected to each other is called a "switch tree". -->

DSA中的D表示分布式(Distrubuted)，因为该系统被设计为能配置与管理级联的交换机通过交换机间
的链路（彼此连接的端口），这些比较特殊的端口在DSA技术中被称为DSA端口， 相互连接的多个交
换机的集合被称为交换机树。

<!-- For each front-panel port, DSA creates specialized network devices which are 
used as controlling and data-flowing endpoints for use by the Linux networking 
stack. These specialized network interfaces are referred to as "slave" network 
interfaces in DSA terminology and code. -->

对于每一个前端面板端口， DSA会创建一个特殊的网络设备用于管理和数据传输的端点在Linux网络
栈中。这些特殊的网络接口在DSA中被称为slave接口。

<!-- The ideal case for using DSA is when an Ethernet switch supports a "switch tag" 
which is a hardware feature making the switch insert a specific tag for each 
Ethernet frame it receives to/from specific ports to help the management 
interface figure out: -->

使用DSA的理想场景是以太网交换机可以支持SWITCH TAG，这是一个硬件功能，交换机可以为从特定
端口收到或发送的每一个以太网帧插入一个特殊的标签， 以帮助管理接口找出：

<!-- * what port is this frame coming from -->

* 该帧来自于哪一个端口

<!-- * what was the reason why this frame got forwarded -->

* 转发此帧的原因是什么

<!-- * how to send CPU originated traffic to specific port -->

* 如何将CPU发起的流量发送到特定的端口

<!-- The subsystem does support switches not capable of inserting/stripping tags, but
the features might be slightly limited in that case (traffic separation relies 
on Port-based VLAN IDs). -->

DSA也支持没有SWITCH TAG的交换机， 但是这种情况下功能可能会受到轻微的限制（流量分离依赖于
基于端口的VLAN ID）。

<!-- Note that DSA does not currently create network interfaces for the "cpu" and 
"dsa" ports because: -->

注意DSA当前不会为CPU端口与DSA端口创建网络接口：

<!-- * the "cpu" port is the Ethernet switch facing side of the management controller, 
  and as such, would create a duplication of feature, since you would get two 
  interfaces for the same conduit: master netdev, and "cpu" netdev. -->

* CPU端口是从管理器站在以太网交换机侧；因此将会创建CPU接口将会产生重复的功能。因为你将会
为同一个管道创建两个接口： master接口与cpu接口。

<!-- * the "dsa" port(s) are just conduits between two or more switches, and as such 
  cannot really be used as proper network interfaces either, only the downstream,
  or the top-most upstream interface makes sense with that model. -->

* DSA端口只是两个或多个交换机之间的管道， 因此也不能用作正常的网络接口， 在DSA模型中只
  有下游与最顶端的接口是有意义的。

## LINKS

* Linux Kernel Documents <https://www.kernel.org/doc/html/latest/networking/dsa/dsa.html?highlight=bridge>