## 函数

在英文里面，形参(parmaters),实参(argument)
```
auto i = "hi";
char arrat[] = "hi"; //字符数组初始化的特殊性
```
i的类型是`const char*`， 按照我的理解 将其转化为`char *`不合理啊，但是《primer》提到
用字符串字面值初始化字符数组是一种特殊形式。

#### 参数传递
* 函数调用时候，形参用实参的值初始化。形参的初始化与一般变量的初始化没什么不同。
* 函数形参设置为const reference ，如果我们不需要修改其值，这样同时能够避免拷贝带来的代价

Using Reference Parameters to Return Additional Information

>Exercise 6.14: Give an example of when a parameter should be a reference
type. Give an example of when a parameter should not be a reference.
举例子，什么时候用值传递，什么时候用引用传递

当形参为引用时候，实参不能是右值; 因为引用必须绑定到对象上，这个时候可以将形参设为`const reference`

##### const Parameters and Arguments
**切记**:
```
const int ci = 42; // we cannot change ci; const is top-level
int i = ci; // ok:当我们拷贝ci，其顶层常量属性被忽略
```
这也能理解了为啥
```
auto i = "hi";
char arrat[] = "hi"; //字符数组初始化的特殊性
```
i的类型是`const char`， 将其转化为`char`，这里执行的也就是拷贝初始化。

#### 数组传递
数组引用传递下，形参与实参的维度必须一致，因为数组维度也是数组类型的一部分。、
但是数组直接传递，eg
`void foo(int array[10])` 实际传递的是int*,这个时候我们调用foo()时候
```
int test[]={1,2,3,4}
foo(test)
```
即使test只有四个元素，与形参看起来指定的元素个数不匹配，但是因为传递的是`int*`
形参指定的`10`，只是表示希望传入的数组有10个元素，但传入的实际数组里面元素个数不确定。