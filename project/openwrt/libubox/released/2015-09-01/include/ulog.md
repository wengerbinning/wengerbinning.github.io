

#### ulog

```c
void ulog(int pri, const char *fmt, ...)
__attribute__((format (printf, 2, 3)));

#define ULOG_INFO(fmt, ...) ulog(LOG_INFO,    fmt, ## __VA_ARGS__)
#define ULOG_NOTE(fmt, ...) ulog(LOG_NOTICE,  fmt, ## __VA_ARGS__)
#define ULOG_WARN(fmt, ...) ulog(LOG_WARNING, fmt, ## __VA_ARGS__)
#define ULOG_ERR(fmt, ...)  ulog(LOG_ERR,     fmt, ## __VA_ARGS__)
```