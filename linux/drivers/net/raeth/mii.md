


#### __mii_mgr_read

```c
u32 __mii_mgr_read (u32 phy_addr, u32 phy_register, u32 *read_data);
```

通过MDIO_PHY_CONTROL_0寄存器按照C22的协议,该寄存器可以按照PIAC寄存器来。


#### __mii_mgr_write

```c
u32 __mii_mgr_write (u32 phy_addr, u32 phy_register, u32 write_data)
```



#### mii_mgr_read

ESW_PHY_POLLING

```c
u32 mii_mgr_read(u32 phy_addr, u32 phy_register, u32 *read_data);

```