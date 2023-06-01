
# case语句实现多程序执行,可以使用文本通配符,*表示任意文本,a?b表示a与b任意一个字符,[a-z]表示a-z之间的一个字符

```shell
case $var in
root)
    lscpu
    echo "you are $var"
;;
vamei)
    echo "you are $var"
;;
-f|--file)
    echo file
;;
*)
    echo "you are the others"
;;
esac
```