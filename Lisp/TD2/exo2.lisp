(format t "exo2.lisp")
(defun Question (chaine)
        (format t "~A" chaine)
        (read)
)
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
;Exercice 5
