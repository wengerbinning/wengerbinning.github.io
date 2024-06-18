#### struct lws_context

```c
struct lws_context {
 #if defined(LWS_WITH_SERVER)
	char canonical_hostname[96];
 #endif

#if defined(LWS_WITH_FILE_OPS)
	struct lws_plat_file_ops fops_platform;
#endif

#if defined(LWS_WITH_ZIP_FOPS)
	struct lws_plat_file_ops fops_zip;
#endif

	lws_system_blob_t system_blobs[LWS_SYSBLOB_TYPE_COUNT];

#if defined(LWS_WITH_SYS_SMD)
	lws_smd_t				smd;
#endif
#if defined(LWS_WITH_SECURE_STREAMS)
	struct lws_ss_handle			*ss_cpd;
#endif
	lws_sorted_usec_list_t			sul_cpd_defer;

#if defined(LWS_WITH_NETWORK)
	struct lws_context_per_thread		pt[LWS_MAX_SMP];
	lws_retry_bo_t				default_retry;
	lws_sorted_usec_list_t			sul_system_state;

	lws_lifecycle_group_t			lcg[LWSLCG_COUNT];

	const struct lws_protocols		*protocols_copy;

#if defined(LWS_WITH_NETLINK)
	lws_sorted_usec_list_t			sul_nl_coldplug;
	/* process can only have one netlink socket, have to do it in ctx */
	lws_dll2_owner_t			routing_table;
	struct lws				*netlink;
#endif

#if defined(LWS_PLAT_FREERTOS)
	struct sockaddr_in			frt_pipe_si;
#endif

#if defined(LWS_WITH_HTTP2)
	struct http2_settings			set;
#endif

#if LWS_MAX_SMP > 1
	struct lws_mutex_refcount		mr;
#endif

#if defined(LWS_WITH_SYS_METRICS)
	lws_dll2_owner_t			owner_mtr_dynpol;
	/**< owner for lws_metric_policy_dyn_t (dynamic part of metric pols) */
	lws_dll2_owner_t			owner_mtr_no_pol;
	/**< owner for lws_metric_pub_t with no policy to bind to */
#endif

#if defined(LWS_WITH_NETWORK)
/*
 * LWS_WITH_NETWORK =====>
 */

	lws_dll2_owner_t		owner_vh_being_destroyed;

	lws_metric_t			*mt_service; /* doing service */
	const lws_metric_policy_t	*metrics_policies;
	const char			*metrics_prefix;

#if defined(LWS_WITH_SYS_METRICS) && defined(LWS_WITH_CLIENT)
	lws_metric_t			*mt_conn_tcp; /* client tcp conns */
	lws_metric_t			*mt_conn_tls; /* client tcp conns */
	lws_metric_t			*mt_conn_dns; /* client dns external lookups */
	lws_metric_t			*mth_conn_failures; /* histogram of conn failure reasons */
#if defined(LWS_ROLE_H1) || defined(LWS_ROLE_H2)
	lws_metric_t			*mt_http_txn; /* client http transaction */
#endif
#if defined(LWS_WITH_SYS_ASYNC_DNS)
	lws_metric_t			*mt_adns_cache; /* async dns lookup lat */
#endif
#if defined(LWS_WITH_SECURE_STREAMS)
	lws_metric_t			*mth_ss_conn; /* SS connection outcomes */
#endif
#if defined(LWS_WITH_SECURE_STREAMS_PROXY_API)
	lws_metric_t			*mt_ss_cliprox_conn; /* SS cli->prox conn */
	lws_metric_t			*mt_ss_cliprox_paylat; /* cli->prox payload latency */
	lws_metric_t			*mt_ss_proxcli_paylat; /* prox->cli payload latency */
#endif
#endif /* client */

#if defined(LWS_WITH_SERVER)
	lws_metric_t			*mth_srv;
#endif

#if defined(LWS_WITH_EVENT_LIBS)
	struct lws_plugin		*evlib_plugin_list;
	void				*evlib_ctx; /* overallocated */
#endif

#if defined(LWS_WITH_TLS)
	struct lws_context_tls		tls;
#if defined (LWS_WITH_TLS_JIT_TRUST)
	lws_dll2_owner_t		jit_inflight;
	/* ongoing sync or async jit trust lookups */
	struct lws_cache_ttl_lru	*trust_cache;
	/* caches host -> truncated trust SKID mappings */
#endif
#endif
#if defined(LWS_WITH_DRIVERS)
	lws_netdevs_t			netdevs;
#endif

#if defined(LWS_WITH_SYS_ASYNC_DNS)
	lws_async_dns_t			async_dns;
#endif

#if defined(LWS_WITH_SYS_FAULT_INJECTION)
	lws_fi_ctx_t			fic;
	/**< Toplevel Fault Injection ctx */
#endif

#if defined(LWS_WITH_CACHE_NSCOOKIEJAR) && defined(LWS_WITH_CLIENT)
	struct lws_cache_ttl_lru *l1, *nsc;
#endif

#if defined(LWS_WITH_SYS_NTPCLIENT)
	void				*ntpclient_priv;
#endif

#if defined(LWS_WITH_SECURE_STREAMS)
	struct lws_ss_handle		*hss_fetch_policy;
#if defined(LWS_WITH_SECURE_STREAMS_SYS_AUTH_API_AMAZON_COM)
	struct lws_ss_handle		*hss_auth;
	lws_sorted_usec_list_t		sul_api_amazon_com;
	lws_sorted_usec_list_t		sul_api_amazon_com_kick;
#endif
#if !defined(LWS_WITH_SECURE_STREAMS_STATIC_POLICY_ONLY)
	struct lws_ss_x509		*server_der_list;
#endif
#endif

#if defined(LWS_WITH_SYS_STATE)
	lws_state_manager_t		mgr_system;
	lws_state_notify_link_t		protocols_notify;
#endif
#if defined (LWS_WITH_SYS_DHCP_CLIENT)
	lws_dll2_owner_t		dhcpc_owner;
					/**< list of ifaces with dhcpc */
#endif

	/* pointers */

	struct lws_vhost		*vhost_list;
	struct lws_vhost		*no_listener_vhost_list;
	struct lws_vhost		*vhost_pending_destruction_list;
	struct lws_vhost		*vhost_system;

#if defined(LWS_WITH_SERVER)
	const char			*server_string;
#endif

	const struct lws_event_loop_ops	*event_loop_ops;
#endif

#if defined(LWS_WITH_TLS)
	const struct lws_tls_ops	*tls_ops;
#endif

#if defined(LWS_WITH_PLUGINS)
	struct lws_plugin		*plugin_list;
#endif

#ifdef _WIN32
/* different implementation between unix and windows */
	struct lws_fd_hashtable fd_hashtable[FD_HASHTABLE_MODULUS];
#else
	struct lws **lws_lookup;

#endif

/*
 * <====== LWS_WITH_NETWORK end
 */

#endif /* NETWORK */

	lws_log_cx_t			*log_cx;
	const char			*name;

#if defined(LWS_WITH_SECURE_STREAMS_PROXY_API)
	const char	*ss_proxy_bind;
	const char	*ss_proxy_address;
#endif

#if defined(LWS_WITH_FILE_OPS)
	const struct lws_plat_file_ops *fops;
#endif

	struct lws_context **pcontext_finalize;
#if !defined(LWS_PLAT_FREERTOS)
	const char *username, *groupname;
#endif

#if defined(LWS_WITH_MBEDTLS)
	mbedtls_entropy_context mec;
	mbedtls_ctr_drbg_context mcdc;
#endif

#if defined(LWS_WITH_THREADPOOL) && defined(LWS_HAVE_PTHREAD_H)
	struct lws_threadpool *tp_list_head;
#endif

#if defined(LWS_WITH_PEER_LIMITS)
	struct lws_peer			**pl_hash_table;
	struct lws_peer			*peer_wait_list;
	lws_peer_limits_notify_t	pl_notify_cb;
	time_t				next_cull;
#endif

	const lws_system_ops_t		*system_ops;

#if defined(LWS_WITH_SECURE_STREAMS)
#if !defined(LWS_WITH_SECURE_STREAMS_STATIC_POLICY_ONLY)
	const char			*pss_policies_json;
	struct lwsac			*ac_policy;
	void				*pol_args;
#endif
	const lws_ss_policy_t		*pss_policies;
	const lws_ss_auth_t		*pss_auths;
#if defined(LWS_WITH_SSPLUGINS)
	const lws_ss_plugin_t		**pss_plugins;
#endif
#endif

	void *external_baggage_free_on_destroy;
	const struct lws_token_limits *token_limits;
	void *user_space;

#if defined(LWS_WITH_SERVER)
	const struct lws_protocol_vhost_options *reject_service_keywords;
	lws_reload_func deprecation_cb;
#endif

#if !defined(LWS_PLAT_FREERTOS)
	void (*eventlib_signal_cb)(void *event_lib_handle, int signum);
#endif

#if defined(LWS_HAVE_SYS_CAPABILITY_H) && defined(LWS_HAVE_LIBCAP)
	cap_value_t caps[4];
	char count_caps;
#endif

	lws_usec_t time_up; /* monotonic */
#if defined(LWS_WITH_SYS_SMD)
	lws_usec_t smd_ttl_us;
#endif
	uint64_t options;

	time_t last_ws_ping_pong_check_s;
#if defined(LWS_WITH_SECURE_STREAMS)
	time_t					last_policy;
#endif

#if defined(LWS_PLAT_FREERTOS)
	unsigned long time_last_state_dump;
	uint32_t last_free_heap;
#endif

	unsigned int max_fds;
#if !defined(LWS_NO_DAEMONIZE)
	pid_t started_with_parent;
#endif

#if !defined(LWS_PLAT_FREERTOS)
	uid_t uid;
	gid_t gid;
	int fd_random;
	int count_cgi_spawned;
#endif

	unsigned int fd_limit_per_thread;
	unsigned int timeout_secs;
	unsigned int pt_serv_buf_size;
	unsigned int max_http_header_data;
	unsigned int max_http_header_pool;
	int simultaneous_ssl_restriction;
	int simultaneous_ssl;
	int simultaneous_ssl_handshake_restriction;
	int simultaneous_ssl_handshake;
#if defined(LWS_WITH_TLS_JIT_TRUST)
	int		vh_idle_grace_ms;
#endif

#if defined(LWS_WITH_PEER_LIMITS)
	uint32_t pl_hash_elements;	/* protected by context->lock */
	uint32_t count_peers;		/* protected by context->lock */
	unsigned short ip_limit_ah;
	unsigned short ip_limit_wsi;
#endif

#if defined(LWS_WITH_SYS_SMD)
	uint16_t smd_queue_depth;
#endif

#if defined(LWS_WITH_NETLINK)
	lws_route_uidx_t			route_uidx;
#endif

	char		tls_gate_accepts;

	unsigned int deprecated:1;
	unsigned int inside_context_destroy:1;
	unsigned int being_destroyed:1;
	unsigned int service_no_longer_possible:1;
	unsigned int being_destroyed2:1;
	unsigned int requested_stop_internal_loops:1;
	unsigned int protocol_init_done:1;
	unsigned int doing_protocol_init:1;
	unsigned int done_protocol_destroy_cb:1;
	unsigned int evlib_finalize_destroy_after_int_loops_stop:1;
	unsigned int max_fds_unrelated_to_ulimit:1;
	unsigned int policy_updated:1;

#if defined(LWS_WITH_NETLINK)
	unsigned int nl_initial_done:1;
#endif

	unsigned short count_threads;
	unsigned short undestroyed_threads;
	short plugin_protocol_count;
	short plugin_extension_count;
	short server_string_len;
	unsigned short deprecation_pending_listen_close_count;

#if defined(LWS_WITH_SECURE_STREAMS_PROXY_API)
	uint16_t	ss_proxy_port;
#endif

	/* 0 if not known, else us resolution of the poll wait */
	uint16_t us_wait_resolution;

	uint8_t max_fi;
	uint8_t captive_portal_detect;
	uint8_t captive_portal_detect_type;

	uint8_t		destroy_state; /* enum lws_context_destroy */
};
```

