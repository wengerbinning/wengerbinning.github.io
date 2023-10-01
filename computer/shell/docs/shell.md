# Shell


Shell是Linux的终端控制程序，是处理计算机与人之间交互的程序；在众多的shell中，bash是大多
Linux发行版本默认shell。zsh是我喜欢的shell。

shell是一个命令解释器，建立了用户和操作系统之间的接口，当用户输入一条命令后，shell对命令进行解析，
然后调用相应的程序来执行。这些命令根据是否是shell程序内部支持可以分为内部命令与外部命令，而且shell
解释程序有bash,tcsh等。

命令行工具是可以在终端执行的软件，这些工具可以分为shell内置的命令与第三方的命令。

## 基础语法


shell是用户与操作系统进行交互的接口。是一个命令解释器。shell存在多种，例如bash、tcsh、zsh。
在shell中，在按下回车后会对当前输入进行解释执行。


在shell中有一下几个快捷键

Ctrl + H, 删除字符。
Ctrl + W, 删除一个单词。

Ctrl + U，删除一行
Ctrl + X，





Ctrl + Z, 挂起任务。
Ctrl + C, 终止任务。

除此之外，也可以通过stty来设定自己的快捷键。


-----

Linux存在详细的联机文档。


以下一些Linux的工具：
* less
* man

* info



### 分支结构

#### 条件判断




* 循环结构: 重复执行某段代码;

```bash
#!/bin/bash

now=`date+'%Y%m%d%H%M'`
deadline=`date --date='1 hour'+'%Y%m%d%H%M'`
# while 循环语句
while [$now -lt $deadline]
do  # while 隶属代码
    date
    echo "not yet"
    sleep 10
    now=`date+'%Y%m%d%H%M'
done
#for 循环语句: 执行'ls log*'语句,并以空格分割,之后依次赋值给var,并执行for隶属代码
for var in `ls log*`
do  #for 隶属代码
    rm $var
done
# 构建空格分割文本
MT7615((i=1;i<=5;i++))
do
    each $i
done
# seq生成等差数列
seq 1 2 10   # 第一个参数为起始,第二个参数为步长,第三个参数为终止
let 'index++'   # 标识index自增一个单位

for var1 in `seq 1 2 10`
do
 echo $var1
done
# break 可以跳出当前循环结构,continue跳出本次循环

# 无线循环
while :   # 等价于 while true
do
    <content>
done

for (( ; ; ))





如果执行命令后不想输出结果,则可以将输出重定向到`/dev/null`中,`/dev/null`中的内容都会被丢弃.

### 文件的包含

文件的包含用于在一个文件中使用另一个文件代码内容,通常以`. <shellfilename>`(顿号与文件之间的空格不可省略)或`source <shellfile>`来包含.

```bash

. ./bashfile

source bashfile
```

## 工具集合

### date

date是shell进行时间运算的工具

```shell
# 使用YYYY/mm/dd HH:MM:SS的格式操作。
date +"%Y/%m/%d %H:%M:%S"
```
### nc

nc是用来设置路由信息的工具。

* TCP端口扫描：

  ```shell
  # nc -v -z -w2 <ip> <port>
  nc -v -z -w2 192.168.0.3 1-100
  ```

* UDP端口扫描：
  
  ```shell
  # nc -u -z -w2 <ip> <port>
  nc -u -z -w2 192.168.0.3 1-100
  ```

* 扫描指定端口：

  ```shell
  nc -nvv 192.168.0.1 80
  ```

### tr

（tr，translate）工具主要用于压缩重复字符、删除文件中的控制字符以及进行字符转换操作。

```shell
# 替换重复字符串
tr -s str_1 str_2
# 删除字符
tr -d str_1
# 字符替换
tr -t str_1 str_2
# 字符集替补
```

### awk

awk是一个处理文本的工具。是由Alfred Aho， Peter Weinberger & Brian Kernighan开发。

```shell
# @#:
# @#:
# @#:
# @#:

# usage A: awk [<POSIX or GNU style options>...] -f <progfile> [--] <file>...
# usage B: awk [<POSIX or GNU style options>...] [--] <program> <file>...

# option
#     -f
#     -F
#     -v
#     -b
#     -c
#     -C
#     -d
#     -D
#     -e
#

# 通过自定义命令对输入文件进行处理。
awk {cat} <file>
# 通过指定脚本来执行。
awk -f <script> <file>
# 通过指定字符对输入文件进行分割
awk -F ',' <command> <file>

```

### cut
-------------------------------------------------------------------------------

```shell
# @#: cut
# @#:
# @#:
# @#:
# usage: cut <option>... [<file>...] 

# option:
#     -b, --bytes
#     =<byte list>:
#     -c, --characters=<charscter list>:
#     -d, --delimiter=<delimiter>:
#     -f, --fields=<field list>:
#     -n: ignored
#     -s, --only-delimited:
#     -z, --zero-terminated:
#     --complement:
#     --output-delimiter=<string>:
#     --help
#    --version
```

