


## 模块结构

* 该模块提供的头文件

```txt
json-c/arraylist.h
json-c/bits.h
json-c/debug.h
json-c/json_config.h
json-c/json_c_version.h
json-c/json.h
json-c/json_inttypes.h
json-c/json_object.h
json-c/json_object_iterator.h
json-c/json_object_private.h
json-c/json_tokener.h
json-c/json_util.h
json-c/linkhash.h
json-c/printbuf.h
json-c/random_seed.h
```

* 该模块提供的库文件

```txt
libjson-c.a
libjson-c.so -> libjson-c.so.2.0.1
libjson-c.so.2 -> libjson-c.so.2.0.1
libjson-c.so.2.0.1
libjson-c.la
pkgconfig/json-c.pc
```

## 模块接口

#### [printbuf.h](./printbuf.md)

数据结构

* [struct printbuf](./printbuf.md#struct-printbuf)

操作接口

* [printbuf_new](./printbuf.md#printbuf_new)
* [printbuf_memappend](./printbuf.md#printbuf_memappend)
* [printbuf_memappend_fast](./printbuf.md#printbuf_memappend_fast)
* [printbuf_memset](./printbuf.md#printbuf_memset)
* [printbuf_reset](./printbuf.md#printbuf_reset)
* [printbuf_free](./printbuf.md#printbuf_free)

#### [json_util.h](./json_util.md)

函数

* json_object_from_file

* json_object_to_file
* json_object_to_file_ext
* json_parse_int64
* json_parse_double
* json_type_to_name
