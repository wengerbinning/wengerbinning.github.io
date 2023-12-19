



* 数据类型

```
struct sk_buff;
```

### 函数接口



* 东向接口

```c

```

* 北向接口

```c
static inline struct dst_entry *skb_dst (const struct sk_buff *skb);
struct inline void skb_dst_set (struct sk_buff *skb, struct dst_entry *dst);
```

* 南向接口


```c
```

* 西向接口

```c
```







* 内部接口

## FILES

include/linux/skbuff.h

