(defun factorial (n)
;; n!
   (cond ((zerop n)  1)
          (t (* n  (factorial (- n 1) ))
          )
   )
)

(defun fib (n)
   (cond 
        ((or (zerop n) (eql n 1))  1         )
        ( t (+ (fib (- n 1)) (fib (- n 2))))
   )
)