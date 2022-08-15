
#### 宏

```c
/* file: bits/getopt_core.h */
#define no_argument		    0
#define required_argument	1
#define optional_argument	2
```

#### 数据结构

```c
/* file: bits/getopt_core.h */
struct option
{
  const char *name;
  /* has_arg can't be an enum because some compilers complain about
     type mismatches in all the code that assumes it is an int.  */
  int has_arg;
  int *flag;
  int val;
};
```


#### 导出函数接口

###### getopt_long

```c
/* file: bits/getopt_core.h */
extern int getopt_long (int ___argc, char *__getopt_argv_const *___argv, const char *__shortopts, const struct option *__longopts, int *__longind) __THROW __nonnull ((2, 3));
```


```c
/* file: bits/getopt_core.h */
extern int getopt_long_only (int ___argc, char *__getopt_argv_const *___argv, const char *__shortopts, const struct option *__longopts, int *__longind) __THROW __nonnull ((2, 3));
```