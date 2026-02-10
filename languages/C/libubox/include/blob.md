
## 预处理

```c

#define BLOB_COOKIE		0x01234567

#define BLOB_ATTR_EXTENDED 0x80000000
#define BLOB_ATTR_ID_MASK  0x7f000000
#define BLOB_ATTR_ID_SHIFT 24
#define BLOB_ATTR_LEN_MASK 0x00ffffff

#define BLOB_ATTR_ALIGN    4
```


## 数据结构

#### enum enum_blob_attr

```c
enum {
	BLOB_ATTR_UNSPEC,
	BLOB_ATTR_NESTED,
	BLOB_ATTR_BINARY,
	BLOB_ATTR_STRING,
	BLOB_ATTR_INT8,
	BLOB_ATTR_INT16,
	BLOB_ATTR_INT32,
	BLOB_ATTR_INT64,
	BLOB_ATTR_LAST
};
```

#### struct blob_attr

```c
struct blob_attr {
	uint32_t id_len;
	char data[];
} __packed;
```


#### struct blob_attr_info

```c
struct blob_attr_info {
	unsigned int type;
	unsigned int minlen;
	unsigned int maxlen;
	bool (*validate)(const struct blob_attr_info *, struct blob_attr *);
};
```

#### struct blob_buf 

```c
struct blob_buf {
	struct blob_attr *head;
	bool  (*grow) (struct blob_buf *buf, int minlen);
	int     buflen;
	void   *buf;
};
```


## 函数接口


#### blob_data

```c
static inline void *blob_data (const struct blob_attr *attr)
{
	return (void *) attr->data;
}
```

#### blob_id

```c
static inline unsigned int blob_id (const struct blob_attr *attr)
{
	int id = (be32_to_cpu(attr->id_len) & BLOB_ATTR_ID_MASK) >> BLOB_ATTR_ID_SHIFT;
	return id;
}
```

#### blob_is_extended

```c
static inline bool blob_is_extended (const struct blob_attr *attr)
{
	return !!(attr->id_len & cpu_to_be32(BLOB_ATTR_EXTENDED));
}
```

#### blob_len

```c
static inline unsigned int blob_len (const struct blob_attr *attr)
{
	return (be32_to_cpu(attr->id_len) & BLOB_ATTR_LEN_MASK) - sizeof(struct blob_attr);
}
```


#### blob_raw_len

```c
static inline unsigned int blob_raw_len (const struct blob_attr *attr)
{
	return blob_len(attr) + sizeof(struct blob_attr);
}
```

#### blob_pad_len

```c
static inline unsigned int blob_pad_len (const struct blob_attr *attr)
{
	unsigned int len = blob_raw_len(attr);
	
    len = (len + BLOB_ATTR_ALIGN - 1) & ~(BLOB_ATTR_ALIGN - 1);
	
    return len;
}
```

Value API

#### blob_get_u8

```c
static inline uint8_t blob_get_u8 (const struct blob_attr *attr)
{
	return *((uint8_t *) attr->data);
}
```

#### blob_get_u16

```c
static inline uint16_t blob_get_u16 (const struct blob_attr *attr)
{
	uint16_t *tmp = (uint16_t*)attr->data;

	return be16_to_cpu(*tmp);
}
```

#### blob_get_u32

```c
static inline uint32_t blob_get_u32 (const struct blob_attr *attr)
{
	uint32_t *tmp = (uint32_t*)attr->data;
	return be32_to_cpu(*tmp);
}
```

#### blob_get_u64

```c
static inline uint64_t blob_get_u64 (const struct blob_attr *attr)
{
	uint32_t *ptr = (uint32_t *) blob_data(attr);
	uint64_t tmp = ((uint64_t) be32_to_cpu(ptr[0])) << 32;
	tmp |= be32_to_cpu(ptr[1]);
	return tmp;
}
```

#### blob_get_int8

```c
static inline int8_t blob_get_int8 (const struct blob_attr *attr)
{
	return blob_get_u8(attr);
}
```

#### blob_get_int16

```c
static inline int16_t blob_get_int16 (const struct blob_attr *attr)
{
	return blob_get_u16(attr);
}
```

#### blob_get_int32

```c
static inline int32_t blob_get_int32 (const struct blob_attr *attr)
{
	return blob_get_u32(attr);
}
```

#### blob_get_int64

```c
static inline int64_t blob_get_int64 (const struct blob_attr *attr)
{
	return blob_get_u64(attr);
}
```

#### blob_get_string

```c
static inline const char *blob_get_string (const struct blob_attr *attr)
{
	return attr->data;
}
```


#### blob_next

```c
static inline struct blob_attr *blob_next (const struct blob_attr *attr)
{
	return (struct blob_attr *) ((char *) attr + blob_pad_len(attr));
}
```


####

```c
extern void blob_fill_pad(struct blob_attr *attr);
extern void blob_set_raw_len(struct blob_attr *attr, unsigned int len);
extern bool blob_attr_equal(const struct blob_attr *a1, const struct blob_attr *a2);

extern int blob_buf_init(struct blob_buf *buf, int id);
extern void blob_buf_free(struct blob_buf *buf);
extern bool blob_buf_grow(struct blob_buf *buf, int required);

extern struct blob_attr *blob_new(struct blob_buf *buf, int id, int payload);
extern void *blob_nest_start(struct blob_buf *buf, int id);
extern void blob_nest_end(struct blob_buf *buf, void *cookie);
extern struct blob_attr *blob_put(struct blob_buf *buf, int id, const void *ptr, unsigned int len);
extern bool blob_check_type(const void *ptr, unsigned int len, int type);
extern int blob_parse(struct blob_attr *attr, struct blob_attr **data, const struct blob_attr_info *info, int max);
extern struct blob_attr *blob_memdup(struct blob_attr *attr);
extern struct blob_attr *blob_put_raw(struct blob_buf *buf, const void *ptr, unsigned int len);
```


#### blob_buf_init

```c
extern int blob_buf_init(struct blob_buf *buf, int id);
```