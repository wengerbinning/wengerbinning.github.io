

## 内部函数

#### blobmsg_add_array

```c
static bool blobmsg_add_array (struct blob_buf *b, struct array_list *a)
{
	int i, len;

	for (i = 0, len = array_list_length(a); i < len; i++) {
		if (!blobmsg_add_json_element(b, NULL, array_list_get_idx(a, i)))
			return false;
	}

	return true;
}
```

#### __blobmsg_add_json

```c
static bool __blobmsg_add_json (struct blob_buf *b, json_object *obj)
{
	bool ret = false;

	if (!obj)
		return false;

	if (json_object_get_type(obj) != json_type_object)
		goto out;

	ret = blobmsg_add_object(b, obj);

out:
	json_object_put(obj);

	return ret;
}
```

## 函数实现


#### blobmsg_add_json_from_file

```c
bool blobmsg_add_json_from_file (struct blob_buf *b, const char *file)
{
    return __blobmsg_add_json(b, json_object_from_file(file));
}
```