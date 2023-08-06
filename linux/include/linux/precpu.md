
## 数据结构


#### struct pcpu_group_info

```c
struct pcpu_group_info {
    int nr_units;
    unsigned long base_offset;
    unsigned int *cpu_map;
};
```

#### struct pcpu_alloc_info 

```c
struct pcpu_alloc_info 
{

}
```

## 数据对象


#### pcpu_base_addr

```c
extern void *pcpu_base_addr;
```

#### pcpu_unit_offset

```c
extern const unsigned long *pcpu_uint_offset;
```

