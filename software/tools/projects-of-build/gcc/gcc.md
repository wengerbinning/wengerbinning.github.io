  # gcc

## 基本参数

```shell
# 指定编译语言：c,objective-c,c-header,c++,cpp-output,assembler,assembler-with-cpp.或者为none，则取消之前设定的语言指定，开启默认的智能识别（根据文件后缀名。
-x <programming language>
# 预处理源文件。
-E
# 预处理时不删除注释信息。
-S
# 编译成汇编文件，即*.s.
-C
# 汇编成二进制文件，即*.obj。
-c <file name>
# 生成可执行文件
-o <file name>
# 包含一些文件。
-include <file name>
# 指定头文件搜索目录
-I <directory>
# -I-
# -idurafter dir
# -iprefix prefix
# -iwithprefix dir
# 生成文件关联的信息。
-M
#－ＭＭ
# -MD
# -MMD
# 指定搜索库的路径
-L <directory>
# 用于指定库路径下的库。
-l
# 编译器优化
-O {0,1,2,3}
# 在编译时产生调试信息。
-g

# 定义一个宏
-DDEBUG

# 取消一个宏
-UDEBUG

```

## 生成库文件

静态库是*.a;动态库是*.so,都是由*.o文件生成的。

* 生成动态库：

  ```shell
  gcc -fPIC -shared hotplug.c -o libusb.so `pkg-config --libs --cflags libusb-1.0`
  ```
* 使用ar生成静态库：

  ```shell
  ar -rt libtest.a test.o demo.o
  ar cr libtest.a demo.o test.o
  # -r 在库中插入模块，存在时替换。
  # -c 创建一个库，
  # -s 创建文件索引，ranlib可以为无索引的库添加索引。
  # 显示库中的模块。
  ar tv libdemo.a
  # 显示库的索引表。
  mn -s lib.a

  # 使用静态库：
  gcc -o main -L/lib -ltest -g main.c
  ```

* 使用gcc生成动态库：在使用动态库是需要将库的路径加入`LD_LIBRARY_PATH`变量中.

  ```shell
  # 使用fPIC标签生成*.o文件。
  gcc -fPIC -c demo.c
  # 传递 -shared标签给gcc
  gcc -shared libtest.so demo.o
  ```












  * 预处理是处理元文件中的预处理指令，使用`gcc -E`或`cpp`预处理器可以生成预处理后的文件，也称为编译。

```shell
gcc -o hellworld.i -E hellworld.c
```

```shell
cpp helloworld.c > helloworld.i
```

* 编译是将预处理之后的文件编译生成汇编文件，使用`gcc -S`或`cc1`编译器可以实现编译过程。

编译过程经过了词法分析、语法分析、语义分析以及优化等几个过程。将其他编程语言编写的代码转化为汇编代码。

```shell
gcc -o helloworld.s -S helloworld.i
```

* 汇编是将汇编代码转化为二进制序列的过程，通过`gcc -c`或`as`汇编器来实现汇编过程。

```shell
gcc -o helloworld.o -c helloworld.s
```

* 链接是将各模块的二进制序列组装成一个可执行程序的路过程，通过`gcc`或`ld`链接器实现链接过程。

```shell
gcc -o helloworld helloworld.o
```


* 编译时包含符号表。

```shell
gcc -g -o helloworld helloworld.c
```




## 程序

根据编译器不同的参数，可以编译出适用于不同计算机的程序；而大多数64位的计算机同时可以运行32位计算机的程序，为了方便，将适用于64位计算机的程序称为64位程序，将适用于32位的程序称为32位程序。

```shell
# 编译成32位程序。
gcc -m32 <file.c>
# 编译成64位程序。
gcc -m64 <file.c>
```
