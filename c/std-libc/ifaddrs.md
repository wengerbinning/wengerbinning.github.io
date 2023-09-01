

## 数据结构

#### struct ifaddrs

```c
struct ifaddrs 
{
    struct ifaddrs *ifa_next;
    char *ifa_name;
    unsigned int ifa_flags;
    struct sockaddr *ifa_addr;
    struct sockaddr *ifa_netmask;
    union {
        struct sockaddr *ifu_boradaddr;
        struct sockaddr *ifu_dstaddr;
    } ifa_ifu;

#ifndef ifa_boradaddr
#define ifa_broadaddr ifa_ifu.ifu_boradaddr
#endif
#ifndef ifa_dstaddr
#define ifa_destaddr ifa_ifu.ifu_dstaddr
#endif
};
```