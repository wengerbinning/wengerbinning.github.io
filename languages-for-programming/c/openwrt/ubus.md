为了在OpenWrt中提供守护进程和应用程序间的通讯，开发了ubus项目工程。它包含了守护进程、库以及一些额外的帮助程序。

ubus有对象与方法。

使用场景：

```c
// subscriber & notifier

// notifier 是发送消息的一方。
ubus_add_object()
ubus_notify()

// subscriber 是订阅消息的一方。
ubus_register_subscriber()
ubus_lookup_id()
ubus_subscribe()
```

```c
// invoke 远程调用
ubus_invoke()
```

```c
// event方式广播通知

// 监听者：

ubus_register_event_handler()
```


