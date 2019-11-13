(define (square x)
    (* x x))

(define (square-list items)
(define (iter things answer)
(if (null? things)
answer
(iter (cdr things)
(cons answer (square (car things))
))))

(iter items '()))

(define list1 (list 1 2 3))
(square-list list1)
;> > > > (((() . 1) . 4) . 9) 这个与之前练习2_18的情况一样