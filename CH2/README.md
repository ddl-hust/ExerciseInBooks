前言：在看完了primer CH16之后决定慢慢地把C++primer 从头再过一遍，把练习题做一遍
------------------------



#### ch2 变量与基本类型
Types determine the meaning of the data and operations in our programs.
类型决定了数据的意义与可以在上面做的操作

The arithmetic types are divided into two categories: integral types (which include
character and boolean types) and floating-point types.
算术类型分为两大类：整型与浮点数，其中整型包括了字符('a'->56)，布尔型(0,1)。

在计算机里面一个 字节(byte) 8 bits ，一个字(word) 32bits`
**为什么选用int,double**；
1. char 也能够表示int，但是在一些机器的编译器上有符号，有一些无符号。
2. 执行浮点数用double,因为float精度不够。double类型的计算代价与float差别不大
浮点数如何在计算机里面表示？
[参考](http://www.ruanyifeng.com/blog/2010/06/ieee_floating-point_representation.html)

看书里面有个疑惑
`
unsigned char c= -1; //假设char 8bits ，c=255
`
为什么会这样?
计算机里面没有减法操作，对负数的操作，需要将其转化“正数”，一个简单粗暴的计算方法，用该负数加上无符号数的模即
-1+256=255


#### 字面值常量
字面值常量对应于一种数据，其形式与值决定了它的数据类型

##### 字符串字面值
字符串字面值的实际类型是由常量字符组成的数组，**编译器在数组的末尾加上一个空字符('\0')**。因此字符串字面值的实际长度比它的内容多1.

### 2.2 变量
>Initialization is not assignment. Initialization happens when a variable is given
a value when it is created. Assignment obliterates an object’s current value
and replaces that value with a new one.
这就涉及到了直接初始化与拷贝初始化了，看个例子就明白了
```
string s1="ddl"; //拷贝初始化
string s2(10,'7') //直接初始化
```
初始化是个很复杂的概念，一方面在于初始化的方式很多

>Uninitialized objects of built-in type defined inside a function body have
undefined value. Objects of class type that we do not explicitly initialize have
a value that is defined by the class.

内置类型的变量未被显式初始化，他的值由定义的位置决定，函数类部：未定义，函数外部初始化为0.
因此如果在函数内部使用未初始化的变量，将带来无法预估的后果。

#### 声明与定义


#### 标识符(identifier)
声明：由基本数据类型与声明符列表组成，
标识符到底是什么？我现在理解为变量的名字，基本类型的声明而言，声明符就是变量名即标识符，对于复合类型，比如引用(reference)，声明符为`&r`,指针`*p`，变量名为`r`,`p`。
> identifier：Sequence of characters that make up a name. Identifiers are casesensitive.

>We define a reference type by writing a declarator of the form &d,
where d is the name being declared:

>a declaration is a base type
followed by a list of declarators. Each declarator names a variable and gives the
variable a type that is related to the base type



引用与被引用对象类型必须匹配，但是下面两个例外
1. const reference
```
double d=2.0
const int & ci=d;
```
为什么 `int &ci=d;`不行?
编译器首先要做一个类型转换
`int temp=d;` 然后将引用绑定到临时对象`temp`上
对于`no const reference`，这样的行为显然不是我们想要的，我们通过引用来改变的是一个临时对象的值，而不是`d`
2. 对基类(base class)的引用可以转化为继承类(derived class)
详细看15.2.3小结

一些符号在不同的语境下含义不同：
注意*，&，是声明符的一部分，还是操作符(解引用,取地址)

#### 空指针
初始化：使用字面值`nullptr`,可以转化为任意其他类型的指针,下面是其他几种初始化空指针的方法。
```
int *p1 = nullptr; // equivalent to int *p1 = 0;
int *p2 = 0; // directly initializes p2 from the literal constant 0
// must #include cstdlib
int *p3 = NULL; // equivalent to int *p3 = 0;
```
`NULL`不建议使用，作为预处理变量，在预处理阶段用`0`替换。

#### 理解复合类型

一句定义语句，可能定义不同类型的变量eg.
`// i is an int; p is a pointer to int; r is a reference to int
int i = 1024, *p = &i, &r = i;`

`int* p1, p2; // p1 is a pointer to int; p2 is an int`

这句话形式上面可能误解，`int*`并没有修饰所有变量，基本声明类型为`int`，`*`作为修饰符修饰p1。
因此为了消除这种误解，两种方式
```
1. int *p1,*p2  //cpp primer 采用这一形式

2.int* p1; int* p2;
```

