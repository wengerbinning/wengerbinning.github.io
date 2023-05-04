






### Kernel Modules

```c
/* file: include/uapi/asm-generic/unistd.h */

/* kernel/module.c */
#define __NR_init_module    105
__SYSCALL(__NR_init_module, sys_init_module)

#define __NR_delete_module  106
__SYSCALL(__NR_delete_module, sys_delete_module)
```

#### sys_init_module


#### sys_init_module

