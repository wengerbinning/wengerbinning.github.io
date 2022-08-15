getopt core模块提供参数解析的核心功能。



#### 导出数据对象

###### optarg

```c
/* file: bits/getopt_core.h  */
extern char *optarg;
```

###### optind

```c
/* file: bits/getopt_core.h  */
extern int optind;
```

###### opterr

```c
/* file: bits/getopt_core.h  */
extern int opterr;
```

###### optopt

```c
/* file: bits/getopt_core.h  */
extern int optopt;
```


#### 导出函数接口

###### getopt

```c
/* file: bits/getopt_core.h  */
extern int getopt (int ___argc, char *const *___argv, const char *__shortopts) __THROW __nonnull ((2, 3));
```