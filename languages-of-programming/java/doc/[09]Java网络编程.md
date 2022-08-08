# Java网络编程

[//]: # (__author__ = "Wenger Binning")

* `java.net`包提供常见的两种网络支持:TCP 与 UDP.

## socket编程

* 套接字使用TCP提供了两台计算机之间的通信机制。 客户端程序创建一个套接字，并尝试连接服务器的套接字    

* 当连接建立时，服务器会创建一个 Socket 对象。客户端和服务器现在可以通过对 Socket 对象的写入和读取来进行通信。

  `java.net.Socket` 类代表一个套接字，并且 `java.net.ServerSocket `类为服务器程序提供了一种来监听客户端，并与他们建立连接的机制

  * 服务器实例化一个 ServerSocket 对象，表示通过服务器上的端口通信。
  * 服务器调用 ServerSocket 类的 accept() 方法，该方法将一直等待，直到客户端连接到服务器上给定的端口。
  * 服务器正在等待时，一个客户端实例化一个 Socket 对象，指定服务器名称和端口号来请求连接。
  * Socket 类的构造函数试图将客户端连接到指定的服务器和端口号。如果通信被建立，则在客户端创建一个 Socket 对象能够与服务器进行通信。
  * 在服务器端，accept() 方法返回服务器上一个新的 socket 引用，该 socket 连接到客户端的 socket。

### ServerSocket类的方法

| 方法                                                         | 说明                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| **public ServerSocket(int port) throws IOException**         | 创建绑定到特定端口的服务器套接字。                           |
| **ublic ServerSocket(int port, int backlog) throws IOException** | 利用指定的 backlog 创建服务器套接字并将其绑定到指定的本地端口号。 |
| **public ServerSocket(int port, int backlog, InetAddress address) throws IOException** | 使用指定的端口、侦听 backlog 和要绑定到的本地 IP 地址创建服务器。 |
| **public ServerSocket() throws IOException**                 | 创建非绑定服务器套接字。                                     |
| **public int getLocalPort()**                                | 返回此套接字在其上侦听的端口                                 |
| **public Socket accept() throws IOException**                | 侦听并接受到此套接字的连接                                   |
| **public void setSoTimeout(int timeout)**                    | 通过指定超时值启用/禁用 SO_TIMEOUT，以毫秒为单位。           |
| **public void bind(SocketAddress host, int backlog)**        | 将 ServerSocket 绑定到特定地址（IP 地址和端口号）。          |

## InetAddress类

