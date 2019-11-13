(define (abs x)
    (if (< x 0)
        (- x)
        x))

(define ( better-make-rat x y)

    (if (and (> x 0)  (> y 0))
        (cons x y)      
        (cons (abs x) (- (abs y)))))

(better-make-rat -1 2)
(better-make-rat -1 -2)
;上面这样来处理有问题，参考答案
(define (make-rat n d)
    (if (< d 0)
        (cons (- n) (- d))
        (cons n d)))

;;;;2.2 构造线段
(define (make-seg x y)
    (cons x y))
(define (start-seg x)
    (car x))
(define (end-seg x)
    (cdr x))

(define (make-point x y)
    (cons x y))
(define (xcor x)
    (car x))
(define (ycor x)
    (cdr x))

;求线段中点
(define (mid-segment seg)
    ( make-seg
        (/ (+ (xcor (start-seg seg))
         (xcor (end-seg seg))) 2)
        (/ (+ (ycor (start-seg seg))
        (ycor (end-seg seg))) 2)
    ))
;显示帮助函数
(define (print-point p)
(newline)
(display "(")
(display (xcor p))
(display ",")
(display (ycor p))
(display ")"))

(define a (make-point 2 2))
(define b (make-point 3 4))
(define seg1 (make-seg a b))

(define mid (mid-segment seg1))
(print-point mid)

;2.3  构建四边形
; 太鸡儿多了。。。

;2.4另一种pair表示方法
(define (cons x y)
(lambda (m) (m x y)))

(define (car z)
(z (lambda (p q) p)))

(define (cdr z)
  (z (lambda (p q) q)))
(car (cons 10 12))
(cdr (cons 10 12))

((lambda (m) (m 1 2))               ; 代换 m
    (lambda (p q) p))

;;; 5-cons.scm
(define (power a b)
   (define (iter result a b)
       (if (= b 1)
           result
           (iter (* result a) a (- b 1))))
   (iter a a b)
   )

(define (cons x y)
    (* (power 2 x)
       (power 3 y)))

;how to get car and cdr
;car 一直除2，知道除不尽为止
(define (car z)
    (if (= 0 (remainder z 2))
        (+ 1 (car (/ z 2)))
        0))

(define (cdr z)
    (if (= 0 (remainder z 3))
        (+ 1 (car (/ z 3)))
        0))
(define x (cons 3 2))
(car x)
(cdr x)

