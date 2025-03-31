
struct net_device {
    char name[IFNAMSIZ];

};


struct net_device_ops {
    int (*ndo_open) (struct net_device *dev);
    int (*ndo_stop) (struct net_device *dev);
    int (*ndo_set_config) (struct net_device *dev, struct ifmap *map);

    netdev_tx_t	(*ndo_start_xmit)(struct sk_buff *skb, struct net_device *dev);
};


__netdev_start_xmit -> ndo_start_xmit

netdev_start_xmit -> __netdev_start_xmit
dev_queue_xmit_accel -> __netdev_start_xmit
dev_queue_xmit -> __netdev_start_xmit



dev_direct_xmit -> netdev_start_xmit
dev_hard_start_xmit -> xmit_one -> netdev_start_xmit


packet_direct_xmit -> dev_direct_xmit

__dev_queue_xmit -> dev_hard_start_xmit
sch_direct_xmit -> dev_hard_start_xmit