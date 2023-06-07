在Linux中数据的接受发送流程




## 发送数据

#### socket

将数据递送到响应的协议处理

#### network protocol

通过协议栈对数据进行封装



* 实际发送数据 [netdev_start_xmit](../include/linux/netdevice.md#netdev_start_xmit)



sch_direct_xmit -> dev_hard_start_xmit

__qdisc_run -> qdisc_restart -> sch_direct_xmit

__dev_xmit_skb -> __qdisc_run

__dev_xmit_skb -> sch_direct_xmit


__dev_queue_xmit -> __dev_xmit_skb

__dev_queue_xmit -> dev_hard_start_xmit

dev_queue_xmit -> __dev_queue_xmit


#### network driver

通过驱动封装函数写入NIC中




## 接收数据


#### network driver

通过硬件中断通知CPU处理数据。

* netif_receive_skb
* __netif_receive_skb

#### network protocol

进入网络协议栈

#### socket

将数据递送给用户层