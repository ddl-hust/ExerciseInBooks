; 表示vector in 2-D,以及一些四则运算
(define (make-vec x y)
    (cons x y))

(define (xcor-vec z)
    (car z))
(define (ycor-vec z)
    (cdr z))

(define (add-vec v1 v2)
    (cons (+ (car v1) (car v2)) (+ (cdr v1) (cdr v2)))
    )

(define (sub-vec v1 v2)
    (cons (- (car v1) (car v2)) (- (cdr v1) (cdr v2)))
    )
(define (scale-vec s v)
    (cons (* s (car v) ) (* s (cdr c))))

;2.47
(define (make-frame origin edge1 edge2)
(list origin edge1 edge2))
(define (slect-origin frame)
    (car frame))
(define (slect-edge1 frame)
    (car (cdr frame)))
(define (slect-edge2 frame)
    (cdr (cdr frame)))


;2.48 segment
(define (make-segment x y)
    (cons x y))
(define (start-segment seg)
    (car seg))
(define (end-segment seg)
    (cdr seg))

(define seg (make-segment (make-vec 0 0) (make-vec 1 1)))
(end-segment seg)

;2.49 这个练习很好，虽然不能直接画出来，但是确定了我之前的理解
;定义 picture接受线段集合， 调用picture 传入指定frame
