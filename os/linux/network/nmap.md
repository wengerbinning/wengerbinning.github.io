








## 主机发现


* 列表扫描: 不会向目标主机发送任何报文。

```shell
nmap -sL 192.168.1.0/24
```

* 不做端口扫描

```shell
nmap -sn 192.168.1.0/24
```



* 

```
nmap -Pn
nmap -PS
nmap -PA
nmap -PU
nmap -PY
nmap -PE
nmap -P0
```
## 端口扫描


```
nmap -sS
nmap -sT
nmap -sU
nmap -sY
nmap -sN
nmap -sF
nmap -sX
nmap -sA
nmap -sW
nmap -sM
nmap -sZ
nmap -sI
nmap -s0
```

```
nmap -p
```

