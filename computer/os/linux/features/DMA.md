DMA (Direct Memory Access，直接内存访问)
--------------------------------------

涉及到硬件模块

* CPU - 处理器
* DMA - DMA控制器
* DEV - 外设
* MEM - 内存

DMA 处理流程

* CPU配置DMA - CPU告诉DMA:起始地址, 目的地址, 传输长度, 传输方向.
* DMA处理MEM - DMA接管总线, 和内存交换数据.
* DMA通知CPU - DMA完成后产生中断通知CPU.

DMA 处理模式

* 单次传输 - Single Transfer
* 突发传输 - Burst Transfer
* 循环缓存 - Circular Transfer

DMA 相关地址

* 虚拟地址 - (VA, Virtual Address): 由MMU映射到物理地址
* 总线地址 - (BA, Bus Address/DMA Address): 可能由IOMMU映射到物理地址
* 物理地址 - (PA, Physical Address): 物理地址


DMA_T_RW DMA_BIDRECTIONAL - 读写
DMA_T_OR DMA_TO_DEVICE - 只读
DMA_T_OW DMA_FROM_DEVICE - 只写
DMA_NONE DMA_NONE - 无行为