## 预处理


#### blobmsg_for_each_attr

```c
#define blobmsg_for_each_attr(pos, attr, rem) \
	for (rem = attr ? blobmsg_data_len(attr) : 0, pos = attr ? blobmsg_data(attr) : 0;              \
	     rem > 0 && (blob_pad_len(pos) <= rem) && (blob_pad_len(pos) >= sizeof(struct blob_attr));  \
	     rem -= blob_pad_len(pos), pos = blob_next(pos))
```

## 数据结构

#### enum blobmsg_type

```c
enum blobmsg_type {
	BLOBMSG_TYPE_UNSPEC,
	BLOBMSG_TYPE_ARRAY,
	BLOBMSG_TYPE_TABLE,
	BLOBMSG_TYPE_STRING,
	BLOBMSG_TYPE_INT64,
	BLOBMSG_TYPE_INT32,
	BLOBMSG_TYPE_INT16,
	BLOBMSG_TYPE_INT8,
	__BLOBMSG_TYPE_LAST,
	BLOBMSG_TYPE_LAST = __BLOBMSG_TYPE_LAST - 1,
	BLOBMSG_TYPE_BOOL = BLOBMSG_TYPE_INT8,
};
```

#### struct blobmsg_hdr

```c
struct blobmsg_hdr {
	uint16_t namelen;
	uint8_t name[];
} __packed;
```

#### struct blobmsg_policy

```c
struct blobmsg_policy {
	const char *name;
	enum blobmsg_type type;
};
```


#### blobmsg_hdrlen

```c
static inline int blobmsg_hdrlen (unsigned int namelen)
{
	return BLOBMSG_PADDING(sizeof(struct blobmsg_hdr) + namelen + 1);
}

```

#### blobmsg_clear_name

```c
static inline void blobmsg_clear_name (struct blob_attr *attr)
{
	struct blobmsg_hdr *hdr = (struct blobmsg_hdr *) blob_data(attr);
	hdr->name[0] = 0;
}
```

#### blobmsg_name


```c
static inline const char *blobmsg_name(const struct blob_attr *attr)
{
	struct blobmsg_hdr *hdr = (struct blobmsg_hdr *) blob_data(attr);
	return (const char *) hdr->name;
}
```

#### blobmsg_type

```c
static inline int blobmsg_type(const struct blob_attr *attr)
{
	return blob_id(attr);
}
```

#### blobmsg_data

```c
static inline void *blobmsg_data (const struct blob_attr *attr)
{
	struct blobmsg_hdr *hdr = (struct blobmsg_hdr *) blob_data(attr);
	char *data = (char *) blob_data(attr);

	if (blob_is_extended(attr))
		data += blobmsg_hdrlen(be16_to_cpu(hdr->namelen));

	return data;
}
```

#### blobmsg_data_len

```c
static inline int blobmsg_data_len(const struct blob_attr *attr)
{
	uint8_t *start, *end;

	start = (uint8_t *) blob_data(attr);
	end = (uint8_t *) blobmsg_data(attr);

	return blob_len(attr) - (end - start);
}
```


#### blobmsg_len

```c
static inline int blobmsg_len(const struct blob_attr *attr)
{
	return blobmsg_data_len(attr);
}
```


#### blobmsg_check_attr

```c
bool blobmsg_check_attr (const struct blob_attr *attr, bool name);
```

#### blobmsg_check_attr_list

```c
bool blobmsg_check_attr_list (const struct blob_attr *attr, int type);
```

#### blobmsg_check_array

```c
int blobmsg_check_array (const struct blob_attr *attr, int type);
```

#### blobmsg_parse

```c
int blobmsg_parse (const struct blobmsg_policy *policy, int policy_len, struct blob_attr **tb, void *data, unsigned int len);
```

#### blobmsg_parse_array

```c
int blobmsg_parse_array (const struct blobmsg_policy *policy, int policy_len, struct blob_attr **tb, void *data, unsigned int len);
```

#### blobmsg_add_field

```c
int blobmsg_add_field (struct blob_buf *buf, int type, const char *name, const void *data, unsigned int len);
```

#### blobmsg_add_u8

```c
static inline int blobmsg_add_u8 (struct blob_buf *buf, const char *name, uint8_t val)
{
	return blobmsg_add_field(buf, BLOBMSG_TYPE_INT8, name, &val, 1);
}
```

#### blobmsg_add_u16

```c
static inline int blobmsg_add_u16 (struct blob_buf *buf, const char *name, uint16_t val)
{
	val = cpu_to_be16(val);
	return blobmsg_add_field(buf, BLOBMSG_TYPE_INT16, name, &val, 2);
}
```

