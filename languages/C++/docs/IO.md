# IO库

IO库是用来处理IO数据的接口，共有iostream、fstream以及sstream三个相关的头文件，其中iostream中实现了stream、istream、ostream类对一般IO
进行操作，fstream实现了fstream、ifstream、ofstream类对文件IO进行操作，sstream中实现了stringstream、istringstream、ostringstream类
对string类型数据进行操作。并且增加了对宽字符的支持，在每一个类型前增加一个w前缀就是对宽字符的实现。

在所有的IO类中都是使用继承机制的，并且IO类对象是没有赋值与拷贝操作的。

每一个IO类有一个状态标志位iostate，其中有badbit、failbit、eofbit以及goodbit来表示流漰溃、操都有作失败、文件结束、状态正常

每一个流都有一个缓存，




* istream cin
* ostream cout
* ostream cerr
* ostream clog


* end-of-file
