


raw
filter
mangle
nat



NF_INET_PRE_ROUTING:(raw,mangle,nat)
NF_INET_LOCAL_IN:(mangle,filer,nat)
NF_INET_FORWARD:(mangle,filer)
NF_INET_LOCAL_OUT:(raw,mangle,filer,nat)
NF_INET_POST_ROUTING:(mangle,nat)



enum nf_ip_hook_priorities {
	NF_IP_PRI_FIRST = INT_MIN,
	NF_IP_PRI_RAW_BEFORE_DEFRAG = -450,
	NF_IP_PRI_CONNTRACK_DEFRAG = -400,
	NF_IP_PRI_RAW = -300,
	NF_IP_PRI_SELINUX_FIRST = -225,
	NF_IP_PRI_CONNTRACK = -200,
	NF_IP_PRI_MANGLE = -150,
	NF_IP_PRI_NAT_DST = -100,
	NF_IP_PRI_FILTER = 0,
	NF_IP_PRI_SECURITY = 50,
	NF_IP_PRI_NAT_SRC = 100,
	NF_IP_PRI_SELINUX_LAST = 225,
	NF_IP_PRI_CONNTRACK_HELPER = 300,
	NF_IP_PRI_CONNTRACK_CONFIRM = INT_MAX,
	NF_IP_PRI_LAST = INT_MAX,
};


struct nf_hook_ops {
	/* User fills in from here down. */
	nf_hookfn		*hook;
	struct net_device	*dev;
	void			*priv;
	u_int8_t		pf;
	unsigned int		hooknum;
	/* Hooks are ordered in ascending priority. */
	int			priority;
};







##



nf_hook -> nf_hook_slow -> nf_hook_entry_hookfn

NF_HOOK_COND
NF_HOOK
NF_HOOK_LIST

##

ip_rcv:NFPROTO_IPV4->NF_INET_PRE_ROUTING
ip_local_deliver:NFPROTO_IPV4->NF_INET_LOCAL_IN
