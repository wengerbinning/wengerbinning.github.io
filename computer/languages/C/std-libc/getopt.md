



#### optarg

#### getopt

```c
int getopt (int ___argc, char *const *___argv, const char *__shortopts);
```

>
> `__shotropts`中每一个字符代表一个option, 在option之后加`:`表示该字符必须均具有值, 加`::`表示值是可选的.
>


#### getopt_long