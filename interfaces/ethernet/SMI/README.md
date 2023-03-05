# SMI

<!-- ---------------------------------------------------------------------- -->

SMI(Serial Management Interface, 串行管理接口， 也称作MII管理接口)是MII用于MAC监控
PHY的接口， 通过该接口一个MAC可以监控最大32个PHY， 其中MAC作为Master， PHY作为Slave。

该接口有MDC与MDIO两条信号线， MDC为MDIO提供时钟， MDIO用来读写PHY寄存器，以管理PHY的
状态。MDIO在MDC的上升沿触发读写。


MDIO数据传输协议有两个版本Caluse 22与Caluse 45


```c
/*
F               F              0            
++++++++++++++++++++++++++++++++
|                              |
|                              |
++++++++++++++++++++++++++++++++


*/

```






