body元素中的内容是可以显示在页面上。



## 元素列表

在body元素的内容可以使用以下元素

### Heading

h1-h6标签标记一级到六级标题。

```html
<h1>level 1 title</h1>
<h2>level 2 title</h2>
<h3>level 3 title</h3>
<h4>level 4 title</h4>
<h5>level 5 title</h5>
<h6>level 6 title</h6>
```

### pragpraph

p标签标记一段文本。

```html
<p>pragraph</p>
```
格式化标签

* b
* em
* i
* small
* strong
* sub
* ins
* del

计算机输出标签

* code
* kbd
* samp
* var
* pre

引用

* abbr
* address
* bdo
* blockquote
* q
* cite
* dfn

### hr

hr

### br

br标签标记一个换行， 是一个空元素。

```html
<br/>
```

### link

a标签用于标记一个链接

```html
<a herf="http://example.com">link</a>
```

#### 属性

* href
* target
* rel
* download

### img

img标签标识一个图像，是一个空元素。

```html
<img src="image.png" width="400" height="300"/>
```

#### 元素属性

* `src` - 指定图像资源的位置，可以是url,也可以是本机路径。
* `alt` - 图像定义一串预备的可替换的文本
* `width`
* `height` 

### map

### area

### table

table标签来标记表格

```html
<table>
    <thead>
        <tr>
            <th>ID</th>
            <th>NAME</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td>1</td>
            <td>first</td>
        </tr>
        <tr>
            <td>2</td>
            <td>second</td>
        </tr>
    </tbody>
</table>
```


### list

HTML支持无序、有序与自定义列表

* 无序列表

```html
<ul>
    <li>list 1</li>
    <li>list 2</li>
</ul>
```

* 有序列表

```html
<ol>
    <li></li>
    <li></li>
</ol>
```

* 自定义列表

```html
<dl>
    <dt>
        <dd></dd>
    </dt>
    <dt>
        <dd></dd>
    </dt>
</dl>
```

### block

### form

表单

```html
<form name="" action="" method="">
    
    <input type="submit" value="">
</form>
```



###
iframe标签