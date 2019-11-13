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

#### 迭代器失效
进行insert(),erase()，等改变容器元素的操作都可能让迭代器失效
在运行时报错`munmap_chunk(): invalid pointer`
一个问题：存储空间没有从新分配，指向插入位置之前的迭代器有效，插入操作之后的将会失效？
我的理解是，插入操作导致内存位置在插入点整体向后移动，此时原有的指针指向的位置与元素不对应，但是解引用应该就是之前的值。
通过编程来验证下。
```
int main()
{
    vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout<<v.size()<<" "<<v.capacity()<<endl;
    auto begin = v.begin();
    begin=v.insert(begin,100);
    cout<<"begin after insert:"<<*begin<<endl;
    v.insert(begin,1000);
    cout<<"after insert:"<<v.size()<<" "<<v.capacity()<<endl;
    cout<<"begin after insert:"<<*begin<<endl;
    for (auto i : v) cout << i << " ";

    return 0;
}
```
符合预期

