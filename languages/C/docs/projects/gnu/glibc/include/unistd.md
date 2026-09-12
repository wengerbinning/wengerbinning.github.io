# unistd.h

unistd中实现了一些关于进程相关的接口。




fork系列函数实现来创建子进程的功能。即对当前进程做一份拷贝。

```c
__pid_t fork (void);
```

对当前进程做一份拷贝，称拷贝的进程为子进程(child process)，被拷贝的进程成为主进程(host process)，也称为子进程的父进程(parent process)。
该函数调用一次，但返回两次：子进程返回0，主进程返回子进程的进程ID。子进程与主进程只共享代码段；数据段、堆、栈是一个完整的副本，因为许多场景在
fork之后使用exec，子进程中数据会被替换，不会用到父进程的副本数据，因此这些副本数据复制采用写时复制(COW, Copy On Write)技术：子进程与主进程
共享数据，并有内核将权限改为只读，如果主进程与子进程中有一个写入数据，内核将对写入区域的页空间进行复制；

主进程与子进程的执行顺序由内核的调度算法决定，如果要求两进程间数据同步，则需要实现进程间通信来保证同步。

fork在与I/O函数之间的交互关系，write函数无缓存，所以数据是直接写入，而标准I/O库是带缓存的，如果标准输出连到终端设备为行缓存，否则为全缓存；在
fork之后，子进程会拥有一份主进程的标准I/O的缓存。

在fork之后，重定向主进程的标准输出，子进程的标准输出也会被重定向。因为子进程拥有主进程的文件描述符的副本，但是描述符共享主进程的文件表项。在子进程
与主进程中需要分别关闭文件描述符才能关闭一个文件。

```c
__pid_t vfork (void);
```

其效果与fork类似，但是在创建子进程后，并不会将主进程的地址空间完全复制到子进程中，使用vfork后一般会立即使用exec替换程序。且vfork保证子进程先运行，
在子进程调用exec或exit之后，主进程才能被调度运行。

---

exec系列函数实现来使用程序文件替换当今进程的任务的功能。

* `int execv(const char *path, char *const argv[]);`

  使用可执行程序文件替换当前进程的程序，第一个参数是一个可执行程序的路径，第二个参数是一个元素为char类型指针的数组常量，其中最后一位元素须为一个空
  指针。进程的环境变量会保留。
  
```c
extern int execv (const char *__path, char *const __argv[]);
```

* `int execve(const char *path, char *const argv[], char *const envp[]);`

  使用可执行程序文件替换当前进程的程序，与execv的区别是增加了一个环境变量的参数。

```c
extern int execve (const char *__path, char *const __argv[], char *const __envp[]);
```

* `int execl (const char *path, const char *arg, ...);`

  使用可执行程序文件替换当前进程的程序,与execv的区别在于参数。
  
* `fexecve`
* `execle`
* `execvp`
* `execlp`
* `execvpe`




```c
int pipe (int __pipedes[2]);
```

pipe用于创建一个无名管道，用于与子进程通信。该管道是默认阻塞，


