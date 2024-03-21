

## 模块依赖

#### 外部模块

#### 内部模块

## 预处理


#### JSON_OBJECT_DEF_HASH_ENTRIES

```c
#define JSON_OBJECT_DEF_HASH_ENTRIES 16
#define JSON_C_TO_STRING_PLAIN      0
#define JSON_C_TO_STRING_SPACED     (1<<0)
#define JSON_C_TO_STRING_PRETTY     (1<<1)
#define JSON_C_TO_STRING_NOZERO     (1<<2)
```


#### json_object_object_foreach

```c
// struct json_object *obj;
// key is string
// val is string
json_object_object_foreach(obj, key, val)

```

```c
# define json_object_object_foreach(obj,key,val) \
	char *key;                                                                                        \
	struct json_object *val __attribute__((__unused__));                                              \
	for(struct lh_entry *entry ## key = json_object_get_object(obj)->head, *entry_next ## key = NULL; \
		({ if(entry ## key) {                                                                           \
			key = (char*)entry ## key->k;                                                                 \
			val = (struct json_object*)entry ## key->v;                                                   \
			entry_next ## key = entry ## key->next;                                                       \
		} ; entry ## key; });                                                                           \
		entry ## key = entry_next ## key )
```

```c
#define json_object_object_foreachC (obj,iter) \
    for(iter.entry = json_object_get_object(obj)->head; (iter.entry ? (iter.key = (char*)iter.entry->k, iter.val = (struct json_object*)iter.entry->v, iter.entry) : 0); iter.entry = iter.entry->next)
```

```c
#undef FALSE
#define FALSE ((json_bool)0)

#undef TRUE
#define TRUE ((json_bool)1)
```

## 数据结构

#### json_type

```c
typedef enum json_type {
  /* If you change this, be sure to update json_type_to_name() too */
  json_type_null,
  json_type_boolean,
  json_type_double,
  json_type_int,
  json_type_object,
  json_type_array,
  json_type_string,
} json_type;
```

#### struct json_object_iter

```c
struct json_object_iter
{
    char *key;
    struct json_object *val;
    struct lh_entry *entry;
};
```

#### json_bool

```c
typedef int json_bool;
```

#### printbuf

```c
typedef struct printbuf printbuf;
```

#### lh_table

```c
typedef struct lh_table lh_table;
```

#### array_list

```c
typedef struct array_list array_list;
```

##### json_object

```c
typedef struct json_object json_object;
```

##### json_object_iter

```c
typedef struct json_object_iter json_object_iter;
```

##### json_tokener

```c
typedef struct json_tokener json_tokener;
```



#### json_object_delete_fn

```c
typedef void (json_object_delete_fn) (struct json_object *jso, void *userdata);
```

#### json_object_to_json_string_fn

```c
typedef int (json_object_to_json_string_fn) (struct json_object *jso, struct printbuf *pb, int level, int flags);
```

## 数据对象

### 外部数据对象

```c
extern const char *json_number_chars;
extern const char *json_hex_chars;
```



## 函数接口

JSON Obejct API

#### json_object_get


该函数会增加json对象引用计数器。

```c
extern struct json_object *json_object_get (struct json_object *obj);
```

#### json_object_put

该函数会减小json对象引用计数器。

```c
int json_object_put (struct json_object *obj);
```

#### json_object_is_type

```c
extern int json_object_is_type (struct json_object *obj, enum json_type type);
```

#### json_object_get_type

```c
extern enum json_type json_object_get_type (struct json_object *obj);
```

#### json_object_to_json_string

```c
extern const char *json_object_to_json_string (struct json_object *obj);
```

#### json_object_to_json_string_ext

```c
extern const char *json_object_to_json_string_ext (struct json_object *obj, int flags);
```

#### json_object_new_object

```c
extern struct json_object *json_object_new_object (void);
```

#### json_object_get_object

```c
extern struct lh_table *json_object_get_object (struct json_object *obj);
```

#### json_object_object_length

```c
extern int json_object_object_length (struct json_object* obj);
```

#### json_object_object_add

```c
extern void json_object_object_add (struct json_object* obj, const char *key, struct json_object *val);
```

#### json_object_object_get_ex

通过key值获json字段

```c
extern json_bool json_object_object_get_ex (struct json_object* obj, const char *key, struct json_object **value);
```

#### json_object_object_del

```c
extern void json_object_object_del (struct json_object *obj, const char *key);
```

#### json_object_object_length

该函数用于获取json对象中存在的对象数量。

```c
extern int json_object_object_length (struct json_object *obj);
```




JSON Array API


#### json_object_new_array

```c
extern struct json_object *json_object_new_array (void);
```
#### json_object_get_array

```c
extern struct array_list *json_object_get_array (struct json_object *obj);
```

#### json_object_array_length

```c
extern int json_object_array_length (struct json_object *obj);
```

#### json_object_array_sort

```c
extern void json_object_array_sort (struct json_object *jso, int(*sort_fn)(const void *, const void *));
```

#### json_object_array_add

```c
extern int json_object_array_add (struct json_object *obj, struct json_object *val);
```

#### json_object_array_put_idx

```c
extern int json_object_array_put_idx (struct json_object *obj, int idx, struct json_object *val);
```

#### json_object_array_get_idx

```c
extern struct json_object *json_object_array_get_idx (struct json_object *obj, int idx);
```

JSON Boolearn API

#### json_object_new_boolean

```c
extern struct json_object *json_object_new_boolean (json_bool b);
```

#### json_object_get_boolean

```c
extern json_bool json_object_get_boolean (struct json_object *obj);
```

Intenger API

```c
extern struct json_object* json_object_new_int(int32_t i);
```

```c
extern struct json_object* json_object_new_int64(int64_t i);
```


```c
extern int32_t json_object_get_int(struct json_object *obj);
```

```c
extern int64_t json_object_get_int64(struct json_object *obj);
```

Double API

#### json_object_new_double

```c
extern struct json_object *json_object_new_double (double d);
```

#### json_object_new_double_s

```c
extern struct json_object *json_object_new_double_s (double d, const char *ds);
```
#### json_object_get_double

```c
extern double json_object_get_double (struct json_object *obj);
```

String API

#### json_object_new_string

```c
extern struct json_object *json_object_new_string (const char *s);
```

#### json_object_new_string_len
```c
extern struct json_object *json_object_new_string_len (const char *s, int len);
```

#### json_object_get_string

```c
extern const char* json_object_get_string (struct json_object *obj);
```

#### json_object_get_string_len

```c
extern int json_object_get_string_len (struct json_object *obj);
```