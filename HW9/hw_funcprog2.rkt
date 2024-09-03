;;;
; CSE240 Functional Programming 2 Homework
; (fill in)
;
; Completion time: (3 hours)
;
; @version (8.12)
;;;


; Q1
(define (sumEven lst)
  (if (null? lst)
      0
      (+ (if (even? (car lst)) (car lst) 0)
         (sumEven (cdr lst)))))

((lambda (lst)
   (define (sumEven-inner lst poop)
     (if (null? lst)
         poop
         (sumEven-inner (cdr lst)
                       (+ poop (if (even? (car lst)) (car lst) 0)))))
   (display (sumEven-inner lst 0)))
 '(1 3 -4 5 6 -7)) ; Should return 2
(newline)

; Q2
(define (list-push-back lst new-list)
  (append lst new-list))

(display (list-push-back '(4 3 7 1 2 9) '(1 2))) ; should append to the back making the array (4 3 7 1 2 9 1 2)
(newline)

; Q3
(define (list-push-front lst new-list)
  (append new-list lst))

(display (list-push-front '(4 3 7 1 2 9) '(1 2))) ; should append to the front making the array (1 2 4 3 7 1 2 9)
(newline)

; Q4
(define (list-draw-front n lst)
  (if (<= n 0)
      '()
      (cons (car lst) (list-draw-front (- n 1) (cdr lst)))))
(display (list-draw-front 3 '(4 3 7 1 2 9))) ;returns n amount of elemnents in this case it should return (4 3 7)
(newline)

; Q5
(define (list-draw-back n lst)
  (if (<= n 0)
      '()
      (if (= n (length lst))
          lst
          (list-draw-back n (cdr lst)))))

(display (list-draw-back 3 '(4 3 7 1 2 9))) ;returns n amount of elemnents in this case it should return (1 2 9)
(newline)

; Q6
(define (list-shuffle lst1 lst2)
  (if (or (null? lst1) (null? lst2))
      '()
      (cons (car lst1)
            (cons (car lst2)
                  (list-shuffle (cdr lst1) (cdr lst2))))))

(display (list-shuffle '(1 2) '(a b))) ;should append both arrays to eachother with alternating elements