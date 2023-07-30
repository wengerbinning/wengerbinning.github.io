

## 数据结构

#### enum net_device_flags

```c
enum net_device_flags {
#if __UAPI_DEF_IF_NET_DEVICE_FLAGS
    IFF_UP              = 0x1 << 0x0;
    IFF_BROADCAST       = 0x1 << 0x1;
    IFF_DEBUG           = 0x1 << 0x2;
    IFF_LOOPBACK        = 0x1 << 0x3;
    IFF_POINTTOPOINT    = 0x1 << 0x4; 
    IFF_NOTRAILERS      = 0x1 << 0x5;
    IFF_RUNNING         = 0x1 << 0x6;
    IFF_NOARP           = 0x1 << 0x7;
    IFF_PROMISC         = 0x1 << 0x8;
    IFF_ALLMULIT        = 0x1 << 0x9;
    IFF_MASTER          = 0x1 << 0xA;
    IFF_SLAVE           = 0x1 << 0xB;
    IFF_MULIICAST       = 0x1 << 0xC;
    IFF_PORTSEL         = 0x1 << 0xD;
    IFF_AUTOMEDIA       = 0x1 << 0xE;
    IFF_DYNAMIC         = 0x1 << 0xF;
#endif
#if _UAPI_DEF_IF_NET_DEVICE_FLAGS_LOWER_UP_DORMANT_ECHO
    IFF_LOWER_UP        = 0x1 << 0x10;
    IFF_DORMANT         = 0x1 << 0x11;
    IFF_ECHO            = 0x1 << 0x12;
#endif
};
```