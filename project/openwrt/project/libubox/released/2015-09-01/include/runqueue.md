



#### struct runqueue

```c
struct runqueue {
    //
    struct safe_list tasks_active;
    struct safe_list tasks_inactive;
    //
    struct uloop_timeout timeout;
    //
    int running_tasks;
    int max_running_tasks;
    //
    bool stopped;
    bool empty;

    //
    void (*empty_cb) (struct runqueue *q);
};
```
#### struct runqueue_task_type

```c
struct runqueue_task_type {
    const char *name;
    
    void (*run) (struct runqueue *q, struct runqueue_task *t);
    void (*cancel) (struct runqueue *q, struct runqueue_task *t, int type);
    void (*kill) (struct runqueue *q, struct runqueue_task *t);
};
```

#### struct runqueue_task

```c
struct runqueue_task {
    struct safe_list list;
    const struct runqueue_task_type *type;
    struct runqueue *q;

    void (*cimplete) (struct runqueue *q, struct runqueue_task *t);

    struct uloop_timeout timeout;
    int run_timeout;
    int cancel_timeout;
    int cancel_type;

    bool queued;
    bool running;
    bool canceled;
};
```


#### struct runqueue_process

```c
struct runqueue_process {
    struct runqueue_task task;
    struct uloop_process proc;
};
```
