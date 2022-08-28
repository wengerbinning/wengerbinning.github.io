


struct dst_entry;





ip_local_delive

receive
--------

```c
ip_rcv
```


```c
/* Note:
 * 该函数执行了netfilter的LOCAL_IN处的钩子，并执行了ip_local_deliver_finish
 */
ip_local_deliver
```

```c
ip_local_deliver_finish
```


Send 
----

```c
/* Note:
 *  该函数执行netfilter的POSTROUTING处的钩子，通过调用
 *  ip_finish_output
 */
ip_output
```

```c
// 该函数
//
ip_finish_output
```








route
--------

```c
// 调用netfilterde NF_INET_FORWARD .
ip_forward
```

```c
__mkroute_input
ip_mkroute_input
ip_route_input_slow
ip_route_input_noref
```