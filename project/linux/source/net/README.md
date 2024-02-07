网络子系统

#### Files

* Kconfig
* Makefile

* socket.c
* sysctl_net.c
* devres.c
* compat.c

#### Call Graph

#### Build Configures

* NET
  <!--  -->
* ETHERNET_PACKET_MANGLE
* WANT_COMPAT_NETLINK_MESSAGES
* COMPAT_NETLINK_MESSAGES
* NET_INGRESS
* NET_EGRESS
* NET_REDIRECT
* SKB_EXTENSIONS
* INET
* SOKC_DIAG
* NETWORK_SECMARK
* NET_PTP_CLASSIFY
<!--  -->
* NETFILTER
* NETFILTER_ADVANCED
* BRIDGE_NETFILTER

#### Symbol Table

<!-- Data Type -->
*
<!-- Data Object -->
* socket_file_ops
* pf_family_name
* net_family_lock
* net_families
* sock_inode_cachep
* sockfs_ops
* sockfs_dentry_operations
<!-- Function Interface -->
* move_addr_to_kernel
* move_addr_to_user
* sock_alloc_inode
* sock_free_inode
* init_once
* init_inodecache
* sockfs_dname
* sockfs_xattr_get
*
* kernel_bind
* kernel_listen
* kernel_accept
* kernel_connect
* kernel_getsockname
* kernel_getpeername
* kernel_sendpage
* kernel_sedpage_locked
* kernel_sock_shutdown
* kernel_sock_ip_overhead

#### Modules

* [core](core.md)



#### device

* dev.o
* ethool.o
* dev_addr_lists.o
* dst.o
* netevent.o
* neighbour.o
* rtnetlink.o
* utils.o
* link_watch.o
* filter.o
* dev_ioctl.o
* tso.o

## Modules

#### core
#### ethernet
#### 802
#### sched
#### netlink
#### ipv6