


```make
helloworld_objs = helloworld.o

helloworld: $(helloworld_objs)
    $(CC) -o $@ $<
```