一些操作符的使用，先略过在使用上遇到不懂的时候再看

#### 4.11类型转换
- 算数类型的隐式转化有一个原则：保留精度
`int val=3.5+1;`看这句话，首先算数运算转化得到一个`double`,然后在初始化过程中，用初始值转化为`int`类型，这里发生了截断。
因此，不是`3.5`先转化为`3`再+1.

算数运算转化的几个原则
- In most expressions, values of integral types smaller than int are first
promoted to an appropriate larger integral type.
其他隐式类型转化
1. 数组转化为指针
例外：使用`decltype`,引用(这个在二维数组里面出现过)
his conversion is not performed when an array is used with decltype or as the
operand of the address-of (&), sizeof, or typeid (which we’ll cover in § 19.2.2 (p.
826)) operators. The conversion is also omitted when we initialize a reference to an
array (§ 3.5.1, p. 114). As we’ll see in § 6.7 (p. 247), a similar pointer conversion
happens when we use a function type in an expression.
2. A constant integral value of 0 and the literal nullptr can be converted to any pointer type; a
pointer to any nonconst type can be converted to void*, and a pointer to any type
can be converted to a const void*. 