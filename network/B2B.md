<!-- A back-to-back connection is the direct connection of the output of one device to the input of a similar or related device. -->
B2B连接(Back to Back Connection)是将一设备的输出直接将连接到另一个类似设备的输入的连接方式。


A back-to-back user agent operates between both end points of a communications session and divides the communication channel 
into two call legs, and mediates all SIP signaling between the endpoints of the session, from establishment to termination.
一个B2BUA将在一个通信的会话的两个端点间操作，将通信通道划分为两个呼叫分支，并在会话端点之间调节从建立到终止的所有SIP信令。

As all control messages for each call flow through the B2BUA, a service provider may implement value-added features available during the call.
由于每个呼叫的所有控制消息都流经B2BUA, 因此服务提供者可以在呼叫期间实现可用的增值功能。

In the originating call leg, the B2BUA acts as a user agent server (UAS) and processes the request as a user agent client (UAC) to the destination end, handling the signaling between end points back-to-back.
在发起呼叫阶段中， B2BUA可以充当代理服务器， 并作为用户代理客户端处理发送到目标端的请求， 处理端点之间B2B的信令。

A B2BUA maintains complete state for the calls it handles. Each side of a B2BUA operates as a standard SIP user agent network element as specified in RFC 3261

