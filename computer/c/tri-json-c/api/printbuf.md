
## 预处理

#### printbuf_memappend_fast

```c
/* file: printbuf.h */

#define printbuf_memappend_fast(p, bufptr, bufsize) \
    do {                                                         \
        if ((p->size - p->bpos) > bufsize) {                     \
            memcpy(p->buf + p->bpos, (bufptr), bufsize);         \
            p->bpos += bufsize;                                  \
            p->buf[p->bpos]= '\0';                               \
        } else {                                                 \
            printbuf_memappend(p, (bufptr), bufsize);            \
        }                                                        \
    } while (0)
```

该宏函数会根据填充内容大小来决定是否使用[printbuf_memappend](#printbuf_memappend)函数。

## 数据结构

#### struct printbuf
```c
struct printbuf 
{
  char *buf;
  int   bpos;
  int   size;
};
```

## 函数接口


#### [printbuf_new](../printbuf.md#printbuf_new)

```c
/* file: printbuf.h */

extern struct printbuf *printbuf_new (void);
```

该函数用于申请一个[struct printbuf](#struct-printbuf)对象。



#### [printbuf_memappend](../printbuf.md#printbuf_memappend)

```c
/* file: printbuf.h */

extern int printbuf_memappend (struct printbuf *p, const char *buf, int size);
```

该函数用于向[struct printbuf](#struct-printbuf)对象p添加size大小的数据buf，对象p会自动扩充内存。


#### [printbuf_memset](../printbuf.md#printbuf_memset)

```c
/* file: printbuf.h */

extern int printbuf_memset (struct printbuf *pb, int offset, int charvalue, int len);
```

该函数用于重写[struct printfbuf]对象pb从offset开始的len长度的内容， 填充内容为charvalue。

#### [sprintbuf]()

```c
/* file: printbuf.h */

extern int sprintbuf (struct printbuf *p, const char *msg, ...);
```

#### [printbuf_reset](../printbuf.md#printbuf_reset)

```c
/* file: printbuf.h */

extern void printbuf_reset (struct printbuf *p);
```

该函数会清空[struct printbuf](#struct-printbuf)对象p的内容。

#### [printbuf_free](../printbuf.md#printbuf_free)

```c
extern void printbuf_free (struct printbuf *p);
```

该函数用于释放[struct printfbuf](#struct-printbuf)对象p.