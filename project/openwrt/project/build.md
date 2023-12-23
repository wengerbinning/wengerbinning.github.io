


* 更新所有的软件包

```shell
./scripts/freeds update -a
```

* 安装所有的软件包

```shell
./scripts/freeds install -a
```

* 配置openwrt

```shell
make menuconfig
```

* 编译

```shell
make
#
# make V=s
```


* 编译单个模块

```shell
make package/openssl/clean
make package/openssl/compile
make package/openssl/install
```



## Makefile

* world
* buildversion
* feedsversion
* diffconfig
* prepare





#### toplevel

* oldconfig
* menuconfig
* nconfig
* xconfig


#### host-build.mk

* Host/Comfigure
* Host/Compile
* Host/Install

#### package.mk

* BuildPackage
* Build/Prepare
* Build/Configure
* Build/Compile
* Build/Install
* Build/Dist
* Build/DiskCheck


#### meson.mk

* Meson/CreateNativeFile
* Meson/CrateCrossFile
* Host/Configure/Meson
*

#### openssl

* Build/Configure
* Build/Compile

* Package/openssl/Default
* Package/openssl/Default/description

* Package/libopenssl
* Package/libopenssl/config
* Package/libopenssl/description


