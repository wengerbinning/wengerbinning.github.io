
CGit + fcgiwrap


```conf


worker_processes          1;

events {
  worker_connections      1024;
}


http {
	include                 mime.types;
	default_type            application/octet-stream;
	sendfile                on;
	keepalive_timeout       65;
	gzip                    on;

	# Cgit
	server {
		listen                80;
		server_name           git.example.com;
		root                  /usr/share/webapps/cgit;
		try_files             $uri @cgit;

	# Configure HTTP transport
		location ~ /.+/(info/refs|git-upload-pack) {
			include       	fastcgi_params;
			fastcgi_param   SCRIPT_FILENAME     /usr/lib/git-core/git-http-backend;
			fastcgi_param   PATH_INFO           $uri;
			fastcgi_param   GIT_HTTP_EXPORT_ALL 1;
			fastcgi_param   GIT_PROJECT_ROOT    /vcs/git;
			fastcgi_param   HOME                /vcs/git;
			fastcgi_pass    unix:/run/fcgiwrap.sock;
		}

		location @cgit {
			include        fastcgi_params;
			fastcgi_param   SCRIPT_FILENAME /usr/lib/cgit/cgit.cgi;
			fastcgi_param   PATH_INFO       $uri;
			fastcgi_param   QUERY_STRING    $args;
			fastcgi_param   HTTP_HOST       $server_name;
			fastcgi_pass   unix:/run/fcgiwrap.sock;
		}
	}
}
```


#### cgit


* `/etc/cgitrc`

```
#
# cgit config
#

css=/cgit.css
logo=/cgit.png

# Following lines work with the above Apache config
#css=/cgit-css/cgit.css
#logo=/cgit-css/cgit.png

# Following lines work with the above Lighttpd config
#css=/cgit/cgit.css
#logo=/cgit/cgit.png

# Allow http transport git clone
enable-http-clone=1


# if you do not want that webcrawler (like google) index your site
robots=noindex, nofollow

# if cgit messes up links, use a virtual-root. For example, cgit.example.org/ has this value:
virtual-root=/


scan-path=/vcs/git
```