内存技术设备(MTD, Memory Technology Device)是linix kernel为NOR flash与NAND flash设备提供统一的接口而引入的抽象层。
MTD一般分为四层，自上之下依次是：设备节点、MTD设备层、MTD原始设备层、Flash硬件驱动层。Flash硬件驱动层负责对flash硬件进行
读写以及擦除操作，关于NOR flash的驱动位于driver/mtd/chips/下，关于NAND flash的驱动位于driver/mtd/nand/下；

MTD原始设备层实现了一个描述MTD原始设备的数据结构mtd_info,该数据结构包含许多关于MTD的数据以及操作函数，其中在mtdcore.c中
实现了MTD原始设备的相关接口，在mtdpart.c实现了有关MTD分区的接口。该数据结构在创建之后偶将会添加到mtd_table中。

在MTD原始设备的基础上，kernel定义了两类设备：MTD的字符设备与块设备，字符设备的相关实现在mtdchar.c中，块设备的相关实现在
mtdblock.c中。

