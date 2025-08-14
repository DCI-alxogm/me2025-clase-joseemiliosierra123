Algoritmo num_par_impar
	Repetir
		Escribir 'Ingresa un numero'
		Leer numero
		Si numero MOD 2=0 Entonces
			Escribir 'El numero ',numero,'es par'
		SiNo
			Escribir 'El numero ',numero,'es impar'
		FinSi
		Escribir '¿Quieres ingresar otro numero? (S/N)'
		Leer contador
	Hasta Que contador<>'S' Y contador<>'s'
FinAlgoritmo
