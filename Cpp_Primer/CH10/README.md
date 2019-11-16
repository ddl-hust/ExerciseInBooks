#### 概述

1.算法并不直接操作容器，通过迭代器遍历来指定一个范围。

算法基本按照读，写，排列来分类

> 标准库算法不改变所操作容器大小，为什么使用`back_inserter`不会失效？
 the algorithms don't change the size, but the iterator can change it by using the container operation.

>算法为什么不直接改变容器大小？

 #### lambda
 捕获列表是啥

 
 ##### 10.3.4 参数绑定
 背景：像`find_if`等算法接受一个可调用对象，此调用对象必须接受单一参数
 ```
 bool check_size(const string &s,string::size_type);
 ``` 
如果不用lambda来捕获参数，还有没有其他方法呢？
答案是`bind`,bind 接受一个可调用对象，生成一个新的可调用对象。
`auto newcallable=bind(callable arg_list)`

#### 反向迭代器
使用：#include<iterator>

应用场景：比如我们需要打印一句话的最后一个单词
```
auto recomma =fing(line.crbegin(),line.crend(),',');
cout<<string(line.crbegin(),recomma)<<endl;
```
结果是有问题的，需要先将`recomma`转化为普通迭代器，通过调用`reverse_iterator.base()`
符合预期的答案：`string(recomma.base(),line.end())`
注意，反向迭代器调用base()，返回的迭代器与之相邻(P365)

[tag anki]
error1. 无符号数比较错误
for (size_t i = vec.size()-1; i >= 0; i--)
{
    cout << vec[i];
}

[tag anki]
使用普通迭代器逆序打印vector
遇到的问题： for (auto it = --vec.cend(); it != vec.begin() - 1; it--) cout << *it << " ";

改进：  for (auto iter = v.cend(); iter != v.cbegin();)
        std::cout << *--iter << " ";
心得：反向迭代器在做算法题目里面很有效，查找最后元素之类的。
