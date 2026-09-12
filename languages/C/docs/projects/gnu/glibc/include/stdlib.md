# stdlib.h

stdlib中实现了一些基本的数据转换与数据操作的接口。




```c
void* malloc (unsigned size);
```

```c
void* calloc (unsigned n, unsigned size);
```

```c
void* valloc (size_t __size);
```

```c
unsigned long int strtoul(const char *str, char **endptr, int base);
```

strtoul()函数用于将字符串转化为无符号的长整型。
