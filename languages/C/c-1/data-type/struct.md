struct是一种自定义的数据类型，在使用前需要有明确的声明。

* 结构体的声明

```c
struct Account {
    unsigned long id;
    
    
}

```

* 结构体的初始化
* 内存对齐

在定义结构体时我们需要注意结构体成员的对齐。

**位结构体**

位结构体即使用位域的结构体，通过位域来指定结构体成员使用固定比特大小的空间，这种方式可以定义一个标志
中的含义。位域值的大小在0~15.且成员类型只能为int。当位域值为1时默认为unsigned。

```c
struct flags {
    unsigned enable: 1;
    unsigned bg_color: 8;
    unsigned 
};
```
