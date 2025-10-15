

* Properties
* Methods


### 定义一个对象

```js
let person = { name = "guest", age = 16 };
```

```js
let person = {};

person.name = "test";
person.age = 16;
```

```js
let person = new Object;

person.name = "test";
person.age = 16;
```

```js
const person = {
    fullName: function() {
        return this.firstName + " " + this.lastName;
    }
}
```

```js
person.run = function () {
    return this.firstName + " " + this.lastName;
}
```

### 对象的数据访问


```js
let age = person.age;
```

```js
let age = person["age"];
```


```js
delete person.age;
```

```js
delete person["age"];
```


```js
let val = person.fullName();
```
