交叉编译中需要先生成交叉编译链工具，在生成gcc编译链工具需要编译linux头文件、binutils、gcc以及glibc

 

* `--build`指定编译这个项目的编译器是在什么机器与平台，即在什么平台编译；
* `--host`指定编译后的程序在什么平台使用，即在什么平台运行；
* `--target`指定构建的程序将来在编译其他项目时的结果在什么平台运行，默认与host相同，即编译的结果可以编译什么平台的程序。

`binutils`包含二进制相关的程序，例如objdump、strip等;gcc是包含各种语言的编译器程序;glib是C语言的标准库，可以更换为其
他类似的库：glibc、EGlib、uClibc等以及newlib、detlibc等。

并且工具链中一般包含内核头文件，作为库与计算机的桥梁。gcc一般与glibc相互依赖。所以在C99中定义了两种实现gcc的实现方式:
hosted与freestandig，hosted支持完整的C标准，包括语言标准与标准库，freestanding仅支持完整的语言标准。binutil是gcc
与glibc都需要的，并且binutils不依赖其他库。


CLFS=/mnt/clfs


CLFS_FLORT=soft
CLFS_FPU=

CLFS_HOST=x86_64-cross-linux-gnu
CLFS_TARGET=arm64-linux-musleabi
CLFS_ARCH=arm64
CLFS_ARM64_ARCH=

## Linux 头文件编译

```shell

```


