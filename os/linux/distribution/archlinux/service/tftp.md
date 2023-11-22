
* 安装软件包

```shell
sudo pacman -S tftp-hpa
```

* 修改配置文件， tftp根目录为 /var/tftp

```/etc/conf.d/tftd
TFTPD_ARGS="--user nobody --secure --create /var/tftp"
```

* 重启服务

```
sudo systemctl restart tftpd.service
```