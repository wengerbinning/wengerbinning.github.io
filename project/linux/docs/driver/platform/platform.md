platform模型由platform bus、platform driver以及platform device组成，该模式是为了统一驱动
模型而抽象出来的

**platform bus**


**platform driver**

```c
/* linux/device.h */
struct device_driver {
    const char *name;
    struct bus_type *bus;
    struct module *owner;
    const char *mod_name;
    bool suppress_bind_attrs;
    const struct of_device_id *of_match_table;
    const struct acpi_device_id *acpi_match_table;
    int (*probe)(struct device *dev);
    int (*remove)(struct device *dev);
    void (*shutdown)(struct device *dev);
    int (*suspend)(struct deivce *dev, pm_message_t state);
    int (*resume)(struct device *dev);
    const struct attribute_group **groups;
    const struct dev_pm_ops *pm;
    struct driver_private *p;
};

/* linux/platform_device.h */
struct platform_driver {
    int (*probe)(struct platform_device *);
    int (*remove)(struct platform_device *);
    void (shutdown)(struct platform_device *);
    int (*suspend)(struct platform_device *, pm_message_t state);
    int (*resume)(struct platform_device *);
    struct device_driver driver;
    const struct platform_device_id *id_table;
}
```


**platform_device**

```c
struct platform_device {
    const char *name;
    int id;
    bool id_auto;
    struct device dev;
    u32 num_resource;
    struct resource *resource;
    const struct platform_device_id *id_entry;
    struct mfd_cell *mfd_cell;
    struct pdev_archdata archdata;
};
```
