ioctl是用户与驱动程序进行交互的接口，用户通过该函数可以直接调用驱动函数来执行，在用户到驱动之间需要经过sys_ioctl()来进行转换。

ioctl在用户空间提供一下接口：

* `int ioctl(int __fd, unsigned long int __request, ...) __THROW`

```c
/* @param __fd file description
 * @param __request
 * 
 * @return int
 */
int ioctl(int __fd, unsigned long int __request, ...) __THROW;
```