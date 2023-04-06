
## 宏


#### ARRAY_SIZE

```c
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]) + __must_be_array(arr))
```


## 数据类型



## 数据对象



## 函数接口s


#### snprintf

```c
int snprintf (char *buf, size_t size, const char *fmt, ...);
```

```c
/* file: include/linux/kernel.h */

extern __printf(3, 4) int snprintf (char *buf, size_t size, const char *fmt, ...);
```

```c
/* file: lib/vsprintf.c */

int snprintf(char *buf, size_t size, const char *fmt, ...)
{
	va_list args;
	int i;

	va_start(args, fmt);
	i = vsnprintf(buf, size, fmt, args);
	va_end(args);

	return i;
}
```

```c
EXPORT_SYMBOL(snprintf);
```



