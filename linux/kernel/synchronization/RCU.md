# Read Copy Update

RCU将同步开销的非对称分布发挥到逻辑极限。在RCU机制中，存在以下几个概念：

读侧临界区(read-side critical sections)是对共享数据进行读操作的临界区。

写侧临界区(write-side critical sections)是对共享数据进行写操作的临界区。每次写操作都会有移除
阶段与回收阶段，中间相隔一个宽限期

静默态(Quiescent state)当没有线程运行在读侧临界区，就处于静默态，持续一段时间的静默态称为延长的
静默态。

宽限期(Grace period)宽限期是指所有线程都至少进入一次静默态的时间，宽限期前所有在读侧临界区的在宽
限期后都会结束。




## API


```c
rcu_read_lcok();
```

rcu_read_lock在读取受rcu保护的数据结构时使用，即进入读侧临界区。

```c
rcu_read_unlock();
```

rcu_read_unlock在读取受rcu保护的数据结构完成后使用，即退出读侧临界区。

```c
synchronize_rcu();
```

synchronize_rcu在更新数据后，阻塞等待读线程退出，用来确保读侧临界区结束后释放旧的结构体，

```c
call_rcu();
rcu_assign_pointer();
rcu_dereference();
```