#### struct lws

```c
struct lws {

	struct lws_a			a;

	/* structs */

#if defined(LWS_ROLE_H1) || defined(LWS_ROLE_H2)
	struct _lws_http_mode_related	http;
#endif

#if defined(LWS_ROLE_H2)
	struct _lws_h2_related		h2;
#endif

#if defined(LWS_ROLE_WS)
	struct _lws_websocket_related	*ws; /* allocated if we upgrade to ws */
#endif

#if defined(LWS_ROLE_DBUS)
	struct _lws_dbus_mode_related	dbus;
#endif

#if defined(LWS_ROLE_MQTT)
	struct _lws_mqtt_related	*mqtt;
#endif

#if defined(LWS_ROLE_H2) || defined(LWS_ROLE_MQTT)
	struct lws_muxable		mux;
	struct lws_tx_credit		txc;
#endif

	lws_lifecycle_t			lc;

	/* lifetime members */

#if defined(LWS_WITH_EVENT_LIBS)
	void				*evlib_wsi; /* overallocated */
#endif

	lws_sorted_usec_list_t		sul_timeout;
	lws_sorted_usec_list_t		sul_hrtimer;
	lws_sorted_usec_list_t		sul_validity;
	lws_sorted_usec_list_t		sul_connect_timeout;

	struct lws_dll2			dll_buflist; /* guys with pending rxflow */
	struct lws_dll2			same_vh_protocol;
	struct lws_dll2			vh_awaiting_socket;

#if defined(LWS_WITH_SYS_ASYNC_DNS)
	struct lws_dll2			adns; /* on adns list of guys to tell result */
	lws_async_dns_cb_t		adns_cb; /* callback with result */
#endif

#if defined(LWS_WITH_SERVER)
	struct lws_dll2			listen_list;
#endif

#if defined(LWS_WITH_CLIENT)
	struct lws_dll2			dll_cli_active_conns;
	struct lws_dll2			dll2_cli_txn_queue;
	struct lws_dll2_owner		dll2_cli_txn_queue_owner;

	/**< caliper is reused for tcp, tls and txn conn phases */

	lws_dll2_t			speculative_list;
	lws_dll2_owner_t		speculative_connect_owner;
	/* wsis: additional connection candidates */
	lws_dll2_owner_t		dns_sorted_list;
	/* lws_dns_sort_t: dns results wrapped and sorted in a linked-list...
	 * deleted as they are tried, list empty == everything tried */
#endif

#if defined(LWS_WITH_SYS_FAULT_INJECTION)
	lws_fi_ctx_t			fic;
	/**< Fault Injection ctx for the wsi, hierarchy wsi->vhost->context */
	lws_sorted_usec_list_t		sul_fault_timedclose;
	/**< used to inject a fault that closes the wsi after a random time */
#endif

#if defined(LWS_WITH_SYS_METRICS)
	lws_metrics_caliper_compose(cal_conn)
#endif

	lws_sockaddr46			sa46_local;
	lws_sockaddr46			sa46_peer;

	/* pointers */

	struct lws			*parent; /* points to parent, if any */
	struct lws			*child_list; /* points to first child */
	struct lws			*sibling_list; /* subsequent children at same level */

	const struct lws_role_ops	*role_ops;
	struct lws_sequencer		*seq;	/* associated sequencer if any */
	const lws_retry_bo_t		*retry_policy;

	lws_log_cx_t			*log_cx;

#if defined(LWS_WITH_THREADPOOL) && defined(LWS_HAVE_PTHREAD_H)
	lws_dll2_owner_t		tp_task_owner; /* struct lws_threadpool_task */
#endif

#if defined(LWS_WITH_PEER_LIMITS)
	struct lws_peer			*peer;
#endif

#if defined(LWS_WITH_UDP)
	struct lws_udp			*udp;
#endif

#if defined(LWS_WITH_CLIENT)
	struct client_info_stash	*stash;
	char				*cli_hostname_copy;

#if defined(LWS_WITH_CONMON)
	struct lws_conmon		conmon;
	lws_usec_t			conmon_datum;
#endif
#endif /* WITH_CLIENT */

	void				*user_space;
	void				*opaque_parent_data;

	struct lws_buflist		*buflist; /* input-side buflist */
	struct lws_buflist		*buflist_out; /* output-side buflist */

#if defined(LWS_WITH_TLS)
	struct lws_lws_tls		tls;
	char				alpn[24];
#endif

	lws_sock_file_fd_type		desc; /* .filefd / .sockfd */

	lws_wsi_state_t			wsistate;
	lws_wsi_state_t			wsistate_pre_close;

	/* ints */
#define LWS_NO_FDS_POS (-1)
	int				position_in_fds_table;

#if defined(LWS_WITH_CLIENT)
	int				chunk_remaining;
	int				flags;
#endif

	unsigned int		cache_secs;
	short				bugcatcher;

	unsigned int			hdr_parsing_completed:1;
	unsigned int			mux_substream:1;
	unsigned int			upgraded_to_http2:1;
	unsigned int			mux_stream_immortal:1;
	unsigned int			h2_stream_carries_ws:1; /* immortal set as well */
	unsigned int			h2_stream_carries_sse:1; /* immortal set as well */
	unsigned int			h2_acked_settings:1;
	unsigned int			seen_nonpseudoheader:1;
	unsigned int			listener:1;
	unsigned int			pf_packet:1;
	unsigned int			do_broadcast:1;
	unsigned int			user_space_externally_allocated:1;
	unsigned int			socket_is_permanently_unusable:1;
	unsigned int			rxflow_change_to:2;
	unsigned int			conn_stat_done:1;
	unsigned int			cache_reuse:1;
	unsigned int			cache_revalidate:1;
	unsigned int			cache_intermediaries:1;
	unsigned int			favoured_pollin:1;
	unsigned int			sending_chunked:1;
	unsigned int			interpreting:1;
	unsigned int			already_did_cce:1;
	unsigned int			told_user_closed:1;
	unsigned int			told_event_loop_closed:1;
	unsigned int			waiting_to_send_close_frame:1;
	unsigned int			close_needs_ack:1;
	unsigned int			ipv6:1;
	unsigned int			parent_pending_cb_on_writable:1;
	unsigned int			cgi_stdout_zero_length:1;
	unsigned int			seen_zero_length_recv:1;
	unsigned int			rxflow_will_be_applied:1;
	unsigned int			event_pipe:1;
	unsigned int			handling_404:1;
	unsigned int			protocol_bind_balance:1;
	unsigned int			unix_skt:1;
	unsigned int			close_when_buffered_out_drained:1;
	unsigned int			h1_ws_proxied:1;
	unsigned int			proxied_ws_parent:1;
	unsigned int			do_bind:1;
	unsigned int			validity_hup:1;
	unsigned int			skip_fallback:1;
	unsigned int			file_desc:1;
	unsigned int			conn_validity_wakesuspend:1;
	unsigned int			dns_reachability:1;

	unsigned int			could_have_pending:1; /* detect back-to-back writes */
	unsigned int			outer_will_close:1;
	unsigned int			shadow:1; /* we do not control fd lifecycle at all */

#if defined(LWS_WITH_SECURE_STREAMS)
	unsigned int			for_ss:1;
	unsigned int			bound_ss_proxy_conn:1;
	unsigned int			client_bound_sspc:1;
	unsigned int			client_proxy_onward:1;
#endif

	unsigned int                    tls_borrowed:1;
	unsigned int                    tls_borrowed_hs:1;
	unsigned int                    tls_read_wanted_write:1;

#ifdef LWS_WITH_ACCESS_LOG
	unsigned int			access_log_pending:1;
#endif

#if defined(LWS_WITH_CLIENT)
	unsigned int			do_ws:1; /* whether we are doing http or ws flow */
	unsigned int			chunked:1; /* if the clientside connection is chunked */
	unsigned int			client_rx_avail:1;
	unsigned int			client_http_body_pending:1;
	unsigned int			transaction_from_pipeline_queue:1;
	unsigned int			keepalive_active:1;
	unsigned int			keepalive_rejected:1;
	unsigned int			redirected_to_get:1;
	unsigned int			client_pipeline:1;
	unsigned int			client_h2_alpn:1;
	unsigned int			client_mux_substream:1;
	unsigned int			client_mux_migrated:1;
	unsigned int			client_subsequent_mime_part:1;
	unsigned int                    client_no_follow_redirect:1;
	unsigned int                    client_suppress_CONNECTION_ERROR:1;
	/**< because the client connection creation api is still the parent of
	 * this activity, and will report the failure */
	unsigned int			tls_session_reused:1;
	unsigned int			perf_done:1;
	unsigned int			close_is_redirect:1;
	unsigned int			client_mux_substream_was:1;
#endif

#ifdef _WIN32
	unsigned int sock_send_blocking:1;
#endif

	uint16_t			ocport, c_port, conn_port;
	uint16_t			retry;

#if defined(LWS_WITH_CLIENT)
	uint16_t			keep_warm_secs;
#endif

	/* chars */

	char lws_rx_parse_state; /* enum lws_rx_parse_state */
	char rx_frame_type; /* enum lws_write_protocol */
	char pending_timeout; /* enum pending_timeout */
	char tsi; /* thread service index we belong to */
	char protocol_interpret_idx;
	char redirects;
	uint8_t rxflow_bitmap;
	uint8_t bound_vhost_index;
	uint8_t lsp_channel; /* which of stdin/out/err */

#ifdef LWS_WITH_CGI
	char hdr_state;
#endif

#if defined(LWS_WITH_CLIENT)
	char chunk_parser; /* enum lws_chunk_parser */
	uint8_t addrinfo_idx;
	uint8_t sys_tls_client_cert;
	uint8_t c_pri;
#endif

	uint8_t		af;

#if defined(LWS_WITH_CGI) || defined(LWS_WITH_CLIENT)
	char reason_bf; /* internal writeable callback reason bitfield */
#endif

#if defined(LWS_WITH_NETLINK)
	lws_route_uidx_t		peer_route_uidx;
	/**< unique index of the route the connection is estimated to take */
#endif
	uint8_t immortal_substream_count;
	/* volatile to make sure code is aware other thread can change */
	volatile char handling_pollout;
	volatile char leave_pollout_active;

#if LWS_MAX_SMP > 1
	volatile char undergoing_init_from_other_pt;
#endif
};
```


##

* lws_context_user


* lws_malloc
* lws_realloc
* lws_zalloc

* lws_free

* lws_wsi_user
* lws_wsi_tsi

* lws_get_parent
lws_get_child
