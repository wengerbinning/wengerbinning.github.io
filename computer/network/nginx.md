nginx

* 文件共享

  ```nginx.conf
  autoindex on;
  ```

* 服务代理


        * 用户验证：nginx中提供了ngx_http_auth_basic_module模块来实现用户验证，默认支持该模块，仅需要在配置中
        配置即可.

        ```nginx.conf
        # 该项是控制是否开启验证的开关，默认为off，若为其他字符，则表示开启验证并提示。
        auth_basic "Please input password"; 
        # 该项是指定验证文件的路径。
        auth_basic_user_file /etc/nginx/htpasswd;
        ```
  
  配置文件可以使用htpasswd或者openssl来生成。

nginx是一个web服务器。



通过nginx可以实现web服务器、代理服务器、邮件服务器，支持fastcgi，ssl，virtual host, url rewirte， gzip等功能。


主要配置文件有；

* `/etc/nginx/nginx.conf`

    该配置文件是nginx的基础配置文件。
    
* `/etc/nginx/modules-available`
* `/etc/nginx/modules-enabled`

    这两份目录分别保存了nginx可用的模块与已启用的模块。
    
*`/etc/nginx/mime.types`
* `/etc/nginx/conf.d`
* `/etc/nginx/sites-available`
* `/etc/nginx/sites-enabled`

    这四份配置文件与目录分别保存了http服务的基本配置、可用http与已启用的http配置。
    
    
    * 反向代理中注意路径。

```


```
    
    
## http服务

## 代理服务

nginx作为代理服务器
