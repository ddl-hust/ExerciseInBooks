#### 1.1.4 复合程式
- Numbers and a rithmetic operations are primitive data and procedures.
-  Nesting of combinations provides a means of combining operations.
-  Deﬁnitions that associate names with values provide a limited means of abstraction.
进一步抽象， `procedure deﬁnitions` 将一系列复合运算用一个函数名代替
eg. `(define (square x) (* x x))` () 是lisp 语法的特点
![](image/1.png)

 would be in an actual call to the procedure being deﬁned. 
 实际调用 eg.(square 5)

 #### 1.1.5 替代模型

 替代模型先计算，运算符，运算子，用运算子替代形参。

 注意值替代只是为了帮助我们理解，实际上解释器并不是这样工作的。

 其次替代模型是有缺陷的，   
 > when we address in Chapter 3 the use of procedures with “mutable data

 在计算f(5)有两种方式:

 one is alternative “fully expand and then reduce” evaluation method is known as` normal-order` evaluation, in contrast to the “evaluate the arguments and then apply” method that the interpreter actually uses, which is called `applicative-order` evaluation  
简单来说，一个就是先展开。化简，另一个先带入值

#### 1.1.6 条件表达式
在lisp里面做一个绝对值的条件判断如下：
```
(define (abs x)
 (cond ((> x 0) x)
        ((= x 0) 0)
        ((< x 0) (- x))))
```
cond 表示condtional

(if ⟨predicate⟩ ⟨consequent⟩ ⟨alternative⟩)

-----
#### 练习
lisp 里面都是前缀表达式，因此需要很熟悉的将中缀表达式转化为前缀

#### 1.1.7 牛顿法求平方根
精彩部分来了，
> the contrast between function and procedure is a reﬂection of the generaldistinctionbetweendescribingpropertiesofthingsanddescribing how to do things, or, as it is sometimes referred to, the distinction
between declarative knowledge and imperative knowledge.  In mathematics we are usually concerned with declarative(whatis)descriptions,whereas in computer science we are usually concerned with imperative (how to) descriptions
平方根这个问题描述起来，并不能直接给你解决思路。

----------
看教学视频
what is process ? procdure

key:控制复杂度
课程三大主题：
1. 黑盒
2. 约定接口
3. 元语言抽象

#### 学习`lisp` 
无关乎语言本身，先问几个问题：
1. 该语言的primitive elements
2. means of combinations
3. means of abstractions

lisp 前缀表达式，下面是一个简单的combination
`(+ 1 2 2)` 一个运算符`+`，三个运算子,一个问题，+是多目运算符么？`+`在这里不在是我们一般意义的加法运算符，而是一个函数。
lisp 语法只需要这些，就足以做很多事情了，看下面例子

#### 求平方根

课后问题：
```
(define a (* 5 5)) //变量
(define  (D) (* 5 5))　//procedure
```

－－－－－
#### lec1b:计算过程
两种不同的加法计算引出了递归与迭代
书中给出了斐波拉契函数的递归与迭代
迭代：
```
(define (factorial n)
(fact-iter 1 1 n))
(define (fact-iter product counter max-count)
(if (> counter max-count)
product
(fact-iter (* counter product)
(+ counter 1)
max-count)))
```

递归：
```
(define (factorial n)
(if (= n 1)
1
(* n (factorial (- n 1)))))
```
**两者的区别**：
1. 递归的“形状”先扩大，在收缩，有延迟运算，编译器因此需要额外保存这些运算，这些额外保存的信息与问题的规模
   呈线性关系，
2. 对于迭代whose state can be summarized by a fixed number of state variables，也就是不需要保存额外的运算
 
从另一个角度来看

3. 迭代的程序变量完全描述了任意时刻的程序运行状态，如果在两个状态之间中断，我们只需要给出三个变量的值就能恢复(product,counter,max－count)
4.  递归而言，some additional “hidden” information, maintained by the interpreter and not　contained in the program variables

区分一个概念 recursive process or recursive procedure
recursive procedure:程序用自己来定义自己

recursive process:
> following a pattern that is, say, linearly recursive, we are speaking
about how the process evolves, not about the syntax of how a procedure
is writen. 

也就是说上述两个计算斐波拉契的都是`recursive procedure`,因为他们都用自己来定义了自己，但是一个是`recursive process`，一个是`iterative process`。 

在用迭代做课后练习`ｅ11`的时候,在下面的基础上实际上可以提前结束程序，我们要求f(n)，实际上在i=n-2的时候，ｆ(n)就已经计算了，此时返回`a`
```
(define (f n)
    (f-iter 2 1 0 0 n))

(define (f-iter a b c i n)
    (if (= i n)　;改为(= i (- n 2))
        c ;改为 a
        (f-iter (+ a (* 2 b) (* 3 c))   ; new a
                a                       ; new b
                b                       ; new c
                (+ i 1)
                n)))
```


#### lambada 匿名函数
`(define (plus4 x) (+ x 4))`==`(define plus4 (lambda (x) (+ x 4)))`

使用lambada 创建局部变量
![](image/let.png)

- 求方程的根


------------
重新来理解　求平方根，用不动点的方法

#### 寻找函数的不动点(P120)
不动点定义：
f(x)=x ，x为f的不动点

------------
11.3 星期天
按照书上章节，一章一章来，一道练习一道的做，无他

#### 1.3　高阶函数

##### １.3.1 函数作为参数

由求和运算一步一步挖掘本质，写一个用数学定义的求和，而不是针对某种特殊类型的求和
```
(define (sum term next a b)
    (if (> a b )
        0   
        (+ 
        (term a)
        (sum term next (next a) b ) 
        ) )
    )
```
书里面给的，在之前求和函数的基础上，用来构建更加复杂的程序，用于求积分。
(define (add-dx x)
(+ x dx))

(define (integral f a b dx)

(* (sum f (+ a (/ dx 2.0)) add-dx b) 
    dx))

练习１.29
term 就是f, next=(b-a)/n,边界也给了
不知道的：
每一项前面的系数如何确定