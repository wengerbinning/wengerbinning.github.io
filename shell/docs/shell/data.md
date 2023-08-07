**数据对象**


  ```shell
  # 变量的定义格式。
  <varible name>=<string value>
  # 在定义格式的基础上可以使用以下两种格式，将命令执行后的返回结果赋值给变量。
  # 第一种格式
  <variable name>=`<command>`
  # 第二种格式
  <varible name1>=$(<command>)
  # 当然也是可以使用变量间相互赋值的。
  <variable name 1> = ${<variable name  2>}
  # shell中也支持数组。
  # 第一种格式
  <array_name>=(<value_0>,<value_1>)
  # 第二种格式
  <array_name>=(
      value_0
      value_1
  )
  # 第三种格式，可以不使用连续下标,且下标无限制。
  <array_name>[0]=<value_0>
  <array_name>[999]=<value_999>
  ```

* 数据的对象的使用，使用`$`来标识变量对象。

  ```shell
  # 输出数据对象，这两种格式
  echo $<varible_name>
  echo varible=$<variable_name>
  #这种格式的输出与上面个相似，可以转义变量名与转义字符。
  echo "Variable = $<variablename>"
  # 这种合适的输出不能转义变量名与转义字符，会将所有的字符当做普通字符输出。
  echo 'Variable = $<variablename>'
  # 使用以下格式来对字符串变量来进行切片。
  echo ${<variable_name>[:<start_index>:<count>]}
  # <https://www.cnblogs.com/quzq/p/12104360.html>
  echo ${#variablename}                                       # 获取字符串的长度
  echo ${<groupname>[<index>]}                                # 显示数组元素
  echo ${<groupname>[@]}                                      # 显示所有元素
  echo ${#<groupname>[@]}                                     # 获取数组长度
  echo ${#<groupname>[*]}                                     # 获取数组长度
  echo ${<variable_name>#*demo}                                   # 符号#表示从左到右匹配到/之前的字符串。
  echo ${<variable_name>##*demo}                                  # 符号#表示从右到左匹配到/之前的字符串。
  echo ${<variable_name>%demo*}
  echo ${<variable_name>%%demo*}
  ```

* 变量的属性

  ```bash
  # 限定变量为只读变量
  readonly <variable_name>=
  # shell脚本中的变量默认是全局变量，函数中定义的也是，但是在函数中可以显式定义为局部变量
  local <veriable_name>=
  ```

* 删除变量

  ```bash
  unset <variable_name>
  ```

* 变量类型：在shell中存在三种变量:局部变量(当前shell实例中有效),环境变量(所有程序都能访问),shell变量(shell程序设定的特殊变量).