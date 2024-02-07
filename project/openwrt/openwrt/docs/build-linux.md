
平台厂商
设备平台
设备厂商
设备型号


linux是以平台厂商、设备平台进行分类管理的。





* scripts/patch-kernel.sh

```
./scripts/patch-kernel.sh $
```



* GENERIC_PLATFORM_DIR := $(TOPDIR)/target/linux/generic

* GENERIC_FILES_DIRx
* GENERIC_BACKPORT_DIR
* GENERIC_PATCH_DIR
* GENERIC_HACK_DIR

* FAILES_DIR
* PATCH_DIR





#### quilt.mk

* define PatchDir
* define Kernel/Patch/Default

#### kernel-defaults.mk

* define Kernel/Patch
* define Kernel/CopyImage

* define Kernel/Prepare/Default
* define Kernel/Configure/Default
* define Kernel/CompileModules/Default
* define Kernel/CompileImage/Default
* define Kernel/Clean/Default

#### kernel-build.mk

* define Kernel/Prepare
* define Kernel/Configure
* define BuildKernel



BuildKernel ->  Kernel/Prepare -> Kernel/Prepare/Default -> Kernel/Patch -> Kernel/Patch/Default