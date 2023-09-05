





### 函数接口

```c
static inline struct iphdr *ip_hdr (const struct sk_buff *skb);

static inline struct iphdr *inner_ip_hdr(const struct sk_buff *skb);

static inline struct iphdr ipip_hdr (const struct sk_buff *skb);
```







## FILES

include/linux.ip.h
include/uapi/linux/ip.h

