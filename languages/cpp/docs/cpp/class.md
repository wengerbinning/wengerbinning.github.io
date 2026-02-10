# 类

类是一种允许我们自定义的数据结构的机制。类的基本思想是数据抽象(data abstraction)与封装(encapsulation)。数据抽象是一种依赖于接口(interface)与实现(implementation)分离的编程技术；类的接口包含用户可以执行的开放接口与仅内部使用的私有接口，类的实现则包括类的数据成员、负责接口实现的函数。封装则实现了类的接口与实现分离，封装后类隐藏了它的实现细节，也就是说用户只能使用接口而无法访问实现。即类是一个数据抽象的实现。

在使用类来实现一个具体的数据类型时，我们需要有一个抽象数据类型(abstract data type)，然后根据抽象数据结构来确定类的数据成员与函数成员；抽象数据类型是一类对象的抽象模型，包含属性与方法两大类，类的数据成员即抽象数据类型的属性，函数成员即抽象数据类型的方法。同时，类使用访问说明符(access specifiers)来控制类的封装性：public说明符标识成员可以被外部直接访问，private标识成员只能内部访问或者通过public修饰的接口来间接访问。

类可以使用class与struct来实现，两者的区别仅在与第一个访问说明符不同，class默认为private,struct默认为public。这里仅以class举例，struct可以根据实际情况来使用。

```c++
class String {
    char *_data;
    unsigned length;
    public:
        String(const char *);
        String(Const &String);
        ~String();
    private:
        char * _data();
        unsigned _length();
    public:
        &String sub(int, unsigned);
        &String append($String);
};

String::String(const char *) {
    // todo:
}

char * String::_data() {
    // todo:
};
```

类使用访问说明符(access specifiers)来控制类的封装性，访问说明符共有三个：public、protected以及private，public修饰的成员可以在整个程序中访问，private修饰的成员只能在类的内部访问，在class中的类定义中第一个默认访问说明符是private，struct的类定义是public。
类默认对成员的权限是私有的，所以开始的数据成员我们都是直接声明的；公有的权限需要使用`public`来标识。

在函数成员中，一般会通过一个`this`的隐式参数来访问调用对象，所以在声明函数成员中不要使用this来作为形参的标识符。this是一个常量指针，指向一个对象本身；例如String类型中，this的类型是`String * const`，所以当对象本身是一个常量时，this会指向一个常量对象是不被允许的，所以需要修改this指向一个const常量，这类函数成员称为常量函数成员，即不
会修改数据成员的函数成员。本质是修改this指向一个常量对象，即`const String * const`。常量对象只能访问常量函数成员。常量函数使用`const`在函数参数之后来标识，该标识在
声明与实现中都要做显式说明。

在类中，编译器会将类的编译分为两步：声明与实现，首先编译所有的声明，然后编译所有的实现，所以在类中无需关注成员的顺序。

类的函数成员可以三种方式实现行数的内联：直接在类内实现的隐式内联，声明时指定内联以及实现时指定内联。

数据成员是描述类的数据特征，一般设定为私有成员；通过接口来管理数据，不支持本身类型、寄存器、外部、constexpr与decltype的成员；C++11之后，在类中中可以指定类内初始值。
在类中，常量成员、引用成员、类对象成员以及派生类的构造函数对超类构造函数的调用必须采用内初始值或者构造函数的初始化列表来进行初始化。一般使用初始化列表初始化数据成员。
可变数据成员：可变数据成员不经常使用。可变数据成员可以在常量函数中改变、对象为常量时也可以被改变，使用`mutable`来声明。

```c++
  class Human {
    private:
      mutable string name;
    public：
      void Print() const;
  }

  void Human::Print() const {
    cout << this.name;
    this->name = "NULL";
  }
  
```

类的函数成员即类的行为特征，本质是函数，一般设定为公开成员，作为ADT的外部接口；可以在类内直接实现；也可以在类内声明，类外实现。在方程成员中，有一个默认参数this指针。

静态成员是独立于任意该类型对象而存在的，所有实例化对象共享；是实现类间内存共享的机制。静态函数只能访问静态数据成员，使用static修饰。

* 静态数据成员：不能通过构造函数初始化，只能在定义时指定初始值。

  ```C++
  class Human {
    private:
      string name;
      static int COUNT;
      static initCount();
  }

  int Human::COUNT = initCount();     // 使用静态函数initCount()来初始化COUNT。
  ```

  在静态数据成员中，有一种特殊的静态数据成员：静态常量成员`const static int DAY;`

