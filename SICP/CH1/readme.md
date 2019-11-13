#### 理解let
有时候函数里面需要局部变量，比如
｀f (x ， y) = x(1 + xy)^2 + y(1 − y) + (1 + xy)(1 − y)｀
a=1+xy;
b=1-y;
则ｆ可以简化为　ｆ=x*a^2+yb+ab
我们可以这么实现
```
(define (f x y)
(define (f-helper a b)
(+ (* x (square a))
(* y b)
(* a b)))
(f-helper (+ 1 (* x y))
(- 1 y)))
```
进一步使用lambda匿名函数
```
(define (f x y)
((lambda (a b)
(+ (* x (square a))
(* y b)
(* a b)))

(+ 1 (* x y))
(- 1 y)))
```
进一步简化
```
(define (f x y)
(let ((a (+ 1 (* x y)))
(b (- 1 y)))
(+ (* x (square a))
(* y b)
(* a b))))
```
于是引出了`let`

#### 1.3.4 返回函数
在之前求不动点基础上，进一步抽象

;返回函数
(define (average-damp f)
(lambda (x) (average x (f x))))

(define (sqrt x)
(fixed-point (average-damp (lambda (y) (/ x y)))
1.0))

如何复用代码，在这个的基础上可以很简单的扩展到求立方根
(define (cube-root x)
(fixed-point (average-damp (lambda (y) (/ x (square y))))
1.0))


#### 牛顿法
使用牛顿法求方程的根，将其转化为求函数的不动点
![](../image/fix_point.png)
首先定义如何求导数，求导数输出函数，返回导函数
(define (deriv g)
(lambda (x) (/ (- (g (+ x dx)) (g x)) dx)))

牛顿法转换函数
(define (newton-transform g)
(lambda (x) (- x (/ (g x) ((deriv g) x)))))

牛顿法求不动点
(define (newtons-method g guess)
(fixed-point (newton-transform g) guess))


将之前求不动点与牛顿法求解，进一步抽象
(define (fixed-point-of-transform g transform guess)
(fixed-point (transform g) guess))

在这个抽象的基础上，实例化avarge-damping, 牛顿法
；avarge
(define (sqrt x)
(fixed-point-of-transform
(lambda (y) (/ x y)) average-damp 1.0))

;牛顿
(define (sqrt x)
(fixed-point-of-transform
(lambda (y) (- (square y) x)) newton-transform 1.0))
结尾精辟
>As programmers, we should be alert to opportunities to identify the underlying abstractions in our programs and to build upon them and generalize them to create more powerful abstractions. But is is not to say that one should always write programs in the most abstract way　possible; expert programmers know how to choose the level of abstraction appropriate to their task. But it is important to be able to think in　terms of these abstractions, so that we can be ready to apply them in new contexts. 