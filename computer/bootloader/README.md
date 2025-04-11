bootloader是系统加载之前的一段代码，负责初始化过程

#### ATF(Arm Trusted Firmware)

权限等级(Exception Level)
------------------------

按照递增权限越高.

* EL0: User applications.
* EL1: Operating System.
* EL2: Hypervisor.
* EL3: Low-level Firmware.



启动顺序(BootLoader Stage)
-------------------------

* BL1(EL3): Architectural initialization
* BL2: Platform initialization
* BL30: System Control Processor Firmware
* BL31: EL3 Runtime Firmware
* BL32: Secure-EL1 Payload(optional)
* BL33: Non-trusted Firmware



ARM Fixed Virtual Platforms(FVPs)

#### BL1

#### BL2
#### BL31
#### BL32(optional)
#### BL33


#### FIT(Flattened Image Tree)


#### FIP()

##### V1

PHY MEMORY



#### V2

FBL(Flash Bootloader)
SBL(Secondary Bootloader)





**通用电脑**

BIOS

grub




**嵌入设备**


uboot






## LINKS

* <https://docs.u-boot.org/en/latest/#>
* <https://lists.denx.de/listinfo/u-boot>

* <https://chromium.googlesource.com/external/github.com/ARM-software/arm-trusted-firmware/+/v0.4-rc1/docs/firmware-design.md>
* <https://ohwr.org/project/soc-course/wikis/ARM-Trusted-Firmware-(ATF)>
* <https://xilinx-wiki.atlassian.net/wiki/spaces/A/pages/18842107/Arm+Trusted+Firmware>
* <https://software-dl.ti.com/processor-sdk-linux/esd/docs/06_03_00_106/linux/Foundational_Components_ATF.html>
* <https://community.arm.com/support-forums/f/embedded-and-microcontrollers-forum/49353/exception-levels-linux-booting-in-general-with-atf-but-not-implementing-trustzone-v8>