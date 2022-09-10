



```c

#define be32_to_cpu __be32_to_cpu
#define cpu_to_be32 __cpu_to_be32


```



```c
#define __ntohl(x)  __be32_to_cpu(x)
#define __htonl(x)  __cpu_to_be32(x)
#define __ntohs(x)  __be16_to_cpu(x)
#define __htons(x)  __cpu_to_be16(x)

#define ntoshl  __ntohl
#define htonl   __ntonl
#define ntohs   __ntohs
#define htons   __htons
```





## FILES

include/linux/byteorder/generic.h

include/uapi/linux/byteorder/little_endian.h
include/upai/linux/byteorder/big_endian.h

user_headers/include/linux/byteorder/litter_endian.h
user_headers/include/linxu/byteorder/big_endian.h