Algoritmo Ecuacion_cuadratica
	Definir x1,x2,xi1,xi2,a,b,c,discr Como Real
	Definir contador Como Caracter
	Repetir
		Escribir 'Ingresa a, b, c'
		Leer a,b,c
		Si a=0 Entonces
			Si b<>0 Entonces
				x1 <- -c/b
				Escribir x1
			SiNo
				Escribir 'Solución tribial'
			FinSi
		SiNo
			discr <- b^2-4*a*c
			Si discr>0 Entonces
				x1 <- (-b+raiz(discr))/(2*a)
				x2 <- (-b-raiz(discr))/(2*a)
				Escribir x1,x2
			SiNo
				x1 <- -b/(2*a)
				x2 <- x1
				xi1 <- raiz(abs(discr))/(2*a)
				xi2 <- -xi1
				Escribir x1+xi1,x2+xi2
			FinSi
		FinSi
		Escribir '¿Quieres ingresar otro numero? (S/N)'
		Leer contador
	Hasta Que contador<>'S' Y contador<>'s'
FinAlgoritmo
