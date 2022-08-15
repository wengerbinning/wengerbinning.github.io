

## Common Function Attributes

这类函数属性在绝大多数目标平台都支持。

* access

* alias属性

```
alias ("target")
```


```c
void __f() {}

void f () __attribute__ ((alias("__f")))
```