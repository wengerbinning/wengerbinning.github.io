proc是一个proc虚拟文件系统挂载的目录，用于管理计算机进程等信息，在该目录下有以下文件：

* `<pid>/`目录存储进程号为pid的进程信息。
* `fs/`
* `irq/`
* `driver/`
* `bus/`
* `asound/`
* `dynamic_debug/`
* `pressure/`
* `scsi/`
* `sys/`
* `sysvipc/`
* `tty`
* `vmnet/`

* `self`文件是一个指向到当前进程的链接文件。
* `thread-self`文件是一个指向当前进程的当前线程信息的链接文件。
* `net`文件是一个指向当前进程的net的链接文件。
* `mounts`指向当前进程的挂载的链接文件。

* `swaps`
* `stat`
* `misc`
* `kmsg`
* `feys`
* ``