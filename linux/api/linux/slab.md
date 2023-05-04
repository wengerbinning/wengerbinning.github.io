


* `GFP_AOMIC`: 分配过程是一个原子操作， 不能被打断。
* `GFP_KERNEL`: 常规分配内存。
* `GFP_DMA`: 给DMA控制器分配内存。
    




#### kmalloc

kmalloc申请内存位于物理内存映射区， 物理上连续。不能超过128KiB。


#### kzalloc

kzalloc是对kmalloc的封装， 会对申请的内存进行清零。


```c
void *kzalloc(size_t size, gfp_t flags);
```

#### kfree



### 

#### vmalloc

vmalloc会申请一块在虚拟内存连续，但物理内存不一定连续的内存区， 内存大小无限制


#### vfree