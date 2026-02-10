汇编是通过汇编器将汇编代码转化为机器指令的过程，

目标文件是汇编器生成的目标， 



汇编器在GCC中是as

```shell
as hellworld.s -o helloworld.o
```

```shell
gcc -c helloworld.s -o helloworld.o
```



目标文件的格式有Linux平台的ELF与Windows平台的PE， 两者均为COFF的变种



### ELF

ELF(Executable Linkable Format)是Linux平台下的可执行文件的格式。ELF文件有
可重定位文件、可执行文件、共享目标文件、核心转储文件。





### PE-COFF

PE()是Windows平台下的可执行文件的格式。