


## 函数接口

#### eth_hdr

```c
static inline struct ethher *eth_hdr (const struct sk_buff *skb)
{
    return (struct ethher *)sjb_mac_header(skb);
}
```
