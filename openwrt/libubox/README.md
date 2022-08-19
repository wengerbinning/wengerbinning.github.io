







































uloop
=====

uloop是基于kqueue或者epoll实现的IO复用框架。

```c
static int pool_fd = -1;
```

```c

int uloop_init();
```

```c
int  uloop_fd_add(struct uloop_fd *sock, unsigned int flags);
```

```c
int uloop_run(void);
```

```c
int uloop_done(void);
```

runqueue
========

runqueue是使用uloop的定时器实现的任务队列。


* 初始化任务队列。

```c
void runqueue_init(struct runqueue *q);
```

* 取消任务队列。

```c
void runqueue_cancel(struct runqueue *q);
```

* 杀死所有任务。

```c
void runqueue_kill(struct runqueue *q);
```

* 停止所有任务。

```c
void runqueue_stop(struct runqueue *q);
```

* 重新开始任务。

```c
void runqueue_resume(struct runqueue *q);
```
