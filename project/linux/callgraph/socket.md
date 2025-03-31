



__sys_sendto -> sock_sendmsg



sock_sendmsg -> sock_sendmsg_nosec
sock_sendmsg_nosec -> sock->ops->sendmsg

## struct proto_ops

struct proto_ops inet_stream_ops
* sendmsg:inet_sendmsg

struct proto_ops inet_dgram_ops
* sendmsg:inet_sendmsg

sendmsg:inet6_sendmsg


##

inet_sendmsg -> sk->sk_prot->sendmsg

## struct proto

struct proto raw_prot
* sendmsg:raw_sendmsg
struct proto tcp_prot
* sendmsg:tcp_sendmsg
struct proto udp_prot
* sendmsg:udp_sendmsg
struct proto ping_prot
* sendmsg:ping_v4_sendmsg


##

raw_sendmsg -> ip_push_pending_frames -> ip_send_skb -> ip_local_out
ip_local_out -> dst->output

##

struct xfrm_state_afinfo xfrm4_state_afinfo
* output:xfrm4_output
* output_finish:xfrm4_output_finish

##

xfrm4_outpu -> __xfrm4_output -> afinfo->output_finish
output_finish: xfrm4_output_finish -> xfrm_output
xfrm4_output_finish -> xfrm_output -> xfrm_output2 -> xfrm_output_resume -> dst_output -> dev->xmit

##

struct xfrm_type_offload esp_type_offload
* xmit:esp_xmit

##

esp_xmit -> esp_output_tail -> crypto_aead_encrypt