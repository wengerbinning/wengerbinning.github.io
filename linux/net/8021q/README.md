






```c

```



```Makefile
# PRE
obj-$(subst m,y,$(CONFIG_VLAN_8021Q))	+= vlan_core.o
# OBJS
obj-$(CONFIG_VLAN_8021Q)		        += 8021q.o

# 8021q
8021q-y					            := vlan.o vlan_dev.o vlan_netlink.o
8021q-$(CONFIG_VLAN_8021Q_GVRP)		+= vlan_gvrp.o
8021q-$(CONFIG_VLAN_8021Q_MVRP)		+= vlan_mvrp.o
8021q-$(CONFIG_PROC_FS)			    += vlanproc.o
```


```c
struct vlan_ethhdr {
    unsigned char	h_dest[ETH_ALEN];
    unsigned char	h_source[ETH_ALEN];
	__be16	h_vlan_proto;
	__be16	h_vlan_TCI;
	__be16	h_vlan_encapsulated_proto;
};

```



```c
struct vlan_dev_priv {
	unsigned int    nr_ingress_mappings;
	u32				ingress_priority_map[8];
	unsigned int    nr_egress_mappings;
	struct vlan_priority_tci_mapping   *egress_priority_map[16];

	__be16		    vlan_proto;
	u16				vlan_id;
	u16				flags;

	struct net_device  *real_dev;
	unsigned char	    real_dev_addr[ETH_ALEN];

	struct proc_dir_entry  *dent;
	struct vlan_pcpu_stats __percpu    *vlan_pcpu_stats;

#ifdef CONFIG_NET_POLL_CONTROLLER
	struct netpoll *netpoll;
#endif
};
```


=========================







vlan_core.o
------------



vlan.o
-------



vlan_dev.o
----------
void vlan_setup(struct net_device *dev);
void vlan_dev_set_ingress_priority(const struct net_device *dev, u32 skb_prio, u16 vlan_prio);
int vlan_dev_set_egress_priority(const struct net_device *dev, u32 skb_prio, u16 vlan_prio);
int vlan_dev_change_flags(const struct net_device *dev, u32 flags, u32 mask);
void vlan_dev_get_realdev_name(const struct net_device *dev, char *result); 

static int vlan_dev_open(struct net_device *dev);
static int vlan_dev_stop(struct net_device *dev);
static netdev_tx_t vlan_dev_hard_start_xmit(struct sk_buff *skb,struct net_device *dev);
static int vlan_dev_change_mtu(struct net_device *dev, int new_mtu);
static int vlan_dev_set_mac_address(struct net_device *dev, void *p);
static int vlan_dev_ioctl(struct net_device *dev, struct ifreq *ifr, int cmd);

static int vlan_dev_neigh_setup(struct net_device *dev, struct neigh_parms *pa);


static int vlan_dev_init(struct net_device *dev);
static void vlan_dev_uninit(struct net_device *dev);

----------

static const struct ethtool_ops vlan_ethtool_ops;
static const struct net_device_ops vlan_netdev_ops;






vlan_netlink.o
---------------
