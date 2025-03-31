struct net_device {
    char name[IFNAMSIZ];

};


struct net_device_ops {
    int (*ndo_open) (struct net_device *dev);
    int (*ndo_stop) (struct net_device *dev);
    int (*ndo_set_config) (struct net_device *dev, struct ifmap *map);

    netdev_tx_t	(*ndo_start_xmit)(struct sk_buff *skb, struct net_device *dev);
};


__netdev_start_xmit -> ndo_start_xmit
netdev_start_xmit -> __netdev_start_xmit
dev_queue_xmit_accel -> __netdev_start_xmit
dev_queue_xmit -> __netdev_start_xmit




dev_direct_xmit -> netdev_start_xmit
dev_hard_start_xmit -> xmit_one -> netdev_start_xmit


packet_direct_xmit -> dev_direct_xmit

__dev_queue_xmit -> dev_hard_start_xmit
sch_direct_xmit -> dev_hard_start_xmit





##
struct proto_ops;

sendmsg: packet_sendmsg -> packet_snd
recvmsg: packet_recvmsg


#
struct inet_connection_sock_af_ops;
queue_xmit: ip_queue_xmit -> __ip_queue_xmit


ip_local_out -> __ip_local_out


dst_output -> dst->output


ip_output -> ip_finish_output -> __ip_finish_output -> ip_finish_output2 -> neigh_output -> neigh_hh_output -> dev_queue_xmit
ip_mr_input
ip_mc_output


struct proto_ops



## NET_TX_SOFTIRQ

net_tx_action

## NET_RX_SOFTIRQ

net_rx_action -> napi_poll

## BPF
Documentation/networking/filter.txt
struct bpf_func_proto;
struct bpf_verifier_ops;
sk_attach_filter
sk_attach_bpf
sk_filter_trim_cap
sk_filter


## packet handler

dev_add_pack

##
__netif_receive_skb_core -> deliver_skb

dev_queue_xmit_nit



gro_normal_list -> __netif_receive_skb_list -> __netif_receive_skb_list_core -> __netif_receive_skb_core