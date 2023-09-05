

## 数据对象

#### br_link_ops

```c
struct rtnl_link_ops br_link_ops __read_mostly = {
    .kind = "bridge",
    .priv_size = sizeof(struct net_bridge),
    .setup = br_dev_setup,
    .maxtype = IFLA_BR_MAX,
    .policy = br_polocy,
    .validate = br_validate,
    .newlink = br_dev_netlink,
    .changelink = br_changelink,
    .dellink = br_dev_delete,
    .get_size = br_get_size,
    .fill_info = br_fill_info,

    .slave_maxtypes = IFLA_BRPORT_MAX,
    .slave_policy = br_port_policy,
    .slave_changelink = br_port_slave_changelink,
    .get_slave_size = br_port_get_slave_size,
    .fill_slave_info = br_port_fill_slave_info,
};
```

## 函数接口

