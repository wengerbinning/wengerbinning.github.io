



```c
struct module {
    enum module_state   state;
    struct list_head    list;
    char    name[MODULE_NAME_LEN];
    struct module_kobject       mkobj;
    struct module_attribute    *modinfo_attrs;
    const char     *version;
    const char     *srcversion;
    struct kobject *holders_dir;
    const struct kernel_symbol *syms;
    const unsigned long        *crcs;
    unsigned int    num_syms;
#if defined(CONFIG_SYSFS)
    struct mutex param_lock;
#endif
    struct kernel_param    *kp;
    unsigned int            num_kp;
    unsigned int    num_gpl_syms;
     
    ...
};  
```


## LINKS

include/linux/module.h