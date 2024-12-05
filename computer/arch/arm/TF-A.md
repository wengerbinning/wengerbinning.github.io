
TZ(Trust Zone)
ATF(Arm Trusted Firmware)


PSCI
SMC
SBBR(Server Base Boot Requirements)
SBSA(Server Base System Architecture)
MM(Management Mode)




Arm Trusted Firmware
====================


EL(Exception Level)
-------------------

EL0:Non-Secure, Secure
EL1:Non-Secure, Secure
EL2:Non-Secure, Secure
EL3:Secure


Trust Chain
-----------

EL3: BL1(Trusted Boot ROM)
EL3: BL2(Trusted Boot Firmware)
EL3: BL31(EL3 Runtime Firmeware)
EL3: BL32(OPTee OS + Security App)
EL2: BL33(UEFI/U-Boot)
EL1: Kernel
EL0: System(Rootfs)
