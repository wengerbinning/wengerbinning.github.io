NAPI(New API)是在2.5/2.6引入的一种用于改善网络数据包接收机制， 主要为解决大流量下的性能问题。

传统接收机制: 数据到达网卡时触发硬件中断, CPU立即响应处理.
* 小流量时,中断及时, 延迟低
* 大流量时,每个包都产生中断, 存在中断风暴问题.

NAPI接收机制： NAPI 引入轮询与中断的混合模型.
* 小流量时, 网卡触发中断处理.
* 大流量时, 中断触发后, 驱动暂时屏蔽中断, 进入轮询模式, 知道队列处理完成或达到上限, 重新打开中断.



struct napi_struct {

}



netif_napi_add()


napi_schedule()
napi_complete_done()

中断 -> napi_schedule -> NET_RX_SOFTIRQ -> poll -> 阈值重新打开中断





void napi_schedule(struct napi_struct *n); - 触发轮询处理


napi_schedule(n)
* 安全检查(检查是否可以被调度)
* 保存中断信息并关闭当前CPU中断.
* 检查是否需要需要调度线程, 不需要则中调度软中断 - NET_RX_SOFTIRQ.
* 调度线程
* 打开当前CPU中断并恢复中断信息.



gro_result_t napi_gro_receive (struct napi_struct *napi, struct sk_buff *skb)




## MAPI


