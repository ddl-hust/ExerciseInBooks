;reverse list
(define (reverse items)
    (define (iter items result)
    (if (null?  items)
        result
        (iter (cdr items) (cons (car items ) result))
    ))
    (iter items '()))




(define list1 (list 1 2 3))
(reverse list1)