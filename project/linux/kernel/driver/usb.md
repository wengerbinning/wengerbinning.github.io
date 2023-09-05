#
USB


USB的协议栈

* USB设备类驱动
* USB核心驱动(USBD)
* USB主机控制器驱动(HCD)
* USB设备




HCD,Host Controller Driver,通过HCI对USB主控制器的各类操作进行分装，为上层提供一个访问USB设备的服务。
===

HCD仅对USB总线驱动程序提供服务，以及管理主控制器的各种行为。

```
struct xhci_hcd;  
```
**xhci-pic**

```c
struct hc_driver;

struct pci_device_id pci_ids[];

struct pci_diver;

// linux/platform_device.h

struct usb_hcd;

struct platform_driver;


```



```c
// file: linux/usb.h

struct urb;

```


USBD
====

USBD是整个USB主机驱动的核心，主要功能有USB总线管理、USB总线设备管理、USB总线带宽管理、USB的4种数据传输、USB HUB驱动、为USB设备类提供服务。


usb_device, usb_bus, usb_driver, 
URB是HSBD与上下层通信的数据结构。


 

USB设备类驱动
===========

USB的设备类驱动有mass storage、 serial等
这类



```c
// usb_device_id用于描述该驱动可以支持那些设备。
// file: include/linux/mod_devicetable.h
struct usb_device_id {
    u16 match_flags;
    u16 idVendor;

}
```

```c
struct usb_driver {
    char *name,                                // 驱动程序的名称。 
    probe                                      // USB驱动程序的探测函数指针。
    disconnect                                 // 断开函数指针。
    suspend
    resume
    reset_resume
    pre_reset
    post_reset
    id_table                                    // 包含该驱动程序支持的USB设备。
    supports_autosuspend
    soft_unbind
}
```



```c
// 
struct usb_interface {

}
```




--------------------------

Linux kernel关于USB的代码在driver/usb目录中。



core/



host/


storage/





