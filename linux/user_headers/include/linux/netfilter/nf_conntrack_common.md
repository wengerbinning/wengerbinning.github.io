


## 数据结构

#### 

```c
enum ip_conntrack_info {
    IP_CT_ESTABLISHED,
    IP_CT_RELATED,
    IP_CT_NEW,
    IP_CT_IS_REPLY,

    IP_CT_ESTABLISHED_REPLY = IP_CT_ESTABLISHED + IP_CT_IS_REPLY,
    IP_CT_RELATED_REPLY = IP_CT_RELATED + IP_CT_IS_REPLY,
    
}
```