

```c
#define	CSR_NETLINK	30
#define	CSR_READ	0
#define	CSR_WRITE	1
#define	CSR_TEST	2

#define RALINK_CSR_GROUP	 2882
```


#### CSR_MSG

```c
typedef struct rt2880_csr_msg CSR_MSG;
```



#### csr_netlink_init

```c
int csr_netlink_init (void);
```

#### rt2880_csr_msgsend

```c
int rt2880_csr_msgsend (CSR_MSG* csrmsg);
```

#### rt2880_csr_receiver

```c
void rt2880_csr_receiver (struct sock *sk, int len);
```







CSR: Control Switch Register