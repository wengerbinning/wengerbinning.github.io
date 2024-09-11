





## location

```conf
location [modifier] <match> {
	# content
}
```



### modifier

修饰符

#### none

如果修饰符不存在，则匹配规则满足URI的前缀即可。


#### =

如果存在`=`修饰符， 则匹配规则需要与URI完全一致。

#### ~

如果存在`~`修饰符， 则匹配规则为区分大小写的正则字符串并进行正则匹配。

#### ~*

如果存在`~*`修饰符，则匹配规则为不区分大小写的正则字符串并进行正则匹配

#### ^~

如果存在`^~`修饰符，则该匹配规则作为最佳的规则，并且不会进行正则匹配。

### match

#### /

#### /path

#### /path/

#### regex



## Nginx location Choose

#### exact match location

#### longest matching prefix location

#### regular expression locations


## LINKS



* <https://nginx.org/en/docs/http/ngx_http_core_module.html#location>