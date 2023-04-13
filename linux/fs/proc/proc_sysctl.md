

## 数据对象

```c
static const struct dentry_operations proc_sys_dentry_operations;
static const struct file_operations proc_sys_file_operations;
static const struct inode_operations proc_sys_inode_operations;
static const struct file_operations proc_sys_dir_file_operations;
static const struct inode_operations proc_sys_dir_operations;
```


#### root_table

```c
static struct ctl_table root_table[] = {
	{
		.procname = "",
		.mode = S_IFDIR|S_IRUGO|S_IXUGO,
	},
	{ }
};

static DEFINE_SPINLOCK(sysctl_lock);
```

#### sysctl_table_root

```c
static struct ctl_table_root sysctl_table_root = {
	.default_set.dir.header = {
		{{
            .count = 1,
		    .nreg = 1,
		    .ctl_table = root_table 
        }},
		.ctl_table_arg = root_table,
		.root = &sysctl_table_root,
		.set = &sysctl_table_root.default_set,
	},
};
```

## 函数接口


#### append_path

该api将name添加到path中，偏移量为pos。

```c
static char *append_path (const char *path, char *pos, const char *name)
{
	int namelen;
	namelen = strlen(name);

	if (((pos - path) + namelen + 2) >= PATH_MAX)
		return NULL;

	memcpy(pos, name, namelen);
	pos[namelen] = '/';
	pos[namelen + 1] = '\0';
	pos += namelen + 1;

	return pos;
}
```





