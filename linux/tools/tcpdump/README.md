Tcpdump是一个网络分析工具，该项目提供一个分析工具`tcpdump`与一个C/C++库`libpcap`。




## option

* `--list-interfaces`显示所有接口。

* `-F <file path>`指定匹配的参数文件。

* `-E`根据参数分析IPsec的报文。
* `-h, --help`显示帮助文档。
* `-H` 尝试识别802.11sd的mesh报文。
* `-i <interface>, --interface=<interface>` 指定抓取接口。
* `-I, --monitor-mode` 指定接口为监听模式，部分接口支持。
* `--immediate-mode` 紧急模式，抓取数据绕过缓存直接送到tcpdump.
* `-n` 指定不转换地址与端口。
* `-N` 不打印域名。
* `-Q <direction>, --direction=<direction>`指定数据方向。
* `-w <file>`将报写入file文件中
* `-U, --packet-buffered`


LINKS
=====

* <https://tcpdump.org>

SOURECE CODE
============

**tcpdump**

* github

```shell
git clone https://github.com/the-tcpdump-group/tcpdump
```

**libpcap**

* github

```shell
git clone https://github.com/the-tcpdump-group/libpcap
```






