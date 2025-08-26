Algoritmo Ago_26_serie_Taylor
	Definir op,nmax,n,fact,factr,residuo Como Entero
	Definir x,h,x0,f,valorreal,xi,c,u,e1,e2 Como Real
	n <- 0
	fact <- 1
	Escribir 'Escoge qué función quieres aproximar'
	Escribir '1. e^x, 2. sen(x), 3. cos(x), 4. sqrt(1+x), 5. ln(1+x)'
	Leer op
	Escribir 'Ingresa el punto en el que deseas calcular el valor de tu función'
	Leer x
	Escribir 'Ingresa tu valor de h'
	Leer h
	x0 <- x-h
	xi <- (x+x0)/2
	Escribir 'Ingresa el número de aproximaciones que deseas'
	Leer nmax
	Segun opcion op  Hacer
		1:
			// e^x
			valorreal <- exp(x)
			Mientras n<nmax Hacer
				Si n=0 Entonces
					f <- exp(x0)
					r <- exp(xi)*h
					error <- valorreal-f
					Escribir f,r,error
				SiNo
					fact <- fact*(n+1)
					factr <- fact*(n+2)
					n <- n+1
					f <- f+(exp(x0)*h^n)/fact
					r <- (exp(xi)*h^(n+1))/factr
					error <- valorreal-f
					Escribir f,r,error
				FinSi
			FinMientras
		2: // sen(x)
			valorreal <- sen(x)
			Mientras n<nmax Hacer
				residuo <- n MOD 4
				Segun opcion residuo  Hacer
					0:
						// sen(x)
						Si n=0 Entonces
							f <- sen(x0)
							r <- cos(xi)*h
							error <- valorreal-f
							Escribir f,r,error
						SiNo
							f <- f+(sen(x0)*h^n)/fact
							r <- (cos(xi)*h^(n+1))/factr
							error <- valorreal-f
							Escribir f,r,error
						FinSi
					1: // cos(x)
						f <- f+(cos(x0)*h^n)/fact
						r <- (-sen(xi)*h^(n+1))/factr
						error <- valorreal-f
						Escribir f,r,error
					2: // -sen(x)
						f <- f+(-sen(x0)*h^n)/fact
						r <- (-cos(xi)*h^(n+1))/factr
						error <- valorreal-f
						Escribir f,r,error
					3: // -cos(x)
						f <- f+(-cos(x0)*h^n)/fact
						r <- (sen(xi)*h^(n+1))/factr
						error <- valorreal-f
						Escribir f,r,error
				FinSegun
				fact <- fact*(n+1)
				factr <- fact*(n+2)
				n <- n+1
			FinMientras
		3: // cos(x)
			valorreal <- cos(x)
			Mientras n<nmax Hacer
				residuo <- n MOD 4
				Segun opcion residuo  Hacer
					0:
						// cos(x)
						Si n=0 Entonces
							f <- cos(x0)
							r <- -sen(xi)*h
							error <- valorreal-f
							Escribir f,r,error
						SiNo
							f <- f+(cos(x0)*h^n)/fact
							r <- (-sen(xi)*h^(n+1))/factr
							error <- valorreal-f
							Escribir f,r,error
						FinSi
					1: // -sen(x)
						f <- f+(-sen(x0)*h^n)/fact
						r <- (-cos(xi)*h^(n+1))/factr
						error <- valorreal-f
						Escribir f,r,error
					2: // -cos(x)
						f <- f+(-cos(x0)*h^n)/fact
						r <- (sen(xi)*h^(n+1))/factr
						error <- valorreal-f
						Escribir f,r,error
					3: // sen(x)
						f <- f+(sen(x0)*h^n)/fact
						r <- (cos(xi)*h^(n+1))/factr
						error <- valorreal-f
						Escribir f,r,error
				FinSegun
				fact <- fact*(n+1)
				factr <- fact*(n+2)
				n <- n+1
			FinMientras
		4: // sqrt(1+x)
			valorreal <- rc(1+x)
			u <- 1+x0
			c <- 0.5
			Si x0<(-1) Entonces
				Escribir 'Función no definida en el parámetro ingresado'
			SiNo
				Mientras n<nmax Hacer
					Si n=0 Entonces
						f <- rc(u)
						r <- c*(1+xi)^(c-1)*h
						error <- valorreal-f
						Escribir f,r,error
					SiNo
						e1 <- c-n+1
						e2 <- c-n
						f <- f+((e1*u^(e2))*h^n)/fact
						r <- ((e2*(xi+1)^(e2-1))*h^(n+1))/factr
						error <- valorreal-f
						Escribir f,r,error
					FinSi
					fact <- fact*(n+1)
					factr <- fact*(n+2)
					n <- n+1
				FinMientras
			FinSi
		5: // ln(1+x)
			valorreal <- ln(1+x)
			u <- 1+x0
			Si x0<=(-1) Entonces
				Escribir 'Función no definida en el parámetro ingresado'
			SiNo
				Mientras n<nmax Hacer
					Si n=0 Entonces
						f <- ln(u)
						r <- (1+xi)^(-1)*h
						error <- valorreal-f
						Escribir f,r,error
					SiNo
						Si n=1 Entonces
							f <- u^(-n)*h
							r <- ((-1)*(1+xi)^(-2)*h^2)/2
							error <- valorreal-f
							Escribir f,r,error
						SiNo
							f <- ((-n+1)*u^(-n)*h^n)/fact
							r <- ((-n)*(1+xi)^(-n-1)*h^(n+1))/factr
							error <- valorreal-f
							Escribir f,r,error
						FinSi
					FinSi
					fact <- fact*(n+1)
					factr <- fact*(n+2)
					n <- n+1
				FinMientras
			FinSi
		De Otro Modo:
			Escribir 'Opción no valida'
	FinSegun
FinAlgoritmo
