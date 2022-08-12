sysvinit是来自system V的init模块，该模块提供init进程供系统是初始化时调用，在调用之后，首先会读取
/etc/inittab的配置文件来

inittab的任务是确认系统runlevel，其每一个登记项的格式如下：

<id>:<runlevel>:<action>:process

* id是登记项标识，用于唯一的标识一个登记项，最多4位字符；

* runlevel是运行级别，用于确定系统进入预定的运行模式，一般有8种模式。

0 关机
1 单用户
2 多用户，维护模式，NFS服务不开启
3 多用户，命令行模式
4 保留
5 多用户，图形化界面
6 重启
S/S 系统故障后的排错与恢复。

* action动作关键词

boot 只在引导过程中运行的进程

bootwait 只在引导过程中运行的进程，在单用户模式进入多用户模式时执行

initdefault 系统默认的运行级别

off

once

ondemand

powerfail

powerwait

 respawn


 sysinit


 在扫描完之后，启动/etc/rc.d/rc.sysinit脚本