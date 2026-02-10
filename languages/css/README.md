


## 元素选择器

简单的选择器

* 标签选择器

```css
h1 {
    color: white;
}
```

* 类型选择器

```css
.account {
    color: black;
}
```

* ID选择器

```css
#paaword {
    color: yellow;
}
```

组合选择器


* 后代选择器

```css
/* div标签下所有的p标签 */
div p {
    color: white;
}
```

* 

```css
div -> p {
    color: white;
}
```

* 

```css
div + p {
  background-color: yellow;
}
```

* 

```css
div ~ p {
  background-color: yellow;
}
```

伪类线选择器

* 

```css
a:link {
    color: white;
}
```

伪标签选择器

* 

```css
p::first-line {
  color: #ff0000;
  font-variant: small-caps;
}
```

属性选择器

```css
a[target="_blank"] {
  background-color: yellow;
}
```







## 应用

* 

```html
<!DOCTYPE html>
<html>
<head>
<link rel="stylesheet" href="mystyle.css">
</head>
<body>

<h1>This is a heading</h1>
<p>This is a paragraph.</p>

</body>
</html>
```

* 

```html
<!DOCTYPE html>
<html>
<head>
<style>
body {
  background-color: linen;
}

h1 {
  color: maroon;
  margin-left: 40px;
}
</style>
</head>
<body>

<h1>This is a heading</h1>
<p>This is a paragraph.</p>

</body>
</html>
```

* 

```html
<!DOCTYPE html>
<html>
<body>

<h1 style="color:blue;text-align:center;">This is a heading</h1>
<p style="color:red;">This is a paragraph.</p>

</body>
</html>
```