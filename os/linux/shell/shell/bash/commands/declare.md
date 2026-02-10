declare用于声明变量并指定变量的属性。


declare -p 显示所有变量的属性



## 属性

在以下属性中使用+号会关闭对应属性

* 声明一个索引数组

```bash
declare -a var
```

* 声明一个关联数组

```bash
declare -A var
```

* 导出到环境变量

```bash
declare -x var
```

* 变量值的小写属性被禁用， 都会转化为大写字符。

```bash
declare -u var
```