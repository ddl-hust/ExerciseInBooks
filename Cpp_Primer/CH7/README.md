## 类

### 定义抽象数据类型

#### this 
当我们调用类的成员函数的时候，我们怎么知道是哪个对象在调用呢？
实际上，成员函数通过一个名为`this`隐式的参数来访问调用它的对象，用对象的地址来初始化`this`。
比如
```
Sales_data total;
total.isbn(); //等价于 Sales_data::isbn(&total);
``` 
在成员函数内部，我们可以直接使用调用该函数的对象成员，下面的语句效果是一样的
```
string isbn() {return BookNo;} // {return this->BookNo;}
```
因为`this`总是指向这个对象，this 是个const 指针，我们不能改变this中保存的地址

#### const 成员函数
const限定符 目的: to modify the type of the implicit this pointer

默认下，`this`总是指向非常量类型的常量指针，假如有个常量对象，根据类型转化的规则，非常量指针
不能绑定到常量对象，那我们要怎么做呢？`this`是隐式的，我们不能直接在前面加`const`限定符，为了解决这个问题
我们在 成员函数参数列表后面加`const`来表示`this` is a pointer to const.

* 因为this是指向常量的指针,所以常成员函数不能修改调用它的对象的值。
* 常量成员函数的的申明与定义(如果在内外部定义)都要在参数列表后面加上`const`,作为比较，内联函数只需要在声明**或者**定义后面加上`inline`

#### 构造函数
目的：初始化类的数据成员
* 构造函数没有返回类型，名字与类名相同
* 不同于其他成员函数，构造函数不能声明为`const`,因为在我们创建一个const对象时候，其常属性只有在构造函数初始化之后才具有，因此即使我们在创建一个const 对象，构造函数不是const member function 也可以向其写值。

##### 默认构造函数
如果我们的类没有显式的定义一个构造函数，编译器将为我们隐式默认定义一个。默认构造函数初始化类数据成员的规则:
- 类内初始值
- 默认初始化

* 如果我们定义了其他的构造函数，除非我们自己定义一个默认构造函数，否则类将没有默认构造函数，我们可以使用`=default`
eg. `Sale_data()=default;`这样做的目的是，我们需要其他形式的构造函数，也需要默认构造函数，我们希望这个构造函数的行为与编译器合成的一样。


做课后习题的时候有一个疑问？
```
Screen& display(std::ostream& os)
    {
        do_display(os);
        return *this;
    }

    const Screen& display(std::ostream& os) const
    {
        do_display(os);
        return *this;
    }

    void do_display(std::ostream& os) const {os<<contents;}
```
do_display is const member function,因此在no-const display 调用do_display时候，
`this`指针会隐式转化为`const this`,this指针里面的地址存的都是同一个对象的地址，不同的是，非常量版本的display里面的this 是指向no-const的，而do_display里面的this 指向const。这并不矛盾。

#### 友元再谈
可以把一个类声明为另外一个类的友元，这样友元类的成员函数就能访问该类包括非公有成员的所有成员。
友元关系不存在传递性，每个类负责自己的友元类或者友元函数。

也可以只将类的某个成员函数声明为友元函数，这样就有些顺序问题。

#### 名字查找的规则
一般来说，名字查找十分直接，
-  First, look for a declaration of the name in the block in which the name was
used. Only names declared before the  are considered.
-  If the name isn’t found, look in the enclosing scope(s).
-  If no declaration is found, then the program is in error.

但是对于类的成员函数来说：
- First, the member declarations are compiled.
- Function bodies are compiled
也就是说在编译器处理了所有的声明之后，成员函数体的定义才会处理，因此即使我们的成员函数在函数体内用到了一些数据成员，数据成员的声明
在后面，这样是没问题的。
**注意**:这样一个两阶段的处理过程仅仅适用于类成员函数体。声明里面的类型，函数返回的类型，函数的参数列表里面的类型，必须在使用他们之前可见。如果在类里面没有查找到，就会继续向类定义的作用域查找。

成员函数名字一般的查找规则：
1. 函数自身作用域
2. 类作用域
3. 外围作用域，类定义之上，当成员函数定义在类外面时，除了考虑类定义之前的全局作用域，还要考虑成员函数定义之前的全局作用域

#### 默认构造函数的作用(什么时候需要默认构造函数)
万物皆对象，当一个对象默认初始化或者值初始化，默认构造函数此时自动调用

##### 默认初始化
- 在块作用域(比如函数内部)，定义非静态变量，或者数组时候，我们没有提供初始值 eg.
```
void foo(){
    int i; //默认初始化
    int arr[10]; //默认初始化
}
```
- 类的成员使用合成默认构造函数
- 类的成员没有在初始值列表里面显式初始化

##### 值初始化
- 数组初始化提供的默认值少于数组元素个数
- 局部静态变量没有初始值
- 类似 vector<int> vec(10);  指定了元素个数，来进行值初始化


#### 类的隐式转换
对于接受一个参数的构造函数，存在参数类型->类类型转化
这种转化只允许进行一步，比如对于之前啊的Sale_data
```
// error: requires two user-defined conversions:
// (1) convert "9-999-99999-9" to string
// (2) convert that (temporary) string to Sales_data
item.combine("9-999-99999-9");
```
由于存在这种由参数类型到类的转化，可能带来一些意想不到的情况，我们可以在构造函数前加上`explicit`，禁止这种隐式转换。
关于`explicit`使用的几点注意：
-  only on constructors that can be called with
a single argument. 
- is used only on the constructor declaration inside
the class.
- explicit Constructors Can Be Used Only for Direct Initialization

做课后习题遇到了一个有意思问题
parameter is a non-const reference , we can't pass a temporary to that parameter.
[参考](https://stackoverflow.com/questions/1565600/how-come-a-non-const-reference-cannot-bind-to-a-temporary-object/1565811#1565811)