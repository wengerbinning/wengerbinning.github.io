



```
hnat_probe -> hnat_init_debugfs
hnat_probe -> hnat_enable_hook
```


```
hnat_remove -> hant_disable_hook
```


```
mtk_hnat_nf_post_routing -> mtk_hnat_dscp_update




mtk_hnat_ipv4_nf_pre_routing -> hant_set_head_frags
mtk_hnat_ipv4_nf_pre_routing -> do_hnat_ext_to_ge
mtk_hnat_ipv4_nf_pre_routing -> do_ge2ext_fast

mtk_hnat_ipv4_nf_post_routing -> mtk_hnat_nf_post_routing

mtk_hant_ipv4_nf_local_out -> hnat_set_head_frags


mtk_hnat_ipv6_nf_pre_routing
mtk_hnat_ipv6_nf_post_routing
mtk_hnat_ipb6_nf_local_out

mtk_hnat_br_nf_local_in -> do_hnat_ext_to_ge
mtk_hnat_br_nf_local_in -> do_hnat_ext_to_ge2
mtk_hnat_br_nf_local_in -> do_hnat_ge_to_ext

mtk_hnat_br_nf_local_out -> mtk_hnat_nf_post_routing

mtk_pong_hqos_hander -> do_ext2_ge_fast_learn
mtk_pong_hqos_hander -> do_ge2ext_fast

hnat_enable_hook -> hnat_register_nf_hooks -> nf_register_net_hooks
```

```
mtk_sw_nat_hook_tx
```

```
mtk_ppe_dev_register_hook
```

```
mtk_ppe_dev_unregister_hook
```

```
foe_clear_all_bind_entries
```