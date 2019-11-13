;牛顿法求三次项根

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

(define (deriv g)
(define dx 0.00001)
(lambda (x) (/ (- (g (+ x dx)) (g x)) dx)))

;牛顿法转换函数
(define (newton-transform g)
(lambda (x) (- x (/ (g x) ((deriv g) x)))))

;牛顿法求不动点
(define (newtons-method g guess)
(fixed-point (newton-transform g) guess))

(define (cubic a b c)
    (lambda (x) (+ (*  x x x) 
                (* a x x)
                (* b x)
                c    
    ))
)

(newtons-method (cubic 0 0 1) 1)