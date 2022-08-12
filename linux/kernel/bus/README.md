总线是设备驱动模型中的一部分，负责将注册的设备与驱动对应起来。有SPI、I2C、USB等总线，在一些外
设中，例如LED、定时器、蜂鸣器等这些都是通过内存的寻址空间来寻址的，所以CPU与这些设备的通信不需要通
过总线，而linux kernel为了统一管理这些外设，虚拟出一条总线来管理这类外设，称之为platform总线，
该总线是一条伪总线。


platform bus
------------

platform总线将platform驱动与platform设备分离，在探测到platform设备时，就会在内核中注册对应的
platform驱动。该总线模型声明在include/linux/device.h中
