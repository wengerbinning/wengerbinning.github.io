




#### blobmsg_add_json_from_file

```c
bool blobmsg_add_json_from_file (struct blob_buf *b, const char *file)
{
    return __blobmsg_add_json(b, json_object_from_file(file));
}
```