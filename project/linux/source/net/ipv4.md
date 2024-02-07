IPv4实现了一个 struct packet_type 类型 ETH_P_IP

```c
static struct packet_type ip_packet_type __read_mostly = {
    .type = cpu_to_be16(ETH_P_IP),
    .func = ip_rcv
    .list_func = ip_list_rcv,
};
```




#### output

```
ip_local_out -> __ip_local_out -> nf_hook -> dst_output
```



#### input

```
ip_rcv_finish -> ip_rcv_finish_core -> ip_route_input_noref

ip_rcv -> NF_HOOK(NF_INET_PRE_ROUTING) -> ip_rcv_finish
ip_list_rcv -> ip_sublist_rcv -> NF_HOOK_LIST(NF_INET_PRE_ROUTING) -> ip_rcv_finish
```


#### xfrm


xfrm4_transport_finish



#### route

```
ip_route_inout_slow -> ip_mkroute_input
ip_route_inout_slow -> skb_dst_set_noref

ip_route_input_noref -> ip_route_input_rcu -> ip_route_inout_slow
```