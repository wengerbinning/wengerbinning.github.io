该模块提供有关位操作的接口。


宏函数
-----

*GENMASK(h, l)*

GENMASK(h, l)用于获取l到h的掩码。

```c
#define GENMASK(h, l) (((1UL << ((h) - (l) + 1)) - 1) << (l))
```

```c

#define __GENMASK(h, l) (((~UL(0)) - (UL(1) << (l)) + 1) & (~UL(0) >> (BIT_PER_LONG -1 -(h))))

#define GENMASK(h, l) (GENMASK_INPUT_CHECK(h, l) + _GENMASK(h, l)) 
```
