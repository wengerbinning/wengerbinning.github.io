



## 内部函数

```c
static void blob_init (struct blob_attr *attr, int id, unsigned int len);
static inline struct blob_attr *offset_to_attr (struct blob_buf *buf, int offset);
static inline int attr_to_offset (struct blob_buf *buf, struct blob_attr *attr);
static struct blob_attr *blob_add (struct blob_buf *buf, struct blob_attr *pos, int id, int payload);

static bool blob_buffer_grow (struct blob_buf *buf, int minlen);
```

#### blob_init

```c
static void blob_init (struct blob_attr *attr, int id, unsigned int len)
{
	len &= BLOB_ATTR_LEN_MASK;
	len |= (id << BLOB_ATTR_ID_SHIFT) & BLOB_ATTR_ID_MASK;
	attr->id_len = cpu_to_be32(len);
}
```

#### offset_to_attr

```c
static inline struct blob_attr *offset_to_attr (struct blob_buf *buf, int offset)
{
	void *ptr = (char *)buf->buf + offset - BLOB_COOKIE;
	return ptr;
}
```

#### attr_to_offset

```c
static inline int attr_to_offset (struct blob_buf *buf, struct blob_attr *attr)
{
	return (char *)attr - (char *) buf->buf + BLOB_COOKIE;
}
```

#### blob_add

```c
static struct blob_attr *blob_add (struct blob_buf *buf, struct blob_attr *pos, int id, int payload)
{
	int offset = attr_to_offset(buf, pos);
	int required = (offset - BLOB_COOKIE + sizeof(struct blob_attr) + payload) - buf->buflen;
	struct blob_attr *attr;

	if (required > 0) {
		if (!blob_buf_grow(buf, required))
			return NULL;
    
		attr = offset_to_attr(buf, offset);
	} else {
		attr = pos;
	}

	blob_init(attr, id, payload + sizeof(struct blob_attr));
	blob_fill_pad(attr);
	return attr;
}
```

#### blob_buffer_grow

该函数已256字节对齐的方式增长。

```c
static bool blob_buffer_grow (struct blob_buf *buf, int minlen)
{
	struct blob_buf *new;
	int delta = ((minlen / 256) + 1) * 256;
	
    new = realloc(buf->buf, buf->buflen + delta);
	if (new) {
		buf->buf = new;
		memset(buf->buf + buf->buflen, 0, delta);
		buf->buflen += delta;
	}
	return !!new;
}
```

## 函数实现

#### blob_fill_pad

```c
void blob_fill_pad (struct blob_attr *attr)
{
	char *buf = (char *) attr;
	int len = blob_pad_len(attr);
	int delta = len - blob_raw_len(attr);

	if (delta > 0)
		memset(buf + len - delta, 0, delta);
}
```

#### blob_nest_start

```c
void *blob_nest_start (struct blob_buf *buf, int id)
{
	unsigned long offset = attr_to_offset(buf, buf->head);
	buf->head = blob_new(buf, id, 0);
	if (!buf->head)
		return NULL;
    
	return (void *) offset;
}
```

#### blob_nest_end

```c
void blob_nest_end (struct blob_buf *buf, void *cookie)
{
	struct blob_attr *attr = offset_to_attr(buf, (unsigned long) cookie);
	blob_set_raw_len(attr, blob_pad_len(attr) + blob_len(buf->head));
	
    buf->head = attr;
}
```

#### blob_buf_grow

```c
bool blob_buf_grow (struct blob_buf *buf, int required)
{
	int offset_head = attr_to_offset(buf, buf->head);

	if (!buf->grow || !buf->grow(buf, required))
		return false;

	buf->head = offset_to_attr(buf, offset_head);
	return true;
}
```

#### blob_buf_init

```c
int blob_buf_init (struct blob_buf *buf, int id)
{
	if (!buf->grow)
		buf->grow = blob_buffer_grow;

	buf->head = buf->buf;
	if (blob_add(buf, buf->buf, id, 0) == NULL)
		return -ENOMEM;

	return 0;
}
```
