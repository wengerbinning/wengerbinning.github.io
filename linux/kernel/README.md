linux kernel是GNU/Linux的内核，由

源码结构

* `include/`内核头文件。
* `arch/`有关平台相关的内容。
* `crpto/`加密的API.
* `fs/`vfs与各类文件系统。
* `firmware`使用某些驱动程序而需要的设备固件。
* `Documentation/`内核源码文档。

  * `CodindStyle`Linux内核编程风格。
  * `Kernel-doc-nano-HOWTO.txt`注释。
  * `oops-tracing.txt`
  
* `drivers`设备驱动层程序。

* `init`内核引导和初始化。
* `ipc`进程间通信代码。
* `kernel`核心子系统。
* `lib`通用内核函数。
* `mm`
* `net`
* `samples`
* `scripts`
* `security`
* `sound`
* `usr`
* `tools`
* `virt`

* `COPYING`内核许可文件。
* `CREDITS`开发者列表。
* `MAINTAINERS`维护者列表。
* `REPORING-BUGS`
* `Makefile`


arch
----

该目录下存放了关于不同架构平台的相关代码，常用的架构有x86、arm、arm64、mips等。各自相关代码通过以
架构名为目录管理；在各自的目录下都存在include目录，保存了相关的接口信息。这里通过所有架构共同的内容
分类。

**include/asm**

* `io.h`



* 


内核开发说明：

* 内核开发不能使用外部库文件。
* 内核开发推荐使用GNU C.
* 内核中每一个进程只有一个很小的定长栈。
* 

内存管理
------

kmalloc函数














物理内存

虚拟内存是

辅助内存


内存映射是虚拟内存到物理内存的映射


-------------------------

.*.o.cmd文件是内核编译生成*.o的依赖文件，其中有source_*、deps_*、cmd_*三类，其中source表示源码
deps表示依赖有文件



## 头文件

linux/export.h

## 存储设备


**内存设备**

在计算机中，内存设备是一类断电丢失数据的设备，这个设备在市场中通常被称内存条，读写速度比外存设备快，
计算机在执行程序或处理数据时，一般都会将程序或数据读入内存中处理。

**外存设备**

在计算机中，外存设备主要指具有断电不丢失数据的设备，这类设备按照市场产品分类有软盘、硬盘、U盘、光盘
等设备。这类设备在Linux kernel中存在block layer来表示常见的块设备。

flash存储芯片是一种存储数据的芯片，有nand与nor两大类，在linux kernel中存在MTD模型来描述flash
设备，该模型主要封装了不同flash设备，为上层提供统一管理的接口，之后会使用mtd设备来描述所有的flash
设备，

UBI模型是基于mtd设备，封装了ubi设备的一些特性，并为ubifs提供访问mtd设备服务；FTL模型也是基于mtd
设备，为block layer提供访问mtd设备的服务。
