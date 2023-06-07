

```txt
stdio.h
string.h
```




### string.h

#### 数据类型

* size_t 无符号的整型


#### 数据对象

* NULL 空指针常量


#### 函数接口

管理内存相关的接口

* memcmp
* memcpy
* memmove
* memset
* memchr

管理字符串相关的接口

* strcat
* strchr
* strcmp
* strcoll
* strcpy
* strcspn
* strerror
* strlen
* strpbrk
* strrchr
* strstr
* strtok
* strxfrm

* strncat
* strncmp
* strncpy


### [stdint.h](./stdint.md)

```c
#include <bits/libc-header-start.h>
#include <bits/types.h>
#include <bits/wchar.h>
#include <bits/wordsize.h>

/* Exact integral types.  */

/* Signed.  */
#include <bits/stdint-intn.h>

/* Unsigned.  */
#include <bits/stdint-uintn.h>
```


```c
/* Small types.  */

/* Signed.  */
typedef __int_least8_t int_least8_t;
typedef __int_least16_t int_least16_t;
typedef __int_least32_t int_least32_t;
typedef __int_least64_t int_least64_t;

/* Unsigned.  */
typedef __uint_least8_t uint_least8_t;
typedef __uint_least16_t uint_least16_t;
typedef __uint_least32_t uint_least32_t;
typedef __uint_least64_t uint_least64_t;
```

### [stdlib.h](./stdlib.md)

* malloc
* calloc
* realloc
* free





### [math.h](./math.md)



## LINKS

*  malloc <https://blog.csdn.net/wang13342322203/article/details/80862382>
