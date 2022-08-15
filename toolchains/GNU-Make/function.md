

**origin**

* origin函数用于查询变量的来源信息

```
$(origin var)
```


| value | comment |
|:---:|:--- |
| undefined | if variable was never defined. |
| default | if variable has a default definition, as is usual with CC and so on. |
| environment | if variable was inherited from the environment provided to make. |
| environment override | if variable was inherited from the environment provided to make, and is overriding a setting for variable in the makefile as a result of the ‘-e’ option |
| file | if variable was defined in a makefile. |
| command line | if variable was defined on the command line. |
| override | if variable was defined with an override directive in a makefile |
| automatic | if variable is an automatic variable defined for the execution of the recipe for each rule |


**filter**

