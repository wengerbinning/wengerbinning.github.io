


```
while <condition>; do
    <loop statement>
done
```



* 

```shell
loop=true
index=0

while $loop; do
    # If loop more than 3 times, exit after processing accordingly.
    if [ $index -ge 3 ]; then
        break;
    fi
    # Update loop time.
    index=$((index + 1))

    # Loop processing.
    echo "This $index time loop."

    # If need exit, you can open this. 
    #; loop=false
done
```
