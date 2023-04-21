


#### config_init_package

```c
static struct uci_package *config_init_package(const char *config);
```


#### config_init_vlans

```c
static void config_init_vlans (void);
```

#### config_parse_interface

```c
static void config_parse_interface (struct uci_section *s, bool alias);
```



#### config_init_all

初始化 network 与 wireless 配置.

```c
int config_init_all (void);
```
