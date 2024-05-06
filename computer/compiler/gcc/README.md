


## 搜索路径

### 头文件

* 通过gcc的-I参数指定的路径
* 环境变量：C_INCLUDE_PATH、CPLUS_INCLUDE_PATH、OBJC_INCLUDE_PATH
* 系统目录： /include、/usr/include、/usr/local/include
* 编译器指定路径：



#### `#include <>`

使用的是默认交叉编译环境路径。

#### `#include ""`

默认使用的是当前路径,当前路径找不到时，使用工具链环境。

### 库文件

* 通过gcc的-L参数指定的路径
* 环境变量: LD_LIBRARY_PATH
* 配置文件： /etc/ld.so.conf
* 系统目录： /lib、/usr/lib



#### Build Linking

LIBRARY_PATH

#### Runtime

LD_LIBRARY_PATH