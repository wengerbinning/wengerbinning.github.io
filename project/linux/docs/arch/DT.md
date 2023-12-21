设备树(DT, Device Tree)是一种描述计算机的特定硬件设备信息的数据结构，以便于OS的内核管理和使用这
些硬件设备；这些设备有CPU、内存、总线以及其他设备。这些设备信息都保存在设备树资源(DTS,Device Tre
e Source)中，`*.dts`是文本文件，该文件由设备树编译器(DTC, Device Tree Compiler)编译为设备
树序列(DTB, device tree blob)，`*.dtb`是二进制序列文件。用于内核读取。

dtc
