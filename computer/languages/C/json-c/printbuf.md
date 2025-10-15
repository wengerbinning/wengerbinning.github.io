
## 内部函数

```c
static int printbuf_extend (struct printbuf *p, int min_size);
```

#### printbuf_extend

```c
static int printbuf_extend (struct printbuf *p, int min_size)
{
    char *t;
    int new_size;

    if (p->size >= min_size)
        return 0;

    /* Prevent signed integer overflows with large buffers. */
    if (min_size > (INT_MAX - 8))
        return -1;

    if (p->size > (INT_MAX / 2)) {
        new_size =  min_size + 8;
    } else {
        new_size = p->size * 2;
        if (new_size < (min_size + 8))
            new_size = (min_size + 8);
    }

#ifdef PRINTBUF_DEBUG
    MC_DEBUG("printbuf_memappend: realloc bpos=%d min_size=%d old_size=%d new_size=%d\n", p->bpos, min_size, p->size, new_size);
#endif /* PRINTBUF_DEBUG */

    if ( !(t = (char*)realloc(p->buf, new_size)) )
        return -1;

    p->size = new_size;
    p->buf = t;

    return 0;
}
```

## 函数实现

#### [printbuf_new](./api/printbuf.md#printbuf_new)

```c
/* file: printbuf.c */
struct printbuf *printbuf_new (void)
{
  struct printbuf *p;

  p = (struct printbuf *)calloc(1, sizeof(struct printbuf));
  if (!p) return NULL;

  p->size = 32;
  p->bpos = 0;
  
  if ( !(p->buf = (char *)malloc(p->size)) ) {
    free(p);
    return NULL;
  }

  return p;
}
```

#### [printbuf_memappend](./api/printbuf.md#printbuf_memappend)

```c
/* file: printbuf.c */
int printbuf_memappend (struct printbuf *p, const char *buf, int size)
{
  /* Prevent signed integer overflows with large buffers. */
  if (size > (INT_MAX - p->bpos - 1))
    return -1;

  if (p->size <= (p->bpos + size + 1)) {
    if (printbuf_extend(p, (p->bpos + size + 1)) < 0)
      return -1;
  }

  memcpy(p->buf + p->bpos, buf, size);

  p->bpos += size;
  p->buf[p->bpos]= '\0';
  
  return size;
}
```

#### [printbuf_memset](./api/printbuf.md#printbuf_memset)

```c
/* file: printbuf.c */
int printbuf_memset (struct printbuf *pb, int offset, int charvalue, int len)
{
    int size_needed;

    if (offset == -1)
        offset = pb->bpos;

    /* Prevent signed integer overflows with large buffers. */
    if (len > (INT_MAX - offset))
        return -1;

    size_needed = offset + len;
    if (pb->size < size_needed) {
        if (printbuf_extend(pb, size_needed) < 0)
            return -1;
    }

    memset(pb->buf + offset, charvalue, len);
    if (pb->bpos < size_needed)
        pb->bpos = size_needed;

    return 0;
}
```


#### [printbuf_reset](./api/printbuf.md#printbuf_reset)

```c
/* file: printbuf.c */
void printbuf_reset (struct printbuf *p)
{
  p->buf[0] = '\0';
  p->bpos = 0;
}
```

#### [printbuf_free](./api/printbuf.md#printbuf_free)

```c
/* file: printbuf.c */
void printbuf_free (struct printbuf *p)
{
  if (p) {
    free(p->buf);
    free(p);
  }
}
```