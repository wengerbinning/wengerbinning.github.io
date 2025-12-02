

ip_rcv -> NF_HOOK(NF_INET_PRE_ROUTING) -> ip_rcv_finish
ip_sublist_rcv -> NF_HOOK_LIST(NF_INET_PRE_ROUTING) -> ip_rcv_finish
ip_sublist_rcv -> ip_list_rcv_finish

ip_rcv_finish -> ip_rcv_finish_core
ip_rcv_finish -> dst_input

ip_list_rcv_finish -> ip_rcv_finish_core

ip_rcv_finish_core -> ip_route_input_noref






ip_local_deliver -> ip_local_deliver_finish




__ip_local_out -> nf_hook(NFPROTO_IPV4,NF_INET_LOCAL_OUT,dst_output)




Protocol Stack





struct sk_buff {

}




* UDP/TCP/AH/ESP
* IP/ICMP
* Ethernet/VLAN/PPP








netif_receive_skb()/napi_gro_receive()


int netif_receive_skb_core (struct sk_buff *skb);
int netif_receive_skb (struct sk_buff *skb);
void netif_receive_skb_list (struct list_head *head);


gro_result_t napi_gro_receive (struct napi_struct *napi, struct sk_buff *skb)


int __netif_receive_skb_core (struct sk_buff **pskb, bool pfmemalloc, struct packet_type **ppt_prev)
* 时间戳检查
* 解析协议(VLAN, OFFLOAD, QoS)
* 数据处理
* 数据递送(VLAN, )







IPv4
----

IBOUND
int ip_rcv(struct sk_buff *skb, struct net_device *dev, struct packet_type *pt, struct net_device *orig_dev)
* 检查数据
* Netfilter 的 NF_INET_PRE_ROUTING 处理
* 检查数据(分片, TCP, UDP)
* 数据路由
* 数据统计
* 数据递送