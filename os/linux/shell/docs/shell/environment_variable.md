# 环境变量



环境变量是方便管理的机制，其中最常用的变量是PATH，是可执行程序的查询目录；还有工作目录存储在PWD变量中。

## 查找环境变量

```shell
export
env
printenv
```

## 设置环境变量

```shell
export <variable_name>=<variable_value>
declare
set
env
```

## 删除环境变量

```shell
unset <variable_name>
```

## 管理配置文件

通过以上的命令只是本次执行生效，如果想要永久生效，需要修对对应的配置文件。source用于立即生效配置文件

* 所有用户：`/etc/profile`.

* 对于当前用户：`~/bash_profile`、`~/.bash_login`、`~/.profile`，前两个针对SHELL为bash的配置文件，如果shell为zsh，则有`.zshrc`.

* skel

**特殊的环境变量**

* `PATH`是shell用来搜索可执行文件的路径，通常为各个二进制文件的存放路径，多个路径通过`:`来区分。
* `TERM`是
  * `$-`记录但当前设置的shell选项，himBH是默认值，可以通过`set -x`来打开相应选项， `set +x`来
  关闭相应的选项。`set -o`可以查看当前shell的选项列表。 

h - hashall表示shell将命令所在路径记录下来，避免每次查询，
i - interactive-comments表示当前shell是一个交互终端，当执行脚本时是关闭该选项的。
m - monitor打开监控模式，通过job control控制进程。通过`Ctrl+Z`将进程移动到后台，jobs查看后台进程，`fg %1`将后台进程移动到前端。
B - braceexpand打开大括号扩展，可以使用大括号扩展来避免冗长路径。
H - history expand打开记录执行的命令的选项。命令记录在~/.bash_history。
x - xtrace



**pkg-config**

PKG_CONFIG_PATH指定搜索路经，优先级在默认搜索之前。

PKG_CONFIG_LIBDIR指定默认的搜索路经。

PKG_CONFIG_SYSROOT_DIR 指定pkg-config的逻辑根目录。




**GCC**





**程序加载时**

``
