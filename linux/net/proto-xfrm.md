xfrm是





send packet
-----------

tcp_transmit_skb --> ip_queue_xmit --> ip_route_output_ports -->:
udp_sendmsg -->:
    ip_route_output_flow --> xfrm_loop_route -->:
        ? xfrm4_lookup :
        Y --> xfrm4_output --> xfrm4_output_finish --> xfrm4_output --> xfrm_output_resume --> xfrm_output_one -->:
            -- [ transport ] --> xfrm4_transport_output -->:
            -- [ tunnel ] --> xfrm4_prepare_output --> xfrm4_mode_tunnel_output -->:
                ah_output/esp_output --> ip_output -->|
        N --> ip_output -->|

--------------------------------
Network Driver



receive packet
--------------

ip_rcv_finish --> { Routing Subsystem } --> <A> ip_local_deliver --> ip_local_deliver_finish -->:
    -- [ proto == UDP/TCP ] -->
        udp_rcv/tcp_v4_rcv --> xfrm4_policy_check -->|
    -- [ proto == ESP/AH ] --> xfrm4_rcv --> xfrm_input -->:
        ? xfrm_state_lookup :
        Y --> ah_input -->
        N --> esp_input -->
            -- [ transport ] --> xfrm4_transport_input  -->:
            -- [ tunnel ] --> xfrm4_prepare_input --> xfrm4-extract_input --> xfrm4_mode_tunnel_input -->:
                xfrm4_tansport-finish --> xfrm4_rcv_encap-finish --<A>
--------------------------------------------------
Socket









xfrm4_rcv_encap_finish
