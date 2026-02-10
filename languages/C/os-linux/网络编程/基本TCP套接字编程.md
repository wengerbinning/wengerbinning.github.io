**sockaddr**

**sockaddr_in**


以下为关于套接字相关的函数操作。在这些函数中可以按照方向的分为从用户空间到内核空间传递套接字的有bind、connect、sendto以及sendmsg；
这几个函数都是调用sockargs函数。从内核空间到用户空间传递套接字的有accept、recvfrom、recvmsg、getpeername以及getsockname。

**socket**

```c
int socket(int __domain, int __type, int __protocol);
```

通过指定一个通信协议族（协议域）、套接字类型、协议类型来返回一个套接字描述符`sockfd`或者错误代码。

**connect**

```c
int connect(int __fd, const sockaddr *__addr, socklen_t __len);
``` 

通过指定一个套接字描述符、套接字地址的指针以及套接字地址的大小来建立与套接字地址指定的服务器的连接，并返回链连接状态。
此时客户端向服务器发送一个SYN的TCP包，在收到服务器回复的ACK后返回结果。

**bind**

```c
int bind(int __fd, const sockaddr *__addr, socklen_t __len);
```

通过指定套接字描述符、套接字地址对象的指针以及套接字地址的大小，来将套接字与套接字地址绑定在一起；返回绑定的结果。

**listen**

```c
int listen(int __fd, int __n);
```

通过指定一个已经绑定套接字地址的套接字描述符以及允许最大连接个数，将socket创建的套接字转化为一个被动的套接字，即允许其他套接字通过该套接字绑定的套接字地址连接到该套接字。

**accept**

```c
int accept(int __fd, struct sockaddr *__addr, socklen_t *__len);
```

通过指定一个被动套接字描述符与一个套接字地址的地址以及套接字地址长度的地址，返回一个新的套接字描述符或错误代码。在这里套接字地址__addr与长度__len都应该是一个非临时的变量的地址，特别是__len在调用时指定了套接字地址的大小，调用结束时存储__addr的长度。
 