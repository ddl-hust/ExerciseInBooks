;求平方根
(define (square x)
    (* x x))
(define (abs x)
    (if (< x 0)
        (- x)
        x
    ) 
)

(define (avarge guess x)
    (/ (+ guess x) 2)
    )


(define (improve  guess x)
    (avarge guess (/ x guess)
    )
)

(define (good_enough guess x)
    (< (abs (- (square guess) x ) ) 0.001)  
    
    )

(define (sqrt guess x)
    (if (good_enough guess x)
        guess               
        (sqrt (improve guess x) x)
    ) 
    )

(sqrt 1 2)

;1.4
(define (a-plus-abs-b a b)
    ((if (> b 0) + -)
        a b)
)
; (a-plus-abs-b 1 -2)

(define (p) (p))

(define (test x y)
(if (= x 0) 0 y))

;1.6 new if
(define (new-if predicate then-clause else-clause)
(cond (predicate then-clause)
(else else-clause)))

(define ( new-sqrt guess x)
    (new-if (good_enough guess x)
        guess               
        (new-sqrt (improve guess x) x)
    ) 
    )
; (new-sqrt 1 2)

;1.10
(define (A x y)
(cond ((= y 0) 0)
((= x 0) (* 2 y))
((= y 1) 2)
(else (A (- x 1) (A x (- y 1))))))

(A 2 4)

; 迭代斐波拉契数列迭代
(define (fibi n )
    (fib 1 0 n)
)
(define (fib a b n)   
        (if (= n 0) 
            b      
            (fib (+ a b) a (- n 1) ) )  
   )
(fibi 4 )

;1.11 递归
(define (e11 n)
    (if (< n 3)
        n
        (+ (e11 (- n 1)) 
           (* 2 (e11 (- n 2)))
           (* 3 (e11 (- n 3)))
        )
)
)

;1.11 迭代
;
(define (f n)
    (f-iter 2 1 0 0 n))

(define (f-iter a b c i n)
    (if (= i (- n 2)); //实际上
        a
        (f-iter (+ a (* 2 b) (* 3 c))   ; new a
                a                       ; new b
                b                       ; new c
                (+ i 1)
                n)))

;高阶函数练习
(define (sum term next a b)
    (if (> a b )
        0   
        (+ 
        (term a)
        (sum term next (next a) b ) 
        ) )
    )

(define (sum-int a b)
    
    (sum 
    (lambda (x) x) ;匿名函数
     1+ a b)
    )   
(sum-int 1 100)


;1.29
(define (simpson f a b n )
    (define h (/ (- b a) n ))
    (define (y  k)
        (f (+ a (* k h))) )
    (define (factor k)
        (cond ((or (= k 0) (= k n))
                1)
              ((odd? k)
                4)
              (else
                2)))
    (define (next k)
        (+ k 1))
    (define (term k)
        (* (y k) (factor k)))
    (if (not (even? n))
        (error "n canot be odd")
        (* (/ h 3)
        (sum term next (exact->inexact 0) n ) ;分数，小数表示
   
    ))
)

(define (cube x)
    (* x x x))

(simpson cube 0 1 1000)


;1.30 将之前的sum　改为迭代
(define (sum term a next b)
(define (iter a result)
(if (> a b)
  result
(iter (next a )
     (+ ( term a)
      result)))) ; new a, new result
(iter a 0)
)

;1.31_a　类似求和写一个求乘 递归版本
(define (product term next a b)
    (if (> a b)
        1
        (* (term a)
        (product term next (next a) b))))

(product (lambda(x) x)
        (lambda (x)(+ x 1))
        1 3
)

;1.31_b 迭代版本
(define (product_iter term next a b)
    (define (iter a result)
    (if (> a b)
        result
        (iter (next a ) (* (term a) result))))
    (iter a 1)
    )

(product_iter (lambda(x) x)
        (lambda (x)(+ x 1))
        1 3
)