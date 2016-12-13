;1 4 5
(format t "Bibliothèque du TD4/ TD4.lisp / Par D. Thenot")

;Exercice 1 : Prendre n'importe quel nombre d'arguments et renvoie le nombre d'arguments passer à la fonction.
(defun countArgs (&rest args)
  (length args)
)

;Exercice 4 : prend un nom de fichier liste de chaine de caractères représentant chaque ligne du fichier.
;(defun countLigne (nomFichier)
;  (with-open-file (monStream (make-pathname :name nomFichier) :direction :input)
;		  (do

