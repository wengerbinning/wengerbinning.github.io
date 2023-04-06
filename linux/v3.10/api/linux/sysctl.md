## 宏

#### __CTL_TABLE_POLL_INITIALIZER

```c
#define __CTL_TABLE_POLL_INITIALIZER(name) \
{ \
	.event = ATOMIC_INIT(0), \
	.wait = __WAIT_QUEUE_HEAD_INITIALIZER(name.wait) \
}
```

#### DEFINE_CTL_TABLE_POLL

```c
#define DEFINE_CTL_TABLE_POLL(name) \
	struct ctl_table_poll name = __CTL_TABLE_POLL_INITIALIZER(name)
```


## 数据类型


#### struct ctl_table_poll 

```c
/* file: include/linux/sysctl.h */

struct ctl_table_poll {
	atomic_t event;
	wait_queue_head_t wait;
};
```

#### proc_handler

```c
/* file: include/linux/sysctl.h */

typedef int proc_handler (struct ctl_table *ctl, int write, void __user *buffer, size_t *lenp, loff_t *ppos);
```

#### struct ctl_table

```c
/* file: include/linux/sysctl.h */

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
/* file: include/linux/sysctl.h */

struct ctl_node {
	struct rb_node node;
	struct ctl_table_header *header;
};
```

#### struct ctl_table_header

```c
/* file: include/linux/sysctl.h */

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
/* file: include/linux/sysctl.h */

struct ctl_dir {
	/* Header must be at the start of ctl_dir */
	struct ctl_table_header header;
	struct rb_root root;
};
```

#### struct ctl_table_set

```c
/* file: include/linux/sysctl.h */

struct ctl_table_set {
	int (*is_seen)(struct ctl_table_set *);
	struct ctl_dir dir;
};
```


#### struct ctl_table_root

```c
/* file: include/linux/sysctl.h */

struct ctl_table_root {
	struct ctl_table_set default_set;
	struct ctl_table_set *(*lookup)(struct ctl_table_root *root,
					   struct nsproxy *namespaces);
	int (*permissions)(struct ctl_table_header *head, struct ctl_table *table);
};
```

#### struct ctl_path

```c
/* file: include/linux/sysctl.h */

struct ctl_path {
	const char *procname;
};
```

## 函数接口

#### sysctl API
##### proc_sys_poll_notify

```c
/* file: include/linux/sysctl.h */

void proc_sys_poll_notify (struct ctl_table_poll *poll);
```

```c
/* file: fs/proc/proc_sysctl.c */

void proc_sys_poll_notify(struct ctl_table_poll *poll)
{
	if (!poll)
		return;

	atomic_inc(&poll->event);
	wake_up_interruptible(&poll->wait);
}
```

##### setup_sysctl_set

```c
/* file: include/linux/sysctl.h */

extern void setup_sysctl_set (struct ctl_table_set *p, struct ctl_table_root *root, int (*is_seen)(struct ctl_table_set *));
```

##### retire_sysctl_set

```c
/* file: include/linux/sysctl.h */

extern void retire_sysctl_set (struct ctl_table_set *set);
```

##### register_sysctl_root

```c
/* file: include/linux/sysctl.h */

void register_sysctl_root (struct ctl_table_root *root);
```

```c
/* file: fs/proc/proc_sysctl.c */

void register_sysctl_root(struct ctl_table_root *root)
{
}
```

##### __register_sysctl_table

```c
/* file: include/linux/sysctl.h */

struct ctl_table_header *__register_sysctl_table (struct ctl_table_set *set, const char *path, struct ctl_table *table);
```

```c
/* file: fs/proc/proc_sysctl.c */

struct ctl_table_header *__register_sysctl_table (
	struct ctl_table_set *set, 
	const char *path, 
	struct ctl_table *table
) 
{
	struct ctl_table_root *root = set->dir.header.root;
	struct ctl_table_header *header;
	const char *name, *nextname;
	struct ctl_dir *dir;
	struct ctl_table *entry;
	struct ctl_node *node;
	int nr_entries = 0;

	for (entry = table; entry->procname; entry++)
		nr_entries++;

	header = kzalloc(sizeof(struct ctl_table_header) +
			 sizeof(struct ctl_node)*nr_entries, GFP_KERNEL);
	if (!header)
		return NULL;

	node = (struct ctl_node *)(header + 1);
	init_header(header, root, set, node, table);
	if (sysctl_check_table(path, table))
		goto fail;

	spin_lock(&sysctl_lock);
	dir = &set->dir;
	/* Reference moved down the diretory tree get_subdir */
	dir->header.nreg++;
	spin_unlock(&sysctl_lock);

	/* Find the directory for the ctl_table */
	for (name = path; name; name = nextname) {
		int namelen;
		nextname = strchr(name, '/');
		if (nextname) {
			namelen = nextname - name;
			nextname++;
		} else {
			namelen = strlen(name);
		}
		if (namelen == 0)
			continue;

		dir = get_subdir(dir, name, namelen);
		if (IS_ERR(dir))
			goto fail;
	}

	spin_lock(&sysctl_lock);
	if (insert_header(dir, header))
		goto fail_put_dir_locked;

	drop_sysctl_table(&dir->header);
	spin_unlock(&sysctl_lock);

	return header;

fail_put_dir_locked:
	drop_sysctl_table(&dir->header);
	spin_unlock(&sysctl_lock);
fail:
	kfree(header);
	dump_stack();
	return NULL;
}
```

