# 文件管理

在Linux中有普通文件、目录文件、设备文件、链接文件、接口文件。

* 普通文件有纯文本文件、二进制文件、数据库文件等。-

    * 纯文本文件： 经过特定编码转化的文件，例如unicode、utf-8等，可以使用通过的文件编辑器打开、阅读与修改。
    * 二进制文件： 图片、音频、视频、可执行文件等。
    * 数据库文件： 该文件是需要经过特定的程序进行转化才能被我们使用。

* 目录文件是一类特殊的文件，可以包含其他文件和目录。d

* 设备文件有块设备文件与字符设备文件。c

    * 块设备文件成组的设备文件，例如磁盘通常以扇区为一个组，每一个扇区的大小相同。b
    * 字符设备文件直接操作二进制数据的文件，例如键盘，等。

* 链接文件： 使用软链接生成的文件，使用硬链接生成的文件与源文件的属性相同。

* 接口文件一般指socket文件，网络间的通信 s



以上这些文件的类型可以通过ls -l来查看，其格式如下：

```shell

$: ls -l
drwxr-xr-x  # 目录文件
-rw-r--r--  # 普通文件
crw-rw-r--  # 字符设备文件
brw-rw-r--  # 块设备文件
lrwxr-xr--  # 链接文件
srw-rw-rw-  # socket文件

```


为了便于系统管理与软件开发，一些人共同指定了Linux文件系统标准(FSSTND,Filesystem Standard)，
该标准逐渐演化为文件系统层次标准(FHS,Filesystem Hierarchy Standard)。可以帮助用户更加容易
管理与开发。


## 文件查找

```shell
whereis
which
find
locate
```


* 文件的权限：一般文件的权限有rwx三种，在特殊情况下有一些文件具有特殊的权限，例如/usr/bin/passwd具有setuid权限，setuid只对文件有效，其次是setgid只对目录有效，sticky bit只对文件有效，当文件具有x权限时，这些特殊权限以小写形式出现，否则以大写形式出现。


一些特殊的文件

* .sock
* .pid是一个文件文件，保存进程的pid,防止进程启动多个副本，只有具有特定pid文件的写入权限的进程才能正启动，并将自身pid写入文件。
* .\*rc




## 文件管理

* 【功能】新建文件:

  ```shell
  # 新建一个空的文件。
  touch <file>
  # 通过重定向的方式创建文件。
  echo <content>  > <file>
  # 创建一个硬链接文件。
  ln <sources file> <object>
  # 创建一个软连接文件，创建软连接的可执行文件不能被执行。
  ln -s <source_file> <object>
  # 创建一个目录。
  mkdir <directory>
  ```

* 【功能】查看文件:

  ```shell
   # 查看文件内容。
  cat <file>
  # 从最后一行开始显示。
  tac <file>
  # 带行号显示文件。
  nl <file>
  # 格式化显示文本内容。
  printf <format string> <content>
  # 分页查看文件内容。
  more <file>
  # 分页查看文件内容，可以前翻。
  less <file>
  # 显示文件的头部，默认显示头部10行内容。
  head <file>
  # 显示文件的尾部。
  tail <file>
  # 以二进制的方式显示
  od  <file>
  # 统计文件字节数、行数、字数。
  wc -clw <file>
  export                  # 显示环境变量
  ls                      # 显示目录下的所有内容;
  stat                    # 详细显示文件或目录信息;
  pwd                     # 显示工作目录
  diff                    # 比较两个文件
  # 根据路径显示文件名。
  basename <path>
  # 根据文件名显示路径。
  dirname <file>
  size                    # 查看二进制文件的内存信息。
  ```

* 【功能】修改文件:

  ```shell
  chgrp <groupname> <filename>       # 修改文件所有者所在组
  chown <user name>:<group name> <file name>        # 修改文件所有者
  chmod <number> <filename>          # 修改文件属性
  # 使用字符串替换的方式批量修改文件名。
  rename <oldstring> <newstring> <file>
  # 转换文件编码格式。
  iconv <source file> -f <source type> -t <goal type> -o <goal type>
  # 将文件的制表符转换为空白字符。
  expand -t 4 <file>
  # 将文件的空白字符转换为制表符。
  unexpand -t 4 <file>
  # 将文本转化为适合打印的格式。
  pr -h <title> -l <line> <file>
  # 将文件内容以字符为单位反序输出。
  rev <file>
  ```

* 【功能】复制文件:

  ```shell
  cp <sourcefilename> <objectfilename>     # 复制文件
  cp -r <sourcefilename> <objectfilename>  # 复制目录
  ```

* 【功能】移动文件:

  ```shell
  mv <sourcefilename> <objectfilename>    # 移动或重命名
  cd <WorkingDirectory>                   # 切换工作目录
  ```

