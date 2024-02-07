

##

```
# level 1
make world

# level 2 for world
make tools/compile
make toolchain/compile
make target/compile
make buildinfo
make package/cleanup
make package/compile


# level 3 for tools
make tools/{flock,xz,sed,tar,patch,m4,autoconf,autoconf-archive,pkgconf,automake}/compile
make tools/{missing-macros,libtool,flex,bison,bc,libressl,ninja,cmake}/compile
make tools/{dosfstools,e2fsprogs,fakeroot,findutils,zlib}/compile
# level 3 for toolchain
make toolchain/{gdb,binutils,gcc/initial,kernel-headers,musl,gcc/final,fortify-headers}/compile
# level 3 for target
make target/{linux}/compile
# level 3 for package
make package/libs/{libjson-c,libubox,}/host-compile
make package/system/{opkg}/host-compile
make package/libs/{toolchain,libnl-tiny,libjson-c}/compile
make package/utils/lua/compile
make package/libs/libubox/compile
make package/system/{ubus,uci}/compile
make package/utils/ucode/compile
make package/libs/udebug/compile
make package/network/config/netifd/compile
make package/firmware/linux-firmware/compile
make package/kernel/{gpio-button-hotplug,linux}/compile
make package/system/ubox/compile
make package/libs/{ncurses}/host-compile
make package/libs/{zlib,ncurses}/compile
make package/utils/{util-linux,mtd-utils,fstools}/compile
make package/utils/fwtools/{host-compile,compile}




```


## Scripts

#### scripts/timestamp.pl

```
```





## Common

#### include/debug.mk

* var build_debug
* define debug
* define warn
* define debug_eval
* define warn_eval


#### include/depends.mk
#### include/toplevel.mk


#### include/subdir.mk

* define PrepareStaging
* rule $(STAGING_DIR)/.prepared
* rule $(STAGING_DIR_HOST)/.prepared
* define subdir
* define stampfile

#### include/image.mk

* define Image/BuildDTB/sub
* define Image/BuildDTB
* define Image/BuildDTBO

* define Device/Build/dtb
* define Device/Build/dtbo

* define Device/Build/initramfs
* define Device/Build/kernel
* define Device/Build/compile
* define Device/Build/image
* define Device/Build/artifact
* define Device/Build
* define Device/Dump
* define Device

* define BuildImage

#### include/quilt.mk

* define filter_series

* define PatchDir/Quit
* define PatchDir/Default
* define Patchdir

* define HostPatchDir
* define Host/Patch/Default
* define Build/Patch/Default
* define Kernel/Patch/Default

* define Quit/RefreshDir
* define Quit/Refresh/Host
* define Quit/Refresh/Package
* define Quit/Refresh/Kernel
* define Quit/Template

* define Build/Quit
* define Host/Quit




#### include/kernel-build.mk

* define BuildKernel


#### include/image.mk

* BuildImage

#### rules.mk

* var TMP_DIR TMPDIR
* var ARCH ARCH_PACKAGES
* var BOARD SUBTARGET
* var SUBDIR BUILD_SUBDIR
* var NPROC
* var SHELL

* var CP LN XARGS BASH TAR FIND PATCH PYTHON TRUE FALSE
* var INSTALL_BIN INSTALL_SUID INSTALL_DIR INSTALL_DATA INSTALL_CONF

* define shvar
* define shexport
* defined






#### target/linux

define Target/Description
define Device/*






#### package/boot

#### package/kernel

* linux

#### package/firmware

#### package/feeds



#### target/Makefile

* var curdir $(cutdir)/subtargets
* var $(curdir)/builddirs  $(curdir)/builddirs-default
* var $(curdir)/builddirs-install  $(curdir)/sdk/install  $(curdir)/imagebuilder/instal
* call stampfile $(curdir), target, prereq, .config
* call stampfile $(curdir), target, compile, $(TMP_DIR)/.build
* call stampfile $(curdir), target, install, $(TMP_DIR)/.build
* call subdir, $(subdir)

#### Makefile

* rule world

* rule $(toolchain/stamp-compile)
* rule $(target/stamp-compile)
* rule $(package/stamp-compile)
* rule $(package/stamp-install)
* rule $(target/stamp-install)

* rule check
* rule printdb
* rule prepare
* rule _clean
* rule clean
* rule targetclean
* rule dirclean
* rule toolchian_rebuild_check
* rule cacheclean
* rule $(BUILD_DIR)/.prepared
* rule tmp/.prepareq_package
* rule prereq
* rule $(BIN_DIR)/profiles.json
* rule json_overview_image_info
* rule checksum
* rule buildversion
* rule feedsversion
* rule diffconfig
* rule buildinfo
* rule prepare
* rule world
