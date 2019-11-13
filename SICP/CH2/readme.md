## 数据抽象

wishful thiking
为什么要进行数据抽象
比如有理数的运算，不是直接用一些临时变量

#### 列表操作
1. 返回ith 
(define (list-ref items n)
(if (= n 0)
(car items)
(list-ref (cdr items) (- n 1))))

scheme 为了方便定义了 `null?`,`lenth`
lenth 是如何计算的呢?
递归：
(define (lenth items)
if null? items
    0
    + 1 (lenth (cdr items))

迭代：
(define lenth items)
(iter count a)
(
    if null? a
        count
        (iter (+ 1 count) (cdr a) )
)  

两个list如何append
(define (append list1 list2)
(
    (if null? list1)
    list2
    (cons (car list1) (append (cdr list1) list2))
))

**nil**:== '() 空表

#### map list
这个就很像python 里面的操作
不过在scheme 里面使用高阶函数更加方便
(define (map proc items)
(if (null? items)
'()
(cons (proc (car items))
(map proc (cdr items)))))