


```
mkinicpio [options]
```



| short option | long option | value | comment |
|:--- |:--- |:--- |:--- |
| `-A` | `--addhooks` | hooks |  Add specified hooks, comma separated, to image |
| `-c` | `--config` | config | Use alternate config file. (default: /etc/mkinitcpio.conf) |
| `-g` | `--generate` | path | Generate cpio image and write to specified path |
| `-h` | `--help` | - | Display this message and exit |
| `-k` | `--kernel` | kernel version | Use specified kernel version (default: 5.19.9-arch1-1) |
| `-r` | `--moduleroot` | dir path |  Root directory for modules (default: /) |
| `-p` | `--preset` | file | Build specified preset from /etc/mkinitcpio.d |



* 


```
mkinitcpio --generate initramfs-linux-v5.19.6.img -p etc/mkinitcpio.d/linux.preset -c etc/mkinitcpio.conf  -r /home/wenger/repos/wengerbinning/mirrors/rootfs/initramfs/linux-v.5.19.6
```