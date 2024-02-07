ppp(pptp, pppoe, ppox)

#### Generial

```
ppp_create_interface -> ppp_dev_configure
```

```
ppp_send_frame -> pad_compress_skb
ppp_send_frame -> pad_compress_skb -> ppp_push -> pch->chan->ops->start_xmit
ppp_xmit_process -> __ppp_xmit_process -> ppp_send_frame
ppp_start_xmit -> ppp_xmit_process
```

```
ppp_receive_frame -> ppp_receive_nonmp_frame -> netif_rx
ppp_input -> ppp_decompress
ppp_input -> ppp_do_recv -> ppp_receive_frame
```

#### PPTP

pptp_sk_proto

```
pptp_xmit -> skb_realloc_headroom
pptp_xmit -> skb_pull
pptp_xmit -> ip_local_out
```

```
pptp_rcv -> sk_receive_skb
pptp_rcv_core -> ppp_input
```

