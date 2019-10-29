#### 类型成员(P243)
1. 定义：某种类型在类中的别名

eg. `typedef std::string::size_type pos`
 
也可以等价使用
`using pos=std::string::size_type`
2. 类型成员必须先定义后使用；(why)

3. 使用类的类型成员
通过作用域运算符(::)来访问，对于非模板代码，编译器掌握了类的定义，能够知道通过作用域运算符访问的名字是类型还是静态成员，
但对于模板代码就不行，必须在实例化阶段才能知道，
为了处理模板，编译器必须知道名字是否表示一个类型，比如Ｔ是一个模板参数，请看下面语句：
`T::size_type * p`
这个语句就有歧义，编译器不知道我们是定义一个　名为ｐ的指针变量，还是将静态数据成员与p相乘。

默认情况下，Ｃ++嘉定通过作用域运算符访问的名字不是类型，因此如果我们希望使用模板类型参数的类型成员，
必须显式指出。通过关键字`typename` 来实现：
```
template<typename T>
typename T::value_type top(const T&c) //显式指出返回值为类型
{
    pass
}
```

#### 默认模板实参(default template argument)
在Ｃ++11 可以为函数，类模板提供默认实参

与函数默认实参一样，对于模板参数，只有当他右侧的所有参数都有默认实参时候，他才可以有默认实参。


-----------------------

#### 16.2 模板实参推断(template argument deduction)
> 编译器使用调用函数的实参来寻找模板实参；

将实参传递给带模板类型的函数形参，能够自动转化的类型只有`const`转化，以及数组或函数到指针的转换。

> 顶层`const`无论在形参还是实参，都会被忽略

这句话什么意思呢？(P57)
指针本身是一个对象，又可以指向一个对象，也就是指针本身是否为常量与所指对象是否常量相互独立。用*顶层`const`(top level const)*表示指针本身为常量。更为一般的，顶层const可以表示任意的对象为常量。
相对的`底层const`表示指针所指对象为常量。这两个的具体区别在执行拷贝操作时有很大区别：

    1. 顶层const不受影响，因为拷贝操作不会改变被拷贝对象值
   ```
   int i=0;
   const int ci=42;
   i=ci //正确，ci为顶层const，对拷贝操作没影响
   ```
   2. 底层const在执行对象拷贝时候，const限制不可忽略，拷贝入，拷贝出对象必须要有相同的底层const资格，或者两个对象能够进行数据转化,非常量可以转化为常量，反之不行
   ```
    int i=0;
    int* const p1=&i; // top level
    const int ci=42; //top level
    const int *p2 = &ci; //low level
    const int * const p3=p2; //top and low
    const int &r= ci; //引用的const　都是const
    ------------
    int* p=p3; //错误，p3有low level属性，p没有
    p2=p2 　//正确
    p2=&i; //正确，非常量转换为常量
    int& r=ci; //错误，常量不能转化为非常量

   ```


函数参数类型不是模板参数，实参能过进行正常的类型转换(算术转化，派生类->基类，自定义转换等都可以)

--------
１０/29　星期二

#### 函数指针与实参推断

函数指针指向函数，非对象，申明一个指向函数的指针，只需要用指针替换函数名：

`bool compare(cosnt string& s1,const string&s2);//函数`
`bool (*pf)(const string&s1,const string&s2);//函数指针`

**NOTE**:
函数指针名两边的()不可少，去掉则表示函数返回为`bool`指针的函数


#### 理解std::move
标准库里面`move`的定义还是很subtle
```
template<typename T>
typename remove_reference<T>::type &&move(T&& t)
{
    return static_cast<typename remove_reference<T>::type&&>(t);
}
```
来分析下如果传入一个左值，如何通过move得到右值

`string s1("ddl"),s2`;

`s2=std::move(s1)`
首先s1为左值实参，模板类型参数Ｔ被推断为`string&`,
因此返回类型就为`T&&`(remove_reference去掉了&)
再看里面实现，就是用`static_cast`做了静态类型转化。
一般来说,`static_cast`只能用于其他合法的类型转换，但针对右值引用有一条**特例**: 显式的将一个左值转化为右值引用。就像std::move里面做的,在<>里面显式给出。

>`static_cast`：只要不包含底层const，任何具有明确定义的类型转换都可以用static_cast。
这句话什么意思？如果包含了底层const会报什么错？底层const 表示指针所指对象为const
我写了个测试：
```
const int ci=i;
const int *  pi=&ci;
auto res= static_cast<int*>(pi);
```
 `error: invalid static_cast from type ‘const int*’ to type ‘int*’`

顶层常量做`static_cast`没有影响
```
const double d=2.0;
auto res= static_cast<double>(d);
```
#### 动态内存管理类(P464)
在本节课后练习里面解释下面循环语句的作用：
```
for(size_t i=0;i!=size();++i)
    alloc.construct(dest++,std::move(*elem++));
```
这句话是在干什么呢？表示在dest指向的内存空间，用elem指向的元素构造对象，之所以使用move()，为了将左值转化为右值引用，从而调用移动构造函数，减小内存开销。

