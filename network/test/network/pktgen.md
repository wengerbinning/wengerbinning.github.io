


pktgen
======

pktgen是一个由瑞士皇家理工大学的TSlab实验室的Robert Olsson开发的位于linux内核层的高性能网络测试工具。
主用来测试网络驱动与网卡设备，支持多线程，能够产生随机MAC地址、IP地址、UDP端口号的数据包。在使用该工具时，
需要加载内核模块pktgen。

```shell
# Load kernel module.
modprobe pktgen
```

随后在/proc中看到以下内容，其中`kpktgend_*`表示线程控制文件， `pgctrl`控制pktgen，所有的参数都是通过这
两类文件来设置的。

```shell
wenger ~ $ ls /proc/net/pktgen/
kpktgend_0  kpktgend_1  kpktgend_2  kpktgend_3  kpktgend_4  kpktgend_5  pgctrl
```

* pktgen的控制命令：

```shell
# 所有线程开始发送。 
start

# 停止 
stop
```

* 线程的控制命令：


```shell
# 添加某个端口到某个线程上
add_device

# 删除绑定在某个线程的所有端口
rem_device_all


# 对每一个skb进行多少个复制， 0表示不复制。
clone_skb

# 清空计数器，一般程序自动清空。
clear_counters

# 链路包的大小
pkt_size

# 数据包的最小值
min_pkt_size

# 数据包的最大值
max_pkt_size

# 数据包的片数量
flags

# 发包数量

```

**中断亲和力**

在通过网卡发送数据包时，需要将将网卡的的端口绑定到某一个CPU上，从而防止CPU的变动导致的CPU缓存丢失；

* 首先通过`/proc/interrupts`查看与测试网卡有关的中断。测试机的信息如下：

```shell
wenger ~ $ cat /proc/interruptcat /proc/interrupts | grep enp3s0
 134:          0          0          0          0          0   85304653  IR-PCI-MSI 1572864-edge      enp3s0
```

* 将相关中断信号绑定到指定CPU：

```shell
root ~ # echo 20 > /proc/irq/134/smp_affinity
root ~ # cat  /proc/irq/134/smp_affinity
20
```



