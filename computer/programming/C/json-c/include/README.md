



## 模块接口

#### [arraylist.h]


### [printbuf.h](./printbuf.md)

数据结构

* [struct printbuf](./printbuf.md#struct-printbuf)

操作接口

* [printbuf_new](./printbuf.md#printbuf_new)
* [printbuf_memappend](./printbuf.md#printbuf_memappend)
* [printbuf_memappend_fast](./printbuf.md#printbuf_memappend_fast)
* [printbuf_memset](./printbuf.md#printbuf_memset)
* [printbuf_reset](./printbuf.md#printbuf_reset)
* [printbuf_free](./printbuf.md#printbuf_free)



#### [json_object.h](./json_object.md)


#### 函数接口

json对象操作的API

* json_object_get
* json_object_put
* json_object_is_type
* json_object_get_type
* json_object_to_json_string
* json_object_to_json_string_ext

* json_object_new_object
* json_object_get_object
* json_object_object_length
* json_object_object_add
* json_object_object_get_ex
* json_object_object_length


数组类型的函数接口

* json_object_new_array
* json_object_get_array
* json_object_array_length
* json_object_array_sort
* json_object_array_add
* json_object_array_put_idx
* json_object_array_get_idx

布尔类型的函数接口

* json_object_new_boolean
* json_object_get_boolean



#### [json_util.h](./json_util.md)

函数

* json_object_from_file

* json_object_to_file
* json_object_to_file_ext
* json_parse_int64
* json_parse_double
* json_type_to_name
