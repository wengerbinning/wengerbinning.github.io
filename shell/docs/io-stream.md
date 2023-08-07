
### 数据输入

* 数据的输入: 在bash中只能输入字符

```bash
read <variablename>     # 读入文本并赋值给变量
```

### 数据输出

* 数据的输出: 输出文本到屏幕

```bash
# echo 输出字符
echo string         # 输出字符串
# 不换行显示,默认换行显示,-e开启转义
echo -e "string \c"

# printf 输出字符
printf "%10s %20s\n" "Name:" $name # 格式化输出,第一个参数为格式化字符串 之后依次为格式化参数
```

`printf`的转义字符与格式化字符: 转义字符只在格式化字符串中被解释,在格式化字符串,在%之后首先是属性{-(左对齐,默认右对齐),+(显示符号),#,0(以零填补)},然后是精度值,之后是格式化字符,例如`%-50s`表示固定50个字符长度,左对齐.

| 字符 | 说明 | 字符 | 说明 |
|:----:|:--- |:----:|:--- |
| \a | 警告字符 | %c | ASCII字符,显示参数的的第一个字符 |
| \b | 后退 | %d or %i | 十进制数 |
| \c | *禁止换行符 | %e or %E | 浮点数 |
| \f | 换页 | %f | 小数形式 |
| \n | 换行 | %g or %G | 自动选择小数形式 |
| \r | 回车 | %s | 字符串 |
| \t | 水平制表符 | %u | 无符号十进制数 |
| \v | 垂直制表符 | %x or %X | 无符号十六进制 |
| \\ | \符号 | %% | %符号 |



### 输出/输入重定向

一般情况,标准输出/输入都是以终端为对象,重定向是以其他作为对象;一般在Linux中 执行命令时会打开标准输入文件(stdin,文件描述符为0)、标准输出文件(stdout,文件描述符为1)、标准错误文件(stderr,文件描述符为2).

```bash
# 重定向输出至文件,将stdout重定向到file中
<command> > <filename>      # 直接覆盖文件
<command> >> <filename>     # 追加在文件末尾
<command> > <filename> 2>&1       # 将stderr与stdout合并输出到file
# 重MT7615定向输入至文件,将stdin重定向到file中
<command> < <filename>
<command> < <filename> 2<&1        # 将stderr与stdout合并输入
"dwdwd << <tag> <content> <tag>"                      # 将tag之间的内容作为输入
# 将文件描述符为n重定向到file,将stderr重定向到file，缺省n是默认为标准输出。
<command> <number> n> <filename>     # 覆盖的方式
<command> <number> n>> <filename>    # 追加的方式

```