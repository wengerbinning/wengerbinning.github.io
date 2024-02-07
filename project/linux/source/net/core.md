

#### Files

* datagram.h
* net-sysfs.h
* sock_destructor.h
<!--  -->
* sock.c
* sock_diag.c
* sock_map.c
* sock_reuseport.c
* dev.c
* dev_ioctl.c
* bpf_sk_storage.c
* datagram.c
* dev_addr_lists.c
* dst.c
* dst_cache.c
* devlink.c
* drop_monitor.c
* failover.c
* fib_notifier.c
* fib_rules.c
* filter.c
* flow_dissector.c
* flow_offload.c
* gen_estimator.c
* gen_stats.c
* gro_cells.c
* hwbm.c
* link_watch.c
* lwt_bpf.c
* lwtunnel.c
* Makefile
* neighbour.c
* netclassid_cgroup.c
* netevent.c
* net_namespace.c
* netpoll.c
* netprio_cgroup.c
* net-procfs.c
* net-sysfs.c
* net-traces.c
* of_net.c
* page_pool.c
* pktgen.c
* ptp_classifier.c
* request_sock.c
* result
* rtnetlink.c
* scm.c
* secure_seq.c
* selftests.c
* skbuff.c
* skmsg.c
* stream.c
* sysctl_net_core.c
* timestamping.c
* tso.c
* xdp.c
* utils.c


#### Call Graph

```
dev_queue_xmit -> __dev_queue_xmit -> __dev_xmit_skb

__dev_xmit_skb -> q->enqueue
__dev_xmit_skb -> sch_ditect_xmit

netif_receive_skb_core -> __netif_receive_skb_core -> __netif_recevie_skb_core

netif_receive_skb_list -> netif_receive_skb_list_internal -> __netif_receive_skb_list -> __netif_receive_skb_list_core -> __netif_recevie_skb_core

__netif_schedule -> __netif_reschedule -> raise_softirq_irqoff

__napi_schedule -> ____napi_schedule -> wake_up_process


napi_threaded_poll -> __napi_poll


napi_gro_receive -> dev_gro_receive -> naip_skb_finish -> gro_normal_one ->  gro_normal_list -> netif_receive_skb_list_internal



netif_rx -> netif_rx_internal -> enqueue_to_backlog -> __skb_queue_tail



net_tx_action -> qdisc_run -> __qdisc_run
net_tx_action -> qdisc_run -> __qdisc_run



qdisc_restart -> sch_direct_xmit

__qdisc_run -> qdisc_restart
__qdisc_run -> __netif_schedule



netdev_start_xmit -> __netdev_start_xmit -> ops->ndo_start_xmit

dev_hard_start_xmit -> xmit_one -> netdev_start_xmit
```

#### Symbol Table

<!-- Data Type -->
* ptype_base
* ptype_all
* ptype_lock
* offload_base
* offload_lock
<!-- Data Object -->
* ptype_head
<!-- Function Interface -->
* dev_add_pack
* __dev_get_by_name
* dev_get_by_name_rcu
* dev_get_by_name
* __dev_get_by_index
* dev_get_by_index_rcu
* dev_get_by_index
* dev_gro_receive
* __dev_xmit_skb
* dev_loopback_xmit
* __dev_queue_xmit
* dev_queue_xmit
* dev_queue_xmit_accel
* dev_direct_xmit
* deliver_skb
* deliver_ptype_list_skb
* netif_receive_skb_list_internal
* __napi_poll
* napi_threaded_poll
* napi_kthread_create
* netif_napi_add
* napi_gro_receive
* napi_skb_finish
* __napi_schedule
* gro_normal_list
* gro_normal_one

#### net_namespace.o

* pernet_list
* first_device
* net_mutex

* net_namespace_list
* init_net


* net_assign_generic
* ops_init

* __register_pernet_operations
* __unregister_pernet_operations
* register_pernet_operations
* unregister_pernet_operations

* register_pernet_subsys
* unregister_pernet_subsys

##### link_watch.o

* linkwatch_flags
* linkwatch_nextevent
* lweventlist
* lweventlist_lock
* linkwatch_work
* __linkwatch_run_queue
* linkwatch_schedule_work
* linkwatch_fire_event

##### neighbour.o

neigh_direct_output


##### rtnnetlink.o

* struct rtnl_link
* rtnl_mutex
* rtnl_lock
* __rtnl_unlock
* rtnl_unlock
