#### 服务文件

* /usr/bin/in.tftpd
* /usr/bin/tftp
* /usr/lib/systemd/system/tftpd.service
* /usr/lib/systemd/system/tftpd.socket
* /srv/tftp/

#### 服务配置

* /etc/conf.d/tftpd

```/etc/conf.d/tftpd
TFTPD_ARGS="--user guest --create --secure /srv/tftp/
```

#### 说明文档

* /usr/share/licenses/LICENSE

* /usr/share/man/man1/tftp.1.gz
* /usr/share/man/man8/in.tftpd.8.gz

