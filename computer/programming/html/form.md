表单(form)用于收集用户的输入信息。

```html
<form action="" mathod="">
    <label> label </label>

    <!--  -->
    <input type="text"/>
    
    <!--  -->
    <input type="password"/>
    
    <!--  -->
    <input type="radio" name="single-choice" value="A"/>
    <label>A</label>
    <input type="radio" name="single-choice" value="B"/>
    <label>B</label>
    
    <!--  -->
    <input type="checkbox" name="multi-choice" value="A"/> 
    <label>A</label>
    <input type="checkbox" name="multi-choice" value="B"/> 
    <label>B</label>
    <input type="checkbox" name="multi-choice" value="C"/> 
    <label>C</label>

    <!--  -->
    <select>
        <option value="1">first</option>
        <option value="2">second</option>
    </select>
    
    <!--  -->
    <textarea rows="10" cols="30">
        <!-- content -->
    </textarea>

    <!--  -->
     <input type="submit" value="submit"/>
</form>
```


## 元素列表

### form

#### 属性

* `action` - 定义来表单提交的URI, 服务器根据该字段来处理数据
* `method` - 指定表单数据提交的方式，取值范围如下：

  1. `get` - 默认值，指定为HTTP GET方法， 
  2. `post` - 指定为HTTP POST方法

* `enctype`

  1. `text/plain`

### label

```html
<label>lable</label>
```

#### 属性

* for

### input

```html
<input type="radio"/>
```

#### 属性

* `type`

  1. `text` - 文本输入 
  2. `password` - 密码输入
  3. `radio` - 单选按钮
  4. `checkbox` - 复选框
  5. `button` - 普通按钮
  6. `submit` - 提交按钮 
  7. `reset` - 重置按钮

* `value`

### select

### option

option标签标记下拉列表中的选项

```html
<select>
    <option value="1">First</option>
    <option value="2">Second</option>
    <option value="3">Third</option>
</select>
```

#### 属性

option支持所有的HTML全局属性， 其特有的属性如下：

* `value` - 定义该选项的值；如果选中，改值将被传送至服务器；
* `disabled` - 在首次加载时被禁用；
* `selected` - 在首次加载时被选中；
* `label` - 定义当使用optgroup时所使用的标注；

### optgroup

optgroup标签标记一组选项。

```html
<select>
    <optgroup label="class a">
        <option value="1">First</option>
        <option value="2">Second</option>
        <option value="3">Third</option>
    </optgroup>

    <optgroup label="class b">
        <option value="a">First A</option>
        <option value="b">Second B</option>
        <option value="v">Third C</option>
    </optgroup>

</select>
```

#### 属性

optgroup支持所有的HTML全局属性， 其特有的属性如下：

* `label` - 指定选项组的名称。
* `disabled` - 禁用该组选项。

### textarea

#### 属性

* rows
* cols

### button

button标签标记一个点击按钮。

```html
<button type="button" onlick="" > Button </button>
```

#### 属性

* `name` - 指定按钮的名称。
* `type` - 指定按钮类型。

  1. `button`
  2. `reset`
  3. `submit`

* `value` - 初始值。
* `disabled` - 禁用该标签。

### datalist

datalist标签标记一个预先定义的输入控件选项列表。

### keygen

keygen标签标记一个表单的密钥生成器字段

### output

output标签标记一个计算结果

---

### fieldset

fieldset标签标记一组表单元素， 

### legend

legend标签标记fieldset的标题
