## Editor

### awk

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


### cut

### tr
### string
### grep
### sed

### hexdump
### od
### xxd
### biodiff

## Directory

### find

* `-mindepth`
* `-maxdepth`
* `-type`
* `-name`

### ls
### tree
### cd
### mkdir
### rm
### mv
### install
### ln
### stat
### file