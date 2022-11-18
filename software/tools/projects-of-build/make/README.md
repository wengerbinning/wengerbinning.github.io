# make

makes是一个自动化构建工具，有GNU make, BSN make, GNUStep make， Borland make等，这些工具间不兼容，所以这里以Linux中最常用的GUN make作为学习目标。
make会根据Makefile中的规则，判断目标文件与依赖文件的修改时间，如果依赖文件中存在较新的修改，则执行该条规则中的构建命令，否则不执行。因此make会保持所有的
目标文件比其所依赖的文件更加新，该工具的主要学习内容是Makefile的规则编写。

Makefile由变量、规则以及注释组成。makefile的注释由`#`来标识。每一条规则有目标文件、依赖文件以及构建指令组成。make会默认执行第一条规则。


## 宏

在make中支持宏功能，可以创建与使用宏功能。宏在一些教程中合并到变量中，实际内容需要你自己选择。

```Makefile
CC = gcc
CPPFLAGS =
CFLAGS = -fPIC -pipe
LDFLAGS =
LIBS = 
```

在这些宏中有一些宏需要我特别注意一下。

* `CC`

* `CPPFLAGS`

* `FLAGS`

* `LDFLAGS`

## 变量

变量是由字母及下划线组成，在变量的赋值中有四种基本的赋值方式。简单赋值`:=`只对当前语句有效，递归赋值`=`对所有变量有效，条件赋值`?=`变量未定义是赋值，追加赋值`+=`在原来变量值后增加新值

* 变量定义

```makefile
OBJ = main.o type.o

$(OBJ)
${OBJ}
```

变量可以使用`$(<variable name>)`与`${<variable name>}`来使用变量。

* 环境变量是优先级最高的变量，会覆盖makefile中定义的变量并且在所有Makefile中共享变量。也可以使用make的参数来提供环境变量

```Makefile
CC=gcc
CFLAGS="-I/usr/include -I/include"

export CC CFLAGS
```

通过参数来提供环境变量。

```shell
make CC=gcc CFLAGS="-I/usr/include -I/include"
```

* 自动变量

  1. `MAKEFLAGS`变量会在调用子目录时执行
    
    ```Makefile
    # This is top makefile.
    MAKEFLAGS:=-rR
    all: 
        cd sub module && $(MAKE)    
    ````
    
    在调用子模块时，会自动使用-w参数。

    ```Makefile
    # This is sub module.
    all:
        @echo $(MAKEFILE)
    ```

* 模式变量


在Makefile中存在一些特殊的目标，同时存在两个相同目标，后面的会覆盖前面的目标来执行


* `all`

* `install`

* `dist`发布版本

* `.PHONY`是一个伪目标，也称为标签，指定依赖目标是一定会被执行，防止在项目中出现与目标同名的文件时该目标无效的问题。

* `FORCE`是一个伪目标，没有依赖与命令，所以当FORCE作为依赖是总会被执行。

* `clean`主要清除目标文件与可执行文件。

* `distclean`主要清除与发布版本有关的文件，包含Makefile与configure等。

* 空目标是伪目标的变种用来记录上一次执行此规则定义命令的时间。和伪目标不同的是：
这个目标可以是一个存在的文件，一般文件的具体内容我们并不关心，通常此文件是一个空文件。
空目标文件命令部分都会使用“touch”在完成所有命令之后来更新目标文件的时间戳，记录此规则
命令的最后执行时间。 make 时通过命令行将此目标作为终极目标，当前目录下如果不存在这个文
件，“touch”会在第一次执行时创建一个空的文件（命名为空目标文件名）。空命令的唯一作用是防止make在执行时，试图为重建这个目标去查找隐含命令



## 规则

在Makefile中，每一条规则都是由目标文件、依赖文件以及构建指令组成。这些规则又可以分为明确的规则、模糊的规则以及一些特殊的规则等。

* 明确的规则是目标文件、依赖文件以及构建指令共同组成，可以使用变量替代某些内容。

每一条明确的规则包含目标文件、依赖文件以及构建指令。目标文件与依赖文件之间以`:`分隔，目标文件通常只有一个、依赖文件可以有多个并使用空格分隔（将目标文件爱你与
依赖文件所在的行称为依赖行）；构建指令在依赖行之后并以`tab`作为起始，可以存在多行。

```Makefile
# 根据event.o、message.o 、log.o来构建logger文件。
logger：event.o message.o log.o
    gcc -o logger event.o message.o log.o
    echo "logger has built."
```


## 函数

wildcard

## LINKS

[GNU make](https://www.gnu.org/software/make/manual) 是GNU项目中一个子项目.

