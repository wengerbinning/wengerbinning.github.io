


## 使用说明



### 服务端

```shell
iperf3 -s
```




### 客户端


### TCP

* TCP默认是不限速率， 128KiB长的消息段；

```shell
#
iperf3 -c 10.100.0.10
# iperf3 --client 10.100.0.10

# 
iperf3 -c 10.100.0.10 -b 1M
# iperf3 --client 10.100.0.10 --bandwidth 1M

#
iperf3 -c 10.100.0.10 -l 1024
# iperf3 --client 10.100.0.10 --length 1024
```

* 

### UDP

* UDP默认是1Mbps的速率，8KiB的消息段；

```shell
#
iperf3 -c 10.100.0.10 -u
# iperf3 --client 10.100.0.10 --udp

#
iperf3 -c 10.100.0.10 -u -b 0
# iperf3 --client 10.100.0.10 --udp --bandwidth 0

iperf3 -c 10.100.0.10 -u -l 1024
# iperf3 --client 10.100.0.10 --udp --length 1024
```

