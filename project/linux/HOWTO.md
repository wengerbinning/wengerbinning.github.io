

#### Host





```shell
#
make x86_64_defconfig

#
make menuconfig
#make ARCH=x86_64 CROSS_COMPILE=$CROSS_COMPILE menuconfig

```


```shell
#!/usr/bin/env bash

#
SOURCE_DIR=$(pwd)
DEST_PATH="$SOURCE_DIR/destdir"
INSTALL_HDR_PATH=""

#
make arm64_defconfig

#
# make menuconfig
make ARCH=arm64 CROSS_COMPILE=$CROSS_COMPILE menuconfig

#
make ARCH=arm64 headers_install INSTALL_HDR_PATH=$DEST_PATH

#
make -j4 ARCH=x86_64 CROSS_COMPILE=$CROSS_COMPILE
```