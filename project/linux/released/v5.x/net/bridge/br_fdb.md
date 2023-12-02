

#### __br_fdb_get

```c
struct net_bridge_fdb_entry *__br_fdb_get (struct net_bridge *br, 
    const unsigned char *addr, __u16 vid)
{
    struct net_bridge_fdb_entry *fdb;

    hlist_for_each_entry_rcu (fdb, &br->hash[br_mac_hash(addr, vid)], hlist) {
        if (ether_addr_equal(fdb->addr.addr, addr) && fdb->vlan_id == vid) {
            if (unlikely(hash_expired(br, fdb)))
                break;
            
            return fdb;
        }
    }

    return NULL;
}
```

```c
EXPORT_SYMBOL_GPL(__br_fdb_get);
```

#### fdb_find

```c
static struct net_bridge_fdb_entry *fdb_find (struct hlist_head *head, 
    const unsigned char *addr, __u16 vid)
{

    return NULL;
}
```