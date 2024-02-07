netlink是用于实现用户进程与内核进程通信的机制。



net/netlink/af_netlink.h
net/netlink/af_netlink.c
net/netlink/diag.c




#### af_netlink.o

* nl_table
* nl_table_wait
* nl_table_lock
* nl_table_users
* netlink_boradcast_deliver
* do_one_broadcast
* netlink_broadcast_filtered
* netilink_broadcast
* netlink_proto
* __netlink_kernel_create
* netlink_create
* netlink_release
* netlink_rcv_skb