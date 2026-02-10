## 数学运算

在bash中,数字于运算符都会被当作普通文本,不能便捷的进行数学运算;但可以通过$(())语法来进行数值运算,运算符有{`+`,`-`,`*`,`/`,`%`,`**`,`=`，&，|，~};其优先级从高到低是乘方,乘除取余,加减;同一优先级按从左至右的顺序执行.

```bash
reasult=1+2                # 不会计算值,原样赋值
echo $reasult              # 原样打印
echo $((1+2*3/$reasult))   # 计算后打印结果
reasult=$((1+2**3))        # 运算后赋值
"$(echo ls)"               # 首先执行括号内的语句，执行的输出结果再次执行。

# 算数运算符 + - * / % ** = != == 用于数值运算
# 关系运算符 -eq -ne -gt -lt -ge -le 用于数值关系
# 逻辑运算符 !(非) -a or &&(与) -o or ||(或)
# 字符串运算符 = != -z -n $
# 文件检测运算符 -b -c -d -f -g -k -p -u -r -w -x -s -e -S -L
# 使用expr(表达式计算工具)
```



* 数值比较：

  ```shell
  # 相等判断使用eq，即equal。
  test 3 -eq 3
  # 不相等判断使用ne，即unequal。
  test 3 -ne 3
  # 大于判断使用gt，即greather than。
  test 3 -gt 3
  # 大于或等于判断使用ge， 即greather than or equal。
  test 3 -ge 3
  # 小于判断使用lt， 即less than。
  test 3 -lt 3
  # 小于等于判断le， 即less than or equal。
  test 3 -le 3
  ```

* 字符比较：

  ```shell
  # 相等比较。
  $str_1 == $str_2
  # 不相等比较。
  $str_1 != $str_2
  # 大于比较。
  $str_1 > $str_2
  # 大于等于比较
  # 小于比较
  $str_1 < $str_2
  # 小于等于比较
  # 字符串是空串判断
  -z $str
  # 字符串非空判断
  -n $str

  str_1="wengerbinning@163.com"
  str_2="wengerbinning@gmail.com"
  if [ $str_1 = $str_2 ]; then
      echo str_1 & str_2 is same.
  else
      echo str_1 & str_2 is different.
  fi
  if [[ $str_1 == *@*.* ]]; 设立了
  ```

  > Note: 在使用`[]`包含两个字符串比较时，需要确认两个字符串均为非空字符串，可以增加前后缀或者使用[[]]。同时`[[]]`也支持正则比较。但是`[[]]`

* 文件检测：

  ```shell
   # 文件是否存在, 输出0表示文件存在。输出1表示文件不存在。
   test -e demo; echo $?
   # 普通文件是否存在
   test -f demo; echo $?
   # 目录文件是否存在 
   test -d demo; echo $?
    # 脚本编程软连接文件是否存在
    test -L demo; echo $?
   # 文件是否可读
   test -r demo; echo $?
   # 文件是否可写
   test -r demo; echo $?
   # 文件是否可执行
   test -x demo; echo $?
   # 文件存在且不为空
   test -s demo; echo $?
   # 字符特殊文件是否存在
   test -c demo; echo $?
   # 块特殊文件是否存在
   test -b demo; echo $?
  ```

* 逻辑判断: 使用`test`命令来进行逻辑判断,{`-gt`,`-lt`,`-eq`,`-ne`,`-ge`,`-le`}分别表示大于,小于,等于,不等于,不小于,不大于,用于数值测试;

```bash
# 数值判断
    test 3 -gt 2; echo $?   # 3大于2成立时,返回代码为0;显示返回代码
    test 3 -lt 2; echo $?   # 3小于2不成立,返回代码为1;显示返回代码

# 字符串判断
    # 文本相同
    test abc=abx; echo $?
    # 文本不同
    test abc!=abx; echo $?
    test apple>tea; each $?     # 根据词典顺序,文本在另一文本之前
    test apple<tea; echo $?     # 根据词典顺序,文本在另一文本之后
    test -z <string>; echo $?   # 字符串长度为零时为真
    test -n <string>; echo $?   # 字符串长度不为零为真

# 逻辑组合
    !<expression>                  # 非
    <expression1> -a <expression2> # 与
    <expression1> -o <expression2> # 或