json_tokener提供序列化与反序列化json对象的接口。


## 模块依赖

#### 外部模块

* stddef

#### 内部模块

* json_object

## 预编译指令

```c
#define JSON_TOKENER_DEFAULT_DEPTH 32

#define JSON_TOKENER_STRICT  0x01
```

## 数据类型

#### enum json_tokener_error

```c
enum json_tokener_error {
  json_tokener_success,
  json_tokener_continue,
  json_tokener_error_depth,
  json_tokener_error_parse_eof,
  json_tokener_error_parse_unexpected,
  json_tokener_error_parse_null,
  json_tokener_error_parse_boolean,
  json_tokener_error_parse_number,
  json_tokener_error_parse_array,
  json_tokener_error_parse_object_key_name,
  json_tokener_error_parse_object_key_sep,
  json_tokener_error_parse_object_value_sep,
  json_tokener_error_parse_string,
  json_tokener_error_parse_comment,
  json_tokener_error_size
};
```

#### enum json_tokener_state

```c
enum json_tokener_state {
  json_tokener_state_eatws,
  json_tokener_state_start,
  json_tokener_state_finish,
  json_tokener_state_null,
  json_tokener_state_comment_start,
  json_tokener_state_comment,
  json_tokener_state_comment_eol,
  json_tokener_state_comment_end,
  json_tokener_state_string,
  json_tokener_state_string_escape,
  json_tokener_state_escape_unicode,
  json_tokener_state_boolean,
  json_tokener_state_number,
  json_tokener_state_array,
  json_tokener_state_array_add,
  json_tokener_state_array_sep,
  json_tokener_state_object_field_start,
  json_tokener_state_object_field,
  json_tokener_state_object_field_end,
  json_tokener_state_object_value,
  json_tokener_state_object_value_add,
  json_tokener_state_object_sep,
  json_tokener_state_array_after_sep,
  json_tokener_state_object_field_start_after_sep,
  json_tokener_state_inf
};
```

#### struct json_tokener_srec

```c
struct json_tokener_srec
{
  enum json_tokener_state state, saved_state;
  struct json_object *obj;
  struct json_object *current;
  char *obj_field_name;
};
```

#### struct json_tokener

```c
struct json_tokener
{
  char *str;
  struct printbuf  *pb;
  int   max_depth, depth, is_double, st_pos, char_offset;
  enum json_tokener_error err;
  unsigned int ucs_char;
  char  quote_char;
  struct json_tokener_srec *stack;
  int   flags;
};
```

##


## 函数接口

#### json_tokener_error_desc

```c
const char *json_tokener_error_desc (enum json_tokener_error jerr);
```

#### json_tokener_get_error

```c
enum json_tokener_error json_tokener_get_error (struct json_tokener *tok);
```


#### json_tokener_new

```c
extern struct json_tokener *json_tokener_new (void);
```

#### json_tokener_new_ex

```c
extern struct json_tokener *json_tokener_new_ex (int depth);
```

#### json_tokener_free

```c
extern void json_tokener_free (struct json_tokener *tok);
```

#### json_tokener_reset

```c
extern void json_tokener_reset (struct json_tokener *tok);
```

#### json_tokener_parse

```c
extern struct json_object *json_tokener_parse (const char *str);
```

#### json_tokener_parse_verbose

```c
extern struct json_object *json_tokener_parse_verbose (const char *str, enum json_tokener_error *error);
```

#### json_tokener_set_flags

```c
extern void json_tokener_set_flags (struct json_tokener *tok, int flags);
```

#### json_tokener_parse_ex

该接口用于将字符串解析为json对象。

```c
extern struct json_object *json_tokener_parse_ex (struct json_tokener *tok, const char *str, int len);
```