UBI是基于mtd设备实现的抽象模型，其实现了mtd设备特性的管理逻辑（主要有坏块管理、磨损平衡、位翻转）。
其功能类似外存设备中的控制器，可以为文件系统(ubifs)提供的访问mtd设备的服务。之后，我将使用ubi设备
来描述UBI对上提供的服务。

管理ubi设备的工具集成在mtd-utils中，可以通过该工具来管理ubi设备，创建分区





UBI中有逻辑擦除快(LEB, Logical Erase Block)与物理擦除快(PEB, Physical Erase Block)。
