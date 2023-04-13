


```c
#define __init		__section(.init.text) __cold notrace
#define __initdata	__section(.init.data)
#define __initconst	__constsection(.init.rodata)
#define __exitdata	__section(.exit.data)
#define __exit_call	__used __section(.exitcall.exit)


#define __exit          __section(.exit.text) __exitused __cold notrace
```

#### __define_initcall

```c
#define __define_initcall(fn, id) \
	static initcall_t __initcall_##fn##id __used \
	__attribute__((__section__(".initcall" #id ".init"))) = fn
```

#### device_initcall

```c
#define device_initcall(fn)		__define_initcall(fn, 6)
```

#### __initcall

```c
#define __initcall(fn) device_initcall(fn)
```

#### __exitcall

```c
#define __exitcall(fn) \
	static exitcall_t __exitcall_##fn __exit_call = fn
```

#### module_init

```c
#define module_init(x)	__initcall(x);
```

#### module_exit

```c
#define module_exit(x)	__exitcall(x);
```