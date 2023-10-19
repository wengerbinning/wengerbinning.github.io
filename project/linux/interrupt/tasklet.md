tasklet是基于softirq实现的，是为了在开发种隐藏softirq的复杂性。


## feature

一种特定类型的tasklet只能运行在一个CPU上，不能并行。
tasklet可以在运行是改变。
不可阻塞与睡眠。


tasklet是基于softirq实现的中断处理机制。

```c
struct tasklet_struct {
    struct tasklet_struct *next;
    unsigned long state;
    atomic_t count;
    void (*func)(unsigned long);
    unsigned long data;
};
```


## Source Code

### 数据结构

数据类型

```c
struct tasklet_struct;
struct tasklet_head;
```

函数接口

```c
void (*tasklet_action)(unssigned long);
```


### 实例对象

```c
static DEFINE_PER_CPU(struct tasklet_head, tasklet_vec);

static DEFINE_PER_CPU(struct tasklet_head, tasklet_hi_vec);
```


### 函数接口

```c
#define DECLARE_TASKLET(name, func, data)   \
struct tasklet_struct   name = {NULL, 0, ATOMIC_INIT(0), func, data}

#define DECLARE_TASKLET_DISABLED(name, func, data)  \
struct tasklet_struct   name = {NULL, 0, ATOMIC_INIT(1), func, data}
```

```c
static inline void tasklet_disable (struct tasklet_struct *t);
static inline void tasklet_enable (struct tasklet_struct *t);
static inline void tasklet_schedule(struct tasklet_struct *t);
tasklet_hi_schedule
tasklet_kill
```


```c
void tasklet_init (struct tasklet_struct *t, void (*func)(unsigned long), unsigned long data);


```



## LINKS

* [CSDN](https://blog.csdn.net/godleading/article/details/52971179)
  <https://blog.csdn.net/godleading/article/details/52971179>