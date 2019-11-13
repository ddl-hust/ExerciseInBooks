(define (square x)
    (* x x))

(define (square-list items)
(if (null? items)
'()
(cons (square (car items)) (square-list(cdr items)))))

(define list1 (list 1 2 3))
(square-list list1)

;;;;;;;;;generial method
(define (map proc items)
(if (null? items)
'()
(cons (proc (car items))
(map proc (cdr items)))))

(define (square-list items)
(map square items))

(square-list list1)