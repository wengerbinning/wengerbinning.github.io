



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








gcc是一个GCC项目中的一个编译器
s


## OPTIONS

### Option Summary

<!-- Here is a summary of all the options, grouped by type. Explanations are in the following sections. -->
以下是按类型分组的所有选项的摘要。 解释在以下部分中。


#### Linker Options

* -nolibc
* -pthread
* -static
* -static-pie
* -static-libgcc
* -static-libstdc++
* -static-libasan
* -static-libtsan
* -static-liblsan
* -static-libubsan
* -shared
* -shared-libgc
* -symbolic
* -Xlinker
* -Wl, *option*


 ### Options for Linking

<!-- These options come into play when the compiler links object files into an executable output file. They are meaningless if the compiler is not doing a link step. -->
 这些选项在编译器链接目标文件时发挥作用 成一个可执行的输出文件。如果 编译器没有执行链接步骤。

#### -l *library*

Search the library named library when linking.

#### -shared

<!-- Produce a shared object which can then be linked with other objects to form an executable.Not all systems support this
option. For predictable results, you must also specify the same set of options used for compilation(-fpic, -fPIC, or model 
suboptions) when you specify this linker option. -->
生成一个共享对象，然后可以与其他对象链接以形成可执行文件。并不是所有的系统都支持该选项。为了获得可预测的结果，您还必须指定用于编译的同一组选项（
-fpic、-fPIC 或 模型子选项）当您指定此链接器选项时。



 #### -Wl, *option*

 <!-- Pass *option* as an option to the linker.  If option contains commas, it is split into multiple options at the commas.  
You can use this syntax to pass an argument to the option. For example, -Wl,-Map,output.map passes -Map output.map to the
linker. -->
 将选项作为选项传递给链接器。如果选项包含 逗号，它在逗号处被分成多个选项。你 可以使用此语法将参数传递给选项。例如，`-Wl, -Map, output.map`
 将传递参数 `-Map output.map` 给链接器。