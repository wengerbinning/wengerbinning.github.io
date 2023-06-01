# Java异常处理

[//]: # (__author__ = "Wenger Binning")

异常处理

## 异常抛出

## 异常检测

## 异常捕获

## 异常处理

## 异常类型

* 所有的异常都是从java.lang.Exception类继承的子类,Exception与Error都是继承自Throwable.其中Exception主要有两个子类IOException与RuntimeException;Error通常指运行时环境发生的错误.
* Java程序通常不会捕获错误异常.

* Java中内置的异常类: --- Java语言定义了一些异常类在java.lang标准包中.    

  * 非检查性异常:

    | 异常                             | 说明                                                         |
    | -------------------------------- | ------------------------------------------------------------ |
    | `ArithmeticException`           | 出现异常的运算条件时，抛出此异常。例如，一个整数"除以零"时。 |
    | `ArrayIndexOutOfBoundsException` | 用非法索引访问数组时抛出的异常。如果索引为负或大于等于数组大小，则该索引为非法索引。 |
    | `ArrayStoreException ` ?         | 试图将错误类型的对象存储到一个对象数组时抛出的异常。         |
    | `ClassCastException`  ?          | 当试图将对象强制转换为不是实例的子类时，抛出该异常。         |
    | `IllegalArgumentException ` ?    | 抛出的异常表明向方法传递了一个不合法或不正确的参数。         |
    | `IllegalMonitorStateException`  ? | 抛出的异常表明某一线程已经试图等待对象的监视器，或者试图通知其他正在等待对象的监视器而本身没有指定监视器的线程。 |
    | `IllegalStateException ` ?       | 在非法或不适当的时间调用方法时产生的信号。换句话说，即 Java 环境或 Java 应用程序没有处于请求操作所要求的适当状态下 |
    | `IllegalThreadStateException ` ? | 线程没有处于请求操作所要求的适当状态时抛出的异常。           |
    | `IndexOutOfBoundsException ` ?   | 指示某排序索引（例如对数组、字符串或向量的排序）超出范围时抛出。 |
    | `NegativeArraySizeException ` ? | 如果应用程序试图创建大小为负的数组，则抛出该异常。 |
    | `NullPointerException  ` ? | 应用程序试图在需要对象的地方使用 `null` 时，抛出该异常 |
    | `NumberFormatException`  ? | 应用程序试图将字符串转换成一种数值类型，但该字符串不能转换为适当格式时，抛出该异常。 |
    | `SecurityException`  ? | 由安全管理器抛出的异常，指示存在安全侵犯。 |
    | `StringIndexOutOfBoundsException` ? | 此异常由 `String` 方法抛出，指示索引或者为负，或者超出字符串的大小。 |
    | `UnsupportedOperationException` ? | 当不支持请求的操作时，抛出该异常。                           |
    |  |  |

  * 检查性异常:

    | 异常                   | 说明                                   |
    | ---------------------- | -------------------------------------- |
    | `ClassNotFoundException ` ? | 应用程序试图加载类时，找不到相应的类，抛出该异常。 |
    | `CloneNotSupportedException  ` ? | 当调用 `Object` 类中的 `clone` 方法克隆对象，但该对象的类无法实现 `Cloneable` 接口时，抛出该异常。 |
    | `IllegalAccessException ` ? | 拒绝访问一个类的时候，抛出该异常。 |
    | `InstantiationException`  ? | 当试图使用 `Class` 类中的 `newInstance` 方法创建一个类的实例，而指定的类对象因为是一个接口或是一个抽象类而无法实例化时，抛出该异常。 |
    |                        |                                        |
    | `InterruptedException`  ? | 一个线程被另一个线程中断，抛出该异常。 |
    | `NoSuchFieldException ` ? | 请求的变量不存在                       |
    | `NoSuchMethodException`  ? | 请求的方法不存在 |
  
* Throwable类的异常方法:

  | 方法                                        | 说明 |
  | ------------------------------------------- | ---- |
  | `public String getMessage()`                |      |
| `public Throwable getCause()`               |      |
  | `public String toString()`                  |      |
| public void printStackTrace()               |      |
  | public StackTraceElement [] getStackTrace() |      |
  | public Throwable fillInStackTrace()         |      |
  
  捕获异常:
  
  ```
  try
  {
     // 程序代码
}catch(ExceptionName e1)
  {
     //Catch 块
  }
  ```
  
  * 多重捕获:
  
    ```
    try{
       // 程序代码
    }catch(异常类型1 异常的变量名1){
      // 程序代码
    }catch(异常类型2 异常的变量名2){
      // 程序代码
    }catch(异常类型2 异常的变量名2){
      // 程序代码
    }
    ```
  
  * throws / throw 关键字: --- 如果一个方法没有捕获到一个检查性异常，那么该方法必须使用 throws 关键字来声明。throws 关键字放在方法签名的尾部。也可以使用 throw 关键字抛出一个异常，无论它是新实例化的还是刚捕获到的。
  
    ```
    import java.io.*;
    public class className
    {
       public void withdraw(double amount) throws RemoteException,
                                  InsufficientFundsException
       {
           // Method implementation
       }
       //Remainder of class definition
    }
    ```
