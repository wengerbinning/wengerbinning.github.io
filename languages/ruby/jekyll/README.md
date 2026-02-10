jekyll是由ruby开发的一个工具。



jekyll是基于ruby实现的一个静态网站的工具



jekyll核心是一个文本转换引擎



`_config.yml`用于管理全局配置和变量
`_includes/`
`_layouts/`
`_posts/`
`_data/`
`_site/`
`_drafts/`
`jekyll-metadata`
`assets/`





```shell
# ubuntu
apt install jekyll
```



```shell
# 默认构建
jekyll build
# 
jekyll build --destination <destination>
#
jekyll build --source <source> --destination <destionation>
# 
jekyll build --watch
```



```shell
#
jekyll serve
#
jekyll serve --detach
#
jekyll serve --no-watch
```




```yml
#
source: src
#
destination: dest

```


JEKYLL_ENV默认为development