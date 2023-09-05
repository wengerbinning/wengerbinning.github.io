

## 模块依赖

* linux/list.h
* linux/rcupdate.h
* linux/wait.h
* linux/rbtree.h

* uapi/linux/sysctl.h

## 数据结构

#### proc_hander

```c
typedef int proc_handler (struct ctl_table *ctl, int write, void __user *buffer, size_t *lenp, loff_t *ppos);
```

#### struct ctl_table_poll

```c
struct ctl_table_poll {
    atomic_t event;
    wait_queue_head_t wait;
};
```

#### struct ctl_table

```c
struct ctl_table {
    const char procname;
    void *data;
    int maxlen;
    umode_t mode;
    struct ctl_table *child;
    proc_handler *prco_handler;
    struct ctl_table_poll *poll;
    void *extra1;
    void *extra2;
};
```

```c
typedef struct ctl_table ctl_table;
```

#### struct ctl_node

```c
struct ctl_node {
    struct rb_node node;
    struct ctl_table_header *header;
}
```

#### struct ctl_table_header

```c
struct ctl_table_header {
    union {
        struct {
            struct ctl_table *ctl_table;
            int used;
            int count;
            int nreg;
        };
        struct rcu_head rcu;
    };
    struct completion *unregistering;
    struct ctl_table *ctl_table_arg;
    struct ctl_table_root *root;
    struct ctl_table_set *set;
    struct ctl_dir *parent;
    struct ctl_node _node; 
};
```

#### struct ctl_dir

```c
struct ctl_dir {
    struct ctl_table_header header;
    struct rb_root root;
};
```

#### struct ctl_table_set

```c
struct ctl_table_set {
    int (*is_seen) (struct ctl_table_set *);
    struct ctl_dir dir;
};
```

#### struct ctl_table_root

```c
struct ctl_table_root {
    struct ctl_table_set default_set;
    struct ctl_table_set *(*lookup) (struct ctl_table_root *root, struct nsproxy *namespaces);
    w
}
```

## 函数接口

#### register_sysctl_root

```c
void register_sysctll_root (struct ctl_table_root *root);
```

#### __register_sysctl_table

```c
struct ctl_table_header *__register_sysctl_table (struct ctl_table_set *set, const char *path, struct ctl_table *table);
```


#### __register_sysctl_paths

```c
struct ctl_table_header *__register_sysctl_paths (struct ctl_table_set *set, const struct ctl_path *path, struct ctl_table *table);
```


####  register_sysctl

```c
struct ctl_table_header *register_sysctl (const char *path, struct ctl_table *table);
```

#### register_sysctl_table

```c
struct ctl_table_header *register_sysctl_table (struct ctl_table *table);
```

#### register_sysctl_paths

```c
struct ctl_table_header *register_sysctl_paths (const struct ctl_path *path, struct ctl_table *table);
```

#### unregister_sysctl_table

```c
void unregister_sysctl_table (struct ctl_table_header *table);
```

#### setup_sysctl_set

```c
extern void setup_sysctl_set (struct ctl_table_set *p, struct ctl_table_root *root, int (*is_seen) (struct ctl_table_set *));
```

#### register_sysctl_root

```c
void register_sysctl_root (struct ctl_table_root *root);
```

#### retire_sysctl_set

```c
extern void retire_sysctl_set (struct ctl_table_set *set);
```

#### proc_sys_poll_notify 

```c
void proc_sys_poll_notify (struct ctl_table_poll *poll);
```

通用的回调函数接口

#### proc_dostring

```c
extern int proc_dostring (struct ctl_table *, int, void __user *, size_t *, loff_t *);
```


#### proc_dointvec

```c
extern int proc_dointvec (struct ctl_tabe *, int, void __user *, size_t *, loff_t *);
```