# configure.ac是在configure.scan的基础上修改的，在之前是configure.in。

# 在使用autoscan生成configure.scan之后，将名称改为configure.ac；
# 在AC_INIT宏下添加：这个宏的规则由automake来决定。
AM_INIT_AUTOMAKE([foreign -Wall -Werror])

# 如果在项目中使用了宏开关来控制代码，则需要增加一下宏：用于生成config.h
AC_CONFIG_HEADERS([config.h])

# 在`# Checks for programs.`之后为编译需要的程序：
# 该宏为g++
AC_PROG_CXX
# gcc
AC_PROG_CC
# 库文件，如果使用了libtool,则需要去掉这个宏。

# 在AC_OUTPUT上添加一行:指定了autoconf的输出文件。
AC_CONFIG_FILES([Makefile tools/Makefile common/Makefile worker/Makefile])
