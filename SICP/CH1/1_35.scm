;不动点定义
(define tolerance 0.00001)

(define (fixed-point f first-guess)

(define (close-enough? v1 v2)
(< (abs (- v1 v2))
tolerance))

(define (try guess)
    (let ((next (f guess)))
    (display next)
    (newline)
    (if (close-enough? guess next)
    next
    (try next))))

(try first-guess)

)

;不动点找平方根
(define (sqrt x)
(fixed-point (lambda (y) (/ x y))
1.0))
;存在无限循环　results in an infinite loop in which the two
;guesses y1 and y2 repeat over and over, oscillating about the answer
;改进
(define (avarge a b)
    (/ (+ a b) 2))
(define (sqrt x)
(fixed-point (lambda (y) (avarge y (/ x y)))
1.0))

(sqrt 2)

; 找黄金分割不动点
(define gold-split
    (fixed-point (lambda (x) (+ 1 (/ 1 x))) ;注意写法,gold-split不是一个procedure just a variable
    1.0))
gold-split
