New API(NAPI)是设备包处理驱动框架的一个扩展， 通过中断缓(Interrupt mitigation)和与数据包节流(Packet throttling)来提高网络性能。


#### Interrupt mitigation

High-speed networking can create thousands of interrupts per second, all of which tell the system something it already knew: it has lots of packets to process. NAPI allows drivers to run with (some) interrupts disabled during times of high traffic, with a corresponding decrease in system load.

高速网络每秒可以产生数千个中断，所有这些中断都告诉系统它已经知道的事情:它有很多数据包需要处理。NAPI允许驱动程序在高流量时禁用(一些)中断，从而相应降低系统负载。

#### Packet throttling

When the system is overwhelmed and must drop packets, it's better if those packets are disposed of before much effort goes into processing them. NAPI-compliant drivers can often cause packets to be dropped in the network adaptor itself, before the kernel sees them at all.

当系统不堪重负，必须丢弃数据包时，最好在处理这些数据包之前就将它们处理掉。与napi兼容的驱动程序通常会导致数据包在内核看到它们之前就丢弃在网络适配器本身中。


New drivers should use NAPI if the hardware can support it. However, NAPI additions to the kernel do not break backward compatibility and drivers may still process completions directly in interrupt context if necessary.

如果硬件支持，新的驱动程序应该使用NAPI。然而，添加到内核中的NAPI并不会破坏向后兼容性，如果有必要，驱动程序仍然可以直接在中断上下文中处理补全。