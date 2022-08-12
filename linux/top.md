# top工具：

```
Mem: 286656K used, 130596K free, 1628K shrd, 4908K buff, 23456K cached
CPU:   0% usr   1% sys   0% nic  96% idle   0% io   0% irq   1% sirq
Load average: 2.01 2.16 2.43 1/171 4282
```


CPU是显示CPU的状态信息，

usr     用户进程(user)
sys     系统进程(system)
nic     网络接口控制器(Network Interface Controller)
idle    是系统空闲
io      数据I/O(Input/Output)
irq     中断(Interrupt Request)
sirq    软中断(Software Interrupt Request)

Load average前三个分别是1分钟、5分钟、15分钟内的运行队列中的平均进程数，正在运行的进程数/进程总数， 最近运行的进程ID.

* 当1分钟的CPU负载 > 5分钟的CPU负载，说明服务器处于负载高峰期；
* 当1分钟的CPU负载 < 5分钟的CPU负载，说明服务器刚过负载高峰期； 