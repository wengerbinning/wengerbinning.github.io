



* tools
* toolchain
* target/linux
* package/*
* image/*[.]





## Table

Makefile
rules.mk

inlcude/debug.mk
include/depends.mk
include/toplevel.mk
include/subdir.mk
include/download.mk
include/feeds.mk
include/rootfs.mk
include/image.mk
include/image-commands.mk
include/version.mk

inlude/autotools.mk
inlcude/cmake.mk
include/meson.mk
include/

include/toolchian.mk

include/prepare.mk
include/prereq-build.mk
inlcude/host-build.mk


include/target.mk

include/u-boot.mk
include/kernel.mk
include/kernel-defaults.mk
include/kernel-version.mk
include/trusted-firmware-a.mk
include/package.mk
include/package-defaults.mk
include/package-bin.mk
include/package-module.mk
include/package-dumpinfo.mk
inllude/package-ipkg.mk

include/netifilter.mk
include/nsl.mk

## Verbose

##### Makefile

export TOPDIR LC_ALL LANG TZ
export ORIG_PATH PATH
var empty space
var DISTRO_PKG_CONFIG
import STAGING_DIR OPENWRT_BUILD
rule world
if OPENWRT_BUILD != 1
    export OPENWRT_BUILD=1 GREP_OPTIONS CDPATH
    include $(TOPDIR)/include/debug.mk
    include $(TOPDIR)/include/depends.mk
    include $(TOPDIR)/include/toplevel.mk
else
    include $(TOPDIR)/rules.mk
    include $(INCLUDE_DIR)/depends.mk
    include $(INCLUDE_DIR)/subdir.mk
    include $(TOPDIR)/target/Makefile
    include $(TOPDIR)/package/Makefile
    include $(TOPDIR)/tools/Makefile
    include $(TOPDIR)/toolchain/Makefile
end
rule $(toolchain/stamp-compile)
rule $(target/stamp-compile)
rule $(package/stamp-compile)
rule $(package/stamp-install)
rule $(target/stamp-install)
rule check: $(tools/stamp-check) $(toolchain/stamp-check) $(package/stamp-check)
tagret printdb
rule prepare
tagret _clean: FORCE
rule clean: _clean
rule targetclean: _clean
rule dirclean: targetclean clean
rule toolchian_rebuild_check
rule cacheclean
rule tmp/.prereq_packages: .config
rule prereq
rule $(BIN_DIR)/profiles.json: FORCE
rule json_overview_image_info:  $(BIN_DIR)/profiles.json
rule checksum: FORCE
rule buildversion: FORCE
rule feedsversion: FORCE
rule diffconfig: FORCE
rule buildinfo: FORCE
rule prepare: .config $(target/stamp-compile) $(package/stamp-compile)  $(package/stamp-install) $(target/stamp-install) FORCE
rule .PHONY: clean dirclean prereq prepare world package/symlinks package/symlinks-install package/symlinks-clean

#### include/debug.mk

import DUMP DEBUG_SCOPR_DIR
if DUMP == NULL
    var build_debug
end
define debug
define warn
define debug_eval
define warn_eval

#### include/depends.mk

var DEP_FINDPARAMS find_md5 find_md5_reproducible
define rdep

#### include/topdevel.mk

var PREP_MK OPENWRT_BUILD QUIET
export IS_TTY
include $(TOPDIR)/include/verbose.mk
extern SDK

if $(SDK) == 1
    include $(TOPDIR)/include/version.mk
else
    var REVISION SOURCE_DATE_EPOCH
end

export REVISION SOURCE_DATE_EPOCH
extport GIT_CONFIG_PARAMETERS GIT_ASKPASS
export MAKE_JOBSERVER
export GNU_HOST_NAME HOST_OS HOST_ARCH
var SUBMAKE
var IGNORE_PACKAGES

rule prepare-tmpinfo: FORCE
extern CONFIG_HAVE_DOT_COFNIG
rule .config: ./scripts/config/conf

rule scripts/config/%conf: FORCE
call rdep scripts/config script/config/mconf
rule config:scripts/config/conf prepare-tmpinfo FORCE
rule config-clean: FORCE
rule defconfig: scripts/config/conf prepare-tmpinfo FORCE
rule oldconfig: scripts/config/conf prepare-tmpinfo FORCE
rule menuconfig: scripts/config/mconf prepare-tmpinfo FORCE
rule nconfig: scripts/config/nconf prepare-tmpinfo FORCE
rule xconfig: scripts/config/qconf prepare-tmpinfo FORCE
rule prepare_kernel_conf: .config toolchain/install FORCE
rule kernel_oldconfig: prepare_kernel_conf
rule kernel_menuconfig: prepare_kernel_conf
rule kernel_nconfig: prepare_kernel_conf
rule kernel_xconfig: prepare_kernel_conf
rule kernel_xconfig: prepare_kernel_conf
rule printdb: FORCE
rule download: .config FORCE
rule clean dirclean: .config
rule prereq: prepare-tmpinfo .config
rule check: .config FORCE
rule val.%: FORCE
rule %::

rule package/symlinks
rule package/symlinks-install
rule package/symlinks-clean

rule distclean:
rule help:



#### include/kernel.mk



#### inlcude/scan.mk

include $(TOPDIR)/include/verbose.mk
include $(TOPDIR)/rules.mk
var TMP_DIR
rule all: $(TMP_DIR)/.$(SCAN_TARGET)
var SCAN_TARGET SCAN_NAME SCAN_DIR
var TARGET_STAMP FILELIST OVERRIDELIST
rule $(TARGET_STAMP)::
rule $(TMP_DIR)/.$(SCAN_TARGET): $(TARGET_STAMP)
define PackageDir
rule $(OVERRIDELIST)
rule $(FILELIST): $(OVERRIDELIST)
rule $(TMP_DIR)/info/.files-$(SCAN_TARGET).mk: $(FILELIST)
rule $(TARGET_STAMP)::
rule $(TMP_DIR)/.$(SCAN_TARGET): $(TARGET_STAMP)


#### include/package.mk

rule all:
include $(INCLUDE_DIR)/download.mk
var PKG_BUILD_DIR PKG_INSTALL_DIR PKG_BUILD_PARALLEL PKG_SKIP_DOWNLOAD
var MAKE_J PKG_SOURCE_DATE_EPOCH PKG_JOBS

define pkg_build_flag

include $(INCLUDE_DIR)/hardening.mk
include $(INCLUDE_DIR)/prereq.mk
include $(INCLUDE_DIR)/unpack.mk
include $(INCLUDE_DIR)/depends.mk
var QUILT
include $(INCLUDE_DIR)quilt.mk
var find_library_dependencies

var PKG_DIR_NAME
var STAMP_NO_AUTOREBUILD
var PREV_STAMP_PREPARED

var STAMP_PREPARED
var STAMP_CONFIGURED
var STAMP_CONFIGURED_WILDCARD
var STAMP_BUILT
var STAMP_INSTALLED

var STAGING_FILES_LIST
define CleanStaging
var PKG_INSTALL_STAMP

include $(INCLUDE_DIR)/package-defaults.mk
include $(INCLUDE_DIR)/package-dumpinfo.mk
include $(INCLUDE_DIR)/package-ipkg.mk
include $(INCLUDE_DIR)/package-bin.mk
include $(INCLUDE_DIR)/autotools.mk


var PKG_CONFIG_PATH

define Build/Autoclean
define Build/Prepare/Default
define Build/Exports/Default
var Build/Exports
define Build/CoreTargets
define Build/DefaultTargets
define pkg_install_files
defile pkg_install_bin

define BuildPackage


var Build/Prepare
var Build/Configure
var Build/Compile
var Build/Install
var Build/Dist
var Build/DistCheck

#### rules.mk

var CFLAGS
var ARCH ARCH_PACKAGES BOARD SUBTARGET
var TARGET_OPTIMIZATION TARGET_SUFFIX
var BUILD_SUFFIX SUBDIR BUILD_SUBDIR NPROC
define shvar
define file_copy
define sha256sums
define commitcount
rule all:
rule check:
rule val.%:
rule var.%:

