



## 命令参数





## 创建进程


单个子进程

* fork
* wait

```c
pid_t pid;
int ret;

if ((pid = fork()) < 0) {
    return -1;
}

/** The child progress processing flow. */
if (pid == 0) {
    // execl();
}

/** The parent progress processing flow. */
wait(&ret);
printf("The chid progress(%d) return code: %d\n", pid, WEXITSTATUS(ret));
```

多个子进程

* fork
* waitpid

```c
pid_t pid;
int ret;

if ((pid = fork()) < 0) {
    return -1;
}

/** The child progress A processing flow. */
if (pid == 0) {
    // execl();
}

/** The child progress B processing flow. */
if (pid == 0) {
    // execl();
}

/** The parent progress processing flow. */
while ((pid = waitpid(-1, &ret, 0)) > 0) {
    printf("The chid progress(%d) return code: %d\n", pid, WEXITSTATUS(ret));
}
```

