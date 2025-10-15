# fstream

fstream提供了文件操作的实现接口。

## 模板

### 类模板

* `ifstream`：对已存在的文件进行读操作。
* `ofstream`：像向文件写入数据。
* `fstream`：打开文件提供读或写的操作。
* `wifstream`：
* `wofstream`：
* `wfstream`：


### 函数模板

* `getline()`：用户从ifstream读取一行内容。


## 演示

### 文件读取

* 单字节字符文件读取：

  ```c++
  #include <iostream>
  #include <fstream>
  using namespace std; 
  int main() {
      ifstream infile("demo.conf");
      if (!infile.is_open()) {
          // 打开文件失败的处理。
      }
      // 逐行读取到str中并输出在终端中。
      string str;
      while(getline(infile,str)) {
          cout << str << endl;
      }

      return 0;
  }
  ```

* 多字节字符读取：

  ```c++
  #include <iostream>
  #include <fstream>
  using namespace std; 
  int main() {
      wifstream infile("demo.conf");
      if (!infile.is_open()) {
          // 打开文件失败的处理。
      }
      // 逐行读取到str中并输出在终端中。
      wstring str;
      while(getline(infile,str)) {
          wcout << str << endl;
      }

      return 0;
  }
  ```