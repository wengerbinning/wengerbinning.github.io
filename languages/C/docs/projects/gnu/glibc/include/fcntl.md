# fcntl.h

fcntl.h实现了三个函数接口。

```c
int fcntl (int __fd, int __cmd, ...);
```

```c
 int open (const char *__file, int __oflag, ... /* mode_t mode */);
```

open函数用于打开文件，path是文件的路径，oflag表示打开的模式。返回一个文件描述符。oflag参数中可以使用以下宏：

* `O_RDONLY`只读打开文件。
* `O_WRONLY`只写打开文件。
* `O_RDWR`读写打开文件。
* `O_EXEC`只执行打开文件。
* `O_SEARCH`只搜索打开文件。

在使用open时必须指定以上的五个宏之一，并且可以通过或运算来指定多个标志，除了以上必须的之外，可以指定以下可选的标志：

* `O_APPEND`在写文件时，指定追加到尾部。
* `o_CLOEXEC`
* `O_CREAT`当需要文件不存在时创建文件，此时额外指定mode参数，用于创建文件时的权限设置。
* `O_DIRECTORY`当path不是一个目录路径时返回错误。
* `O_EXCL`在使用O_CREAT的同时使用该参数，可以在文件存在时返回错误，仅在文件不存在时正常创建。
* `O_NOCTTY`
* `O_NOFOLLOW`
* `O_NONBLOCK`当path是一个FIFO、块、字符文件时，此选项为文件的本次打开操作和后续的IO操作设置为非阻塞方式。
* `O_SYNC`
* `O_TRUNC`
* `O_TTY_INIT`
* `O_DSYNC`
* `O_RSYNC`

```c
// 该函数受宏 __USE_ATFILE 控制。
int openat (int __fd, const char *__file, int __oflag, ...);
```

openat函数也用于打开文件与open类似。返回一个文件描述符。当path为一个绝对路径时，与open相同，当path为相对路径时，
fd指定了相对路径在文件系统中开始的地址，fd参数是通过打开相对路径所在的目录来获取的（一个目录文件的文件描述符）。当
fd为AT_FDCWD相对路径开始与当前路径。

```c
 int creat (const char *__file, mode_t __mode);
```

creat函数用于创建一个新文件，该文件是以只写的方式打开。等效于`open(path, O_WRONLY|O_CREAT|O_TRUNC, mode);`
creat函数原本是因为之前的open函数不支持打开不存在的文件，需要调用creat创建新的文件，该函数不足之处就是在读文件时需
要，关闭文件后在打开文件才能读，所以在使用该函数时，一般使用`open(path, O_RDWE|O_CREAT|O_TRUNC, mode);`。
