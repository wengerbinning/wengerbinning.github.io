
## 宏

```c
#define ARRAY_LIST_DEFAULT_SIZE 32
```

## 数据类型


#### struct array_list

```c
struct array_list
{
  void **array;
  int length;
  int size;
  array_list_free_fn *free_fn;
};
```

#### array_list_free_fn

```c
typedef void (array_list_free_fn) (void *data);
```

## 函数接口

#### array_list_new

```c
extern struct array_list* array_list_new(array_list_free_fn *free_fn);
```

#### array_list_free

```c
extern void array_list_free(struct array_list *al);
```

#### array_list_add

```c
extern int array_list_add(struct array_list *al, void *data);
```

#### array_list_put_idx

```c
extern int array_list_put_idx(struct array_list *al, int i, void *data);
```

#### array_list_length

```c
extern int array_list_length(struct array_list *al);
```

#### array_list_sort

```c
extern void array_list_sort (struct array_list *arr, int(*compar)(const void *, const void *));
```