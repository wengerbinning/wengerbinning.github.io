









ip_rcv -> ip_rcv_finish -> ip_rcv_finish_core -> ip_route_input_noref
ip_local_deliver -> ip_local_deliver_finish -> ip_protocol_deliver_rcu



int ip_rcv(struct sk_buff *skb, struct net_device *dev, struct packet_type *pt, struct net_device *orig_dev);



