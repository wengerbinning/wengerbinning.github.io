# regex

正则表达式是处理字符串的有效工具。

## 类型

* `regex`：单字节的匹配字符串类型。
* `wregex`：多字节的匹配字符串类型。

## 模板

### 类模板

* `basic_regex`：生成匹配字符串类型。
* `match_results`：

### 函数模板

* `regex_match()`：Exactly matches a regular expression.
* `regex_search()`：Replaces matched regular expressions.
* `regex_replace()`：Searches for a regular expression match.
* `swap()`：Swaps basic_regex or match_results objects.


## 演示

* 字符串模式匹配：

 ```c++
 #include<regex>
 rengex pattern(".*?");

 if ()

 ```

* `regex_match(<string>,<pattern>) -> bool`: 匹配字符串。
* `rengex_search()