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

