nm命令用于输出制定目标文件的符号信息。




*

```shell
# 已定义的符号
nm -U helloworld.o
# 未定义的符号
nm -u helloworld.o
```



局部

* b - 符号在BSS
* d - 符号在DATA
* t - 符号在TEXT

全局

* A - 符号为绝对地址
* B - 符号在BSS
* D - 符号在DATA
* T - 符号在TEXT
* U - 表示未定义的符号