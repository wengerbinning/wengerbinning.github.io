#### dev_kobj

```c
static struct kobject *dev_kobj;
```

#### sysfs_dev_char_kobj

```c
struct kobject *sysfs_dev_char_kobj;
```

#### sysfs_dev_block_kobj

```c
struct kobject *sysfs_dev_block_kobj;
```

#### device_add

```c
int device_add (struct device *dev);
```

#### device_register

```c
int device_register (struct device *dev);
```