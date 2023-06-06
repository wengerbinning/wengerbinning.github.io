HTTP keep-alive 即HTTP的长链接。是客户端与服务端的一个约定， 在开启时， 服务端返回
response后不会关闭TCP， 同理， 客户端在收到 response 后 不会关闭TCP， 发送下一个HTTP请求
时复用该TCP


HTTP1.0中默认关闭keep-alive, 需要在头部加入 Connection: Keep-Alive 来启用keep-alive
HTTP1.1中默认启用keep-alive, 需要在头部加入 Connection: close 来关闭 keep-alive



客户端控制是否使用keep-alive
服务端控制keep-alive时间






server


keepalive_timeout <seconds>
keepalive_requests 


