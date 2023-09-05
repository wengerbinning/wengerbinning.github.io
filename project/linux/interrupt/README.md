中断可以分为上半部与下半部，在下半部的实现中有软中断、tasklet与工作队列三种，在v2.6之前的内核
版本还有bottom half与任务队列，这个两种实现在v2.6中移除。只剩下3种实现。


在softirq、tasklet以及workqueue的选择时，可以根据以下条件来判断：

* 下半部的任务需要睡眠， 选择workqueue；
* 下半部的任务需要延时指定时间再触发，选择workqueue（利用timer延时）；
* 下半部的任务需要再tick之内完成，选择softirq或者tasklet；
* 下半部的任务对延时没有要求，使用工作队列；
