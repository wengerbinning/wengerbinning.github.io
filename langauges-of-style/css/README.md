层叠样式表(CSS, Cascading Style Sheets)是一种文本样式语言。用于描述如何显示HTML文本。


选择器
-----


* 元素名称选择器： 根据html的标签名称来选择

```css
p {
    text-align: center;
    color: red;
}
```

* 元素ID选择器： 根据html的标签的id属性来选择。

```css
#username {
    text-align: center;
    color: red;
}
```

* 元素CLASS选择器： 根据html的标签的class属性来选择。

```css
.txt {
    text-align: center;
    color: red;
}
```

* 通用选择器： 选择html中所有标签

```css
* {
    text-align: center;
    color: red;
}
```

* 分组选择器： 选择一组html标签。

```css
h1, h2, h3 {
    text-algin: center;
    color: red;
}
```


* 后代选择器： 选择某一标签下的标签

```css
div p {

}
```


* 子类选择器： 选择


```css
div > p {
    ground-color: yellow;
}
```


* 

```css
div + p {

}
```


```css
div ~ p {

}
```

* 伪类用于定义元素的特殊状态。


```css
/* 未访问的连接 */
a:link {

}
```

```css
/* 已访问的连接 */
a:visted {

}
```

```css
/* 鼠标悬停， 须在 link与visted之后才有效 */
a:hover {

}
```

```css
/* 已选择的链接， 须在hover之后才有效 */
a:active {

}
```

```css
/* p作为第一个子元素时 */
p:first-child {

}
```


* 属性选择器: 选择带有该属性的元素。

```css
p[target] {

}
```











## LINKS

* [WikiPedia](https://en.wikipedia.org/wiki/Style_sheet_language)
  👉 <https://en.wikipedia.org/wiki/Style_sheet_language>

* [W3School](https://www.w3school.com.cn/css/index.asp)
  👉 <https://www.w3school.com.cn/css/index.asp>