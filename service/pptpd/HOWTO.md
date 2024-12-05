
## 服务安装

### archlinux

* `pptpd`

#### 服务配置

* `chap-secrets` -> `/etc/ppp/chap-secrets`
* `options.pptpd` -> `/etc/ppp/options.pptpd`
* `pptpd.conf` -> `/etc/pptpd.conf`

#### 服务管理

```shell
# 查看服务
sudo systemctl status pptpd
# 启动服务
sudo systemctl start pptpd
# 停止服务
sudo systemctl stop pptpd
# 重启服务
sudo systemctl restart pptpd
# 服务自启
sudo systemctl enable pptpd
```

#### 服务维护

```shell
# 系统日志
sudo journalctl -fu pptpd
```