## 预处理宏

```c

#define __htonl(x)  __cpu_to_be32(x)
#define __htons(x)  __cpu_to_be16(x)
#define __ntohl(x)  __be32_to_cpu(x)
#define __ntohs(x)  __be32_to_cpu(x)

#define htonl(x)    __htonl(x)
#define ntohl(x)    __ntohl(x)
#define htons(x)    __htons(x)
#define ntohs(x)    __ntohs(x)
```



## 函数接口

#### le16_to_cpu

```c
static inline void le16_to_cpu (__be16 *var, u16 val) {

}
```