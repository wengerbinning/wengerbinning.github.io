Linux在访问设备时， 存在一下几种IO模型：

阻塞IO模型(Blocking I/O Model)
非阻塞IO模型(Nonblocking I/O Model)

IO多路复用模型(I/O Multiplexing Model)
信号驱动IO模型(Signal Driven I/O Model)
异步IO模型(Asynchronous I/O Model)



#### Block I/O Model

在IO访问时，如果条件没有满足， 当前任务会被切换，直到满足才被切换回来。存在任务被阻塞的缺点。

#### Nonblock I/O Model

在IO访问时， 如果条件没有满足， 直接返回； 存在轮询操作导致CPU占用率较高的缺点。


#### I/O Multiplexing Model

IO多路复用模型在linux中使用了select/poll/epoll机制来实现的。



##### select

select是BSD UNIX引入的

select --> SYSCALL --> core_sys_select --> do_select

在 do_select 中：

poll_initwait --> poll_schedule_timeout --> poll_freewait

p->qproc --> poll_wait --> poll

在driver中：

poll --> poll_wait


wake_up_interruptible



##### poll

poll是 system V引入的



##### epoll


