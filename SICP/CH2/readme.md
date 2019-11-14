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

#### 2.2 一个综合的例子
>A frame can be described by three vectors—an origin vector and two edge vectors

这里面的vector就理解为空间矢量点
frame 的构造以及选择函数

>make-frame：which takes three vectors and produces a frame,
three corresponding selectors： origin-frame, edge1-frame, and edge2-frame

use coordinates in the unit square (0 ≤ x ; y ≤ 1) to specify
images.With each frame, we associate a frame coordinate map, which
will be used to shift and scale images to fit the frame. 

也就是说image的范围是确定的，我们需要将其转换到相应的frame。
给出下面公式：Origin(Frame) + x · Edge1(Frame) + y · Edge2(Frame):(坐标变换公式)

(define (frame-coord-map frame)
(lambda (v)
(add-vect (origin-frame frame)(add-vect (scale-vect (xcor-vect v) (edge1-frame frame))
(scale-vect (ycor-vect v) (edge2-frame frame))))))
每一个frame都定义了自己的坐标转换程序,输入一个矩形，返回一个函数，这个函数的输入是vector

输入坐标在单位坐标系，通过转换到frame坐标系
If the argument vector is in the unit square, the result vector will be in the frame

```
(define (segments->painter segment-list)
(lambda (frame)
(for-each
(lambda (segment)
(draw-line
((frame-coord-map frame)
(start-segment segment))
((frame-coord-map frame)
(end-segment segment))))
segment-list)))
```
painter是一个procedure ,输入的是线段集合
返回一个函数，这个接受一个frame参数，也就是说将 之前的线段画在frame上面。
 ？？？ yes

 #### 定义高阶函数
```
(define (transform-painter painter origin corner1 corner2)
(lambda (frame)
(let ((m (frame-coord-map frame)))
(let ((new-origin (m origin)))
(painter (make-frame
new-origin
(sub-vect (m corner1) new-origin)
(sub-vect (m corner2) new-origin)))))))
```
在此基础上实现`beside`等
进而引出` stratified design`(分层设计)
 1. >the notion that a complex system should be structured as a sequence
of levels that are described using a sequence of languages. Each level is
constructed by combining parts that are regarded as primitive at that
level, and the parts constructed at each level are used as primitives at
the next level. 

2. > Stratified design helps make programs robust, that is, it makes it
likely that small changes in a specification will require correspondingly
small changes in the program. 

#### 2.3符号化数据
概念如何引出，发展，推理
问题：
1.语义不明 当我们构(list a b)
我们使用的是a,b代表的值，而不是符号本身
再比如，say your name aloud,到底是啥意思，于是引入引用(qotation)

判断符号是否在符号集合里面，`eq?`内置程序，判断两个符号是否相等
```
(define (memq item x)
(cond ((null? x) false)
((eq? item (car x)) x)
(else (memq item (cdr x)))))
```
##### 求导
先按照wishful thinking 
> that is, we will first define a differentiation algorithm that operates on abstract objects such as
“sums,” “products,” and “variables” without worrying about how these
are to be represented. Only aerward will we address the representation
problem.
假设下面的函数已经有了以及内置的`number?`
```
(variable? e) Is e a variable?
(same-variable? v1 v2) Are v1 and v2 the same variable?
(sum? e) Is e a sum?
(addend e) Addend of the sum e.
(augend e) Augend of the sum e.
(make-sum a1 a2) Construct the sum of a1 and a2.
(product? e) Is e a product?
(multiplier e) Multiplier of the product e.
(multiplicand e) Multiplicand of the product e.
(make-product m1 m2) Construct the product of m1 and m2
```
我们就可以按照导数运算法则构建出符号表达式
```
(define (deriv exp var)
(cond ((number? exp) 0)
((variable? exp) (if (same-variable? exp var) 1 0))
((sum? exp) (make-sum (deriv (addend exp) var)
(deriv (augend exp) var)))
((product? exp)
(make-sum
(make-product (multiplier exp)
(deriv (multiplicand exp) var))
(make-product (deriv (multiplier exp) var)
(multiplicand exp))))
(else
(error "unknown expression type: DERIV" exp))))
```

下面要做的就是如何构建表达式，以及选择器。
按照lisp 原有的先序表达式来构建这些表达式

(define (variable? a )
    (symbol? a))

(define (make-sum a1 a2) (list '+ a1 a2))
等等，很直接，用list 构造，但是带来一个问题，求导之后的表达式没有化简。
这个时候我们抽象障碍的作用就体现出来了，我们只需改动构造器，而不用动求导部分
```
(define (make-sum a1 a2)
(cond ((=number? a1 0) a2)
((=number? a2 0) a1)
((and (number? a1) (number? a2))
(+ a1 a2))
(else (list '+ a1 a2))))

(define (=number? exp num) (and (number? exp) (= exp num)))
```
> problem of algebraic simplification is complex because, among other reasons, a
form that may be simplest for one purpose may not be for another.