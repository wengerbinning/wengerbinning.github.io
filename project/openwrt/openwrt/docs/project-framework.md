




## Common

#### include/debug.mk
#### include/depends.mk
#### include/toplevel.mk
#### include/subdir.mk

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

#### Makefile

* rule world

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
* rule .PHONY



#### target/linux

define Target/Description
define Device/*






#### package/boot

#### package/kernel

* linux

#### package/firmware

#### package/feeds
