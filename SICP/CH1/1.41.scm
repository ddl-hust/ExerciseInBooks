; double a procedure

(define (double procedure)
 (lambda (x) (procedure (procedure x) )))

((double 1+) 1)