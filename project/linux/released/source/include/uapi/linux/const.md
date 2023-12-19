



#### _AC & _AT

有一部分宏常量会同时使用在汇编代码与C代码中， 不能直接使用字面量，因此提供`_AC_`与`_AT`
两个带参的宏来解决该问题。该机制需要通过`__ASSEMBLY`宏来区分当前使用的场景时汇编代码还
是C代码， 分别采用不同的实现。

* 汇编语言的实现

```
#define _AC(X, Y)   X
#define _AT(T, X)   X
```

* C语言的实现

```
#define __AC(X, Y)  (X##Y)

#define _AC(X, Y)  __AC(X, Y)
#define _AT(T, X)  ((T)(X))
```


