


## 函数实现

#### blobmsg_add_field

```c
int blobmsg_add_field (struct blob_buf *buf, int type, const char *name, const void *data, unsigned int len)
{
	struct blob_attr *attr;
	void *data_dest;

	attr = blobmsg_new(buf, type, name, len, &data_dest);
	if (!attr)
		return -1;

	if (len > 0)
		memcpy(data_dest, data, len);

	return 0;
}
```