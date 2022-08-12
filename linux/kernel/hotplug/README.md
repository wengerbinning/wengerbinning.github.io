Hotplug

热拔插是





uevent事件是linux kernel发出的一种通知信息。


udev与mdev是两个使用uevent机制处理热拔插文件的用户空间程序，udev是基于netlink（socket）实现的，在系统中创建了一个deamon程序udevd，通过监听内核
发送的uevent来执行相应的热拔插行为（创建设备节点、加载卸载驱动模块）；mdev是基于hotplug_helper机制实现的，即向`/proc/sys/kernel/hotplug`中写入处理脚本
即可。该文件内容会同步到`/sys/kernel/uevent_helper`。



<https://lkw.readthedocs.io/en/latest/doc/03_kernel_modules.html#dmesg>