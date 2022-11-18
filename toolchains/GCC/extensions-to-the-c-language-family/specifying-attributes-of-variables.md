

## Common Variables Attributes

这些变量属性支持绝大部分目标平台。


* alias属性用于定义一个变量的别名。

  * 如果

```
alias("target")
```



```c
int target;

extern int __attribute__ ((alias("target"))) alias;
```


* aligned属性


* warn_if_not_aligned属性



* strict_flex_array属性

* alloc_size属性

* alloc_size属性

* cleanup属性


* common属性


* nocommon属性

* copy

* deprecated

* unavailable

* mode

* nonstring

* packed

* section

* tls_model

* unused

* used

* retain

* uninitialized

* vector_size

* visibility


* weak

* noinit

* persistent

* objc_nullability