#### blobmsg_add_u32

```c
static inline int blobmsg_add_u32 (struct blob_buf *buf, const char *name, uint32_t val)
{
	val = cpu_to_be32(val);
	return blobmsg_add_field(buf, BLOBMSG_TYPE_INT32, name, &val, 4);
}
```

#### blobmsg_add_u64

```c
static inline int blobmsg_add_u64 (struct blob_buf *buf, const char *name, uint64_t val)
{
	val = cpu_to_be64(val);
	return blobmsg_add_field(buf, BLOBMSG_TYPE_INT64, name, &val, 8);
}
```

#### blobmsg_add_string

```c
static inline int blobmsg_add_string (struct blob_buf *buf, const char *name, const char *string)
{
	return blobmsg_add_field(buf, BLOBMSG_TYPE_STRING, name, string, strlen(string) + 1);
}
```

#### blobmsg_add_blob

```c
static inline int blobmsg_add_blob (struct blob_buf *buf, struct blob_attr *attr)
{
	return blobmsg_add_field(buf, blobmsg_type(attr), blobmsg_name(attr),
				 blobmsg_data(attr), blobmsg_data_len(attr));
}
```

#### blobmsg_open_nested

```c
void *blobmsg_open_nested (struct blob_buf *buf, const char *name, bool array);
```

#### blobmsg_open_array

```c
static inline void *blobmsg_open_array (struct blob_buf *buf, const char *name)
{
	return blobmsg_open_nested(buf, name, true);
}
```

#### blobmsg_open_table

```c
static inline void * blobmsg_open_table(struct blob_buf *buf, const char *name)
{
	return blobmsg_open_nested(buf, name, false);
}
```


#### blobmsg_close_array

```c

static inline void blobmsg_close_array (struct blob_buf *buf, void *cookie)
{
	blob_nest_end(buf, cookie);
}
```

#### blobmsg_close_table

```c
static inline void blobmsg_close_table(struct blob_buf *buf, void *cookie)
{
	blob_nest_end(buf, cookie);
}
```


#### blobmsg_buf_init

```c
static inline int blobmsg_buf_init(struct blob_buf *buf)
{
	return blob_buf_init(buf, BLOBMSG_TYPE_TABLE);
}
```

#### blobmsg_get_u8

```c
static inline uint8_t blobmsg_get_u8(struct blob_attr *attr)
{
	return *(uint8_t *) blobmsg_data(attr);
}
```

#### blobmsg_get_bool

```c
static inline bool blobmsg_get_bool(struct blob_attr *attr)
{
	return *(uint8_t *) blobmsg_data(attr);
}
```

#### blobmsg_get_u16

```c
static inline uint16_t blobmsg_get_u16 (struct blob_attr *attr)
{
	return be16_to_cpu(*(uint16_t *) blobmsg_data(attr));
}
```

#### blobmsg_get_u32

```c
static inline uint32_t blobmsg_get_u32 (struct blob_attr *attr)
{
	return be32_to_cpu(*(uint32_t *) blobmsg_data(attr));
}
```

#### blobmsg_get_u64

```c
static inline uint64_t blobmsg_get_u64(struct blob_attr *attr)
{
	uint32_t *ptr = (uint32_t *) blobmsg_data(attr);
	uint64_t tmp = ((uint64_t) be32_to_cpu(ptr[0])) << 32;
	tmp |= be32_to_cpu(ptr[1]);
	return tmp;
}
```


#### blobmsg_get_string

```c
static inline char *blobmsg_get_string (struct blob_attr *attr)
{
	if (!attr)
		return NULL;

	return (char *) blobmsg_data(attr);
}
```

#### blobmsg_alloc_string_buffer

```c
void *blobmsg_alloc_string_buffer (struct blob_buf *buf, const char *name, unsigned int maxlen);
```

#### blobmsg_realloc_string_buffer

```c
void *blobmsg_realloc_string_buffer(struct blob_buf *buf, unsigned int maxlen);
```


#### blobmsg_add_string_buffer

```c
void blobmsg_add_string_buffer(struct blob_buf *buf);
```


#### blobmsg_vprintf

```c
void blobmsg_vprintf (struct blob_buf *buf, const char *name, const char *format, va_list arg);
```

#### blobmsg_printf

```c
void blobmsg_printf(struct blob_buf *buf, const char *name, const char *format, ...) __attribute__((format(printf, 3, 4)));
```