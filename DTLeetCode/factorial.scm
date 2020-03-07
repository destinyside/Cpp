#!/usr/bin/scheme --script
(define (factorial n)
  (define (fact-iter n ans)
    (if (> n 0) (fact-iter (- n 1) (* ans n)) ans))
  (fact-iter n 1))

(define string-numeric?
  (lambda (x)
    (if (string? x)
    (let ([p #t])
      (map (lambda (y) (set! p (and p y)))
	     (map char-numeric? (string->list x)))
      p)
	 #f)))

(define numbers (cdr (command-line)))
(display numbers)
(newline)
(map (lambda (x) 
       (display x)
       (display " ")
       (if (string-numeric? x)
	   (begin 
	     (display (string->number x))
	     (display (factorial (string->number x))))
	   #f)
	   (newline)) 
     numbers)
