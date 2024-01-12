

















#### 服务配置

* `/etc/pptpd.conf`

```
localip 10.0.0.1
remoteip 10.0.0.100-200
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