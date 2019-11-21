#### share_ptr和new 结合


reset搭配unique使用
```
if (!p.unique())
p.reset(new string(*p)); // we aren't alone; allocate a new copy
*p += newVal; // now that we know we're the only pointer, okay to change this
object
```

alloctor内存分配这一段什么意思
auto const p=alloc.allocate(5);
        auto q=p;

#### 综合案例分析
目的：在一个文件里面查询单词，结果为单词在文件中出现的次数以及所在行列表，输出行按照升序排列。

分析：
我们需要什么样的操作：
- 逐行读取，并且将每一行分解为单词
- 将每个单词与其出现的行关联
- 行号升序，无重复

定义数据结构
TextQuery():

返回类型： QueryResult():
