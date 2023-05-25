
#### blob.h


数据结构

* struct blob_attr
* struct blob_attr_info
* struct blob_buf

函数接口

struct blob_attr 类型的操作函数

* blob_data 获取数据对象的数据字段
* blob_id 获取数据u对象的id字段
* blob_is_extended 检查数据对象是否是扩展
* blob_len 获取数据对象的数据部分长度
* blob_raw_len 获取数据对象的长度
* blob_pad_len 获取数据对象实际分配长度

* blob_get_u8
* blob_get_u16
* blob_get_u32
* blob_get_u64
* blob_get_string

* blob_buf_init




#### blobmsg_json.h 

数据结构

* blobmsg_json_format_t

函数接口

* blobmsg_add_object

* blobmsg_add_json_element

* blobmsg_add_json_from_string

* [blobmsg_add_json_from_file](./blobmsg_json.md#blobmsg_add_json_from_file) 从json格式的文件读入内容并转化为blobmsg对象。

* blobmsg_format_json_with_cb

* blobmsg_format_json

* blobmsg_format_json_indent
