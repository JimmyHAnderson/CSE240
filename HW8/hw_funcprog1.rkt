;;;
; CSE240 Functional Programming 1 Homework
; This assignment involves pracicing various expressions and procedures in Scheme.
; 
; For the first assignment, we are providing the default header so you can see how it
; looks in Scheme. For future assignments, you will need to add it yourself.
;
; Completion time: (3 hours)
;
; @version (8.12)
;;;


; Q1
;1 9 - 2 + 5 
(+ 5 (- 9 2))
;2 5 * ( 6 + 12 + 5 ) – 25
(- (* 5 (+ 6 (+ 12 5))) 25)
;3 7 * (( 5 - ( 1 * 3 )) + ( 2 * 4 ) )
(* 7 (+ (- 5 (* 1 3)) (* 2 4)))
;4 3 * ( 4 + ( ( ( 6 * 6 ) + ( 6 * 6 ) ) / ( 10 + 2 ) ) )
(* 3 (+ 4 (/ (+ (* 6 6) (* 6 6)) (+ 10 2))))
;5  ((((((4 + 6)*(6 + 4))/ 2)/ 2)– 5) / 2 ) + ((((4 * 5) + (5 * 4)) / 2) + (4 * 5))
(+ (/ (/ (/ (/ (+ (* (+ 4 6) (+ 6 4)) 2) 2) 2) 5) 2) (+ (/ (+ (/ (+ (* 4 5) (* 5 4)) 2) (* 4 5)))))

; Q2
(define (add a b)
  (+ a b))

; Q3

(define (square-helper n currentSum)
  (if (= n 0) ; The code for stopping condition and its return value are: 
      0
      (add currentSum (square-helper( - (abs n) 1) currentSum ) ))) ; The code for size-m problem is:
 
     

(define (square n)  ; The code for size-n problem is:
  (square-helper (abs n) (abs n) ))   ; The code for constructing size-n problem is:

(square 5)  ; Output should be 25
 (square 7)  ; Output should be 49
(square -5)  ; Output should be 25
; Q4
(define (read-for-square)
  (square (read)))
(read-for-square) ; calls upon the read-for-square in order to take input
; Q5
(define (diff-squares)
  (- (read-for-square) (read-for-square)))
(diff-squares) ;calls upon the the diff squares

; Q6
(define (sum-odds max)
  (if (<= max 0)
      0
      (if (odd? max) ;checks to see if the value is odd
          (+ max (sum-odds (- max 1))) ; if it is odd then we add and subtract from the max in order to get a new value
          (sum-odds (- max 1))))) ; if the value is even then we simply just decrement 
(sum-odds (read)) ; calls upon the function so if we input 10 we should get 25 as the output

; Q7
(define (fib a)
  (cond ((= a 0)
         0)
        ((= a 1)
         1)
        (else
         (+ (fib (- a 1)) (fib (- a 2))))))
(fib (read)) ; calls upon the function fib 0) should give 0, (fib 9) should give 34.