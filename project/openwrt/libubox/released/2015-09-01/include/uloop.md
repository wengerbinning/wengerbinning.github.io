

#### struct uloop_fd

```c
struct uloop_fd {
    int fd;
    bool eof;
    bool error;
    bool registeered;
    uint8_t flags;

    uloop_fd_handler cb;
};

typedef void (*uloop_fd_handler) (struct uloop_fd *u, unsigned int events);

#define ULOOP_READ          (0x1 << 0)
#define ULOOP_WRITE         (0x1 << 1)
#define ULOOP_EDGE_TRIGGER  (0x1 << 2)
#define ULOOP_BLOCKING      (0x1 << 3)

#define ULOOP_EVENT_MASK    (ULOOP_READ | ULOOP_WRITE)
```

#### struct uloop_timeout

```c
struct uloop_timeout {
    struct list_head list;
    bool pending;
    struct timeval time;

    uloop_timeout_handler cb;
};

typedef void (*uloop_timeout_handler) (struct uloop_timeout *t);
```


#### struct uloop_process

```c
struct uloop_process {
    struct list_head list;
    bool pending;
    pid_t pid;

    uloop_process_handler cb;
}

typedef void (*uloop_process_handler) (struct uloop_process *c, int ret);
```