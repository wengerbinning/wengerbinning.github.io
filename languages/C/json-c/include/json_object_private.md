
## 数据结构

#### json_object_private_delete_fn

```c
typedef void (json_object_private_delete_fn) (struct json_object *o);
```

#### struct json_object

```c
struct json_object
{
  enum json_type o_type;
  json_object_private_delete_fn *_delete;
  json_object_to_json_string_fn *_to_json_string;
  int _ref_count;
  struct printbuf *_pb;
  union data {
    json_bool c_boolean;
    double c_double;
    int64_t c_int64;
    struct lh_table *c_object;
    struct array_list *c_array;
    struct {
        char *str;
        int len;
    } c_string;
  } o;
  json_object_delete_fn *_user_delete;
  void *_userdata;
};
```