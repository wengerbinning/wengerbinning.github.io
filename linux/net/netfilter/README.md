netfilter是一个用于管理网络数据包的框架，提供网络地址转换、数据包内容修改、数据包过滤等功能。








netfilter框架于2000年合入2.4.x




netfilter在网络数据中提供了5个钩子点

PREROUTING
LOCAL_IN
FORWARD
LOCAL_OUT
POSTROUTING


每个钩子的返回类型是

NF_DROP
NF_ACCEPT
NF_STOLEN
NF_QUEUE
NF_REPEAT
