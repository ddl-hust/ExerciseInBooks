;1.32 进一步抽象sum，product

;先复习下sum的递归与非递归
; (define (sum term next a b)
;     (if (> a b)
;         0
;         (+ (term a)
;         (sum term next (next a) b)
;         )))

;非递归
(define (sum term next a b)
    (define (iter a result)
    (if (> a b)
     result
     (iter (next a)
            (+ (term a) result))))
    (iter a 0) ;调用递归式
    )
;;;;;;;;;;;;;;;;;;;;;;;;

; null-value 用于判断递归终止条件
; (define (accumulate combiner null-value term a next b)
;     (if (> a b)
;         null-value
;         (combiner (term a)
;         (accumulate combiner null-value term (next a) next b))))

;;;;非递归
(define (accumulate combiner null-value term a next b)
    (define (iter a result)
        (if (> a b)
            result
            (iter (next a) (combiner (term a) result )
             )))
    (iter a null-value)
    )

(define (sum term next a b)
    (accumulate + 0 term a next b))

(define (product term next a b)
    (accumulate * 1 term a next b)
    )

(sum (lambda(x) x)
       (lambda(x) (+ x 1))
       1 100)

(product (lambda(x) x)
       (lambda(x) (+ x 1))
       1 4)
