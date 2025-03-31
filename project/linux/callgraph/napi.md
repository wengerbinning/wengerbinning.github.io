
napi_kthread_create(napi_threaded_poll) -> kthread_run

napi_poll -> __napi_poll

netpoll_start_xmit -> netdev_start_xmit
netpoll_send_skb_on_dev -> netpoll_start_xmit
queue_process -> netpoll_start_xmit
netpoll_send_skb -> netpoll_send_skb_on_dev
__napi_schedule -> ____napi_schedule -> wake_up_process

napi_complete -> napi_complete_done -> __napi_schedule
