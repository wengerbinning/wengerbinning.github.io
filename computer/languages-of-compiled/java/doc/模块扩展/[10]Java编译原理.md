# Java编译原理

[//]: # (__author__ = "Wenger Binning")

Java编译的过程由源文件（\*.java）经过编译器javac生成跨平台的位码文件（\*.class），然后经由不同平台上的JVM生成平台对应的机器码，实现一次编译，多处运行。

## JVM

JVM（Java Virtual Machine）是处于编译器与计算机系统之间的翻译系统，可以将Java编译器生成的位码文件翻译成当前系统对应的可运行程序。`CLASSPATH`变量是JVM寻找字码文件的路径信息，除环境变量的方式，也可以使用java工具的`-classpath`参数来指定，`-classpath`简化为`-cp`

## JRE

JRE（Java Runtime Environment）是由JVM、Java SE API与部署技术组成。用于执行Java程序。其中Java SE API包含了各式常用的链接库。独立的JRE通常称为Public JRE。

## JDK

JDK（Java Development Kit）是由Java语言环境、JRE与编译程序包组成。包含的JRE通常称为Private JRE。

### 编译程序包

## 配置路径

* CLASSPATH
* SOURCEPATH
* MODULE-PATH
* MODULE-SOURCE-PATH
