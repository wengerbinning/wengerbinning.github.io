uevent

将uevent实现通知用户空间可以通过两种方式：kmod模块以及netlink通信机制.



kmod模块 通过 `/sys/kernel/uevent_helper`