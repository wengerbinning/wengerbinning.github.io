内存管理(MM, Memory Management)




buddy system
------------

伙伴系统(buddy system)是一个内存管理系统，用来解决内存的碎片化问题；



slab缓存分配器
------------







SLUB



SLOB
-----


SLOB是嵌入式系统中的一个slab的实现。




scatter & gathers list
----------------------

分散列表(scatter list)是为了聚集(gathers).



IO内存空间的地址资源分配情况可以通过proc的的iomem文件查看，该内容是以树的形式显示

__iomem是linux v2.6.9加入的特性，用来描述指针是指向一个IO的内存空间

IO端口空间的地址资源分配情况可以通过proc的ioports文件查看，改内容是以树的形式显示。




LINKS
-----

1. https://blog.csdn.net/zrlean/article/details/7788670?spm=1001.2101.3001.6661.1&utm_medium=distribute.pc_relevant_t0.none-task-blog-2%7Edefault%7ECTRLIST%7Edefault-1-7788670-blog-108866518.pc_relevant_aa&depth_1-utm_source=distribute.pc_relevant_t0.none-task-blog-2%7Edefault%7ECTRLIST%7Edefault-1-7788670-blog-108866518.pc_relevant_aa&utm_relevant_index=1


