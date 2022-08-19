拥塞控制是TCP发送方针对网络拥堵情况所采取的措施。

拥塞控制机制：慢启动、拥塞避免、

在1999年公布的RFC 2581给出了控制TCP拥塞的不同算法，RFC2582与RFC3390进一步修正这些算法。主要有慢启动（SS，Slow Start）与加性增和乘性减（AIMD，Additive-increase，multiplicative-decrease）。

* SS：初始拥塞窗口为1,逐步试探网络，
* AIMD：