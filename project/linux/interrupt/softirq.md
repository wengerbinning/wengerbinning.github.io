软中断(softirq)是随SMP的出现应用而生的，是tasklet的实现基础。

## 功能特性

软中断必须等待内核调度才能执行；
软中断在单个CPU上不能嵌套使用；
同一个软中断可以在多个CPU上并行；
不可阻塞与睡眠。

## 注意事项

软中断必须是可重入函数。





## 源码分析


### 数据结构

枚举类型

```c
enum {
    HI_SOFTIRQ, 
    TIMER_SOFTIRQ,
    NET_TX_SOFTIRQ,
    NET_RX_SOFTIRQ,
    BLOCK_SOFTIRQ,
    BLOCk_IOPOLL_SOFTIRQ,
    TASKLET_SOFTIRQ,
    SCHED_SOFTIRQ,
    HRTIMER_SOFTIRQ,
    RCU_SOFTIRQ,
    NR_SOFTIRQ
};
```

| 


结合体


数据类型

```c
struct softirq_action;
```


### 实例对象


```c
static struct softirq_action    softirq_vec[NR_SOFTIRQS];
```




### 函数接口

```c
void open_softirq(int nr, void (*action)(struct softirq_action *));

void raise_softirq(unsigned int nr);

```



