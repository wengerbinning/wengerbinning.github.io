


```c
struct context_1

```


```c
struct context {
    struct options options;
    bool first_time;
    int mode;
    struct gc_arena gc;
    struct env_set *es;
    openvpn_net_ctx_t net_ctx;
    struct signal_info *sig;
    struct plugin_list *plugins;
    bool did_we_daemonize;
    struct context_persist persist;
    struct context_0 *c0;
    struct context_1  c1;
    struct context_2  c2;
};
```