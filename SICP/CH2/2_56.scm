;扩展求导法则的谓词

(define (exp? expre)
    (and (pair? expre) (eq? (car expre) '**))) ;Exception in =: ** is not a number  符号比较用eq?

(define (make-exp u n)
    (cond
        ((= n 1) u )
        ((= n 0) 1)
        (else   (list '** u n))))
(define (base exp)
    (cadr exp))
(define (expoent exp)
    (caddr exp))

(define (deriv exp var)
(cond 
((number? exp) 0)
((variable? exp) (if (same-variable? exp var) 1 0))
((sum? exp) (make-sum (deriv (addend exp) var)(deriv (augend exp) var)))
((product? exp)(make-sum(make-product (multiplier exp)(deriv (multiplicand exp) var))
    (make-product (deriv (multiplier exp) var)(multiplicand exp))))
((exp? exp) 
    (make-product (expoent exp) 
    (make-product (make-exp (base exp) (- (expoent exp) 1)) (deriv (base exp) var))))
(else (error "unknown expression type: DERIV" exp))))

;;;;;;;书中代码，为了输出结果测试，copy
;; number

(define (=number? exp num)
    (and (number? exp)
         (= exp num)))

;; variable

(define (variable? x)
    (symbol? x))

(define (same-variable? v1 v2)
    (and (variable? v1)
         (variable? v2)
         (eq? v1 v2)))

;; sum

(define (make-sum a1 a2)
    (cond ((=number? a1 0)
            a2)
          ((=number? a2 0)
            a1)
          ((and (number? a1) (number? a2))
            (+ a1 a2))
          (else
            (list '+ a1 a2))))

(define (sum? x)
    (and (pair? x)
         (eq? (car x) '+)))

(define (addend s)
    (cadr s))

(define (augend s)
    (caddr s))

;; product

(define (make-product m1 m2)
    (cond ((or (=number? m1 0) (=number? m2 0))
            0)
          ((=number? m1 1)
            m2)
          ((=number? m2 1)
            m1)
          ((and (number? m1) (number? m2))
            (* m1 m2))
          (else
            (list '* m1 m2))))

(define (product? x)
    (and (pair? x)
         (eq? (car x) '*)))

(define (multiplier p)
    (cadr p))

(define (multiplicand p)
    (caddr p))

(deriv (list '** 'x '1) 'x)

(deriv '(** x 3) 'x)


;2.57处理多项之和