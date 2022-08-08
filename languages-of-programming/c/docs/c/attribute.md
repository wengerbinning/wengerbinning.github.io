`__attribute__`提供一种方式，来为变量、函数参数、结构体、联合体等设置特殊属性。这些属性可以分为多
种类型。

常见的变量属性
-----------

* `alias("var_target")`变量属性指定该变量是指定变量的别名。

```c
int var_target;
extern int __attribute__ ((alias ("var_target"))) var_alias;
```

变量var_alias是var_target的别名，并且当var_alias与var_target必须不在一个`translation unit`
内时报错。

* `aligned`与`aligned(alignment)`变量属性指定该变量的最小对齐方式，以字节为单位；指定参数时，
参数必须是2的整数次方；无参数时，表示最大对齐方式，通常时8字节与16字节

```c
int x __attribute__ ((aligned (16))) = 0;
// or
struct foo { int x[2] __attribute__ ((aligned (8))); };
```

当然，也可以使用宏`__BIGGEST_ALIGNMENT__`来指定。

* `deprecated`与`deprecated(msg)`属性会在使用该对象时出现警告信息，一般用于提示该对象在未来被
弃用。

```c
extern int old_var __attribute__ ((deprecated));
extern int old_var;
int new_fn () { return old_var; }
```

* `unavailable`与`unavailable(msg)`属性表示对象不可用。

```c

```


* `mode`属性

* `nonstring`属性

* `packed`属性

* `tls_model("tls_model")`
