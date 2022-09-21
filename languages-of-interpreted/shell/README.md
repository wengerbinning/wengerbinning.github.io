环境变量TERM标识终端类型：xterm、xterm-256color。xterm默认支持8色， xterm-256color默认支持256种颜色。可以通过`tput color`查看颜色


环境变量是操作系统中用来指定操作系统运行时的环境参数，环境变量通常以键值对存储。类似于命令参数，存储在用户空间。

* `PATH`：可执行文件的搜索路径。
* `SHELL`：当前shell程序。
* `TERM`：当前终端类型，决定一些程序的显示方式。
* `LANG`：语言和locale。
* `HOME`：当前用户的家目录。


在`stblib.h`中定义了管理环境变量的函数。

* `getenv()`
* `setenv()`
* `unsetenv()`
