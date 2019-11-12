#### 容器初始化
将一个容器初始化为另一个容器拷贝时候，两个容器的容器类型与原始类型必须匹配。
当传递迭代器参数就不要求容器类型匹配。

#### swap
swapping two containers is guaranteed to be fast，the elements themselves are not swapped; internal data structures are swapped.
> Excepting array, swap does not copy, delete, or insert any elements and is
guaranteed to run in constant time.

swap 可以用来做如下事情，直接看例子
```
vector<int> V;
  for(int i=0; i<10; ++i)
  {
        V.push_back(i);
  }
  std::cout<<V.size()<<" "<<V.capacity()<<endl;

  std::vector<int>(V).swap(V);

  std::cout<<V.size()<<" "<<V.capacity()<<endl;
```
我们创建一个临时拷贝vector，他的size=capacity，然后交换。

#### 序列容器操作
之前的一些操作针对所有容器，迭代器阿，等等，下面的一些操作只对序列容器有效
1. 添加元素
insert(),一些操作之前没有注意到
emplce():直接用参数在内存空间构造对象
