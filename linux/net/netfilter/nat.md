网络地址转换(NAT)是一种修改数据包的网络地址的


SNAT(source nat)
DNAT(dest nat)
FNAT(full nat)



L4LB四层负载均衡




```c
struct nf_nat_l3proto;
struct nf_nat_l4proto;
```


```c
nf_nat_inet_fn
```




ipv4
-------------

```c
nf_nat_ipv4_in
nf_nat_ipv4_out
nf_nat_ipv4_local_fn

// 调用转发
nf_nat_inet_fn
```