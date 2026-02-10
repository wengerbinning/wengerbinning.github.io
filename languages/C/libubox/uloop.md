# libubox

libubox是openwrt中的基础库，许多应用都是基于该库进行开发的，例如uhttpd， netifd, ubusd等。
libubox主要提供一套基于事件驱动的机制，同时提供链表、键值链表、平衡二叉树、MD5以及json等。

## uloop

其中uloop是一个模块，用于提供三个功能：定时器事件处理、进程事件处理、文件描述符事件处理。uloop_run会轮询处理这三类任务。

**定时器事件处理**

```c
struct uloop_timeout {
    struct list_head list;      /** 节点指针 */
    bool pending;               /** true: 有效定时器 ，flase: 删除该定时器 */
    uloop_timeout_handle cb;    /** 回调函数 * /
    struct timeval time;        /** 定时时间 */
};

// 注册定时器。用户不直接使用，被uloop_timeout_set调用。
int uloop_tiemout_add(struct uloop_timeout * timeout);
// 设置定时器时间。
int uloop_timeout_set(struct uloop_timeout * timeout, int msecs);
// 获取定时器剩余时间。
int uloop_timeout_remaining(struct uloop_timeout * timeout);
// 销毁定时器。
int uloop_timeout_cancel(struct uloop_timeout * timeout);
```

**进程事件处理**

```c
typedef void (*uloop_process_handler)(struct uloop_process *c, int ret);

struct uloop_process {
    struct list_head list;
    bool pending;               
    uloop_process_handler cb;   /** 回调函数，进程退出时执行。 */
    pid_t pid;                  /** 文件描述符 */
};

// 注册新的进程到进程事件处理循环
int uloop_process_add(struct uloop_process * p);
// 从进程处理循环中销毁该进程事件
int uloop_process_delete(struct uloop_process * p);
```

**文件描述符事件处理**

文件描述符事件处理是基于一个uloop_fd的抽象数据类型来实现的，具体内容如下：

```c
struct uloop_fd {
    uloop_fd_handle cb; /** 文件描述符处理函数 */
    int fd;             /** 文件描述符 */
    bool eod;           /** EOF */
    bool error;         /** error */
    bool registered;    /** 是否已添加到epoll的监控队列 */
    uint8_t flags;      /** 一些权限标志 */
};
```

* `int uloop_fd_add(struct uloop_fd *sock, unigned int flags);`

注册一个文件描述符到事件处理循环,最多支持10个文件描述符。

* `int uloop_fd_delete(struct uloop_fd *sock);`

删除一个文件描述符从事件处理循环中。


## usock

usock
