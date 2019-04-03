(defun hello () 
 (concatenate 'string "hello " (read-line))

)
(format t (hello))
