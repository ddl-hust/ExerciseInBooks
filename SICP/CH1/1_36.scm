;需要1_22一些知识，输出换行符，显示信息
;将不动点数据都打印出来

;不动点定义
(define tolerance 0.00001)

(define (fixed-point f first-guess)

(define (close-enough? v1 v2)
(< (abs (- v1 v2))
tolerance))

(define (try guess)
    (let ((next (f guess)))
    (display next)
    (newline)
    (if (close-enough? guess next)
    next
    (try next))))

(try first-guess)

)


;显示更加漂亮版本
(define tolerance 0.000001)

(define (fixed-point f first-guess)
                
    (define (close-enough? v1 v2)
        (< (abs (- v1 v2)) tolerance))

    (define (try guess step)
        (display-info guess step)                       ; 每次进入测试时打印一次猜测
        (let ((next (f guess)))
            (if (close-enough? next guess)
                (begin                                  ; begin用于执行多条语句,返回next
                    ;(display-info next (+ 1 step))      ; 
                    next)
                (try next (+ 1 step)))))

    (try first-guess 1))

(define (display-info guess step)
    (display "Step: ")
    (display step)
    (display " ")
    
    (display "Guess: ")
    (display guess)
    (newline))

(define formula (lambda (x) (/ (log 1000) (log x)))
    )

; (define find-log
;     (fixed-point formula
;     2
;     ))

;平均阻尼函数
(define (average-damp f)
    (lambda (x)
        (average x 
                 (f x))))
(define (average x y )
    (/ (+ x y) 2))

;添加平均阻尼之后对比
(define find-log-avarge 
    (fixed-point (average-damp formula)
    2
    ))

;几个问题，为什么加了damp 收敛变快了?