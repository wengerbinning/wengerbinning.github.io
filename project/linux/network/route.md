



#### struct dst_entry

```c
struct dst_entry {
	struct net_device       *dev;
	struct  dst_ops	        *ops;
	unsigned long		_metricps;
	unsigned long           exires;
#ifdef CONFIG_XFRM
	struct xfrm_state	*xfrm;
#else
	void			*__pad1;
#endif
	int			(*input)(struct sk_buff *);
	int			(*output)(struct net *net, struct sock *sk, struct sk_buff *skb);

	unsigned short		flags;
#define DST_HOST		0x0001
#define DST_NOXFRM		0x0002
#define DST_NOPOLICY	0x0004
#define DST_NOCOUNT		0x0008
#define DST_FAKE_RTABLE		0x0010
#define DST_XFRM_TUNNEL		0x0020
#define DST_XFRM_QUEUE		0x0040
#define DST_METADATA		0x0080

	/* A non-zero value of dst->obsolete forces by-hand validation
	 * of the route entry.  Positive values are set by the generic
	 * dst layer to indicate that the entry has been forcefully
	 * destroyed.
	 *
	 * Negative values are used by the implementation layer code to
	 * force invocation of the dst_ops->check() method.
	 */
	short			obsolete;
#define DST_OBSOLETE_NONE	0
#define DST_OBSOLETE_DEAD	2
#define DST_OBSOLETE_FORCE_CHK	-1
#define DST_OBSOLETE_KILL	-2
	unsigned short		header_len;	/* more space at head required */
	unsigned short		trailer_len;	/* space to reserve at tail */

	/*
	 * __refcnt wants to be on a different cache line from
	 * input/output/ops or performance tanks badly
	 */
#ifdef CONFIG_64BIT
	atomic_t		__refcnt;	/* 64-bit offset 64 */
#endif
	int			__use;
	unsigned long		lastuse;
	struct lwtunnel_state   *lwtstate;
	struct rcu_head		rcu_head;
	short			error;
	short			__pad;
	__u32			tclassid;
#ifndef CONFIG_64BIT
	atomic_t		__refcnt;	/* 32-bit offset 64 */
#endif
};
```
