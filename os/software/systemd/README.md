systemd






mount
path
service





### service


Unit

* Description
* After
* Wants

Service

* Type
* PIDFile
* ExecStartPre
* ExexStart
* ExecReload
* killSignal
* TimeoutStopSec
* KillMode
* PrivateTmp

* Type - 枚举类型， {simple,exec,forking,oneshot,dbus,notify,notify-reload,idle}；指定服务类型；
* RemainAfterExit - 布尔类型(yes, no)， 默认为no；在设置该值后， 当服务进程退出后，服务状态保持；
* WorkingDirectory - 字符串；设置服务运行时的工作目录；




#### Type

simple - 如果ExecStart设置但是Type与BusName未设置的默认值；在进程被fork完成即完成服务启动；
exec - 类似于simple， 在进程执行完成后认为服务完成；
oneshot - 类似于simple，在进程 , 一般与 RemainAfterExit 配合使用；


forking,exec,dbus,notify,idle,oneshot


Install






* example

```txt
[Unit]
Description=The nginx HTTP and reverse proxy server
After=network-online.target remote-fs.target nss-lookup.target
Wants=network-online.target

[Service]
Type=forking
PIDFile=/run/nginx.pid
# Nginx will fail to start if /run/nginx.pid already exists but has the wrong
# SELinux context. This might happen when running `nginx -t` from the cmdline.
# https://bugzilla.redhat.com/show_bug.cgi?id=1268621
ExecStartPre=/usr/bin/rm -f /run/nginx.pid
ExecStartPre=/usr/sbin/nginx -t
ExecStart=/usr/sbin/nginx
ExecReload=/usr/sbin/nginx -s reload
KillSignal=SIGQUIT
TimeoutStopSec=5
KillMode=mixed
PrivateTmp=true

[Install]
WantedBy=multi-user.target
```




#### 服务模板

systemd通过格式`service-name@argument.service`来支持携带参数的服务， 该过程成为服务
的实例化；通常通过格式`service-name@.service`来实现一个服务模板， 例如`dhcpcd@.service`
服务模板可以通过参数为每一个接口来实例化参数。







## 相关链接

* <https://www.freedesktop.org/software/systemd/man/systemd.service.html>
* <https://www.freedesktop.org/software/systemd/man/systemd.unit.html#>
