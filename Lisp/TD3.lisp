(format t "TD3/ Bibliothèque par Damien T.")
;exercice 3 récursif
;(pos+ '(7 5 1 4))
;(7 6 3 7)
;(defun pos+rec(lst)
;  (if (= (length lst) 1)
;    lst
;    (push lst (pos+rec (subsep lst 0 (- length 1))))
;    )
;  )
;)

;Correction
(defun pos+rec (liste)
  (if (or (not (listp liste)) (null liste))
    nil
    (and (numberp (car liste))
      (if (= 1 (length liste))
        liste
        (append (pos+rec (subseq liste 0 (- (length liste) 1)))
                (list (+ (car (last liste)) (- (length liste) 1))))))))

;Exercice 3 b) itérative
(defun pos+it(lst)
  (progn
    (dolist (tmp lst)
    (let ((x 0))
       (setf (nth x lst) (+ (nth x lst) x))
       (setf x (1+ x))
    ))
    lst
  )
)

;Correction
;(defun pos+_it(l)
;  (let ((l2 nil))
;    (do ((i 0 (+ i 1)) (l1 l(cdr l1)))
;    ((= i (length l)) 'done)
;    (setf l2 (append l2 (list(+ (car l1) i)))))
;    )
;)

(defun pos+iter(liste)
  (if (not (listp liste))
    nil
    (let ((incr 0))
      (dolist (tmp liste liste)
          (setf tmp (+ tmp incr))

      )
      (setf incr (+ incr 1))
)))


; EXERCICE 3

(defun pos+rec (l)
	(if  (listp l)
		(if (or (null l) (= (length l) 1))
			l
			(if (not (numberp (car l)))
				nil
				(append  (pos+rec(subseq l 0 (- (length l) 1 )))  (list (+ (- (length l) 1) (car(last l)))) )
			)
		)
	)
)
(defun pos+it (l)
	(if  (listp l)
		(if (null l)
			l 	;on retourne la liste si elle est vide
			(let (tmp)
				(dolist (x l)
					(if (not (numberp (car l)))
						(return nil)
					)
					(setf tmp (append tmp  (list(+ x (length tmp))) ) )
				)
				(setf l tmp)
			)
		)
	)
)

(defun pos+map (l)
	(if  (listp l)
		(if (null l)
			l
			(let ((i -1))
				(mapcar #'(lambda(x)
					(setf i (+ i 1))
					(+ x i)	;Dernière instruction qui est évaluée et entraine l'impression du resultat de l'evalution
						)
				l
				)
			)
		)
	)
)

; EXERCICE 4

(defun interspace-it (elt lst)
	(if (not (listp lst))
		nil
		(if (null lst)
			nil
			(let (tmp)
				(dolist (x lst)
					(if (null (cdr lst))
						(setf tmp (append tmp (list x)))
						(progn
							(setf tmp (append tmp  (list x)))
							(setf tmp (append tmp  (list elt)))
						)
					)
				)
			(setf l tmp)
			)
		)
	)
)

(defun interspace-rec (elt lst)
	(if (not (listp lst))
		nil
		(if (null lst)
			nil
			(let (tmp)
				(if (null (cdr lst))
					(setf tmp (append tmp (list (car lst))))
					(setf tmp (append tmp (list (car lst) elt) (interspace-rec elt (cdr lst))))

				)
			)
		)
	)
)

; EXERCICE 2
;Créer un vecteur avec "vector", ex: (vector 1 2 .... N) // Ne pas faire comme avec un make-array pour l'initialisation
; de valeur avec vector.
;Création de vecteur avec make-array avec un tableau de 1 dimension

(defun precede-rec (obj vec)
	(if (or (not (vectorp vec)) ( = (length vec) 1))
		nil
		(let (lst)
			(if (not ( = (length vec) 1))
				(if (equal obj (aref vec 1)) ;member pour vérifier si on ajoute pas un doublon
					(progn
						(setf lst (append lst (list  (aref vec 0)) (remove (aref vec 0) (precede-rec obj (subseq vec 1))) ))
					)
					(setf lst (append lst (precede-rec obj (subseq vec 1))))
				)
				(setf lst nil)
			)
		)
	)
)

(defun precede-it (obj vec)
	(if (or (not (vectorp vec)) ( = (length vec) 1))
		nil
		(let (lst)
			(do ((tmp  vec (subseq tmp 1)))
				((= (length tmp) 1) nil lst)
				(when (equal obj (aref tmp 1)) ;member pour vérifier si on ajoute pas un doublon
					(setf lst (remove (aref tmp 0) lst))
					(setf lst (append lst (list (aref tmp 0))))
				)
			)
		)
	)
)


; EXERCICE 1

(defun min-max (vec)
	(if (not (vectorp vec))
		nil		   ; Cas d'arret de ma fonction récurssive (le cas ou vec == NIL)
	  (let (lst (min (aref vec 0)) (max (aref vec 0))) ;Le couple sera représenté par une liste;			
	    (if (not (= (length vec) 1))
				(progn
					(if (> min (car(min-max (subseq vec 1))))
						(setf min (car(min-max (subseq vec 1))))
						min
					)
					(if (< max (cadr(min-max(subseq vec 1))))
						(setf max (cadr(min-max (subseq vec 1))))
						max
					)
					(setf lst (list min max))
				)
				(setf lst (list min max))
			)
		)
	)
)

;(defun min-max-labels(vec)
;  (if (not (vectorp vec))
;      nil
;   (labels ((getMin(vec min) (progn (if (< (svref vec 0) min) 
;				  (setf min (svref vec 0)))
;				(getMin (subseq vec 1) min)))
;	     (getMax(vec max) (progn (if (> (svref vec) max)
;					 (setf max (svref vec 0))
;				       )
;				     (getMax (subseq vec 1) max))))
;	    (list (getMin vec (svref vec 0)) (getMax vec (svref vec 0)))
;)))
   

(defun corr_interspace_rec(elt liste)
  (if (or (not (listp liste)) (null liste))
      nil
    (if (null (cdr liste))
	(liste (car liste))
      (append (list (car liste) elt)
	      (corr_interspace_rec elt (cdr liste)))
    )
  )
)

;Correction sans labels exercice 1
(defun minmax (vect) 
  (let ((len (length vect)))
	(cond
	 ((= 0 len) nil)
	 ((= 1 len) (list (svref vect 0) (svref vect 0)))
	 (t (list (min (svref vect 0) (car (minmax (subseq vect1))))
		  (max (svref vect 0) (cadr (minmax (subseq vect 1)
						    )
					    )
		       )
		  )
	    )
	 )
	)
  )

(defun minmax2(vect)
  (labels ((mini (x y)
		(if (< x y) x y))
	   (maxi(x y)
		(if (< x y) y x)))
	  (let ((len (length vect)))
	    (cond 
	     ((= 0 len) nil)
	     ((= 1 len) (list (svref vect 0) (svref vect 0)))
	     (t (list (mini (svref vect 0) (car (minmax2 (subseq vect 1))))
		      (maxi (svref vect 0) (cadr (minmax2 (subseq vect 1))))))))))


;Exercice 2 perso
(defun precede_it(obj vect) (let ((res nil))
			      (dotimes (c (length vect) 'done)
				(if (= c 0) ()
				(if (and (eql obj (aref vect c)) (not (find (aref vect (- c 1)) res)))
				    (setf res (cons (aref vect (- c 1)) res))
				  )
				))
			      (sort res #'char-lessp)
			      )
)
