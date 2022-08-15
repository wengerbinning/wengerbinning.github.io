




## 数据类型



* list

list是一个双向链表的实现

```c
struct list_head;
```

* hlist

hlist是list的一个优化，再头结点只有一个指针域

* hlist_nulls

hlist_nulls是hlist的一个变型

* hlist_bl

hlist_bl是一个hlist的变型


* jhash



## 源码分析


```c
struct hash_bucket;
```



```c
typedef struct {
    int counter;
} atomic_t;
```




```c
struct list_head {
    struct list_head *next, *prev;
};
```


```c
struct hlist_node {
    struct hlist_node *next, **pprev;
};

struct hlist_head {
    struct hlist_node *first;
};

```






## FILES

include/linux/types.h