### sed

sed是采用流编辑模式的文本编辑器，sed会根据流规则来编辑文本。sed默认不会修改源数据而是将数据复
制到缓存区。每次仅处理一行数据，处理完后再处理下一行。

* 使用格式说明：

  ```shell
  # @#: sed执行的结果将默认保存在缓存区，并不会直接修改源文件。如果没有指定-e与-f参数，则默
  # @#: 认将第一个非选项参数作为sed脚本，其他非选项参数作为输入文件，如果为输入文件，则读取
  # @#: 标准输入。如果有多个sed command script，每一个sed command可以使用-e参数，或者使
  # @#: 用semicolon。当然对于a,c,i这几个sed command由于其特殊性，后面不能跟semicolon，
  # @#: 所以只能使用-e参数，获将该command放在最后。
  # usage: sed [<option>...] <sed command script> [<input file>...]
 
  # option:
  #    -n, --quiet, --silent:　抑制匹配模式的自动打印，即只输出匹配到的结果。
  #    -e <script>, --expression=<script>: 将脚本添加到执行的命令中。
  #    -f <script file>, --file=<script file>: 将脚本文件添加到执行的命令中。
  #    -i[<suffix>]， --in-place[=suffix]: 将直接修改源文件，如果提供后缀将进行备份,提
  #        示:后缀与-i参数直接相连，中间没有空格。
  #    -l <N>, --line-length=<N>: 为 'l' 命令指定所需的换行长度,默认70个字符换行。
  #    -E, -r, --regexp-extend: 在脚本中使用正则表达式扩展。
  #    -s, --separate: 将文件视为单独的而不是单个、连续的长流。 
  #    -u, --unbuffered: 从输入文件加载最少量的数据并更频繁地刷新输出缓冲区。
  #    -z, --null-data: 用 NUL 字符分隔行。
  #    -b, --binary: 使用二进制模式打开文件。
  #    --debug: 注释程序执行，即对输出结果进行说明。
  #    --follow-symlinks: 就地处理时遵循符号链接。
  #    --posix: 禁用所有的GNU扩展。
  #    --sandbox: 在沙箱模式下运行（禁用 e/r/w 命令）。
  #    --help: 显示帮助信息。
  #    --version: 显示版本信息。

  # sed command script: [<line address>]<sed command>
  #     line address: 是一个可选的行地址，可以是单行地址，多行地址以及正则表达式。
  #         a single line number:
  #         a range of lines:
  #         a regular expression:
  #     sed command:
  #         a\<text>， a <text>: 在行后添加text。
  #         b: (@!)无条件分支到标签。 标签可以省略，在这种情况下开始下一个循环。
  #         c\<text>, c <text>:  使用text替换行。
  #         d: 删除匹配内容，直接进入下一个循环。
  #         D: (@!)如果模式空间包含换行符，则删除模式空间中直到第一个换行符的文本，并使用结
  #            果模式空间重新开始循环，而不读取新的输入行。
  #         e [<command>]: 没有command时，执行在模式空间中找到的命令并用输出替换模式空
  #             间； 尾随换行符被抑制。有command时，执行命令并将其输出发送到输出流。 该命
  #             令可以跨多行运行，除最后一行以外的所有行都以反斜杠结尾。 
  #         F: 打印当前输入文件的文件名（带有尾随换行符）。
  #         g: 用保持空间的内容替换模式空间的内容。
  #         G: 将换行符附加到模式空间的内容，然后将保持空间的内容附加到模式空间的内容。
  #         h: (hold) 用模式空间的内容替换保持空间的内容。
  #         H: 将换行符附加到保持空间的内容，然后将模式空间的内容附加到保持空间的内容。
  #         i\<text>, i <text>: 在一行前插入文本。
  #         l: 以明确的形式打印模式空间。
  #         n: 如果没有禁用自动打印，则打印模式空间，然后无论如何用下一行输入替换模式空
  #             间。 如果没有更多输入，则 sed 退出而不处理任何更多命令。
  #         N:向模式空间添加一个换行符，然后将输入的下一行附加到模式空间。 如果没有更多输
  #             入，则 sed 退出而不处理任何更多命令。
  #         p: 打印模式空间。
  #         P: 打印模式空间，直到第一个 <newline>.
  #         q[<exit code>]: 退出 sed 而不处理任何命令或输入。 
  #         Q[<exit code>]: 此命令与q相同，但不会打印模式空间的内容。与q一样，它提供了向
  #             调用者返回退出代码的能力。
  #         r <filename>: 读取文件名。
  #         R <filename>: 在当前循环结束时或读取下一个输入行时，将一行要读取的文件名排队
  #             并插入到输出流中。
  #         s/<regular expression>/<replace string>/[<flags>]:（替代）将正则表达式
  #             与模式空间的内容进行匹配。 如果找到，用替换替换匹配的字符串。
  #             flags:
  #                 p: 打印替换后的结果。
  
  #                 <number>: 替换第几次匹配到的字符。有效范围1~512
  #                 g:替换全局所有的匹配字符。
  #                 w <filename>: 将替换后的结果写入文件。
  #         t <label>, T <label>: （测试）仅当自读取最后一个输入行或采用条件分支以来没有
  #             成功替换时才分支到标签。 标签可以省略，在这种情况下开始下一个循环。
  #         v [<version>]: (version) 此命令不执行任何操作，但如果不支持 GNU sed 扩展
  #             或请求的版本不可用，则会使 sed 失败。
  #         w <filename>: 将模式空间写入文件名。
  #         W <filename>: 将模式空间的一部分写入给定的文件名，直到第一个换行符
  #         x: 交换保留空间和模式空间的内容。
  #         y/<src string>/<dst string>: 将模式空间中与任何源字符匹配的任何字符与目标
  #             字符中的相应字符进行音译。
  #         z: (zap) 该命令清空模式空间的内容。
  #         #: 一条评论，直到下一个换行符。
  #         {<cmd>;...}:将多个命令组合在一起。
  #         =: 打印当前输入行号（带有尾随换行符）。
  #         :label: 指定分支命令的标签位置 (b, t, T)。

  # regular :
  #      \s: 表示

  # exit status： 除了以下标准的返回代码，还可以使用q或者Q指定返回代码。
  #     -0： 成功执行。
  #     -1： 语法错误。
  #     -2： 文件不能打开。
  #     -4： IO错误。
  ```

