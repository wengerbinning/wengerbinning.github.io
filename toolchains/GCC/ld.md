


#### -rpath=*path*

<!-- Add a directory to the runtime library search path. This is used when linking an ELF executable with shared objects. 
All -rpath arguments are concatenated and passed to the runtime linker, which uses them to locate shared objects at runtime.
The -rpath option is also used when locating shared objects which are needed by shared objects explicitly included in the
link; see the description of the -rpath-link option. If -rpath is not used when linking an ELF executable, the contents 
of the environment variable "LD_RUN_PATH" will be used if it is defined.-->
将目录添加到运行时库搜索路径。这在将 ELF 可执行文件与共享对象链接时使用。所有 -rpath 参数都被连接并传递给运行时链接器，后者使用它们在运行时定
位共享对象。-rpath 选项也用于定位明确包含在链接中的共享对象所需的共享对象；请参阅 -rpath-link 选项的说明。如果在链接 ELF 可执行文件时未使用
-rpath，则将使用环境变量“LD_RUN_PATH”的内容（如果已定义）。

#### -rptah-link=*path*