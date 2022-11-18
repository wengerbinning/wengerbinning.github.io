stty是一个管理终端设备的工具。

* stty工具的的使用格式

```
stty [<options>] [<settings>]

usage A: 
    stty [-F DEVICE | --file=DEVICE] [SETTING]...

usage B:
    stty [-F DEVICE | --file=DEVICE] [-a | --all] 

usage C:
    stty [-F DEVICE | --file=DEVICE] [-g | --save]
```

* options

| short option | long option | value | introduction |
|:--- |:--- |:--- |:--- |
| `-a` | `--all` | - | print all current settings in human-readable form |
| `-g` | `--save` | - | print all current settings in a stty-readable form |
| `-F` | `--file` | /dev/console | open and use the specified DEVICE instead of stdin |
| - | `--help` | - | display this help and exit |
| - | `--version` | - | output version information and exit |


* settings

特殊字符的设置

| special characters | value | introduction |
|:--- |:--- |:--- |
| discard | ^O | This char will toggle discarding of output |
| eof | ^D | This char will send an end of file (terminate the input) |
| eol | - | This char will end the line |
| eol2 | - | The alternate char for ending the line |
| erase | ^? | This char will erase the last character typed |
| intr | ^C |  This char will send an interrupt signal |
| kill | ^U | This char will erase the current line |
| lnext | ^V | This char will enter the next character quoted |
| quit | ^\ | This char will send a quit signal |
| rprnt | ^R | This char will redraw the current line |
| start | ^Q | This char will restart the output after stopping it |
| stop | ^S | This char will stop the output |
| susp | ^Z | This char will send a terminal stop signal |
| swtch | - | This char will switch to a different shell layer |
| werase | ^W | This char will erase the last word typed |

特殊设置

| key | value | intruduction |
|:--- |:--- |:--- |
| - | N | Set the input and output speeds to N bauds |
| cols | N | Tell the kernel that the terminal has N columns |
| conlums | N | same as cols |
| 



Input Settings

Output settings

| key | value | intruduction |
|:--- |:--- |:--- |
| bs | N | |
| cr | N | |
| ff | N | |
| nl | N | |
| `-ocrnl` | - | |

```shell
```