* 静态函数成员：没有this指针，可以直接访问静态数据成员，但不能直接访问非静态数据成员。不能被声明为常量函数于虚拟函数。

  ```c++
  class Human {
    private:
      string name;
      static int COUNT;
    public:
      static int Count();
  }

  int Count() {
    cout<< COUNT;
    return COUNT;
  }
  
  ```

  > Note：static仅在函数声明时出现，在函数实现时不出现。

类的常量成员时类所具有的

* 类的常量数据成员：只能在构造函数的初始化列表中初始化。

* 类的常量函数成员：

类的函数成员是对数据成员进行处理的函数，因为默认会带一个本身的this指针，所以称为这类函数为函数，用以描述类的行为。在这些函数中有一些特殊的函数需要了解。

## 构造函数

类对象的初始化过程是由一些函数成员来实现的，这类函数称为构造函数(constructor)；其任务是初始化类对象的数据成员，在类对象创建时，根据匹配结果自动调用。构造函数的函数名与类同名，没有返回类型。如果我们没有显式的提供构造函数，类会合成一个默认构造函数(default constructor)来初始化对象。构造函数提供一个初始化列表(constructor initialize list)来初始化对象。

```c++
class String {
    public:
        // 构造函数的声明。
        String(const char* str=0);
        String(const String& str_obj);
        String& operator=(const String& str_obj);
        ~String();
    private:
        char *m_data;
};

// 构造函数的实现。
inline
String::String(const char *str=0) 
{
    if(str) {
        this->m_data = new char[strlen(str)+1];
        strcpy(this->m_data, str);
    }
    else {
        this->m_data =new char[1];
        *(this->m_data) ='\0';
    }
}

```

构造函数的初始化列表是构造函数特有的；相较于函数体类初始化，该方式初始化更加快速。

```c++
class Complex {
    public:
        // 构造函数的声明。
        Complex(double, double);
        Complex& operator+=(const Complex&); 
        double real() const { return this->re; }
        double imag() const { return this->im; }
        
    private:
        double re, im;
        
        Complex& __doapl(const Complex&);
}

// 构造函数的初始化列表。
inline
Complex:: Complex(double r=0, double i=0)
: re(r), im(i)
{}

```


## 拷贝构造函数

拷贝构造函数(copy constructor)是使用已有的对象来初始化的同类型对象是调用的构造函数。此构造函数的参数是自身对象的引用，其他参数都有默认值。

```c++ 
class String {
    public:
        String(const char* str=0);
        // 拷贝构造函数的声明。
        String(const String& str_obj);
        String& operator=(const String& str_obj);
        ~String();
    private:
        char *m_data;
};

// 拷贝构造函数的实现。
inline
String::String(const String& str_obj)
{
    this->m_data = new char[strlen(str_obj.m_data)+1];
    strcpy(this->m_data, str_obj.m_data);
}
```

拷贝是将已有的对象通过赋值符号赋值给另一个同一类型的对象。目标对象已有内容需要先删除后在将原对象深拷贝一份给目标对象。

```c++
class String {
    public:
        String(const char* str=0);
        String(const String& str_obj);
        // 拷贝复制函数的声明。
        String& operator=(const String& str_obj);
        ~String();
    private:
        char *m_data;
};

// 拷贝复制函数的实现。
inline
String& String::operator=(const String& str_obj) 
{
    if( this == &str_obj ) {
        return *this;
    }
    
    delete[] this->m_data;
    this->m_data = new char[strlen(str_obj.m_data)+1];
    strcpy(this->m_data, str_obj.m_data);
    return *this;
}

```

* 移动构造函数(move constructor) 


## 运算符操作
## 析构函数 


* 析构函数是在对象销毁时自动调用的函数，通常用于销毁指针成员。每一类中只能有一个析构函数。

```c++
class String {
    public:
        String(const char* str=0);
        String(const String& str_obj);
        String& operator=(const String& str_obj);
        // 析构函数的声明。
        ~String();
    private:
        char *m_data;
};

// 析构函数的实现。
inline
String:~String(){
    delete[] m_data;
}

```


----

除了以上的函数之外还有一些操作符重载。

* 加法赋值运算符重载    

```c++
class Complex {
    public:
        Complex(double, double);
        // 加法赋值运算符重载声明。
        Complex& operator+=(const Complex&); 
        double real() const { return this->re; }
        double imag() const { return this->im; }
        
    private:
        double re, im;
        
        Complex& __doapl(const Complex&);
}

inline Conplex&
Complex::__doapl(const Complex&)
{

}

// 加法赋值运算符重载实现。
inline Complex& 
Complex::operator+=(const Conplex&)
{
    
}

```


## 友元

类可以允许其他类或者函数访问他的非公开成员，方法是使类或者函数成为类的友元(friend)，将函数作为类的友元，需要在增加一条以friend开头的函数声明。只能出现在类的内部。 
