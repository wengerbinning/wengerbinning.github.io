iptables是一个管理员工具，用于配置网络数据包过滤与NAT。

```
# 
iptables [-t table] {-A|-C|-D|-V} <chain> <rule specification>

#
iptables [-t table] -I <chain> <rule num> <rule specification>
```


ACCEPT、DROP、RETURN

| short option | long option | value | comment |
|:--- |:--- |:--- |:--- |
| `-t` | `--table` | tablemwan3_hook | `filter|nat|mangle|raw|security|` |
| `-A` | `--append` | 
| `-C` | `--check` |
| `-D` | `--delete` |
| `-I` | `--insert` |
| `-R` | `--replace` |
| `-L` | `--list` |
| `-S` | `--list-rules` |
| `-F` | `--flush` |
| `-Z` | `--zore` |
| `-N` | `--new-chain` |
| `-X` | `--delete-chain` |
| `-P` | `--policy` |
| `-E` | `--rename-chain` |
| `-h` | - |

| parameters | value | comment |
|:--- |:--- |:--- |
| `-p` | `--protocol` | `{tcp|udp|udplite|icmp|icmpv6|esp|ah|sctp|mh|all}` |
| `-s` | `--source` | address/mask |
| `-d` | `--destination` | address/mask |
| `-m` | `--match` | match |
| `-j` | `--jump` | target |
| `-g` | `--goto` | chain |
| `-o` | `--out-interface` | name |
| `-f` | `--fragment` |
| `-c` | `--set-counter` | packages bytes |


| short option | long option | value | comment |
|:--- |:--- |:--- |:--- |
| `-v` | `--verbose` |
| `-V` | `--version` |
| `-w` | `--wait` |
| `-n` | `--numeric` |
| `-x` | `--exact` |
| | `--line-numbers` |
| | `--modprobe` | command |




## 使用示例

* 指定ipset集

```shell
# blacklist是一个ipset集
iptables -I INPUT -m set -match-set blacklist src -p tcp -j DROP
```


**conntrack**

该模块与连接跟踪结合使用时，允许访问此数据包/连接的连接跟踪状态。

* `--ctstate` 匹配连接状态，多个状态逗号分隔。

  - `INVALID` 数据包与未知连接关联。
  - `NREW` 数据包与开始一个新的连接关联。
  - `ESTABLISHED` 数据包与
  - `RELATED` 数据包开始一个新的连接，但是与关联一个存在的连接，例如FTP、ICMP等。
  - `UNTRACKED` 数据包不跟踪
  - `SNAT` 一个虚拟状态，请求源地址与响应目标地址不同则匹配。
  - `DNAT` 一个虚拟状态，请求目的地址与响应的源地址不同匹配。

```shell
iptables -A INPUT -m conntrack --ctstate NEW,ESTABLISHED -m comment --comment "!fw3" -j ACCEPT
```

**set**

set用于匹配由ipset定义的IP sets。

* `--match-set` 设置黑名单IP set。

```shell
# 如果数据与blacklist集中元素匹配成功，则丢弃。
iptables -A FORWARD -m set --match-set blacklist -j DROP 
```

**socket**

```shell
# 如果数据与blacklist集中元素匹配成功，则丢弃。
iptables -A FORWARD -m socket --transparent 
```


**comment**

添加256字节以内的注释到任何规则。

* `--comment` 指定注释内容。

```shell
iptables -A INPUT -m comment --comment "My local LAN"
```
