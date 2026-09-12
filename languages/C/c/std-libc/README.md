
## 导入模块
## 预处理宏
## 数据类型
## 数据对象
## 函数接口


* fcntl.h


```c

O_RDONLY
O_WRONLY
O_RDWR

O_APPEND
O_CLOEXEC
O_NOATIME
O_TRUNC

O_SYNC
O_ASYNC
O_NONBLOCK

O_CREAT
O_EXCL
O_DIRECTORY
O_NOCTTY
O_NOFOLLOW

S_IRUSR
S_IWUSR
S_IXUSR
S_IRWXU

S_IRGRP
S_IWGRP
S_IXGRP
S_IRWXG

S_IROTH
S_IWOTH
S_IXOTH
S_IRWXO 

int open(const char *file, int flags, ...);
int create(const char *file, mode_t mode);
close(int fd);
```

```c

```