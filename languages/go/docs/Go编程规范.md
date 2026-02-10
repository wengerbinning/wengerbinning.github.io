# Go编程规范

[//]: # (__author__ = "Clark Aaron")

编程语言的格式样式不是一个主要的问题，但是是一个颇受关注的问题，为了让开发者更有效开发；Go提供`go fmt`来读取源文件，并以缩进和垂直对齐的标准样式格式化源文件，保留注释并必要时重新格式化注释。

## 文档注释

为源码添加注释，可以提高源码的的可读性；注释可以分为行注释与块注释。Go提供`go doc`来读取源文件并提取文档注释来生成帮助godoc文档；出现在顶级声明之前（中间没有新行）的注释将与声明一起提取，作为项目的解释性文本；这些注释的性质和风格决定了godoc生成的文档的质量；文档注释有成员的注释、软件包的注释。

* `//`：行注释，是注释的标准。

  ```go
  // Line coments.
  <code>
  ```

* `/**/`：块注释，主要用于软件包的注释，有时也用于禁用大篇幅源码。

  ```go
  /*
   * Block Comments.
   */
  ```

### 成员的注释

源文件中定义的变量、常量、结构体、接口、函数等都作为软件包的成员，其注释使用行注释，出现在成员声明或定义的上一行，导出成员必须有注释。

* 函数注释：

  ```go
  // Types is a demo function.
  func Types(a interface{}) {
    fmt.Println(a)
  }
  ```

  > Note：函数注释是以函数名开头的完整句子。

### 软件包的注释

软件包应该有包注释，放在`package`语句之前，对于多文件的包，包注释仅需存在于任何一个文件中即可；包注释应该介绍包的功能以及包的整体信息，将首先出现在godoc文档，之后为详细文档，如果包的功能简单，则可以使用行注释描述。

* 软件包的注释：

  ```go
  /* types package.
   *
   * types is a demo package, is analysizing data type and return information.
   */
  package types
  ```

## 命名规范

Golang中的标识符具有语义效果：包内成员对外的可见性取决于其首字母是否大写。

### 成员的名称

包内成员即软件包内部定义的变量、结构体、接口、函数等，成员以首字母小写则对外不可见，首字母大写对外可见;接口名称推荐以`er`结尾，结构体通常定义一个`New()`来返回一个结构体对象，使用`Member()`作为访问不导出包的方法，`Setmember()`作为设置的方法。

### 软件包的名称

当软件包被导入时，软件包的名称将作为该包的内容访问者；软件包的名称应该遵循简洁、小写单字名称，不能使用下划线和首字母大写。

## 源码格式

Go源码的第一条语句须是`package`子句，标明该源码属于哪一个软件包；

* 源文件的软件包标识：

  ```go
  package <packageName>
  ```

  > Note：可执行程序必须使用main包。

* 分号用于分割语句，Go的词法分析器会自动插入分号，所以不要要开发人员添加分号；但是由于分号插入规则，其后果是不能将控制结构的开括号(if、for、switch或select)放在下一行。

## 项目结构

指定`GOPATH`变量，使用`go env`查看Golang环境变量，`go env -w GOPATH=<path>`可以设置环境变量，`go env -u GOPATH`撤销设定；在该目录中建立`bin/`、`pkg/`、`src/`作为通用结构。

* 第一个程序的运行首先在`src/github.com/username/demo`运行：

  ```shell
  go mod init github.com/username/demo
  ```

  > Note：`github.com/username/demo`路径是根据文件路径自定义的。

  将在demo/中建立一个demo.mod文件，之后再demo/中建立一个demo.go文件：

  ```go
  package main

  import "fmt"

  func main() {
      fmt.Println("Hello, World")
  }
  ```

  > Note：可运行程序必须为main包。

  之后使用

  ```shell
  go install github.com/username/demo
  ```

  > Note：也可以在demo/下运行go run demo.go来测试程序是否可以运行。

  即可在`bin/`中构建一个demo.exe，点击运行即可。

* 分组：在定义变量、导入包时可以使用分组，知识项目之间的关系，例如一组变量受互斥锁保护这一事实。

与C语言一样，Golang使用`;`来终止语句，但是与C语言不同的是，Go的词法分析器在扫描时会自动插入分号。
