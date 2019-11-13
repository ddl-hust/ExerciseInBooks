;进一步抽象accumulate,添加过滤器
;如何判断一个素数

(define (filter-accumulate combiner null-value term a next b)
    (if (> a b)
        null-value
        (combiner (term (prime? a))
        (filter-accumulate combiner null-value term (next a) next b))))
;上面写是有问题的，当ａ不是素数，那么combiner了什么？

(define (suqare x)
    (* x x))
(define (prime? x)
    body)