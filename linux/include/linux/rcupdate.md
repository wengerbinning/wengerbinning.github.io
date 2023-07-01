
## 模块依赖

* linux/types.h
* linux/cache.h
* linux/spinlock.h
* linux/threads.h
* linux/cpumask.h
* linux/seqlock.h
* linux/lockdep.h
* linux/completion.h
* linux/debugobjects.h
* linux/bug.h
* linux/compiler.h
* linux/ktime.h
* asm/barrier.h


## 数据结构

## 数据对象


#### rcu_lock_map

```c
extern struct lockdep_map rcu_lock_map;
```

#### rcu_bh_lock_map

```c
extern struct lockdep_map rcu_bh_lock_map;
```

#### rcu_sched_lock_map;

```c
extern struct lockdep_map rcu_sched_lock_map;
```

#### rcu

## 函数接口

#### RCU_INITIALIZER

```c
#define RCU_INITIALIZER(v)  ((typeof(*v) __force __rcu *) (v))
```

#### rcu_init

```c
void rcu_init (void);
```

#### __rcu_read_lock


```c
#ifdef CONFIG_PREEMPT_RCU

void __rcu_read_lock (void);

#else

static inline void __rcu_read_lock (void)
{
    if (IS_ENABLED(CONFIG_PREEMPT_COUNT))
        preempt_disable();
}

#endif /* CONFIG_PREEMPT_RCU */
```

#### __rcu_read_unlock

```c
#ifdef CONFIG_PREEMPT_RCU

void __rcu_read_unlock (void);

#else

static inline void __rcu_read_unlock (void)
{
    if (IS_ENABLED(CONFIG_PREEMPT_COUNT))
        preempt_enable();
}

#endif /* CONFIG_PREEMPT_RCU */
```

#### rcu_read_unlock_special

```c
void rcu_read_unlock_special (struct task_struct *t);
```

#### synchronize_rcu

```c
#ifdef CONFIG_PREEMPT_RCU

void synchronize_rcu (void);

#else

static inline void synchronize_rcu (void)
{
    synchronize_sched();
}

#endif /* CONFIG_PREEMPT_RCU */
```


#### rcu_read_lock

```c
static inline void rcu_read_lock (void)
{
    __rcu_read_lock();
    __acquire(RCU);
    rcu_lock_acquire(&rcu_lock_map);
    RCU_LOCKDEP_WARN(!rcu_is_watching, 
        "rcu_read_lock() used illegally while idle");
}
```

#### rcu_read_unlock

```c
static inline void rcu_read_unlock (void)
{
    RCU_LOCKDEP_WARN(!rcu_is_watching, 
        "rcu_read_unlock() used illegally while idle");
    __release(RCU);
    __rcu_read_unlock();
    rcu_lock_release(&rcu_lock_map);
}
```