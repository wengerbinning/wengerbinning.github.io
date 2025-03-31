



##

netif_receive_skb_internal -> __netif_receive_skb

netif_receive_skb_core -> __netif_receive_skb_one_core
__netif_receive_skb -> __netif_receive_skb_one_core

__netif_receive_skb_one_core -> __netif_receive_skb_core
__netif_receive_skb_list_core -> __netif_receive_skb_core
__netif_receive_skb_core -> deliver_skb

dev_queue_xmit_nit




dev_add_pack
dev_remove_pack


__netif_receive_skb_core:
* ptype_all处理
* 设备rx_handler处理
* 检查VLAN信息
* 更新接口接收统计数据








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