* 【功能】删除文件:

  ```shell
  rm <filename>                           # 移除文件或目录;
  rmdir <directoryname>                   # 删除空目录
  rm -r <directoryname>                   # 删除目录及其子目录;
  # 检查和删除重复内容
  uniq -cdu <file>
  # 删除文件，不能删除目录。
  unlink <file>
  ```

* 【功能】文件查询：

  ```shell
  find <filename>                    # 查找文件,不常使用,对硬盘有损伤
  find / -name "*.c"                 # 发现根目录下的所有c文件
  which <filename>                   # 查找文件,查找$PATH中的内容
  whereis <filename>                 # 查找文件,在数据库中寻找,使用updatedb更新数据库
  locate <filename>                  # 查找文件,同上
  grep <filename>
  ```

* 【功能】其他操作：

  ```shell
  # 创建或更新slocate数据库文件。
  updatedb
  ```

在远距离的文件传输中,经过压缩后再传输会节省很多资源,常用的解压软件有`compress`与`tar`;在Linux中`tar`是常用的压缩工具。

* 【功能】压缩文件:

  ```shell
  tar -cvf <*.tar> <filename>                 # 仅打包文件
  tar -czvf <*.tar.gz> <filename>             # 以gzip方式压缩并打包
  tar -cjvf <*.tar.bz2> <filename>            # 以bzip2方式压缩并打包
  ```

  > Note: -c参数为打包文件，-z参数是以gzip的方式压缩文件，-j参数是以bzip2的方式压缩文件，-v参数是显示过程，-f <package name>为指定包文件。

* 【功能】解压文件:

  ```shell
  tar -xvf <*.tar>  <path>                    # 解包
  tar -xzvf <*.tar.gz> <path>                 # 以gzip方式解压并解包
  tar -xjvf <*.tar.bz2> <path>                # 以bzip2方式解压
  ```

  > Note: -x为解压文件。
  



dev
===

/dev/console 系统控制台
/dev/tty    系统控制终端
/dev/null   空设备，写入内容会被丢弃。

proc
====


/proc/modules 已加载的内核模块的相关信息。




# 文件系统

整个文件系统需要从底层到上层经历：存储介质、磁盘驱动、通用驱动层、文件系统、虚拟文件系统、系统调用、应用程序。

## 通用驱动层

*存储技术设备（MTD，Memory Technology Device）

## 文件系统

在Linux中，文件是存储在块屋里设备上的，每一个存储设备可以定义多种格式的文件系统（类似于分区概念）序列组成，每一个文件系统由引导块、超级块、索引块以及数据块组成，引导块是存放引导程序，超级块是存放文件系统的管理信息，索引块是存放文件索引的地方，数据块是存放文件的地方。

* MINIX：

* 扩展文件系统（EXT，extended file system）:是Linux的文件系统。EXT默认为EXT4.

  * EXT2：
  * EXT3：
  * EXT4：

* 日志闪存文件系统2(jffs2，Journalling Flash File System v2)：jffs是瑞典Axis Communications公司基于Linux 2.0 kernel开发的为嵌入式系统开发的，而jffs2是Redhat基于jffs2开发的闪存文件系统。基于MTD的主要用于NOR类型的文件系统。

* (yaffs/yaffs2，Yet Another Flash FIle System)：

* (cramfs,Compressed ROM FIle System)：是由Linus参与开发的一种只读的压缩文件系统。

* romfs:

* ramdisk:

* ramfs/tmpfs:

* nfs,Network File System:

* 文件配置表（FAT，File Allocation Table）：Microsoft开发的文件系统，现在FAT默认为FAT32.

  * FAT12：最大支持32MB的分区。
  * FAT16：采用32bit的簇地址，
  * FAT32：采用32bit的簇地址，但是仅使用低位的28bit，所以最大容量约为8.7TB，在实际使用不超过32GB的容量，单个文件最大不超过4GB。
  * VFAT：

* squashfs:是基于Linux kernel 的压缩只读文件系统。

* proc:
* sysfs：基于内存的文件系统，挂载于/sys.
* tmpfs:是基于内存的文件系统

## 虚拟文件系统

虚拟文件系统（VFS，Virtual FIle System）是通过对下层的文件系统进行统一封装，对上层提供统一的访问接口，例如mount、umount、open，close、mkdir等。

## devfs
<!-- develop author: Richard Gooch -->
设备文件系统(devfs)是v2.4引入的文件系统。

## udev

udev作为一个devfs的替代方案在v2.6中引入， 用户态udev通过接收netlink来发送uevent事件来创建设备文件节点

## sysfs

系统文件系统(sysfs)是在v2.6引入的文件系统， 该文件系统用于提供一个系统硬件的层级视图。来展示设备驱动模型中各组件的层次关系


* udev

* mdev




ntfsd是一个特殊的文件系统，用于控制linux nfs server.







