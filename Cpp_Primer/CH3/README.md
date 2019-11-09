#### string读写

cin<<s 自动 遇到空白符结束，返回一个运算符左侧的运算对象，即流对象(cin),因此可以连续输入

getline(io&,string&) 从流对象读取，直到遇到换行符(因此叫getline),换行符被读取进来了，但没有存到string对象里面去，
也就是说如果一开始输入换行符，string将是一个空字符串。

#### 字面值与string对象相加
一个原则：两侧运算对象必须有一个为string
字符串字面值与string不是同一个类型
```
string s;
string s= "hello"+","+s; //error
```
string.size()返回类型为 string::size_type 是个无符号类型，因此切记不能用size()与一个负数作比较判断，
负数将转化为一个很大的unsigned， 因此不要把 size()与int混用
```
for( size_t i=0;i<size();i++)
```

#### 对字符串中的字符操作
1. 如何获取字符
2. 获取或者改变字符属性(大小写等)，包含在头文件<cctype>里面，这个头文件沿袭了C的头文件"ctype.h"
但有一点不同
>the names defined in the cname headers are defined inside the std namespace, whereas those defined in the
.h versions are not.

##### 获取字符
通过 range for(auto c：string),对序列的每一个字符进行访问，如果想改变字符内容或者属性，
for(auto &c:string)

如果我们只想访问字符串的部分，有两种办法，下标运算符，迭代器。

### vector
1. 如何定义以及初始化
    - 默认初始化 `vector<T>v1`
    - 拷贝  vector<T>v2=v1,v2(v1);
    - 初始列表 vetor<T>v3{a,b,c...},v3={};

这些初始化的方式多数时候能过互相使用，但是有几点需要注意
-  拷贝初始化，只能提供一个初始值
-  in-class 初始化，只能拷贝初始化或者列表初始化{}
- 列表初始化只能是{}, `()`error

- in-class initializer 指什么？

- 到底是构建对象还是列表初始化对象？
一般来说{}，为列表初始化，()用来构建对象，
但有时候初始化列表里面值与vector里面类型不匹配，此时用该值来构造对象
```
vector<int>v1(2); //构建对象，2个元素，默认值为0
vector<int>v2{2}; //列表初始化，一个元素，值为2

vector<string>s1{10,'a'};//构造

```

2. 添加元素
push_back(),**注意**在循环体内包含push_back()[改变vector大小]，不能使用范围for
```
for(auto v:vector)
{
    vector.push_back(element);
}
```
不能用下标形式来添加元素eg.
```
vector<int> v;
for(decltype(v.size())ix=0;ix!=10;++ix ){
    v[ix]=ix
}
```
`v`是一个空vector,不存在元素，也就不能通过下标运算符访问，下标运算符返回一个引用。

#### 迭代器
- 所有的标准库容器都支持迭代器，但是只有少数的支持下标访问。
- *iter 返回的是`reference`
- 迭代器在循环内做判断尽量用`!=`，这对所有容器都有效，而`<`则不一定

>在100页的二分搜索程序中，为什么用的是 mid = beg + (end - beg) / 2, 而非 mid = (beg + end) / 2 ; ?

因为迭代器支持的运算只有 - ，而没有 + 。end - beg 意思是相距若干个元素，将之除以2然后与beg相加，表示将beg移动到一半的位置。


#### 数组
- 数组不允许拷贝和赋值
- 编译器会自动将数组名转换为指向数组首元素的指针，在使用数组作为一个`auto`变量的初始值
推断得到的类型为指针而非数组
- 使用`decltype`关键字上述转化不会发生
- 数组的下标运算符可以支持负数,对数组元素做下标运算，实际上是对指向数组元素的指针做下标运算。
eg
```
int ia[]={0,2,4,6,8} //5个元素
int* p =&ia[2]; //指向`4`
int j = p[1]; //j = 6 p[1]等价*(p+1)
int k=p[-2];  //k=0,p[-2]等价*(p-2)
```
- 两个数组比大小很麻烦，对比起来vector就方便的多(做练习3.36有感)