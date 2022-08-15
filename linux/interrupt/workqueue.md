工作队列是可以允许阻塞与睡眠的下半部的实现，本质就是将工作内容交给内核线程来处理。

## 功能特性

workqueue可以重入并睡眠

## 注意事项


## 源码分析

### 数据结构


数据类型

```c
struct work_struct
struct workqueue_struct;
struct delayed_work;
struct cpu_workqueue_struct;
```

函数接口

```c
void (*work_func_t) (struct work_struct *work);
```