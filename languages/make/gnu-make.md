
#### subst

```Makefile
$(subst from,to,text)
```

对文本`text`中的`form`字符进行替换为`to`。

#### patsubst


```Makefile
$(patsubst pattern,replacement,text)
```

根据模式匹配进行字符替换。

#### strip

```Makefile
$(strip string)
```

删除文本前后空格，并对文本中多个连续空格进行去重。


#### word

```Makefile
$(word n,text)
```

返回文本中指定位置的单词。

#### wordlist

```Makefile
$(wordlist s,e,text)
```

返回文本中指定位置的单词列表

#### words

```Makefile
$(words text)
```

返回文本中单词的个数。

#### firstword

```Makefile
$(firstword names…)
```

#### lastword

```Makefile
$(lastword names…)
```

#### findstring

```Makefile
$(findstring find,in)
```

在文本`in`中搜索`find`字符，找到则返回`find`字符,否则为空。

#### filter

```Makefile
$(filter pattern…,text)
```

在文本中根据匹配规则过滤单词。

#### filter-out

```Makefile
$(filter-out pattern…,text)
```

在文本中根据匹配规则剔除单词。

#### sort
