

*  指定文件中搜索内容。

```shell
# 按照匹配规则从指定文件中搜索内容。
grep <patterns> <file path>...

# 按照匹配规则从指定文件列表中满足指定规则的的文件中搜索内容。
grep <patterns> --include=*.c ./*

# 按照匹配规则从指定文件列表中不满足指定规则的的文件中搜索内容。
grep <patterns> --exclude=*.c ./*

```


* 指定路径下搜索文件。

```shell
# 按照匹配规则在指定路径下搜索内容。
grep -r <patterns> <dir path>...

# 按照匹配规则在指定路径下搜索内容
grep -R <patterns> <dir path>...

```
