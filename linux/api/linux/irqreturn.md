

#### IRQ_RETVAL

```c
#define IRQ_RETVAL(x)	((x) != IRQ_NONE)
```

#### enum irqreturn

```c
enum irqreturn {
	IRQ_NONE		= (0 << 0),
	IRQ_HANDLED		= (1 << 0),
	IRQ_WAKE_THREAD	= (1 << 1),
};
```

#### irqreturn_t

```c
typedef enum irqreturn irqreturn_t;
```