##### __register_sysctl_paths

```c
/* file: include/linux/sysctl.h */

struct ctl_table_header *__register_sysctl_paths (struct ctl_table_set *set, const struct ctl_path *path, struct ctl_table *table);
```

```c
/* file: fs/proc/proc_sysctl.c */

struct ctl_table_header *__register_sysctl_paths(
	struct ctl_table_set *set,
	const struct ctl_path *path, 
	struct ctl_table *table)
{
	struct ctl_table *ctl_table_arg = table;
	int nr_subheaders = count_subheaders(table);
	struct ctl_table_header *header = NULL, **subheaders, **subheader;
	const struct ctl_path *component;
	char *new_path, *pos;

	pos = new_path = kmalloc(PATH_MAX, GFP_KERNEL);
	if (!new_path)
		return NULL;

	pos[0] = '\0';
	for (component = path; component->procname; component++) {
		pos = append_path(new_path, pos, component->procname);
		if (!pos)
			goto out;
	}
	while (table->procname && table->child && !table[1].procname) {
		pos = append_path(new_path, pos, table->procname);
		if (!pos)
			goto out;
		table = table->child;
	}
	
	if (nr_subheaders == 1) {
		header = __register_sysctl_table(set, new_path, table);
		if (header)
			header->ctl_table_arg = ctl_table_arg;
	} else {
		header = kzalloc(sizeof(*header) +
				 sizeof(*subheaders)*nr_subheaders, GFP_KERNEL);
		if (!header)
			goto out;

		subheaders = (struct ctl_table_header **) (header + 1);
		subheader = subheaders;
		header->ctl_table_arg = ctl_table_arg;

		if (register_leaf_sysctl_tables(new_path, pos, &subheader,
						set, table))
			goto err_register_leaves;
	}

out:
	kfree(new_path);
	return header;

err_register_leaves:
	while (subheader > subheaders) {
		struct ctl_table_header *subh = *(--subheader);
		struct ctl_table *table = subh->ctl_table_arg;
		unregister_sysctl_table(subh);
		kfree(table);
	}
	kfree(header);
	header = NULL;
	goto out;
}
```

##### register_sysctl

```c
/* file: include/linux/sysctl.h */

struct ctl_table_header *register_sysctl (const char *path, struct ctl_table *table);
```

```c
/* file: fs/proc/proc_sysctl.c */

struct ctl_table_header *register_sysctl (const char *path, struct ctl_table *table)
{
	return __register_sysctl_table(&sysctl_table_root.default_set, path, table);
}
```

```c
EXPORT_SYMBOL(register_sysctl);
```


##### register_sysctl_table

```c
/* file: include/linux/sysctl.h */

struct ctl_table_header *register_sysctl_table (struct ctl_table * table);
```

```c
EXPORT_SYMBOL(register_sysctl_table);
```

##### register_sysctl_paths

```c
/* file: include/linux/sysctl.h */

struct ctl_table_header *register_sysctl_paths (const struct ctl_path *path, struct ctl_table *table);
```

```c
EXPORT_SYMBOL(register_sysctl_paths);
```


##### unregister_sysctl_table

```c
/* file: include/linux/sysctl.h */

void unregister_sysctl_table (struct ctl_table_header * table);
```

```c
EXPORT_SYMBOL(unregister_sysctl_table);
```

##### sysctl_init

```c
/* file: include/linux/sysctl.h */

extern int sysctl_init(void);
```


#### proc_handler_xxx API


##### proc_dostring

```c
extern int proc_dostring (struct ctl_table *, int, void __user *, size_t *, loff_t *);
```

##### proc_dointvec

```c
extern int proc_dointvec (struct ctl_table *, int, void __user *, size_t *, loff_t *);
```

##### proc_dointvec_minmax

```c
extern int proc_dointvec_minmax(struct ctl_table *, int, void __user *, size_t *, loff_t *);
```


##### proc_dointvec_jiffies

```c
extern int proc_dointvec_jiffies(struct ctl_table *, int, void __user *, size_t *, loff_t *);
```

##### proc_dointvec_userhz_jiffies

```c
extern int proc_dointvec_userhz_jiffies(struct ctl_table *, int, void __user *, size_t *, loff_t *);
```

##### proc_dointvec_ms_jiffies

```c
extern int proc_dointvec_ms_jiffies(struct ctl_table *, int, void __user *, size_t *, loff_t *);
```

##### proc_doulongvec_ms_jiffies_minmax

```c
int proc_doulongvec_ms_jiffies_minmax (struct ctl_table *table, int, void __user *, size_t *, loff_t *);
```

##### proc_doulongvec_minmax

```c
extern int proc_doulongvec_minmax(struct ctl_table *, int, void __user *, size_t *, loff_t *);
```

##### proc_do_large_bitmap

```c
int proc_do_large_bitmap (struct ctl_table *, int, void __user *, size_t *, loff_t *);
```