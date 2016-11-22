(format t "exo2.lisp, bibliothéque par Damien T.")
;Exercice 2
;Erreur (defun carre(x) (if(< 5 x) (return-from carre (* x x))))
(defun carre(x) (if (and (integerp x) (<= x 5) (> x 0))(format t "Pas de calcule") (* x x)))
;exo 3
(defun mystere(X Y) (if(null Y) nil (if (eql (car Y) X) 0 (let ((Z (mystere X (cdr Y)))) (and Z (+ Z 1))))))
(defun mysterecond(X Y) (cond ((null Y) nil) ((eql (car Y) X) 0) (t (let ((Z (mystere X (cdr Y)))) (and Z (+ Z 1))))))
;Exercice 4
(defun min-max(lst) (let ((max (car lst)) (min (car lst)))
                          (progn (dolist (x lst)
                                  (if(> x max) (setf max x))
                                  (if(< x min) (setf min x))
                                  )
                                  (format t "max : ~A, min : ~A" max min)
                          )
                    )
                    )
;Correction min-max
;(defun min-max(list)
;  (if (or (not (listp list)) (null list))
;    nil
;    (let ((min (car list)) (max (car list)))
;    (dolist (tmp (cdr list))
;      (if (> tmp max)
;      (setf max tmp))
;      (if (< tmp min)
;      (setf min tmp))
;    )
;    (format t "~A ~A" min max)
;    )))
;Exercice 5
(defun maxi(lst)
  (let ((max1 (car lst)) (max2 (car lst)))
        (progn
          (dolist (x lst)
            (if (> x max1)
              (setf max1 x)
            )
          )
          (dolist (x lst)
            (if (and (< x max1) (> x max2))
              (setf max2 x)
            )
          )
          (* max1 max2)
        )
  )
)

;Exercice 6
(defun rever(lst)
  (let (tmp)
    (progn
      (dolist (x lst)
        (setf tmp (cons x tmp))
        )
        tmp
    )
  )
)
