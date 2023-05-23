网络子系统的核心组件







dev.o
------------
static inline int __dev_xmit_skb(struct sk_buff *skb, struct Qdisc *q, struct net_device *dev, struct netdev_queue *txq);

int dev_loopback_xmit(struct sk_buff *skb);
int dev_queue_xmit(struct sk_buff *skb);




flow_dissector.o
-----------------
struct netdev_queue *netdev_pick_tx(struct net_device *dev, struct sk_buff *skb)