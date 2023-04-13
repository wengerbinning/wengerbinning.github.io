<!-- eth0 -->

##### et_get_drvinfo

```c
static void et_get_drvinfo (struct net_device *dev, struct ethtool_drvinfo *info);
```


<!-- Virtual Ethtool OP  eth1 -->

##### et_virt_get_strings

```c
static void et_virt_get_strings (struct net_device *dev, u32 stringset, u8 *data);
```


##### et_virt_get_link

```c
static u32 et_virt_get_link (struct net_device *dev);
```