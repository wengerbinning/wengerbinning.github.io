lsinitcpio是基于shell实现管理initramfs的脚本工具。

## 使用说明

```
lsinitcpio [action] [options] <initramfs>
```

## 参数选项

* action

action

| short option | long option | value | comment |
|:--- |:--- |:--- |:--- |
| `-a` | `--analyze` | - | analyze contents of image |
| `-c` | `--config` | - | show configuration file image was built with |
| `-l` | `--list` | - |  list contents of the image (default) |
| `-x` | `-extract` | - | extract image to disk |

* options

| short option | long option | value | comment |
|:--- |:--- |:--- |:--- |
| `-n` | `--nocolor` | - | disable colorized output |
| `-h` | `--help` | - | display this help |
| `-v` | `--verbose` | - | more verbose output |
| `-V` | `--version` | - | display version information |

