pkg-config是一个搜索依赖项的工具，进经常用于C库的查询，根据`*.pc`文件来查询，默认路经在/usr/lib/pkgconfig/下。
可以通过PKG_CONFIG_PATH、PKG_CONFIG_LIBDIR、PKG_CONFIG_SYSROOT_DIR变量来影响该工具。


```shell
# 获取头文件。
pkg-config -cflags opencv
# 获取库文件。
pkg-config --libs opencv
```