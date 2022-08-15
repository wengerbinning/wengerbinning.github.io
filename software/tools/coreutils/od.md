# od

od是属于GNU项目中的子项目，用来使用特定格式转存文件，默认使用八进制来转存文件。

```shell
od <option> <file>...
```

## option

* `-A <radix>, --address-radix=<radix>`指定基数的显示格式，可以是八进制、十进制、十六禁止，或者不显示。

* `--endian=<order>`指定数据转存的格式是大端存储还是小端存储。

* `-j <bytes>, --skip-bytes=<bytes>`在转存数据之前先跳过多少字节。

* `-N <bytes>, --read-bytes=<bytes>`

* `-S <bytes>, --strings[=<bytes>]`

* `-t <type>, --format=<type>`指定数据显示的格式。

* `-v, --output-duplicates`

* `-w<[n]>, --width[=<n>]`指定一行显示多少个字节数。

* `--traditional`

## LINKS

* [GNU Maual](https://www.gnu.org/software/coreutils/manual/html_node/od-invocation.html#od-invocation)