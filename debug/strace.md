# strace

strace是一个调试工具，可以显示某个进程的系统调用的轨迹。

* 跟踪程序

```shell
strace ls
```

* 跟踪指定进程，子进程不会跟踪。

```shell
strace -p 1000
```

* 跟踪所有子进程。

```shell
strace -f -p 10000
```

* 
