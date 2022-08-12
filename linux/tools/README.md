本目录下记录了Linux环境下的工具集，有些工具集是在Windows与MacOS兼容会在工具描述中说明。主要分为
构建项目的工具与工具两大类，

## 项目构建

在项目构建中，最基础的是编译链工具，其次是基于编译链工具的各种描述编译规则的工具。

### toolchain



### GNU Make

GNU Make通常简称make工具，是一个用于控制如何编译项目的工具

### GNU M4

m4是UNIX宏处理的一个实现。

### Automake

automake是一个自动生成Makefile.in的工具。

### Autoconf

autoconf是一个m4的宏包。


### GNU Libtool


### CMake


### Waf

https://waf.io/apidocs/tutorial.html

### 

## 项目调试

## 账户管理


可以使用write在同一主机的不用终端间发送消息，使用wall来向所有终端进行广播信息，使用mesg来禁止当前
终端收到信息。


## 网络管理


## 服务管理












GNU gcc是Linux上常用的C编译器
环境变量：

CPPFLAGS一般用于指定预处理的参数

```
CPPFLAGS="-DNODEBUG"
```

> Note: NODEBUG是一个标准的ANSI宏，表示不进行调试编译

CFLAGS一般用于指定头文件查找路径。

```
CFLAGS=“-I./include”
```

LDFLAGS一般用于指定链接器搜索共享库的路径。

```
LDFLAGS=“-L./lib”
```

LIBS一般用于指定依赖库。

```
LIBS="-lssl"
```

LD_LIBRARY_PATH一般用来指定搜索路径，近来使用LD_RUN_PATH

GCC参数的使用

* -D参数用于在编译时声明一个宏。一般有两种用法。

直接指定宏名，相当于`#define DEBUG`

```shell
gcc -DDEBUG
```

另一种用法是指定值的用法，相当于`#define LOG_LEVEL=1`

```shell
gcc -DLOG_LEVEL=1
```

* -O参数用于指定优化级别,共有5种优化级别

  1. -O0 默认等级。
  2. -O1 基本优化。
  3. -O2 推荐优化。
  4. -O3 最高优化。
  5. -Os 优化代码尺寸。

* -Wp用于将参数传递给预处理器。
* -Xpreprocessor

* -Wa用于将参数传递给汇编器。
* -Xassembler

* -Wl用于将参数传递给链接器。
* -Xlinker

* -pipe指定使用管道而不是中间文件


* -f系列参数

  1. `-fpic`与`-fPIC`作用于编译阶段，PIC(position independent code)，使编译期生成与位置无关的动态链接，即实现共享库的独立，在每一个程
      序使用该共享库时，实现代码共享，而不是维护一个库的镜像。在生成共享库时，推荐使用该参数。都是为了在动态库中生成位置无关的代码。
      通过全局偏移表（GOT）访问所有常量地址。程序启动时动态加载程序解析。推荐使用`-fPIC`。-fPIC与-fpic都是在编译时加入的选项，
      用于生成位置无关的代码(Position-Independent-Code)。这两个选项都是可以使代码在加载到内存时使用相对地址，所有对固定地址的访问都通      过全局偏移表(GOT)来实现。-fPIC和-fpic最大的区别在于是否对GOT的大小有限制。-fPIC对GOT表大小无限制，所以如果在不确定的情况下，使       用-fPIC是更好的选择。

  2. `-fno-caller-saves`

  3. `-fhonour-copts`

  4. `-fhonour-copts`

  5. `-fpie`与`-fPIE`相同，与PIC与pic相同，但是用于生成可执行文件。

  6. `-ffunction-sections`指示gcc将每个函数(包括静态函数)放在自己的名为.text.function\u name的节中，而不是将所有函数放在一个大的.text      节中.

  7. `-fdata-sections`它放置每个全局或静态变量到 .data.variable_name、.rodata.variable_name 或 .bss.variable_name


* -m系列参数

  1. `-march=`指定目标文件的系统平台
  2. `-mcpu=`指定cpu架构。

* -g系列参数用于配置调试器选项。

  1. 

## 编译警告

在gcc中包含了lint的很多特性，可以识别许多存在问题的语句。这些可以使编译器更加严格的选项都是以`W`(Warning)标识的参数。以下为一些选项及所检查的问题。

<!-- lint是C程序验证器，但是在Linux中没有lint,只有splint -->

* `-Wimplicit`没有显式的声明函数或者参数。
* `-Wreturn-type`返回值出错，需要显式给定返回值。
* `-Wunused`变量声明之后未使用。
* `-Wcomment`在注释中出现`/*`字符，`/*`作为注释的开始标识，不能在出现在注释中。
* `-Wformat`某些输入输出语句所包含的格式说明与参数不匹配。
* `-Wall`检查以上所有警告。




自动构建工具
===========

autoconf、cmake工具是用来检测并生成配置文件的工具，


autoconf
-------
autoscan
autoupdate
autoheader
autoconf
autoreconf
ifnames
autom4te


automake
------
aclocal
automake




* autoscan将对整个项目进行扫描来搜索普通的可移植性问题，例如检查编译器、库、头文件、
结构体等，最终生成configure.scan，该文件是configure.ac（早期使用configure.in）的一
个雏形。在生成之后需要修改为configure.ac并根据项目添加自定义内容。

[//]: # (该命令执行后需要修该configure.ac，并可能定义自己的宏)

* aclocal会根据已经安装的宏、用户自定义的宏、acinclude.m4文件中的宏将configure.ac文件
中所需要的宏集中定义在aclocal.m4中，该文件是一个perl脚本程序。

* autoheader根据configure.ac中的一些宏，运行m4来生成一个autoconfig.h.in文件。

[//]: # (在执行下面之前，需要在每一个源码目录中编写Makefile.am)

* automake将根据Makefile.am中定义的接口建立一个Makefile.in

* autoconf将configure.ac中的宏展开，生成一个configure脚本，

```shell
autoreconf --install --force
```


AM_LIBS 
AM_LFLAGS




autogen.sh是一个自动执行autoconf与automake的脚本。
























