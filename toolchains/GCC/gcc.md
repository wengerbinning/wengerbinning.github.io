



**options**


| short option | value | comment |
|:--- |:--- |
| `-c` | - |
| `-g` | - | 
| `-E` |
| `-S` |



## 使用示例


```c
//
gcc -o helloworld helloworld.c
//
gcc -g -o helloworld helloworld.c
```

**预处理**

GCC中的预处理器是cpp

* 生成预处理之后的文件。


```c
cpp helloworld.c > helloworld.i
```

```shell
# C
gcc -E -o helloworld.i helloworld.c
# C++
g++ -E -o helloworld.ii helloworld.cpp
```


**编译**

GCC中的编译器是cc1.

* 生成汇编文件。

```shell
# C
gcc -S helloworld.i -o helloworld.s
```

在GCC中cc1程序是将完成预处理与编译过程两个步骤。

```shell
# C
cc1 helloworld.c
# C++
cc1plus helloworld.cpp
# Java
jc1 helloworld.java
```

```shell
gcc -S -o helloworld.s helloworld.c 
```


**汇编**

GCC中的汇编器是as。

```shell
as -o helloworld.o helloworld.s 
```

```shell
gcc -c helloworld.s -o helloworld.o 
```


**库文件**

* 静态库

```shell
ar 
```


* 共享库

```shell
#
gcc -fPIC -c name.c
# 
gcc -shared -o libname.so name.o
```


```c
gcc -fPIC -shared -o libname.so name.c
```



**链接**

GCC中的链接器是ld

```shell

ld -static /usr/lib/crtl.o 
```





-static

-shared

-fPIC

-fpic

-fPIE

-fpie

