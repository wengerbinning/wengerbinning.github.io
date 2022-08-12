# 文件系统

文件管理系统是操作系统管理存储设备中的文件的模型，简称文件系统。在Linux中，通过VFS层来讲所有的文件系统进行封装，为上层提供一个统一的接口
来管理文件，在Linux中，有三大类文件系统：基于非易失性的存储介质的文件系统：ext4、resisterfs、fat、ubifs、yaff2等，虚拟文件系统（这个
概念与上面的VFS有所不同，这里的虚拟文件系统是指不存储在非易失的存储介质上，而是在内存中动态生成的；之前的VFS是对所有的文件进行封装的抽象层）
：procfs、sysfs等以及网络文件系统：NTFS、CIFS等。


```c
// linux/fs.h
struct file_operations {
    struct module *owner;
    loff_t (*llseek) (struct file *, loff_t, int);
    ssize_t (*read) (struct file *, char __user *, size_t, loff_t *);
}
```




文件访问权限
==========

在一个进程中，与用户有关的id有ruid（实际用户ID）、euid（有效用户ID）与suid（设置用户ID），与用
户组有关的id有rgid（实际组ID）、egid（有效组ID）、sgid（设置组ID）。

ruid与rgid是标识用户身份，在登录时取自口令文件的登录项，通常在登陆期间不会改变，超级用户进程可以修改。

有效uid、有效gid以及附属gid决定了我们的权限访问

设置uid以及设置gid在执行程序时保存了有效uid与有效gid的备份
