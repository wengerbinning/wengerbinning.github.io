
# 调试器

调试器是用来调试程序的工具，现有的调试器包括gdb、kgdb、xxgdb、mxgdb、ddd、ups等，这里以gdb作为主要调试工具。gdb提供高层的符号调试（根据源码来分析程序）以及
底层的调试（根据可执行程序来分析）。使用调试器可以控制与监控程序，同时提供检查core文件。

核心文件是在程序执行过程中出现严重错误时创建的文件，该文件包含发生错误时该程序和系统的状态信息；核心文件是由计算机内存的转储构成，为节省计算机的磁盘空间，核心文件
可能没有被保存，需要手动使用ulimit开启。

在调试的程序之前，需要确认该程序是包含符号表并在编译过程中使用`-g`参数来生成一些调试所需的额外信息。符号表包含程序中用到的所有变量的名称和它们相关值的列表，如果
没有符号表，将不能现实变量的值与类型；没有使用`-g`参数，gdb将不能用行好来识别源码。


根据未剥离符号表的程序文件以及产生的core文件进行gdb调试。gdb命令会根据命令树来确定命令，例如backtrace，输入ba，bt就可以调用，即使用命令唯一字符子集就可以识别。

```shell
gdb pragram core
```

通用寄存器：

* `pc`: 指令寄存器，指向下一条执行的命令，在当前命令加载时更新。
* `sp`:
* CS: 
* SS:
* BS:
* EX:
* FS:
* GS:

* RSI
* RDI
* RBP
* RSP：保存栈顶地址的寄存器。
* RIP: 保存当前执行指令的地址的寄存器。




**基础调试**



```gdb
# 根据行号添加断点。

(gdb) break 16

# 根据函数名添加断点。

(gdb) break main

# 运行程序。

(gdb) run

# 程序继续运行。(直到遇到断点)。

(gdb) continue

# 单步调试（不进入函数）。

(gdb) next

# 单步调试（进入函数）。

(gdb) step
```

**寄存器相关**

```gdb
# 显示所有寄存器。


```

**变量相关**

```gdb
# 设置变量的打印是格式化后的。

(gdb) set print pretty on

# 通过变量名来打印内容。（后面可以跟字面值）

(gdb) print <variable name>

# 通过变量名来打印变量类型。

(gdb) ptype <variable name>

# 打印局部变量。

(gdb) info local

# 监视变量。

(gdb) watch <variable name>


```


**栈帧相关**

```gdb
# 显示程序栈帧列表。

(gdb) backtrace

# 跳转指定栈帧。（index是栈帧列表前的序号）

(gdb) frame <index>

# 进入下层栈帧。(按照栈帧列表的序号递减)

(gdb) down

# 进入上层栈帧。(按照栈帧列表的序号递增)

(gdb) up

# 显示当前栈帧的信息。

(gdb) info frame
```

**共享库相关**

```gdb
# 显示当前程序依赖的共享库的加载状态。

(gdb) info sharedlibrary 

# 设置逻辑根目录。(一般在交叉编译时使用)

(gdb) set sysroot <sysroot path>

# 显示当前的逻辑根目录。

(gdb) show sysroot

# 设置共享库搜索目录的前缀路径（必须是绝对目录）。

(gdb) set solib-absolute-prefix <prefix path>

# 显示当前搜索库目录的前缀路径。

(gdb) show solib-absolute-prefix

# 设置共享库的搜索路径。

(gdb) set solib-search-path <search path>

# 显示共享库的搜索路径。

(gdb) show solib-search-path
```

**源码相关**

```gdb
# 显示源码文件的搜索路径。

(gdb) show directories

# 将源码路径加入搜索列表。没有source code path参数时恢复默认的搜索列表。

(gdb) directory [<source code path>] 

# 显示当前源码。

(gdb) list
```


**汇编相关**

```gdb
# 指定函数进行反汇编。

disassemble /m <function name>

```

**远程调试**


使用gdbserver进行远程调试，一般在嵌入式上进行调试，这里将嵌入式设备称之为目标主机，控制调试的设备(一般为我们的PC)成为监控主机。

首先在目标主机中通过gdbserver启动程序。

```shell
# 启动待调试的程序。(这里192.168.3.20为目标主机的IP地址，/usr/sbin/helloworld -r start是调试程序的路径与启动参数。)

gdbserver 192.168.3.20:2000 /usr/sbin/helloworld -r start
```


然后在监控主机的启动gdb并设置远程目标。

```shell
aarch64-linux-gnu-gdb helloworld
```

```gdb
# 设置运行程序的远程目标主机。(192.168.3.21是目标主机的IP地址)，开启远程调试后已经启动程序，无需再次启动。

target remote 192.168.3.21：2000
```



size <file path> 打印程序静态大小