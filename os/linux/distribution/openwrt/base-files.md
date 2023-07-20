base-files


## 模块文件

```txt
files/
files/bin/
files/etc/
files/lib/
files/rom/
files/sbin/
files/usr/
image-config.in
Makefile
```

## 模块依赖



## 模块编译

### Makfile

#### 模块依赖

变量依赖

* TOPDIR
* INCLUDE_DIR
* COMMITCOUNT
* PLATFORM_DIR
* GENERIC_PLATFOEM_DIR


#### 全局变量

* PKG_NAME
* PKG_FLAGS
* PKG_RELEASE
* PKG_FILE_DEPENDS
* PKG_BUILD_DEPENDS
* PKG_LICENSE
* PKG_CONFIG_DEPENDS

#### 宏变量

* Package/base-files
* Package/base-files/conffies
* Package/base-files/description
* ImageConfigOptions
* Build/Prepare
* Build/Compile/Default
* Package/base-files/install

* Build/Configure
* Package/base-files/install-key
* Package/base-files/nand-support 
* Package/base-files/emmc-support
* Package/base-files/legacy-sdcard-support

```Makefile
Build/Compile = Build/Compile/Default

$(eval $(call BuildPackge, base-files))
```






## 编译目标







