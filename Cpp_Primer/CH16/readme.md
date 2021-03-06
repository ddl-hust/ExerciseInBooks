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

默认情况下，Ｃ++假定通过作用域运算符访问的名字不是类型，因此如果我们希望使用模板类型参数的类型成员，
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

#### 16.1.4成员模板(595)
作为例子，定义了一个类，类似`unique_ptr`所使用的默认删除器类型
```
class deleteptr
{
public:
    deletptr(ostream &s=std::cerr):os(s){} //默认构造函数，默认输出错误流参数
    template<typename T> void operator()(T*p) const
    {
        os<<"delete unique_ptr"<<endl;
        delete p;
    }
private:
    ostream &os;
}
```
回过头来看[unique_ptr](16.28_unique_ptr/unique_ptr.h)实现(P417)

某个时刻只有一个unique_ptr指向一个对象，当unique_ptr被销毁，所指向对象也被销毁。

由于一个unique_ptr拥有其所指对象，因此unqiue_ptr不支持普通拷贝，赋值操作

但可以通过release(),reset([q])，来转移指针的所有权

unique_ptr的一些操作:

`unique_ptr<T>u1` //空unique_ptr 默认使用delete来释放它的指针
`unique_ptr<T,D>p()` //使用类型为D的可调用对象来释放指针

有了这些铺垫之后，就可以看看，如何用我们写的成员模板作为`unique_ptr`的删除器
```
unique_ptr<int,deleteptr>p(new int,deleteptr());//申明p的删除器类型为deleteptr,并在构造函数中提供了该类型的一个未命名对象
```


-----------------------

#### 16.2 模板实参推断(template argument deduction)
> 编译器使用调用函数的实参来寻找模板实参；

将实参传递给带模板类型的函数形参，能够自动转化的类型只有`const`转化，以及数组或函数到指针的转换。

> 顶层`const`无论在形参还是实参，都会被忽略

这句话什么意思呢？(P57)
指针本身是一个对象，又可以指向一个对象，也就是指针本身是否为常量与所指对象是否常量相互独立。用**顶层 `const `(top level const)** 表示指针本身为常量。更为一般的，顶层const可以表示任意的对象为常量。
相对的`底层const`表示指针所指对象为常量。这两个的具体区别在执行拷贝操作时有很大区别：

    1. 顶层const不受影响，因为拷贝操作不会改变被拷贝对象值
   ```
   int i=0;
   const int ci=42;
   i=ci //正确，ci为顶层const，对拷贝操作没影响
   ```
   2. 底层const在执行对象拷贝时候，const限制不可忽略，拷入，拷出对象必须要有相同的底层const资格，或者两个对象能够进行数据转化,非常量可以转化为常量，反之不行
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
10/29　星期二

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
首先s1为左值实参，经过引用折叠，模板类型参数Ｔ被推断为`string&`,
因此返回类型就为`T&&`(remove_reference去掉了&)
再看里面实现，就是用`static_cast`做了静态类型转化。
一般来说,`static_cast`只能用于其他合法的类型转换，但针对右值引用有一条**特例**: 显式的将一个左值转化为右值引用。就像std::move里面做的,在<>里面显式给出。

>`static_cast`：只要不包含底层const，任何具有明确定义的类型转换都可以用static_cast。
这句话什么意思？如果包含了底层const会报什么错？底层const 表示指针所指对象为const
我写了个测试：
```
const int ci=i; //顶层常量
const int *  pi=&ci; //底层常量
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
这句话是在干什么呢？表示在dest指向的内存空间，用elem指向的元素构造对象，之所以使用move()，为了将左值转化为右值引用，从而调用移动构造函数，不使用拷贝构造函数，减小内存开销。

--------------------------------
2019年10月30日 星期三

#### [share_ptr](16.28_share_ptr/main.cpp)
自己完全实现一个，理解RAII(获得资源即初始化)这个概念
有一些点需要注意
1.`share_ptr`需要管理引用计数,因此在拷贝构造，拷贝赋值的时候，需要将引用计数加一，

2.在析构时候也需要注意

#### 可变模板参数
申明：用省略号(...)表示可变参数
```
template <typename T, typename... Args>
void foo(const T &t, const Args& ... rest);
foo("hi"); // empty pack
//上面的foo()会实例化成下面版本
void foo(const char[3]&); 
```
使用`sizeof...(args)`可以得到可变参数个数,返回一个常量表达式。
> 常量表达式：is an expression whose value cannot change and that can be
evaluated at compile time.

常量表达式在编译是就已经确定，
```
int staff_size = 27; // staff_size is not a constant expression
const int sz = get_size(); // sz is not a constant expression
```
写了练习，一定要注意const，当实参为右值时候,const int & 能够绑定


------
2019年10月31日  星期四

将之前动态内存管理类[vec](16.16/vec.h)重写为模板，

#### 转发参数包
通过组合使用可变参数模板与forward机制来编写函数，实现将实参不变地传递给其他函数，
并添加emplace_back()P

#### 模板特例化
为什么要特例化
特例化形式：
`template<>`<>表示我们将为原来模板的所有参数提供实参

类模板的偏特化
>对于类模板的特例化，我们可以只指定部分实参，而不必要像函数模板的特例化一样，指定全部实参
类模板的部分特例化，本身就是一个模板。也可以特例化参数的一部分特性(&,&&)

定义自己版本的无序容器，hash<Sale_data>,关键字key
[sale_data](16.62/sale_data.h) 是之前类章节里面的，首先需要定义自己的sale_data类

做练习16.62时候出现的错误：
`error C3848: 具有类型“const std::hash<Sales_data>”的表达式会丢失一些 const-volatile 限定符以调用“size_t std::hash<Sales_data>::operator ()(const Sales_data &)”`

` size_t operator()(const Sales_data &s) const;`
我忘了加 const 导致传入的实参 const属性丢失.



