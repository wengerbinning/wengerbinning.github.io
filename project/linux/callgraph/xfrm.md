## XFRM

xfrm4_output __xfrm4_output -> afinfo->output_finish

## struct xfrm_state_afinfo xfrm4_state_afinfo

output_finish: xfrm4_output_finish -> xfrm_output

xfrm_output -> xfrm_output2 -> xfrm_output_resume -> dst_output

## struct xfrm_type_offload esp_type_offload

xmit:esp_xmit

ip_finish_output2 -> neigh_output


neigh_hh_output -> dev_queue_xmit -> __dev_queue_xmit  -> validate_xmit_skb



validate_xmit_skb -> validate_xmit_xfrm



esp_output_tail ->