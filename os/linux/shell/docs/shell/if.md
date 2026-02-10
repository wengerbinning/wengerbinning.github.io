
# if 条件语句,经常与test语句连用
    if [ <expression> ]
    then        # if的隶属代码,条件为真时执行
        echo content
    fi
    if [ 1 ]; then echo true; fi
# if-else 条件语句,可以使用if嵌套实现多分枝结构
    if [ -e $filename ]
    then
        echo <content>
    elif [ <expression> ]
    then
        echo <content>
    else
        echo <content>
    fi
  # efwfwfwfwf
   if [ -n "$1" ]; then
       echo dede
   elif [-z "$1" ]; then
       echo efwef
   else
       echo efwfwe
   fi