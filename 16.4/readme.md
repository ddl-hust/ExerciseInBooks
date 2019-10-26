### CH16 模板与泛型
 模板编译：
 
对于一般的函数以及类类型对象，编译器只需要申明，类的成员函数的定义不需要出现，因此我们将类的定义和函数申明放在头文件里面
，普通函数和类的成员函数放在源文件里面，模板则不同，为了实例化一个模板，编译器需要掌握函数模板的定义，
因此，模板的头文件既包含申明也包括定义。

#### 练习
```
template <typename T,typename U>
T find(T& begin,T&end,const U& val);
```
为啥 出现
`auto result=find(test1.begin(),test1.end(),1);`

**编译器版本**　将Ｃ++11 ->C＋＋！１４

这个错误很更要
 `error: cannot bind non-const lvalue reference of type ‘int&’ to an rvalue of type ‘int’
     auto result=find(test1.begin(),test1.end(),1);`
