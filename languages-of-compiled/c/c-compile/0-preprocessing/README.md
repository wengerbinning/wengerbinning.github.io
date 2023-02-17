预编译的过程是预编译器将源文件与头文件经过处理生成预编译后的文件。

预编译的过程

* 宏展开
* 处理条件预编译指令
* 处理头文件包含指令
* 删除注释
* 添加行号与文件标识
* 保留 pragma 为编译器 


预编译器在GCC中是cpp指令， 


```shell
cpp helloworld.c > helloworld.i
```

```shell
gcc -E helloworld.c -o hellworld.i
```