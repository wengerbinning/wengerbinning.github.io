# 指针

指针是一类只存储对象地址的数据类型，译为指向另一个对象的对象；

#### 指针的声明

指针的声明需要指定其指向内存空间存储的述据类型，同时也提供一种无类型指针`void*`可以存储任何类型的指针，作为函数的参数可以接收任何指针类型，但是在访问该指针指向的存储内容时，需要强制转换具有数据类型的指针。

* 指针的声明：

  ```c++
  <type>* <varName>;
  ```

  > Note：指针在未指定初始值时，使用NULL初始化。

#### 指针的应用

指针在声明时自动使用零值初始化，称为空指针；同时也可以使用`&`来引用已有数据变量的地址，或使用`malloc()`、`new`分配内存空间来初始化指针，分配的内容空间必须使用`free`、`delete`回收；在使用`malloc`时需使用强制类型转换成具有数据类型的指针类型。

* 指针的引用初始化：

  ```c++
  int* intPtr = &<var>;
  ```

* 指针的`malloc`内存分配初始化：

  ```c++
  #include<stdlib.h>
  int* intPtr = (int*)malloc(sizeof(int));
  free(intPtr);
  ```

* 指针的`new`内存分配初始化：

  ```c++
  int* intPtr = new <type>(<value>);
  delete intPtr;
  ```

  > Note：使用type类型的value数据对指针进行初始化和声明。

#### 智能指针

能够自动释放内存的指针，在memory中，包括auto_ptr、shared_ptr、unique_ptr；auto_ptr是独占智能指针，
一个对象只能被一个auto_ptr所指；shared_ptr是共享智能指针，多个指针可以指向同一个对象；unique_ptr是
更安全的auto_ptr。

* 指针指针的定义：

  ```c++
  #include<memory>
  // 定义一个空的智能指针。
  <smartPointer><int> intPtr;
  // 使用已有的智能指针初始化执政指针。
  <smartPointer><int> intPtr(smartPointer);
  // 使用内存分配初始化一个智能指针。
  <smartPointer><int> intPtr(new <type>(<value>));
  ```

  > Note：smartPointer是指auto_ptr、shared_ptr、unique_ptr，其中auto_ptr与shared
  > _ptr可以在同类型的智能指针间赋值，unique_ptr不允许；所有智能指针不能与普通指针互相赋值，但可以通过智能指针的get()
  > 与swap()获取智能指针的地址或交换指针的内容。

#### 常量指针

常量指针是指向常量的指针，又称为底层const。

* 常量指针：

  ```c++
  const int* <ptrName>;
  ```
