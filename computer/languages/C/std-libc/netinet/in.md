

## 数据结构

#### struct in_addr

```c
typedef uint32_t in_addr_t;

struct in_addr
{
    int_addr_t s_addr;
}
```

#### struct sockaddr_in

```c
struct sockaddr_in
{
    __SOCKADDR_COMMON(sin_);
    in_port_t sin_port;
    struct in_addr sin_addr;
    unsigned char sin_zero[sizeof(struct sockadddr) - __SOCKADDR_COMMON_SIZE - sizeof(in_port_t) - sizeof(struct in_addr)];
};
```

#### struct in6_addr

```c
struct in6_addr
{
    union {
        uint8_t  __u6_addr8[16];
        uint16_t __u6_addr16[8];
        uint32_t __u6_addr32[4];
    } _in6_u;


};
```

#### struct sockaddr_in6

```c
struct sockaddr_in6
{
    __SOCKADDR_COMMON(sin6_);
    int_port_t sin6_port;
    uint32_t sin6_flowinfo;
    struct in6_addr sin6_addr;
    uint32_t sin6_scope_id;
};
```