Makefile文件是make执行的规则文件





缺省的变量
--------

| 变量 | 版本 |说明 |
|:---:|:---:|:--- |
| CURDIR | - |当前工作路径，可以使用make的-C选项来指定特定的路径 |
| .RECIPEPREFIX | - | 该变量可以修改构建规则中每一个步骤的开始字符 |





默认指令
-------

| 指令 | 说明 |
|:---:|:--- |
| export | 导出当前变量为环境变量 |





标准目标
-------

all
install
install-html
install-dvi
install-ps
uninstall
install-strip
clean
distclean



* echo

```makefile
echo
```


@放在指令前表示不输出执行，只输出结果。



## 字符变量


* 可覆盖的变量定义, 

```Makefile
VERSION=$(DEFAULT_VERSION)
```



## 构建规则

* 构建规则的格式

```Makefile
target : prerequesties
    recipe
    ...
```

在一个构建规则中，目标可以是一个执行的动作名称，也可以一个输出的目标文件，构建目标的步骤通常是以tab键开始的，

模式匹配规则
-------

模式匹配规则与一般规则类似，只是在目标与依赖中中包含模式匹配字符。

* 模式匹配字符

| 字符 | 说明 |
|:---:|:--- |
| % | 存在在目标中时表示匹配一个不包含空白字符的字符串，在依赖中时表示目标匹配到的字符 |

模式匹配规则可以存在两个目标。

```Makefile
# 通过该规则将生成执行一次生成两个目标。
%.tab.o %.tab.h : %.y
    bison -d $<

```

隐式构建规则
-------

 通过定义模式匹配规则可以实现一个隐式构建规则




内置规则
-------

* file.o由以下指令生成从file.*生成

```Makefile
# C from file.c
$(CC) $(CPPFLAGS) $(CFLAGS) -c
# C++ from file.cc, file.cpp or file.c
$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c
```

* 链接规则target由target.o链接而成

```Makefile
$(CC) $(LDFLAGS) target.o $(LOADLIBES) $(LDLIBS)
```

