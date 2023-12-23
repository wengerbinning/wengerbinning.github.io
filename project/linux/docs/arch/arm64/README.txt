arm64

SVC(Supervisor Call)



exception levels
----------------
EL0 - EL0 has lowest privilege where user applications run.
EL1 - Our beloved Linux kernel runs in EL1.
EL2 - Hypervisor runs in EL2 for virtualisation platforms.
EL3 - EL3 has the highest privilege for Secure Monitor firmware (usually proprietary).



HARDWARE
KERNEL
SYSTEM CALL
LIBRARY FUNCTIOn


el0_svc -> el0_svc_handler -> x