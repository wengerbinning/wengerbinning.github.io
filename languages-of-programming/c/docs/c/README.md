在C语言中有一些基础类型是语言本身提供的，也是我们通过结构体以及联合体进行扩展的基础类型。这些基础类型中
分为数值类型与空白类型两大类。其中数值类型又可以分为整数类型与浮点数类型，在整数类型中有一个特殊类型char用于表示字符类型。

## 整数类型

* char
* short
* int
* long

## 浮点数类型

* float
* double
* long double

| 类型 | 说明 |
|:---:|:--- |
| char | 有符号单字节整数 |
| unsigned char | 无符号单字节整数 |
| short | 有符号短整型 |
| unsigned short | 无符号短整型 |
| int | 有符号整型 |
| unsigned int | 无符号整型 |
| long | 有符号长整型 |
| unsigned long | 无符号长整型 |
| int32_t |
| uint32_t |
| int64_t |
| uint64_t |
| float | 单精度浮点型 |
| double | 双精度浮点类型 |
| long double | 双精度长浮点类型 |

* `unsigned char`与`char`：该类型是原是存储ASCII编码的字符的数据类型，后来经常存储小数值的整数，所占内存空间为1B。
* `unsigned short`与`short`：该类型用于存储小数值的整数，所占内存为2B。
* `unsigned int`与`int`：该类型是常用的整数类型，所占内存为4B。
* `uint32_t`与`int32_t`：该类型是32位的整数类型，所占内存为4B。
* `uint64_t`与`int64_t`：该类型是64位的整数类型，所占内存位8B。
* `uisigned long`与`long`：该类型是大数值的整数类型，所占内存根据程序位数而变，在32位程序上占4B，在64位程序上占8B。
* `float`与`double`：单精度浮点数与双精度浮点数。

在C语言中无符号整数使用原码表示，有符号整数默认使用补码表示，在无符号与有符号同时参与运算时，有符号的整数被隐式转化为无符号整数，对关系运算符的结果产生影响。

### 空白类型

空白类型是void，是指没有任何数据的类型，一般用于无返回、无参数、空指针。



calloc与malloc以及realloc的辨析：

* void* malloc(unsigned size): 用于申请固定size字节的连续内存空间。不会初始化为零值。返回是一个对象。
* void* calloc(unsigned n, unsigned size): 用于申请n个固定size字节的连续内存空间。在分配时初始化为零值。返回是一个数组。
* void* realloc(void *p, unsigned size): 将指针p指向的内存改为size.
