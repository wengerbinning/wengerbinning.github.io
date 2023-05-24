The contents of the root filesystem must be adequate to boot, restore, recover, and/or repair the system.

* To boot a system, enough software and data must be present on the root partition to mount other filesystems.
  This includes utilities, configuration, boot loader information, and other essential start-up data. 
  /usr, /opt, and /var are designed such that they may be located on other partitions or filesystems.

* To enable recovery and/or repair of a system, those utilities needed by an experienced maintainer to 
  diagnose and reconstruct a damaged system must be present on the root filesystem.

* To restore a system, those utilities needed to restore from system backups (on floppy, tape, etc.) 
  must be present on the root filesystem.

| denery | optional | comments |
|:--- |:---:|:--- |
| /boot/ | | Static files of the boot loader |
| /include/ | 1 | |
| /lib/ | | Essential shared libraries and kernel modules |
| /bin/ | | 	Essential command binaries |
| /sbin/ | | Essential system binaries |
| /usr/ | 1 | Secondary hierarchy |
| /proc/ | |
| /sys/ | |
| /dev/ | | 	Device files |
| /etc/ | | Host-specific system configuration |
| root/ |
| /home/ | 1 |
| /opt/ |
| /media/ |
| /mnt/ |
| /tmp/ |
| /var/ |
| /run/ |
| /srv/ |

### boot

This directory contains everything required for the boot process except configuration files not needed at boot time and the map installer. 
Thus /boot stores data that is used before the kernel begins executing user-mode programs. This may include saved master boot sectors and sector map files.

### bin

/bin contains commands that may be used by both the system administrator and by users, but which are required when no 
other filesystems are mounted (e.g. in single user mode). It may also contain commands which are used indirectly by scripts.

There must be no subdirectories in /bin. The following commands, or symbolic links to commands, are required in /bin:

| command | descripotion | 
|:---:|:--- |
| [ |
| [[ |
| cat |
| chgrp |
| chmod |
| chown |
| cp |
| date |
| dd |
| df |
| dmesg |
| echo |
| false |
| hostname |
| kill |
| ln |
| login |
| ls |
| mkdir |
| mknod |
| more |
| mount |
| mv |
| ps |
| pwd |
| rm |
| rmdir |
| sed |
| stty |
| su |
| sync |
| true |
| umount |
| uname |

| command | descripotion | 
|:---:|:--- |
| csh |
| ed |
| tar |
| cpio |
| gzip |
| gnuzip |
| zcat |
| netstat | 
| ping | 

### sbin








## LINKS

* <https://refspecs.linuxfoundation.org/FHS_3.0/fhs/ch03.html>