以太网(Ethernet)是由美国Xerox(施乐)的Palo Alto研究中心于1975年研制成的一种基带总线局域网，数据
传输速率为2.94Mbps。之后Digital、Intel、Xerox于1981年合作提出了以太网规约。次年又修改了第二版，
即DIX Ethernet V2， 这是世界上第一个局域网产品的规约。

在此基础上， 802.3 工作组指定了第一个以太网标准(IEEE 802.3), 其速率是10Mbps，此标准与DIX Ethernet V2
仅在MAC帧格式存在细微差别， 所以IEEE802.3也被称为以太网。

以太网可供选择的传输介质有



标准的以太网帧长度范围是 64 - 1518



Ethernet Frame (Layer 1)
------------------------

8 + 12 ~

* 07B - Preamble
* 01B - SFD, start frame delimiter
* xxB - Ethernet Frame(Layer 2)
* 12B - IPG(Interpacket gap)

Ethernet Frame (layer 2)
------------------------

64B ~ 1522B

* 06B - DST MAC
* 06B - SRC MAC
* 02B - Ethernet Type
* xxB - Playload
* 04B - FCS, Frame Check Sqeuence， 32 CRC



