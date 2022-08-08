# string

string定义容器`basic_string`与字符串有关的内容。需要嵌入头文件：

```c++
#include <string>
```

## 数据类型

在string模块中，实现了4类基于类模板basic_string实现的类型。

* `string`：一种基于类模板basic_string的实现char的专门化的类型。
* `wstring`：一种基于类模板basic_string的实现wchar_t的专门化的类型。
* `u16string`：一种基于类模板basic_string的实现char16_t的专门化的类型。
* `u32string`：一种基于类模板basic_string的实现char32_t的专门化的类型。

## 模板

### 类模板

* `basic_string`：由basic_string类模板实现的序列是标准的c++字符串类。
  
  通常被称为字符串，但不应该将它们与c++标准库中使用的以null结尾的C风格字符串混淆。

### 函数模板

* `to_string()`：将数值类型的对象转化为string类型对象返回。
* `to_wstring()`：将数值类型的对象转化为wstring类型返回。

### 运算符模板

* `operator+()`：用于连接两个字符串。