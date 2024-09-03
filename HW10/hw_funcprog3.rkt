;;;
; CSE240 Functional Programming 3 Homework
; (fill in)
;
; Completion time: (4 hours)
;
; @version (8.12)
;;;


;Q1
; enter your code here:
(define OR-GATE (lambda (a b)
  (if (or (equal? a 1) (equal? b 1))
    1
    0
    )
  )
 )
                  
(define AND-GATE (lambda (a b)
  (if (and (equal? a 1) (equal? b 1))
    1
    0
   )
  )
 )

(define NOT-GATE (lambda (a)
(if (= a 0)
1
0
    )
  )
)
; Test cases
(display "AND-Gate Output\n")
(AND-gate 0 0)
(AND-gate 0 1)
(AND-gate 1 0)
(AND-gate 1 1)
; Expected outputs
;0
;0
;0
;1
; Test cases
(display "OR-Gate Output\n")
(OR-gate 0 0)
(OR-gate 0 1)
(OR-gate 1 0)
(OR-gate 1 1)
; Expected outputs
;0
;1
;1
;1
; Test cases
(display "NOT-Gate Output\n")
(NOT-gate 0)
(NOT-gate 1)
; Expected outputs
;1
;0

; Q2
; enter your code here:
(define XOR-GATE (lambda (a b)
  (if (equal? (OR-GATE a b) 1)
    (if (equal? (AND-GATE a b) 1)
      0
      1
    )
    0
  )
))
; Test cases
(display "XOR-Gate Output\n")
(XOR-gate 0 0)
(XOR-gate 0 1)
(XOR-gate 1 0)
(XOR-gate 1 1)
; Expected outputs
;0
;1
;1
;0

;Q3.1
; enter your code here:
(define half-adder (lambda (x a b)
  (XOR-GATE (XOR-GATE a b) x)
))

;Q3.2
; enter your code here:
(define carry-out (lambda (x a b)
  (OR-GATE (AND-GATE a b) (AND-GATE (XOR-GATE a b) x))
))

;Q3.3
; enter your code here:
(define full-adder (lambda (x a b)
  (cons (carry-out x a b) (half-adder x a b) )
))
; Test cases
(Display "half-adder Output\n")
(half-adder 0 0 0) 	
(half-adder 0 0 1) 	
(half-adder 0 1 0) 	
(half-adder 0 1 1)	
(half-adder 1 0 0) 	
(half-adder 1 0 1)	
(half-adder 1 1 0) 	
(half-adder 1 1 1)

; Expected outputs
;0
;1
;1
;0
;1
;0
;0
;1


; Test cases
(Display "fullAdder Output\n")
(full-adder 0 0 0) 	
(full-adder 0 0 1) 	
(full-adder 0 1 0) 	
(full-adder 0 1 1)	
(full-adder 1 0 0) 	
(full-adder 1 0 1)	
(full-adder 1 1 0) 	
(full-adder 1 1 1)

; Expected outputs
;(0 . 0)
;(0 . 1)
;(0 . 1)
;(1 . 0)
;(0 . 1)
;(1 . 0)
;(1 . 0)
;(1 . 1)


;Q4.1
; enter your code here:
(define tail (lambda (lst)
  (list-ref lst (- (length lst) 1))
))



;Q4.2
(define rmtail (lambda (lst)
  (reverse (cdr (reverse lst)))
))


;Q4.3
; Step 1 size-n problem: Lines of code
; ----> size-n is the total number of bits to be added

; Step 2 Stopping condition: Lines of code
; ----> stopping condition is when the most significant bit (MSB) has been added

; Step 3 size-m problem: Lines of code
; ----> assume all bits before the MSB (n-1) have been added with the carry-in to the MSB being 1 or 0 

; Step 4: Lines of code 
; ----> add the MSB from the two lists plus the carry-in, append to size n-1 list, detect if there is an overflow and return result


;Q4.4
; enter your code here:
(define n-bit-adder (lambda (L1 L2 n) ;size n problem
  (n-bit-adderh L1 L2 n (cons '() 0)) ;code for constructing the size-n problem
                      )
  )
                      
(define n-bit-adderh (lambda (L1 L2 n resulti) 
  (if (equal? n 0) ; stopping condition
    (n-bit-adder-format resulti) ;construction of thesize m problem
    (let ((sum-carry (full-adder (cdr resulti) (tail L1) (tail L2))))
      (let ((sum (cdr sum-carry)) (carry (car sum-carry)))
        (n-bit-adderh (rmtail L1) (rmtail L2) (- n 1) (cons (append (list sum) (car resulti)) carry))
        )
      )
    )
  )
)
                       
(define n-bit-adder-format (lambda (resulti)
  (append (list (list (cdr resulti))) (car resulti)) ; solution to size n-problem
))

;Test cases
(define x1 '(0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0) )	
(define x2 '(1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1) )	
(define x3 '(0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1) )	
(define x4 '(1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0) )
(define x5 '(1 1 0 1 0 1 0 1 0 1 0 1 0 1 1 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 1 1) )	
(define x6 '(1 1 1 0 0 0 1 1 1 0 0 0 1 1 1 0 0 0 1 1 1 0 0 0 1 1 1 0 0 0 1 0) )


(display "n-bit-adder Output\n")
(n-bit-adder  x1 x2 32)
(n-bit-adder  x3 x4 32)
(n-bit-adder  x5 x6 32)
(n-bit-adder  x2 x3 32)
(n-bit-adder  x4 x5 32)
(n-bit-adder  x1 x6 32)
; Expected outputs
;(0 (1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1))
;(0 (1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1))
;(1 (1 0 1 1 1 0 0 0 1 1 1 0 0 1 0 1 1 0 0 0 1 1 1 0 0 0 1 1 1 0 0 1))
;(1 (0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 0))
;(1 (1 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1))
;(0 (1 1 1 0 0 0 1 1 1 0 0 0 1 1 1 0 0 0 1 1 1 0 0 0 1 1 1 0 0 0 1 0))


;Q5 boilerplate (implementations for reduce and filter)
(define reduce
	  (lambda (op base x) ;passing by name
		(if (null? x)
			base
			(op (car x) (reduce op base (cdr x))))))

(define filter (lambda (pred a-list)
	(if (null? a-list)
	    '()
	    (if	(pred (car a-list))
			(cons (car a-list) (filter pred (cdr a-list)))
			(filter pred (cdr a-list)))))) 


;Q5.1
; enter your code here:
(define (number-length lst)
  (length (filter integer? lst)))
;Q5.2
; enter your code here:
(define (count-zeros lst)
  (length (filter (lambda (x) (= x 0)) lst)))

;Q5.3
; enter your code here:
(define (binary->string lst) (list->string (map (lambda (x) (if (= x 0) #\0 #\1)) lst)))
(display (number-length '(1 1 0 1 0 0))) ; Output: 6
(newline)

(display (count-zeros '(1 1 0 1 0 0)))   ; Output: 3
(newline)

(display (binary->string '(1 1 0 1 0 0))) ; Output: "110100"