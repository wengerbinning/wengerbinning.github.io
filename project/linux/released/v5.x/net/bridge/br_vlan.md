


#### br_vlan_init

```c
int br_vlan_init (struct net_bridge *br)
{
    struct net_bridge_vlan_group *vg;
    int ret = -ENOMEM;

    vg = kzalloc(sizeof(*vg), GFP_KERNEL);
    if (!vg)
        goto out;
    
    ret = rhashtable_init(&vg->vlan_hash, &br_vlan_rht_params);
    if (ret)
        goto err_rhtbl;
    
    INIT_LIST_HEAD(&vg->vlan_list);
    br->vlan_proto = htons(ETH_P_8021Q);
    br->default_pvid = 1;
    rcu_assign_pointer(br->vlgrp, vg);
    ret = br_vlan_addr(br, 1, BRIDGE_VLAN_INFO_PVID | BRIDGE_VLAN_INFO_UNTAGGED | BRIDGE_VLAN_INFO_BRENTRY);
    if (ret)
        goto err_vlan_add;

out:
    return ret;

err_vlan_add:
    rhashtable_destroy(&vg->vlan_hash);

err_rhtbl:
    kfree(vg);

    goto out;
}
```

<!-- net bridge port -->

#### nbp_vlan_init

```c
int nbp_vlan_init (struct net_bridge_port *p)
{
    struct net_bridge_vlan_group *vg;
    int ret = -ENOMEM;

    vg = kzalloc(sizeof(struct net_bridge_vlan_group), GFP_KERNEL);
    if (!vg) {
        goto out;
    }

    ret = rhashtable_init(&vg->vlan_hash, &br_vlan_rht_params);
    if (ret) 
        goto err_rhtbl;

    INIT_LIST_HEAD(&vg->vlgrp, vg);
    rcu_assign_pointer(p->vlgrp, vg);
    if (p->br->default_pvid)
}
```

####