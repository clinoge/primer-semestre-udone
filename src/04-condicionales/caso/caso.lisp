(defvar *numero*)
(format t "Introduzca un numero: ")
(finish-output)
(setq *numero* (read))

(cond 
    ((= *numero* 0) (format t "Numero neutro con respecto a la suma~%"))
    ((= *numero* 1) (format t "Numero neutro con respecto a la multiplicacion~%"))
    ((= *numero* 2) (format t "Base del sistema binario~%"))
    ((= *numero* 3) (format t "Lados del triangulo~%"))
    ((= *numero* 4) (format t "Casas de Hogwarts~%"))
    ((= *numero* 5) (format t "Puntas de una estrella~%"))
    ((= *numero* 6) (format t "Primer numero perfecto~%"))
    ((= *numero* 7) (format t "Numero magico~%"))
    (t (format t "Solo se imprimen resultados para numeros del 0 al 7~%")))