



xfrm_output -> xfrm_output2 -> xfrm_output_resume


xfrm_dev_resume -> dev_hard_start_xmit
esp_output_done -> xfrm_dev_resume
esp_output_tail -> esp_output_done
esp6_output_tail -> esp_output_done

esp_xmit -> esp_output_tail



esp_input_done -> esp_input_done2 -> skb_pull_rcsum

# ESP XFMM ESP4
struct xfrm_type;
output: esp_output -> esp_output_tail
input: esp_input -> esp_input_done






# ESP4 PROTO
struct xfrm4_protocol;
handler: xfrm4_rcv -> xfrm4_rcv_spi
input_handler: xfrm_input ->
cb_handler: esp4_rcv_cb ->




xfrm_input -> xfrm->input
xfrm_input -> xfrm_inner_mode_input -> xfrm_prepare_input/xfrm4_transport_input



xfrm4_rcv_encap -> proto->input_handler

