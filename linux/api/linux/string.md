




#### kstrdup

```c
extern char *kstrdup (const char *s, gfp_t gfp);
```

```c
char *kstrdup(const char *s, gfp_t gfp)
{
	size_t len;
	char *buf;

	if (!s)
		return NULL;

	len = strlen(s) + 1;
	buf = kmalloc_track_caller(len, gfp);
	if (buf)
		memcpy(buf, s, len);
	return buf;
}
```

```c
EXPORT_SYMBOL(kstrdup);
```


#### kstrndup

```c
/* file: include/linux/string.h */

extern char *kstrndup(const char *s, size_t len, gfp_t gfp);
```

```c
/* file: mm/util.c */

char *kstrndup (const char *s, size_t max, gfp_t gfp)
{
	size_t len;
	char *buf;

	if (!s)
		return NULL;

	len = strnlen(s, max);
	buf = kmalloc_track_caller(len+1, gfp);
	if (buf) {
		memcpy(buf, s, len);
		buf[len] = '\0';
	}
	return buf;
}
```

```c
EXPORT_SYMBOL(kstrndup);
```