Algoritmo Serie_Mclaurin
	Definir n,m,fact Como Entero
	Definir x,error,errorlimite,aproxant,aproxact Como Real
	Leer x,errorlimite
	n <- 0
	fact <- 1
	error <- 100
	m <- 1000
	Mientras (error>errorlimite) Hacer
		Si n=0 Entonces
			aproxact <- 1
			Escribir aproxact
		SiNo
			aproxant <- aproxact
			aproxact <- ((x^n)/fact)+aproxact
			fact <- fact*(n+1)
			error <- (aproxact-aproxant)/aproxact
			Escribir aproxact,error
		FinSi
		n <- n+1
	FinMientras
FinAlgoritmo
