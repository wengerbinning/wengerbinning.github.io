在Linux中数据的接受发送流程




## 发送数据

#### socket

将数据递送到响应的协议处理

#### network protocol

通过协议栈对数据进行封装

#### network driver

通过驱动封装函数写入NIC中




## 接收数据


#### network driver

通过硬件中断通知CPU处理数据。

#### network protocol

进入网络协议栈

#### socket

将数据递送给用户层