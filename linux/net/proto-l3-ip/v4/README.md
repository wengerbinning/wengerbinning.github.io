








## 函数接口

suoyo

* 北向接口

```c
int ip_local_deliver (struct sk_buff *skb);

int ip_local_out (struct net *net, struct sock *sk, struct  sk_buff *skb);
```



#### netfilter







## FILES

net/ipv4/ip_input.c
net/ipv4/ip_output.c