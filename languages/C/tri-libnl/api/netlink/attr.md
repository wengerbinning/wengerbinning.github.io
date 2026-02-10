

#### nla_put_u8

```c
extern int nla_put_u8 (struct nl_msg *, int, uint8_t);
```

#### nla_put_u16

```c
extern int nla_put_u16 (struct nl_msg *, int, uint16_t);
```

#### nla_put_u32

```c
extern int nla_put_u32 (struct nl_msg *, int, uint32_t);
```

#### nla_put_u64

```c
extern int nla_put_u64 (struct nl_msg *, int, uint64_t);
```

#### nla_put_string

```c
extern int nla_put_string (struct nl_msg *, int, const char *);
```

#### nla_put_flag

```c
extern int nla_put_flag (struct nl_msg *, int);
```

#### nla_put_msecs

```c
extern int nla_put_msecs (struct nl_msg *, int, unsigned long);
```





#### nla_put_nested

```c
extern int nla_put_nested (struct nl_msg *, int, struct nl_msg *);
```

#### nla_nest_start

```c
extern struct nlattr *nla_nest_start (struct nl_msg *, int);
```

#### nla_nest_end

```c
extern int nla_nest_end (struct nl_msg *, struct nlattr *);
```

#### nla_parse_nested

```c
extern int nla_parse_nested (struct nlattr **, int, struct nlattr *, struct nla_policy *);
```

