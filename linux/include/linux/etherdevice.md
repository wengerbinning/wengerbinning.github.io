




## 函数接口

#### ether_addr_equal

```c
static inline bool ether_addr_equal (const u8 *addr1, const u8 *addr2)
{
#if defined(CONFIG_HAVE_EFFICIENT_UNALIGNED_ACCESS)
    u32 fold = ((*(const u32 *)addr1) ^ (*(const u32 *)addr2)) | 
               ((*(const u16 *)(addr1 + 4)) ^ (*(const u16 *)(addr2 + 4)));
    
    return fold == 0;
#else
    const u16 *a = (const u16 *)addr1;
    const u16 *b = (const u16 *)addr2;

    return ((a[0] ^ b[0]) | (a[1] ^ b[1]) | (a[2] ^ b[2])) == 0;
#endif
}
```