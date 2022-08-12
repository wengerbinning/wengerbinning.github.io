软中断(softirq)是在编译期间静态分配的。


```c
/* include/linux/interrupt.h */
struct softirq_action {
	void (*action)(struct softirq_action *);
};

/* kernel/softirq.c */
static struct softirq_action softirq_vec[NR_SOFTIRQ];



```

NR_SOFTIRQ

softirq_vec[]


NET_TX_SOFTIRQ
NET_RX_SOFTIRQ

TASKLET_SOFTIRQ
HI_SOFTIRQ

SCHED_SOFTIRQ

HRTIMER_SOFTIRQ
