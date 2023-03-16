
## 数据类型

#### struct ctl_table

```c
/* A sysctl table is an array of struct ctl_table: */
struct ctl_table 
{
	const char *procname;		/* Text ID for /proc/sys, or zero */
	void *data;
	int maxlen;
	umode_t mode;
	struct ctl_table *child;	/* Deprecated */
	proc_handler *proc_handler;	/* Callback for text formatting */
	struct ctl_table_poll *poll;
	void *extra1;
	void *extra2;
};
```

#### struct ctl_node

```c
struct ctl_node {
	struct rb_node node;
	struct ctl_table_header *header;
};
```

#### struct ctl_table_header

```c
struct ctl_table_header
{
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
	struct ctl_node *node;
};
```



#### struct ctl_dir

```c
struct ctl_dir {
	/* Header must be at the start of ctl_dir */
	struct ctl_table_header header;
	struct rb_root root;
};
```

#### struct ctl_table_set

```c
struct ctl_table_set {
	int (*is_seen)(struct ctl_table_set *);
	struct ctl_dir dir;
};
```


#### struct ctl_table_root

```c
struct ctl_table_root {
	struct ctl_table_set default_set;
	struct ctl_table_set *(*lookup)(struct ctl_table_root *root,
					   struct nsproxy *namespaces);
	int (*permissions)(struct ctl_table_header *head, struct ctl_table *table);
};
```

#### struct ctl_path

```c
struct ctl_path {
	const char *procname;
};
```

## 函数接口



#### __register_sysctl_table

```c
struct ctl_table_header *__register_sysctl_table (struct ctl_table_set *set, const char *path, struct ctl_table *table);
```

#### 

```c
struct ctl_table_header *__register_sysctl_paths (struct ctl_table_set *set, const struct ctl_path *path, struct ctl_table *table);
```

#### register_sysctl

```c
struct ctl_table_header *register_sysctl (const char *path, struct ctl_table *table);
```

#### register_sysctl_root

```c
void register_sysctl_root (struct ctl_table_root *root);
```

#### register_sysctl_table

```c
struct ctl_table_header *register_sysctl_table (struct ctl_table * table);
```

#### register_sysctl_paths

```c
struct ctl_table_header *register_sysctl_paths (const struct ctl_path *path, struct ctl_table *table);
```


#### unregister_sysctl_table

```c
void unregister_sysctl_table (struct ctl_table_header * table);
```



##### proc_do_large_bitmap

```c
int proc_do_large_bitmap (struct ctl_table *, int, void __user *, size_t *, loff_t *);
```

##### proc_doulongvec_ms_jiffies_minmax
```c
int proc_doulongvec_ms_jiffies_minmax (struct ctl_table *table, int, void __user *, size_t *, loff_t *);
```


##### proc_dostring

```c
int proc_dostring (struct ctl_table *, int, void __user *, size_t *, loff_t *);
```