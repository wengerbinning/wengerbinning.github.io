qemu-system-x86_64


```
qemu-system-x86_64 [options] [disk image]
```



| short option | long option | value | comment |
|:---:|:---:|:---:|:--- |
| `-h` | `-help` | | display this help and exit |
| `-version` | | | display version information and exit |
| `-nographic` |  



* `-machine`选择模拟设备的名称。
  - `-machine help`可以查看可选的设备模型。

* `-cpu`选择CPU模型。
  - `-cpu help`可以查看可选的CPU模型。

* `-smp`设置SMP系统参数。
    - `-smp cpu=n[,core=cores][,threads=threads][,dies=dies][,sockets=sockets][maxcpus=maxcpus]`

* `-boot`启动顺序。
  - `-boot [order=drives][,once=drives][,menu=on|off][,splash=sp_name][,splash-time=sp_name][,reboot-timeout=rb_timeout][,strict=on|off]`

* `-m`设置虚拟机的内存大小。默认128MiB。
  - `-m [size=megs][,slots=n][,maxmem=size]`

* `-name <VM name>` 设置虚拟机的名称。
* `-uuid <uuid>`设置系统UUID。

**启动文件**

* `-kernel <bzImage>` 指定内核文件。

**显示设置**

* `-display {sdl|curses|none|gtk|vnc|egl-headless|spice-app}`
* `-nographic`设置

**网络设置**

* `-nic`
disk image是类似于linux.iso的系统镜像。




## 使用实例

* 

```shell
qemu-system-x86_64 arhchlinux-2021.12.01-x86_64.iso
```

```shell
qemu-system-x86_64 -name "Linux 3.10.14" 
```

```shell
qemu-system-x86_64 -nographic -name "Linux 3.10.14"
```


## 相关链接

* <http://t.zoukankan.com/hellogc-p-7482066.html>