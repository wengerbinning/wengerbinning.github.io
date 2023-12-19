时间管理在内核中非常重要。



节拍率
=====

系统定时器频率，即节拍率是通过静态预处理定义的，也就是HZ，在系统启动时按照HZ值对硬件进行设置。体系不
同，节拍率也不一样，该宏是在`asm/param.h`中定义的，x86的HZ默认为100，表示1/100秒为一个时钟周期。


jiffies
=======

jiffies是一个全局变量，用来记录系统自启动以来产生的节拍数。在设备启动时，内核将该变量初始化为0，此
后每次时钟中断都对该变量加一，jiffies在每秒内增加HZ个值（时钟中断每1/HZ秒内执行一次）。该变量声明
在`linux/jiffies.h`





HZ
==





定时器
=====

定时器是内核控制未来某个时间点（基于jiffies）执行某个函数的机制，API存在与linux/timer.h。该机制
类似与软件中断，被调度的函数异步执行，需要满足以下要求：

* 不允许访问用户空间。
* 不能休眠和调度。
* 任何访问数据结构都应该进行保护，防止并发访问。
* 调用一次后会自动注销，如果需要再次运行，需要在重新注册。

有关定时器的数据结构。

```c
struct timer_list {
	struct list_head entry;
	unsigned long expires;			// 记录多少个jiffy之后执行函数。
	struct tvec_base *base;
	void (*function)(unsigned long);
	unsigned long data;
	int slack;
#ifdef CONFIG_TIMER_STATS
	int start_pid;
	void *start_site;
	char start_comm[16];
#endif
#ifdef

}
```

* 初始化结构体。

```c



init_timer(&time_list_timer);

time_list_timer.function = func_timer_hooker;
time_list_timer.expires = jiffies +(HZ * MILLISEC_PERIOD /1000);
time_list_timer.data =  0;

add_timer( &time_list_timer );
```
