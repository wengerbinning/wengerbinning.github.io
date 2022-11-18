
genisoimage别名mkisofs。


```
genisoimage [options] -o <image iso file> <dir>... 
```


## 

| options | value | comment |
|:--- |:--- |:--- |
| `-b` |
| `-c` |
| `-volset` | volume set id | Specifies the volume set ID.  There is space for 128 characters. |
| `-V` | volume id | Specifies the volume ID (volume name or label) to be written into the master block. There is space for 32 characters. |




## 使用示例

* 

```shell
mkisofs -o image.iso path
```


```shell
mkisofs -V
```


```log
wenger@ubuntu:~/labs$ ls -al
total 12
drwxr-xr-x  3 wenger wenger 4096 Nov  6 22:28 .
drwxr-xr-x 17 wenger wenger 4096 Nov  6 22:23 ..
drwxr-xr-x  2 wenger wenger 4096 Nov  6 22:24 cabinet-linux
wenger@ubuntu:~/labs$ mkisofs -V "Cabinet Linux" -o cabinet-linux.iso cabinet-linux/
I: -input-charset not specified, using utf-8 (detected in locale settings)
Total translation table size: 0
Total rockridge attributes bytes: 0
Total directory bytes: 68
Path table size(bytes): 10
Max brk space used 0
174 extents written (0 MB)
wenger@ubuntu:~/labs$ isoinfo -d -i cabinet-linux.iso
CD-ROM is in ISO 9660 format
System id: LINUX
Volume id: Cabinet Linux
Volume set id:
Publisher id:
Data preparer id:
Application id: GENISOIMAGE ISO 9660/HFS FILESYSTEM CREATOR (C) 1993 E.YOUNGDALE (C) 1997-2006 J.PEARSON/J.SCHILLING (C) 2006-2007 CDRKIT TEAM
Copyright File id:
Abstract File id:
Bibliographic File id:
Volume set size is: 1
Volume set sequence number is: 1
Logical block size is: 2048
Volume size is: 174
NO Joliet present
NO Rock Ridge present
wenger@ubuntu:~/labs$ ls -al
total 360
drwxr-xr-x  3 wenger wenger   4096 Nov  6 22:28 .
drwxr-xr-x 17 wenger wenger   4096 Nov  6 22:23 ..
drwxr-xr-x  2 wenger wenger   4096 Nov  6 22:24 cabinet-linux
-rw-r--r--  1 wenger wenger 356352 Nov  6 22:28 cabinet-linux.iso
wenger@ubuntu:~/labs$
```



## 相关链接

* <https://diabloneo.github.io/2022/05/19/iso9660-and-genisoimage-command/>