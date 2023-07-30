


## 数据结构


#### struct _ddebug

```c
struct _ddebug {

    const char *modname;
    const char *function;
    const char *filename;
    const char *format;
    unsigned int lineno: 18;

#define _DPRINTK_FLAGS_NONE             (0x0)
#define _DPRINTK_FLAGS_PRINT            (0x1 << 0)
#define _DPRINTK_FLAGS_INCL_MODNAME     (0x1 << 1)
#define _DPRINTK_FLAGS_INCL_FUNCNAME    (0x1 << 2)
#define _DPRINTK_FLAGS_INCL_LINENO      (0x1 << 3)
#define _DPRINTK_FLAGS_INCL_TID         (0x1 << 4)

#if defined(DEBUG)
#define _DPRINTK_FLAGS_DEFALUT  _DPRINTK_FLAGS_PRINT
#else
#define _DPRINTK_FLAGS_DEFALUT  _DPRINTK_FLAGS_NONE
#endif

    unsigned int flags: 8;  
} __attribute__((aligned(8)));
```

## 数据对象

## 函数接口

#### ddebug_add_module

```c
int ddebug_add_module (struct _ddebug *tab, unsigned int n, const char *modname);
```


#### ddebug_remove_module



```c
static inline int ddebug_remove_module (const char *mod)
{
    return 0;
}
```

如果打开宏 CONFIG_DYNAMIC_DEBUG 后

```c
extern int ddebug_remove_module (const char *mod_name);
```


#### __dynamic_pr_debug

```c
extern __printf(2, 3)
void __dynamic_pr_debug (struct _ddebug *descriptor, const char *fmt, ...);
```

#### ddebug_dyndbg_module_param_cb

```c
extern int ddebug_dyndbg_module_param_cb (char *param, char *val, const char *modname); 
```

#### __dynamic_dev_dbg

```c
extern __printf(3, 4)
void __dynamic_dev_dbg (struct _ddebug *descriptor, const struct device *dev, const char *fmt, ...);
```

#### __dynamic_netdev_dbg

```c
extern __printf(3, 4)
void __dynamic_netdev_dbg (struct _ddebug *descriptor, const struct net_device *dev, const char *fmt, ...);
```

#### DEFINE_DYNAMIC_DEBUG_METADATA

```c
#define DEFINE_DYNAMIC_DEBUG_METADATA(name, fmt) \
    static struct _ddebug __aligned(8) __attribute__((section("__verbose")))   \
    name = {                                                                   \
        .modname = KBUILD_MODNAME,                                             \
        .function = __func__,                                                  \
        .filename = __FILE__,                                                  \
        .format = (fmt),                                                       \
        .lineno = __LINE__,                                                    \
        .flags = _DPRINTK_FLAGS_DEFALUT,                                       \
    }
```

#### dynamic_pr_debug


```c
#define dynamic_pr_debug(fmt, ...) \
    do { if (0) printk(KERN_DEBUG pr_fmt(fmt), ## __VA_ARGS__); } while (0)
```

如果打开宏 CONFIG_DYNAMIC_DEBUG 后

```c
#define dynamic_pr_debug(fmt, ...) \
    do {                                                                       \
        DEFINE_DYNAMIC_DEBUG_METADATA(descriptor, fmt);                        \
        if (unlikely(descriptor.flags & _DPRINTK_FLAGS_PRINT))                 \
            __dynamic_pr_debug(&descriptor, pr_fmt(fmt), ##__VA_ARGS__);       \
    } while (0)
```

#### dynamic_dev_debug

```c
#define dynamic_dev_debug(dev, fmt, ...) \
    do { if (0) dev_printk(KERN_DEBUG, dev, fmt, ## __VA_ARGS__); } while (0)
```

如果打开宏 CONFIG_DYNAMIC_DEBUG 后

```c
#define dynamic_dev_debug(dev, fmt, ...) \
    do {                                                                       \
        DEFINE_DYNAMIC_DEBUG_METADATA(descriptor, fmt);                        \
        if (unlikely(descriptor.flags & _DPRINTK_FLAGS_PRINT))                 \
            __dynamic_dev_debug(&descriptor, dev, fmt, ##__VA_ARGS__);         \
    } while (0)
```

#### dynamic_netdev_debug

```c
#define dynamic_netdev_debug(dev, fmt, ...) \
    do {                                                                       \
        DEFINE_DYNAMIC_DEBUG_METADATA(descriptor, fmt);                        \
        if (unlikely(descriptor.flags & _DPRINTK_FLAGS_PRINT))                 \
            __dynamic_netdev_debug(&descriptor, dev, fmt, ##__VA_ARGS__);      \
    } while (0)
```

#### dynamic_hex_dump

```c
#define dynamic_hex_dump(prefix_str, prefix_type, rowsize, groupsize, buf, len, ascii) \
    do {                                                                       \
        DEFINE_DYNAMIC_DEBUG_METADATA(descriptor,                              \
            __builtin_constant_p(prefix_str) ? prefix_str : "hexdump");        \
        if (unlikely(descriptor.flags & _DPRINTK_FLAGS_PRINT))                 \
            print_hex_dump(KERN_DEBUG, prefix_str, prefix_type,                \
                rowsize, groupsize, buf, len, ascii);                          \
    } while (0)

```