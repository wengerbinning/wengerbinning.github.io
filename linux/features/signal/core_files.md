core文件是在程序崩溃时生成的一个内存映像文件，主要应用来调试。系统为默认是不保存生成的core文件的。需要我们通过设置才能保存core文件到指定路径。

该文件包含程序运行时的内存，寄存器状态，堆栈指针，内存管理信息还有各种函数调用堆栈信息等。该文件满足ELF格式，readelf可以确认一个文件为core文件

**保存core文件**

使用`ulimit -a`查看保存core文件是否被禁止，如果被禁止，请使用使用以下取消限制。

在终端中执行`ulimit -c unlimited`可以让系统为用户保存core文件。

**指定core文件的保存路径**

`/proc/sys/kernel/core_uses_pid`文件可以控制生成的core文件是否有进程ID作为文件扩展。当文件内容为1时，表示开启进程ID作为文件扩展。

`/proc/sys/kernel/core_pattern`文件用来控制core文件的保存路径与命名规则。其中`%p`表示进程ID，`%u`表示当前用户ID，`%g`表示当前用户组ID，`%s`表示产生core文件的信号，`%t`表示生成core文件的时间，`%h`表示主机名，`%e`表示生成core文件的程序名称。

```shell
echo "/var/tmp/corefiles/core-%h-%g-%u-%p-%e-%s-%t" > /proc/sys/kernel/core_pattern
```

> Note:在指定core文件保存格式时，需要确保保存路径存在并且当前用户有写入权限。

**主动生成core文件**

使用kill关闭进程时，使用-s指定信号量来生成core文件，能生成core文件的信号量有SIGABRT、SIGBUS、SIGEMT、SIGFPE等


    