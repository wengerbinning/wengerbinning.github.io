glob

```c
int glob(const char *pattern, int flags, int errfunc(const char *epath, int eerrno), glob_t *pglob);
```
glob是根据指定的模式匹配字符串搜索符合的文件
