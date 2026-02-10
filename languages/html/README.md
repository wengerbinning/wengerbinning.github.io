HTML(HyperText Markup Langauge, 超文本标记语言)是一种用于创建网页的标准标记语言。

#### 元素

HTML文档中使用不同的标签来标记不同元素。元素由标签与内容构成。

```html
<opening tag> content <closing tag>
```

* 开始标签
* 元素内容
* 结束标签

* 空元素是内容为空的元素

* 内联元素
* 块级元素

#### 标签

* 标签对大小写不敏感，推荐使用小写。

#### 属性

* 属性对大小写不敏感，推荐使用小写。
* 属性是元素中用于添加附加信息的机制。
* 属性一般在开始标签中， 并以键值对形式出现。

所有元素通用的属性：

* `id` - 定义元素全局唯一的ID；
* `class` - 为元素定一个一个或多个类别；

* `style` - 定义元素的行内样式；也称内联样式

```html
<p style="color: blue; margin-left:20px;">text</p>
```

* `title` - 描述元素的额外信息；

#### 注释

```html
<!-- coment -->
```

---

* 固定格式

```html
<!DOCTYPE html>
<html>
<!-- document head -->
<head>
    <!-- todo -->
</head>
<!-- document body -->
<body>
    <!-- todo -->
</body>
</html>
```

## 文档内容

* `<!DOCTYPE html>` - 声明为HTML5文档。
* `<html></html>` - HTML的根元素。

html元素标记HTML文档，所有元素均在该标签内。

### 元素内容

#### head

HTML文档头部元素， 说明文档一些元属性，标题等。

#### body

HTML文档的内容元素。



---

#### 表格


* table
* thead
* tbody
* tfoot
* th
* tr
* td
* caption
* colgroup
* col



加粗 - table、th、td

* border
* border-collapse
* border-radius
* border-style
* border-color
