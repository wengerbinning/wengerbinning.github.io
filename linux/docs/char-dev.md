# 字符设备驱动






#### struct cdev

```c
struct cdev {
    struct kobject  kobj;
    struct module  *owner;
    struct file_operations *ops;
    struct list_head    list;
    dev_t   dev;
    unsigned int count;   
};
```

#### API

* cdev_init
* cdev_alloc
* cdev_put
* cdev_add
* cdev_del

* register_chrdev_region
* unregister_chrdev_chrdev_region

* alloc_chrdev_region


#### struct file_operations

```c
struct file_operations {
    struct modeule *owner;
    loff_t  (*llseek) (struct file *, loff_t, int);
    ssize_t (*read) (struct file *, char __user *, size_t, loff_t *);
    ssize_t (*write) (struct file *, char __user *, size_t, loff_t *);
    ssize_t (*aio_read) (struct kiocb *, const struct iovec *, unsigned long, loff_t *);
    ssize_t (*aio_write) (struct kiocb *, const struct iovec *, unsigned long, loff_t *);
    int     (*iterate) (struct file *, struct dir_context *);
    unsigned int    (*poll) (struct file *, struct poll_table_struct *);
    long    (*unlocked_ioctl) (struct file *, unsigned int, unsigned long);
    long    (*compat_ioctl) (struct file *, unsigned int, unsigned long);
    int (*mmap) (struct file *, struct vm_area_struct *);
    int (*open) (struct inode *, struct file *);
    int (*flush) (struct file *, fl_owner_t id);
    int (*release) (struct inode *, struct file *);
    int (*fsync) (struct file *, loff_t, loff_t, int datasync);
    int (*aio_fsync) (struct kiocb *, int datasync);
    int (*fasync) (int, struct file *, int);
    int (*lock) (struct file *, int, struct file_lock *);
    ssize_t (*sendpage) (struct file *, struct page *, int, size_t, loff_t *, int);
    unsigned long   (*get_unmapped_area) (struct file *, unsigned long, unsigned long, unsigned long, unsigned long);
    int (*chec_flags) (int);
    int (*flock) (struct file *, int, struct file_lock *);
    ssize_t (*splice_write) (struct pipe_inode_info *, int, struct file *, loff_t *, size_t, unsigned int);
    size_t  (*splice_read) (struct file *, loff_t *, struct pipe_inode_info *, size_t, unsigned int);
    int (*setlease) (struct file *, long, struct file_lock **);
    long    (*fallocate) (struct file *, int mode, loff_t offset, loff_t len);
    int (*show_fdinfo) (struct seq_file *, struct file *);
};
```



## 创建一个字符设备驱动


```c
struct xxx_dev_t {
    struct cdev cdev;
    // TODO
};


ssize_t xxx_read () {}
ssize_t xxx_write () {}
long xxx_ioctl () {}


struct file_operations xxx_fops = {};



static int __init xxx_init (void) {}

static void __exit xxx_exit (void) {}
```



