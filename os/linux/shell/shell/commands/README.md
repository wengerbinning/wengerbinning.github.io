

## Simple Commands

## Pipelines

## List of Commands

## Compound Commands

shell语言支持复合指令(Compound Commands)。每一个组复合指令以特定的字符标识开始与结束。
复合指令在与重定向组合使用时， 重定向会生效与复合指定的每一个指令，除非显示指定覆盖。

### Looping Constructs

#### until

```txt
until test-commands; do consequent-commands; done
```

#### while

```txt
while test-commands; do consequent-commands; done
```

#### for 

```txt
for name [ [in [words …] ] ; ] do commands; don
```
> 提示： 在使用IFS遍历行时需要保证行内没有n字符，否则就需要特殊字符替换\n后再遍历。

```txt
for (( expr1 ; expr2 ; expr3 )) ; do commands ; done
```

### Conditional Constructs

#### if

#### case

#### select

#### (())

#### [[]]

```txt
[[ expression ]]
```

根据计算计算过返回0与1（布尔值）。

* `==`
* `!=`
* `=~`


* `!`
* `||`
* `&&`


###  Grouping Commands

#### ()

#### {}