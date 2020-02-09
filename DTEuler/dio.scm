
(define (pr x y z) 
  (display i)
  (display " ")
  (display j)
  (display " ")
  (display k)
  (display " ")
  (newline)
  )
(define (dio num)
  (let ([maxm num]
	[maxx 0]
	[imax 4294967296]
	[d 0]
	[t 0]
	[i 0]
	[j 0]
	[k 2])
    (do () 
      ((= j maxm) 'break)
      (set! k 2)

      (do ()
	((= k imax) 'break)
	(display k)
	(display " ")
	(newline)
	(cond
	  ((integer? (sqrt j)) 'continue)
	  (else
	    (let ([cnt j*k*k+1])
	      (if (integer? (sqrt cnt))
		(begin
		  (pr i j k)
		  (set! k imax))
		'else))))
	(set! k (+ k 1)))
      (set! j (+ j 1))))
  )

(dio 10)
