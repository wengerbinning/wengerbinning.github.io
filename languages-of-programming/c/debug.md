在C语言的调试中，可以使用一些语言本省提供的一些特性实现。


在调试中可以利用一些语言自身特性来实现编译时错误的检查。


* 利用struct的位域是非负数的特性

```c
#define BUILD_BUG_ON_ZERO(e)                (sizeof(struct{int: -!!(e);}))
#define BUILD_BUG_ON_NULL(e)        ((void *)sizeof(struct{int: -!!(e);}))

#define BUILD_BUG_ON(condition)     ((void)BUILD_BUG_ON_ZERO(condition))
```


* 利用数组索引只能为非负数的特性。

```c
#define MAYBE_BUILD_BUG_ON(condition)  ((void)sizeof(char[1 - 2 * !!(condition)]))
```

> Note:
> 