# Java系统管理

[//]: # (__author__ = "Wenger Binning")

## 输入与输出

* 使用$Scanner$获取键盘输入:

  1. 导入$Scanner$对象:

     ```java
     import java.util.Scanner;
     ```

   2. 获取输入数据:

      ```java
      public class TestIO {
      
          public static void main(String[] args) {
              Scanner scannerDemo = new Scanner(System.in);    //新建一Scanner对象
              System.out.print("请输入文件名 : ");
              String fileName = scannerDemo.nextLine();        //获取字符串
              System.out.print("请输入文件大小(Byte) : ");
              int fileSize = scannerDemo.nextInt();            //获取整型
        
              System.out.println("文件名为 : "+fileName);
              System.out.println("文件大小 : "+fileSize+" Byte ");
          }
      }
      ```

* 使用$System.out$的方法输出:

  ```java
  int intDemo = 10;
  System.out.print( "<content>" );                //原样输出
  System.out.println( "<content>" );                //原样输出后再输出一个回车换行符
  System.out.printf( "%d",intDemo );                //与C语言的printf函数一样
  ```
  
## 时间与日期



### Date类

* Java中的`java.util`包中提供`Date`类来封装当前时间和日期.该类由两个构造函数:

  ```
  Date();    //以当前时间初始化
  Date(long millisxec);    //距1970年1月1日起的毫秒数
  ```

* 该类的成员方法:

  | 方法                           | 说明                       | 方法 | 说明 |      |      |
  | ------------------------------ | -------------------------- | ---- | ---- | ---- | ---- |
  | `boolean after(Date date);`    | 返回对象是否在指定时间之后 | `    |      |      |      |
  | `boolean before(Date date);`   | 返回对象是否在指定时间之前 |      |      |      |      |
  | `Object clone();`              | 克隆,返回一个Object对象    |      |      |      |      |
  | `int compareTo(Date date);`    | 比较两个时间的大小         |      |      |      |      |
  | `boolean equals(Object date);` | 比较两个时间是否相等       |      |      |      |      |
  | `int getDate();`               | 获取天数 (被弃用!!!)       |      |      |      |      |
  | `int getDay();`                | 获取周几(被弃用!!!)        |      |      |      |      |
  | `int getHours();`              | 获取小时(被弃用!!!)        |      |      |      |      |
  | `int getMinutes();`            | 获取分钟(被弃用!!!)        |      |      |      |      |

  

  ```
  boolean after(Date date);
  boolean before(Date date);
  Object clone();
  int compareTo(Date date);
  int compareTo(Object date);
  boolean equals(Object date);
  long getTime();
  int hashCode();
  void setTime(long time);
  String toDtring();
  ```

* 使用`SimpleDateFormat`格式化日期:

```
import  java.util.*;
import java.text.*;

public class DateDemo {
   public static void main(String args[]) {
 
      Date dNow = new Date( );
      SimpleDateFormat ft = new SimpleDateFormat ("yyyy-MM-dd hh:mm:ss");
 
      System.out.println("当前时间为: " + ft.format(dNow));
   }
}
```

### Calendar类

* Calendar是一个抽象类

#### 创建Calendar对象

```
Calendar dateDemo = Calendar.getInstance();        //默认当前时间
dateDemo.set(int year, int month, int day );
dateDemo.set(Calendar.DATE, 10);
dateDemo.add(Calendar.DATE, 10);    //时间增加
dateDemo.get(Calendar.YEAR);
```



### `GregorianCalendar`类
