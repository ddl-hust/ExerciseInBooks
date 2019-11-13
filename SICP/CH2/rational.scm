(define (make-rat a b)
    (cons(a b))
    )
(define (numer x)
    (car x))
(define (denom x)
    (cdr x))

;化简版本
(define (make-rat n d)
(let ((g (gcd n d)))
(cons (/ n g) (/ d g))))

;定义运算
(define (add-rat x y)
(make-rat (+ (* (numer x) (denom y))
(* (numer y) (denom x)))
(* (denom x) (denom y))))

(define (sub-rat x y)
(make-rat (- (* (numer x) (denom y))
(* (numer y) (denom x)))
(* (denom x) (denom y))))

(define (mul-rat x y)
(make-rat (* (numer x) (numer y))
(* (denom x) (denom y))))

(define (div-rat x y)
(make-rat (* (numer x) (denom y))
(* (denom x) (numer y))))
;how to implement pairs
(define (cons x y)
(lambda (pick) 
  (cond ((= pick 1) x)
		((= pick 2) y))))
(define (car x)
  (x 1))
(define (cdr x)
  (x 2))
