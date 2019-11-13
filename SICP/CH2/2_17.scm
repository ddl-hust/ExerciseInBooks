;2.17 last-element of list
; (define (lenth items)
;     (if (null? items)
;         0
;         (+ 1 (lenth (cdr items))))
; )
; (define list1 (list 1 2 3))
; (lenth list1)

(define (last-element items)
        (if (null? (cdr items))
            items
            (last-element (cdr items)))
    )
(define list1 (list 1 2 3))
(last-element list1)

;最先想到使用lenth 来辅助判断
;进一步 发现不需要 直接判断最后一个元素的cdr即可