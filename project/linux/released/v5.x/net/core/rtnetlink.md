

## 数据结构

#### struct rtnl_link

```c
struct rtnl_link {
    rtnl_doit_func doit;
    rtnl_dumpit_func dumpit;
    rtnl_calcit_func calcit;
};
```



## 数据对象

#### rtnl_mutex

```c
static DEFINE_NUTEX(rtnl_mutex);
```


## 函数接口

#### rtnl_lock

```c
void rtnl_lock (void) {
    mutex_lock(rtnl_mutex);
}
```

```c
EXPORT_SYMBOL(rtnl_lock);
```


#### __rtnl_unlock

```c
void __rtnl_unlock (void) {
    mutex_unlock(rtnl_mutex);
}
```

#### rtnl_unlock

```c
void rtnl_unlock (void)
{
    netdev_run_todo();
}
```

```c
EXPORT_SYMBOL(rtnl_unlock);
```