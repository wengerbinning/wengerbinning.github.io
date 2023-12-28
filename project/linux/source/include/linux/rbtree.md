
#### struct rb_node

```c
struct rb_node {
    unsigned long __rb_parent_color;
    struct rb_node *rb_right;
    struct rb_node *rb_left;
} __attribute__((aligned(sizeof(long))));
```



#### struct rb_root

```c
struct rb_root {
    struct rb_node *rb_node;
}
```



## 函数接口

####