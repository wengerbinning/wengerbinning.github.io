

#####

```shell
echo "1:2:3" | awk 'BEGIN {FS = ":"}; {printf "%s\n", $1}'
```

####


```shell
for (i=1; i<=NF; i++) {
    printf "%s\n", $i
}
```

```shell
for ( in table) {

}
```
