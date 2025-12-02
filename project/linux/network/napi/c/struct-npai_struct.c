


struct napi_struct {
	/* The poll_list must only be managed by the entity which
	 * changes the state of the NAPI_STATE_SCHED bit.  This means
	 * whoever atomically sets that bit can add this napi_struct
	 * to the per-CPU poll_list, and whoever clears that bit
	 * can remove from the list right before clearing the bit.
	 */
	struct list_head poll_list;
	struct hrtimer timer;

	unsigned int napi_id;
	unsigned long state;
	unsigned long gro_bitmask;
	int weight;
	int rx_count;

#ifdef CONFIG_NETPOLL
	int poll_owner;
#endif

	int (*poll) (struct napi_struct *, int);

	struct hlist_node napi_hash_node;
	struct net_device *dev;
	struct list_head dev_list;
	struct gro_list gro_hash[GRO_HASH_BUCKETS];
	struct sk_buff *skb;

	struct task_struct *thread;
};

enum {
	NAPI_STATE_SCHED, /* Poll is scheduled */
	NAPI_STATE_MISSED, /* reschedule a napi */
	NAPI_STATE_DISABLE, /* Disable pending */
	NAPI_STATE_NPSVC, /* Netpoll - don't dequeue from poll_list */
	NAPI_STATE_HASHED, /* In NAPI hash (busy polling possible) */
	NAPI_STATE_NO_BUSY_POLL, /* Do not add in napi_hash, no busy polling */
	NAPI_STATE_IN_BUSY_POLL, /* sk_busy_loop() owns this NAPI */
	NAPI_STATE_THREADED, /* The poll is performed inside its own thread*/
	NAPI_STATE_SCHED_THREADED, /* Napi is currently scheduled in threaded mode */
};

enum {
	NAPIF_STATE_SCHED	 = BIT(NAPI_STATE_SCHED),
	NAPIF_STATE_MISSED	 = BIT(NAPI_STATE_MISSED),
	NAPIF_STATE_DISABLE	 = BIT(NAPI_STATE_DISABLE),
	NAPIF_STATE_NPSVC	 = BIT(NAPI_STATE_NPSVC),
	NAPIF_STATE_HASHED	 = BIT(NAPI_STATE_HASHED),
	NAPIF_STATE_NO_BUSY_POLL = BIT(NAPI_STATE_NO_BUSY_POLL),
	NAPIF_STATE_IN_BUSY_POLL = BIT(NAPI_STATE_IN_BUSY_POLL),
	NAPIF_STATE_THREADED	 = BIT(NAPI_STATE_THREADED),
	NAPIF_STATE_SCHED_THREADED	= BIT(NAPI_STATE_SCHED_THREADED),
};