


#### Board

include $(TOPDIR)/rules.mk
var ARCH
var BOARD
var BOARDNAME
var SUBTARGETS
var FEATURES
var KERNEL_PATCHVER
define Target/Description
include $(INCLUDE_DIR)/target.mk
DEFAILT_PACKAGES
call BuildTarget

#### SubTarget

var SUBTARGET
var BOARDNAME
var FEATURES
var CPU_TYPE
var KERNALNAME
var IMAGES_DIR
var DEFAULT_PACKAGES
define Target/Description
