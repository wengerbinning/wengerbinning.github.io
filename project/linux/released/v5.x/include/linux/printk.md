
## 预处理宏

```c
#define FW_BUG      "[Firmware Bug]: "
#define FW_WARN     "[Firmware Warn]: "
#define FW_INFO     "[Firmware Info]: "

#define HW_ERR      "[Hardware Error]:" 

#define DEPRECATED  "[Deprecated]: "
```

## 数据接口

#### struct va_format

```c
struct va_format {
    const char *fmt;
    va_list *va;
}
```

## 数据对象


#### linux_banner

#### linux_proc_banner

#### console_printk

## 函数接口


#### hex_dump_to_buffer

```c
extern int hex_dump_to_buffer (const void *buf, size_t len, 
    int rowsize, int groupsize, char *linebuf, size_t linebuflen, bool ascii);
```

#### pr_debug

```c
#if defined(CONFIG_DYNAMIC_DEBUG)
#define pr_debug(fmt, ...) \
    denamic_pr_debug(fmt, ##__VA_ARGS__)

#elif defined(DEBUG)
#define pr_debug(fmt, ...) \
    printk(KERN_DEBUG pr_fmt(fmt), ##__VA_ARGS__)

#else
#define pr_debug(fmt, ...) \
    no_printk(KERN_DEBUG pr_fmt(fmt), ##__VA_ARGS__)
#endif
```

