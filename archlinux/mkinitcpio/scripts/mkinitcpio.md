mkinitcpio基于shell实现的用于更新或创建initramfs的工具。

## 使用说明

```
mkinitcpio [options]
```

## 参数选项

* options 

| short option | long option | value | comment |
|:--- |:--- |:--- |:--- |
| `-A` | `--addhooks` | hooks | Add specified hooks, comma separated, to image |
| `-c` | `--config` | config | Use alternate config file. (default: /etc/mkinitcpio.conf) |
| `-g` | `--generate` | path of initramfs img | Generate cpio image and write to specified path |
| `-H` | `--hookhelp` | hook name | Display help for given hook and exit |
| `-h` | `--help` | - |  Display this message and exit |
| `-k` | `--kernel` | kernel version | Use specified kernel version (default: 5.19.4-arch1-1) |
| `-L` | `--listhooks` | - |  List all available hooks |
| `-M` | `--automods` | - | Display modules found via autodetection |
| `-n` | `--nocolor` | - |  Disable colorized output messages |
| `-p` | `--preset` | file |  Build specified preset from /etc/mkinitcpio.d |
| `-P` | `--allpresets` | - | Process all preset files in /etc/mkinitcpio.d |
| `-r` | `--moduleroot` | dir |  Root directory for modules (default: /) |
| `-S` | `--skiphooks` | hooks |  Skip specified hooks, comma-separated, during build |
| `-s` | `--save` | - | Save build directory. (default: no) |
| `-d` | `--generatedir` | dir | Write generated image into dir |
| `-t` | `--builddir` | dir |  Use DIR as the temporary build directory |
| `-D` | `--hookdir` | dir | Specify where to look for hooks |
| `-U` | `--uefi` | path |  Build an UEFI executable |
| `-V` | `--version` | - |  Display version information and exit |
| `-v` | `--verbose` | - |  Verbose output (default: no) |
| `-z` | `--compress` | program | Use an alternate compressor on the image |

当使用`-U`选项时存在以下拓展选项。

| short option | long option | value | comment |
|:--- |:--- | :--- |:--- |
| - | `--cmdline` | path | Set kernel command line from file (default: /etc/kernel/cmdline or /proc/cmdline) |
| - | `--microcode` | path | Location of microcode |
| - | `--osrelease` | path |  Include os-release (default: /etc/os-release) |
| - | `--splash` | path | Include bitmap splash |
| - | `--kernelimage` | path | Kernel image |
| - | `--uefistub` | path | Location of UEFI stub loader |


