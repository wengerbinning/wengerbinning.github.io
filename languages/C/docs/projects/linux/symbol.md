
## ubi-user.h

### 导入模块

* linux/types.h

### 预处理宏

* UBI_VOL_NUM_AUTO
* UBI_DEV_NUM_AUTO
* UBI_MAX_VOLUME_NAME

* UBI_IOCMKVOL
* UBI_IOCRMVOL
* UBI_IOCRSVOL
* UBI_IOCRNVOL
* UBI_IOCRPEB
* UBI_IOCSPEB
* UBI_IOCATT
* UBI_IOCDET
* UBI_IOCVOLUP
* UBI_IOCEBER
* UBI_IOCEBCH
* UBI_IOCEBMAP
* UBI_IOCEBUNMAP
* UBI_IOCEBISMAP
* UBI_IOCSETVOLPROP
* UBI_IOCVOLCRBLK
* UBI_IOCVOLRMBLK

* MAX_UBI_MTD_NAME_LEN
* UBI_MAX_RNVOL

### 数据类型

* struct ubi_mkvol_req
* struct ubi_rsvol_req
* struct ubi_rnvol_req
* struct ubi_leb_change_req
* struct ubi_map_req
* struct ubi_set_vol_prop_req
* struct ubi_blkcreate_req

### 数据对象

### 函数接口



ubidetach -m 6
nand eraseall /dev/mtd6
ubiformat /dev/mtd6 -y
ubiattach -m 6

ubimkvol /dev/ubi1  -N kernel -s 17MiB -t static
ubirmvol /dev/ubi1 -n 0
ubimkvol /dev/ubi1  -N rootfs -s 10MiB -t dynamic



##

