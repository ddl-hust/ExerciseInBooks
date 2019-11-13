;compostion f(g(x))

(define (compostion f g)
    (lambda (x) (f ( g x)))
)

(define (squre x)
    (* x x))
((compostion squre 1+) 6 )

;1.43 
(define (repeat f n)
    (if (= n 1)
        f
        (repeat (compostion f f) (- n 1))))
((repeat squre 1) 5)

;1.44 smooth function
(define dx 0.0001)

(define (smooth f)
 
    (lambda (x) (/ (+ (f (+ x dx))
                (f (- x dx)) (f x)) 3)
    ))
((smooth squre) 5)


(define (smooth-n-times f n)
    (let ((n-times-smooth (repeat smooth n)))
        (n-times-smooth f)))

((smooth-n-times squre 2) 5)