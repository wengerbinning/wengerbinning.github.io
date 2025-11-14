应用层网关(ALG, Application Layer Gateway, Application-level gateway, Application gateway, Application proxy)
是一种计算机网络中用于拓展防火墙与NAT的安全组件。允许在网关定制NAT穿透过滤器，以支持某些应用层协议的地址与端口转换，例如
FTP、BitTorrent、SIP、RTSP、IPsec、L2TP、H.323等；为了使这些协议能通过NAT和防火墙工作，要么外部应用程序必须知道允许通
过的IP地址与端口组合， 要么NAT监控流量并动态打开端口映射。

ALG的作用有：

<!-- * allowing client applications to use dynamic ephemeral TCP/UDP ports to communicate with the known ports used
  by the server applications, even though a firewall configuration may allow only a limited number of known ports. -->
* 允许客户端应用程序动态的使用TCP/UDP端口来与已知端口信息的服务端应用程序通信，甚至在防火墙可能只允许有限的已知端口场景中。

  <!-- In the absence of an ALG, either the ports would get blocked or the network administrator would need to explicitly
  open up a large number of ports in the firewall — rendering the network vulnerable to attacks on those ports. -->
  在没有ALG的情况下， 要么端口被阻塞，要么网络管理员需要在防火墙中显式的打开大量的端口；这将导致网络容易受到针对这些端口的攻击。

<!-- * converting the network layer address information found inside an application payload between the addresses 
  acceptable by the hosts on either side of the firewall/NAT. This aspect introduces the term 'gateway' for an ALG. -->
* 在防火墙与NAT两侧的主机的应用程序间的数据流中转换网络层的地址信息，这就是ALG称为网关的原因。


<!-- * recognizing application-specific commands and offering granular security controls over them -->
* 识别特定程序的命令并对其提供细粒度的安全控制。

<!-- * synchronizing between multiple streams/sessions of data between two hosts exchanging data. -->
* 同步应用程序间的多个数据流与会话。

  <!-- For example, an FTP application may use separate connections for passing control commands and for exchanging
  data between the client and a remote server. During large file transfers, the control connection may remain 
  idle. An ALG can prevent the control connection getting timed out by network devices before the lengthy file 
  transfer completes. -->
  例如，一个FTP应用程序可能在客户端与服务端采用单独的数据流来分别传递控制命令与交换数据，在传输大文件时，控制流可能处于空闲
  状态；ALG可以防止控制流在文件传输完成前被网路设备超时。

在给定的网络中，对有ALG处理的所有数据包进行深度包检测成为可能



For instance, for Session Initiation Protocol (SIP) Back-to-Back User agent (B2BUA), an ALG can allow firewall traversal
with SIP. If the firewall has its SIP traffic terminated on an ALG then the responsibility for permitting SIP sessions 
passes to the ALG instead of the firewall.
例如， 在SIP的B2BUA场景中， ALG可以允许SIP穿透防火墙，如果SIP流量被防火墙阻止，ALG有责任代替防火墙传递SIP会话数据。


Basically a NAT with a built-in ALG can rewrite information within the SIP messages and can hold address bindings until 
the session terminates.
基本上， 内置ALG的NAT可以重写SIP数据中的信息，并保持地址绑定知道会话终止。

A SIP ALG will also handle SDP in the body of SIP messages (which is used ubiquitously in VoIP to set up media 
endpoints), since SDP also contains literal IP addresses and ports that must be translated.
SIP ALG还将处理SIP消息中的SDP，因为SDP中包含有需要转换的地址与端口信息。