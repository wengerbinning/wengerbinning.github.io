
void netif_napi_add (struct net_device *dev, struct napi_struct *napi,
	int (*poll)(struct napi_struct *, int), int weight)
{
	INIT_LIST_HEAD(&napi->poll_list);

	hrtimer_init(&napi->timer, CLOCK_MONOTONIC, HRTIMER_MODE_REL_PINNED);
	napi->timer.function = napi_watchdog;

	init_gro_hash(napi);
	napi->skb = NULL;
	INIT_LIST_HEAD(&napi->rx_list);
	napi->rx_count = 0;

	napi->poll = poll;

	if (weight > NAPI_POLL_WEIGHT)
		netdev_err_once(dev, "%s() called with weight %d\n", __func__, weight);
	napi->weight = weight;
	napi->dev = dev;

#ifdef CONFIG_NETPOLL
	napi->poll_owner = -1;
#endif

	set_bit(NAPI_STATE_SCHED, &napi->state);
	set_bit(NAPI_STATE_NPSVC, &napi->state);
	list_add_rcu(&napi->dev_list, &dev->napi_list);

	napi_hash_add(napi);

	/* Create kthread for this napi if dev->threaded is set.
	 * Clear dev->threaded if kthread creation failed so that
	 * threaded mode will not be enabled in napi_enable().
	 */
	if (dev->threaded && napi_kthread_create(napi))
		dev->threaded = 0;
}
EXPORT_SYMBOL(netif_napi_add);