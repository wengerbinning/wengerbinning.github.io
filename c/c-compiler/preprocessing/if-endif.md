if-endif是用于编译控制的预编译指令

* 通过

```c
#if /* <condition> */
    // Compiling the code only when the condition it ture.
#endif
```



* 

```c
#if 0
    // Disable this code when compiling. 
#endif
```

* 


```c
#if CONFIG_DEUBG
    // code
#endif
```

```c
#if defined(NETWORK)
    // code
#endif
```

```c
#if defined(FS) || defined(NETWORK)
    // code
#endif
```

```c
#if defined(FS) && defined(NETWORK)
    // code
#endif
```

```c
#if !defined(DEBUG)

#endif
```


```c
#if !(defined(DEBUG) || defined(FS))
#endif
```
