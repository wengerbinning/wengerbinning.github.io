# Windows

[//]: # (__author__ = "Clark Aaron")

Windows是Microsoft开发的一款桌面级操作系统。



**Windows API**

Windows API是针对Windows操作系统家族的用户模式提供的系统编程接口。Win32 API是指32位版本的
Windows操作系统的编程接口，以区分16位版本的Windows操作系统的编程接口，在这里Windows API是指
兼容32位与64位的Windows API。该API在Windows SDK文档中有详细描述。具体包含基本服务、组件服务、
用户界面服务、图形和多媒体服务、消息和协作、网络、Web服务。

**Microsft.NET**

Microsoft.NET框架是由框架类库(FCL, Framework Class Library)与公共语言运行库
(CLR, Common Language Runtime)组成，CLR提供以下特性：即时编译、类型检验、垃圾回收、代码安全

**Windows服务**

Windows服务是指由Windows服务控制管理启动的进程。


**DLL**

DLL(动态链接库)是指语一组可调用的子例程，被链接到同一个文件中。不可执行的.NET程序集也被编译成
DLL，但是，没有导出成任何子例程， 而是由CLR解析出编译的单元，以便访问对应的数据类型和成员。

**进程**

进程（Process）是一个资源容器，包含虚拟地址空间、已打开的句柄列表、安全环境、进程ID、至少一个执行线程。

**线程**

线程（Thread）是Windows调度的实体，线程包含一组寄存器、两个栈、线程局部存储(TLS)、线程ID

**纤程**

纤程(Fiber)是应用程序可以调度他自己的执行单位，也被称作轻量线程；


**UMS**

用户模式调度(UMS, User Mode Scheduling)的线程仅在64位上可用

**句柄表**


**访问令牌**

访问令牌(Access token)是保存进程的安全环境的对象。

**VAD**

虚拟地址描述符(VAD, Virtual Address Descriptor)

**Job**

作业(job)是将一组进程当作一个整体来管理。










## 基础知识

### 进程

#### 进程间的通信

* 共享内存
* 管道

#### 服务

### 环境变量

### 开机启动项

开机启动项是在计算机系统启动时自动执行的程序，其主要存在以下几个地方。

* 系统（用户）启动文件夹：系统启动文件夹在。
* 注册表启动项`计算机\HKEY_CURRENT_USER\Software\Microsoft\Windows NT\CurrentVersion\Windows\load`主键；
* 注册表启动项`计算机\HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Winlogon\Userinit`主键；
* 注册表启动项`计算机\HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Policies\Explorer\Run`主键；
* 注册表启动项`计算机\HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Policies\Explorer\Run`主键；
* 注册表启动项`计算机\HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\RunOnce`主键；
* 注册表启动项`计算机\HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\RunOnce`主键；
* 注册表启动项`计算机\HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Run`主键；
* 注册表启动项`计算机\HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Run`主键；

## 发展简述

1983年11月10日，Microsoft宣布开发一个图形用户界面操作系统——Micorsoft Windows。在1985年发布Windows 1.0，只是对MS-DOS的扩展；1987年，发布Windows 2.0；1990年发布Windows 3.0，是第一个在保护模式下运行应用程序的版本

* Windows 1.0：1985年发布。只是对MS-DOS的扩展。
* Windows 2.0：1987年发布。使用了可重叠式窗口，增强了键盘和鼠标接口。
* Windows 3.0：1990年发布。对Intel的286、386、486MCU保护模式的支持。
* Windows NT：1993年发布。可以移植到非Intel处理器上。
* Windows 95：1995年8月发布。集成Windows 3.x与Windows NT。代号Chicago，共有5个版本。
* Windows NT 4.0：1996年7月发布。共有4个版本。
* Windows 98：1998年6月发布。代号Memphis。将internet explore集成到Windows接口与Wenjian管理器中。
* Windows 2000：2000年发布。共有4个版本，Winodws9x系列又发行了Windows me。
* Windows ME：2000年09月发布。
* Windows XP：2001年发布。集成Windows 2000与Windows ME。
* Windows Server 2003：2003年04月发布。共有7种版本。
* Windows Vista：2007年01月发布。引入限制用户模式，支持防火墙。共有6个版本。
* Windows Server 2008：
* Windows 7：2009年10月发布。
* Windows 8：2012年10月发布。
* Windows 10：2015年07月发布。
* Windows Server 2016：2016年09月发布。



### Windows XP 启动原理

1. 预启动：BIOS扫描硬件配置，读取MBR，检查DPT
2. 启动
3. 装载内核：
4. 初始化内核：
5. 用户登录：

* Cleanmgr与超级魔法兔子

* 图标：iconfactory

* 鼠标

* 窗口

* 对话框

* 向导

### 自启动



### 分类

一般所说的DOS泛指微软的MS-DOS；并且将Windows中的命令行、恢复控制台也包含在内。

### DOS的作用

磁盘分区、磁盘格式化、磁盘修复、Ghost备份

win7中有command.com（在ntvdm.exe）进程中的程序，是一个16位的DOS应用程序；

#### 恢复控制台

Windows Vista++不再支持；在XP中执行`\I386\WINNT32.EXE /cmdcons`安装恢复控制台程序。

修改MAC地址： 计算机`\HKEY_LOCAL_MACHINE\SYSTEM\ControlSet001\Control\Class\{4d36e972-e325-11ce-bfc1-08002be10318}\0014\Ndi\params\NetworkAddress`

### 启动盘

nero

### 磁盘管理

* fdisk
* format
* de
* PQ
* vol：显示卷标；
* label：管理卷标。
* convert：将fat卷转化为NTFS。
* chkdsk：检查磁盘。
* recover:从坏磁盘恢复刻度信息。
* compact：显示或更改NTFS分区上的文件或目录压缩。
* defrag：磁盘碎片整理。

### 系统备份

* ghost：系统备份。
* cleanmgr：系统临时文件清理。
* sfc.exe /purgecache:清除文件缓存。

### 系统休眠

* 文件:`C:/hiberfil.sys`

* 关闭系统休眠: `powercfg -h off`



RYCR6-T7Y6M-2TVHK C2YW3-7TYQ8



# Windows的数字激活


## LINKS

* [Windows 官方网站](https://www.microsoft.com/zh-cn/windows/) 
  > <https://www.microsoft.com/zh-cn/windows/>

* [Windows 下载官方资源](https://www.microsoft.com/zh-cn/software-download) 
   > <https://www.microsoft.com/zh-cn/software-download>