


#### socket

```c
int socket (int __domain, int __type, int __protocol);
```


#### bind

```c
int bind (int __fd, __CONST_SOCKADDR_ARG __addr, socklen_t __len);
```

#### connect

```c
int connect (int __fd, __CONST_SOCKADDR_ARG __addr, socklen_t __len);
```
s
#### sendto

```c
ssize_t sendto (int __fd, const void *__buf, size_t __n, int __flags, __CONST_SOCKADDR_ARG __addr, socklen_t __addr_len);
```


#### 