### grep

grep可以用于字符串匹配


* 正则匹配字符：




bc： 一个计算机工具

obase = 2 # 设置输出为2进制
ibase = 10 # 设置输入为10进制
{<username>|<uid>}

###

`<command>&`表示命令在后台运行， Ctrl+Z也会将前台运行的进程移动到后台执行，jobs会显示当前所有的进程以及进程编号，通过`fg %<index>`将后台的进程移动到前台，`bg %<index>`会将前台进程移动到后台 
----



## 转移序列

转移序列是由转移字符(Escape character)和其他字符组成的字符串，在bash中转移字符通常是`^[`、`\e`、`\033`、`\x1B`

ANSI/VT100转义序列


`[0m`取消所有效果
`[1m`粗体
`[2m`瘦体
`[3m`斜体
`[4m`下划线
`[5m`闪烁
`[7m`反色
`[8m`隐藏

* 8/16颜色控制代码与终端类型有关

前景色

`[39m`
`[30m`
`[31m`
`[32m`
`[33m`
`[34m`
`[35m`
`[36m`
`[37m`
`[90m`
`[91m`

背景色


* 88/256颜色控制字符




* `echo`是shell内置的命令，用于显示内容。

echo具有以下参数

  `-e`打开转移序列的开关    







---------
使用exec可以用来打开一个文件并指定一个文件描述符

```shell
# 使用文件描述符3指定到log.txt文件。
exec 3>>log.txt

echo comment >&3

``` 




## SHELL内置的命令

* `echo`
* `type`是一个识别命令类型的命令通过`type <command>`可以识别命令是内置还是第三方。
* `wait`是一个等待工作完成并返回结构的命令。


## 第三方命令

与系统管理有关的命令有

* `hostname`
* `date`
* `uname`
* `script`

关于文件管理的基础命令有

* `touch`
* `mkdir`
* `ls`
* `cp`
* `mv`
* `rm`
* `tr`
* `od`
* `cat`
* `cut`
* `sed`
* `less`
* `more`
* `head`
* `tail`
* `sort`
* `grep`
* `uniq`
* `diff`
* `file`

与文件归档与压缩有关的命令

* `tar`

* bzip2
* bunzip2
* bzcat
* bzip2recover
* gzip
* gunzip
* zcat
* compress

与打印机有关的命令有

* `lpr`
* `lpq`
* `lprm`


与基础办公有关的工具

* `bc`

与跨平台有关系的命令

* `unix2dos`
* `dos2unix`

与账户管理有关的命令

* `w`
who
finger

write
mesg

与命令定位与查询有关的命令

which
whereis
* `apropos`可以使用关键字来搜索工具，需要使用数据库whatis,有makewhatis工具来维护。
* `slocate`slocate是locate的安全版本。

----------------------------------
shell处理命令，tty驱动设备检查每一个字符，当按下回车，驱动将字符缓存区的字符传递给shell来处理。

----------------------------------
在shell的命令中，语法格式大致类似，具体格式的细节需要根据具体命令来使用。一般命令的由命令与参数构成。
在参数中有一类特殊的参数称为选项，一般是带有前缀的-或者--，来指定命令的执行方式。各个参数之间使用空格
分割，在选项中可以将多个合并到一起。一般通过--来表示选项的结束，参数的开始。


----------------------------
重定向(redirection)是改变shell原有的标准输入等。使用

```shell
# 
ls > text
