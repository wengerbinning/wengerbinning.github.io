




* pptpd 








The remote system is required to authenticate itself but I couldn't find any suitable secret (password) for it to use to do so.



#### 服务配置

* `/etc/pptpd.conf`

```
localip 192.168.10.1
remoteip 192.168.10.200-254
```


* `/etc/ppp/options.pptpd`


```
ms-dns 8.8.8.8
ms-dns 8.8.4.4
```



* `/etc/ppp/chap-secrets`

```
user1 pptpd user1-password *
user2 pptpd user2-password *
```




####

## LINKS

* <https://wiki.archlinux.org/title/PPTP_server>