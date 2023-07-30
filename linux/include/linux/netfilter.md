

## 数据结构

#### struct nf_hook_state

```c
struct nf_hook_state {
    unsigned int hook;
    int thresh;
    u_int8_t pf;
    struct net_device *in;
    struct net_device *out;
    struct sock *sk;
    struct net *net;
    struct list_head *hook_list;
    int (*okfn) (struct net *, struct sock *, struct sk_buff *);
};
```