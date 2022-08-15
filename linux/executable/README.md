Linux系统下的可执行文件格式是ELF(Executable Linkable Format)， 属于COFF的变种。中间目标
文件与库以及可执行文件都采用这种格式。

在ELF标准中， 文件共分为4类：

可重定位文件(Relocatable File)，通常为中间目标文件*.o， 包含代码与数据;
可执行文件(Executable File)，通常为可执行的文件
共享目标文件(Shared Object File)，通常为*.so文件， 包含代码与数据，可以被链接器链接到可执行文件
或者动态链接器结合到进程印象中。
核心转储文件(Core Dump File)， 系统将进程的地址空间的内容以及其他信息转储的文件。




目标文件包含代码、数据、符号表、调试信息以及字符串；

ELF文件按照节(Section)的形式存储， 有时也成为段(Segment)， 都表示一定长度的区域；

代码放在代码段中(code Section)， 名字有 .code, ,text
全局变量与局部静态数据放在数据段中(Data section)， 名字有 .data; 未初始化的全局变量与局部静
态变量一般放在 .bss 段， 因为这些变量默认值是0，本应放在 .data 段，并初始化为0，但是没有必要
所以通过一个 .bss 段来记录未初始化的全局变量与局部静态变量的大小总和，只是为他们预留位置，并没
有内容， 不占据空间。


将代码与数据分离，可以设置不同的权限来保护系统， 提高程序的局部性(现代CPU的缓存一般都设计为数据
与指令分离)、系统运行多进程时实现代码段共享。



通过objdump来查看目标文件内容，



* 通过objdump显示可重定位文件的的内容。

```c
objdump -h demo.o
```

ELF文件头

| key | comment |
|:--- |:--- |
| Magic | ELF文件魔数 |
| Class | 机器字节长度 |
| Data | 数据的存储方式 |
| Version | 版本信息 |
| OS/ABI | 运行平台 |
| ABI Version | ABI版本 |
| Type | ELF重定位类型 |
| Machine | 硬件平台 |
| Version | 硬件平台版本 |
| Entry point address | 入口地址 |
| Start of program headers | 程序头入口 |
| Start of section headers | 段表入口 |
| Flags | 标志 |
| Size of this header | 文件头大小 |
| Size of program headers | 程序头大下 |
| Number of program headers | 程序头的数量 |
| Size of section headers | 段表的大小 |
| Number of section headers | 段表的数量 |
| Section header string table index | 符号表 |


32位的ELF

| 自定义类型 | 原始类型 | 长度 | 描述 |
|:--- |:--- | ---:|:--- |
| Elf32_Addr | uint32_t | 4 |
| Elf32_Half |
| Elf32_Off |
| Elf32_Sword |
| Elf32_Word |


64位的ELF

| 自定义类型 | 原始类型 | 长度 | 描述 |
|:--- |:--- | ---:|:--- |
| Elf64_Addr | uint64_t | 8 |
| Elf64_Half |
| Elf64_Off |
| Elf64_Sword |
| Elf64_Word |




.开始的段都是系统内部保留的， 我们也可以添加自己的段，注意不能有.前缀。


| section | label | comment |
|:--- |:--- |:--- |
| .text | 代码段 | 存放执行的区域 |
| .data | 初始化的全局与局部静态数据段 | 存放已初始化的全局与局部静态数据的区域 |
| .bss | 未初始化的全局与局部静态数据段 | 存放未初始化的全局与局部静态数据的区域 |
| .rodata | 只读数据段 | 存放只读变量与字面量的区域 |



| section | label | comment |
|:--- |:--- |:--- |
| .comment | 注释信息 |
| .note.GNU-stack | 堆栈提示段 |
| .rodata1 |
| .debug |
| .dynamic |
| .hash |
| .line |
| .note |
| .strtab |
| .symtab |
| .shstrtab |
| .plt |
| .got |

| .init |
| .fini |



**调试信息**

| section | lable | comment |
|:--- |:--- |:--- |
| .debug_abbrev |
| .debug_info |
| .rel.debug_info |
| .debug_line |
| .rel.debug_line |
| .debug_frame |
| .rel.debug_frame |
| .debug_loc |
| .debug_pubnames |
| .rel.debug_pubnam |
| .debug_aranges |
| .rel.debug_arange |







ELF标准开始是一个文件头，用于描述文件的属性， 包含是否可执行、目标平台、目标操作系统等信息以及
段表(Section Table),