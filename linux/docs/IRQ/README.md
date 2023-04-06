中断处理.



上半部与下半部


#### Top Half


```c
int request_irq (unsigned int irq, irq_header_t handler unsigned long flags, const char *name, void *dev);
```





#### Bottom Half

下半部的机制tasklet, workqueue, softirq, thread_irq



### SoftIRQ

软中断

#### tasklet

tasklet的执行上下文是软中断.

```c
void tasklet_func (unsigned long);

DECLARE_TASKLET(taskletm tasklet_func, data);


// Call in TH.
tasklet_schedule(&tasklet);
```

#### workqueue

workqueue的执行上下文是

