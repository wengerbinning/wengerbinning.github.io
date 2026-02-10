
## 预定义宏

#### __SOCKADDR_COMMON

```c
#define __SOCKADDR_COMMON(sa_prefix) \
    sa_family_t sa_prefix ## family
```

#### __SOCKADDR_COMMON_SIZE

```c
#define __SOCKADDR_COMMON_SIZE \
    (sizeof (unsigned short int))
```

#### __SS_SIZE

```c
#define __SS_SIZE 128
```

## 数据结构

#### sa_family_t

```c
typedef unsigned short int sa_family_t;
```