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
