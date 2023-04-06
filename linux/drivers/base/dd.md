device/driver


#### really_probe

该函数真正执行驱动的probe函数。

```c
static int really_probe (struct device *dev, struct device_driver *drv);
```


#### driver_probe_device

```c
int driver_probe_device(struct device_driver *drv, struct device *dev);
```


#### __device_attach

```c
static int __device_attach(struct device_driver *drv, void *data);
```


#### device_attach 

```c
int device_attach(struct device *dev);
```