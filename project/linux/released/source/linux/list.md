
* 宏

```c
#define LIST_HEAD_INIT(name)    {&(name), &(name)}

#define LIST_HEAD(name)         struct list_head name = LIST_HEAD_INIT(name);


```


* 函数接口

```c
INIT_LIST_HEAD





```








## FILES

include/linux/list.h