#include<stdio.h>
#include<math.h>

int main(){
    int op, nmax, n, fact=1, factr, residuo;
    float x, h, x0, f, valorreal, xi, c, u, e1, e2, r, error;
    
    printf("Escoge la función que deseas aproximar: \n1. e^x \n2. sen(x) \n3. cos(x) \n4. sqrt(1+x) \n5. ln(1+x) \n");
    scanf("%i",&op);
    printf("Ingresa el punto en el que deseas calcular el valor de tu función: \n");
    scanf("%f",&x);
    printf("Ingresa tu valor de h (incremento): \n");
    scanf("%f",&h);
    printf("Ingresa el número de aproximaciones que deseas: \n");
    scanf("%i",&nmax);
    
    x0=x-h;
    xi=(x+x0)/2;
    
    switch(op){
        case 1: //e^x
            valorreal = exp(x);
            printf("Valor real de la función: %f\n", valorreal);
            for(n=0; n<nmax; n++){
                if (n==0){
                    f = exp(x0);
                    r = exp(xi)*h;
                }
                else{
                    fact = fact*(n+1);
                    factr = fact*(n+2);
                    f = f + (exp(x0)*pow(h,n))/fact;
                    r = (exp(xi)*pow(h, n+1))/factr;
                }
                error = valorreal - f;
                printf("Aproximación %i, valor de la función: %f, residuo: %f, diferencia del valor real: %f\n", n, f, r, error);
            }
            break;
            
        case 2: //sen(x)
            valorreal = sin(x);
            printf("Valor real de la función: %f\n", valorreal);
            for(n=0; n<nmax; n++){
                residuo = n%4;
                switch (residuo){
                    case 0: //sen(x)
                        if (n==0){
                            f = sin(x0);
                            r = cos(xi)*h;
                        }
                        else {
                            f = f + (sin(x0)*pow(h, n))/fact;
                            r = (cos(xi)*pow(h, n))/factr;
                        }
                        break;
                    case 1: //cos(x)
                        f = f + (cos(x0)*pow(h, n))/fact;
                        r = (-sin(xi)*pow(h, n+1))/factr;
                        break;
                    case 2: //-sen(x)
                        f = f + (-sin(x0)*pow(h, n))/fact;
                        r = (-cos(xi)*pow(h, n+1))/factr;
                        break;
                    case 3: //-cos(x)
                        f = f + (-cos(x0)*pow(h, n))/fact;
                        r = (sin(xi)*pow(h, n+1))/factr;
                        break;
                }
                fact = fact*(n+1);
                factr = fact*(n+2);
                error = valorreal - f;
                printf("Aproximación %i, valor de la función: %f, residuo: %f, diferencia del valor real: %f\n", n, f, r, error);
            }
            break;
        
        case 3: //cos(x)
            valorreal = cos(x);
            printf("Valor real de la función: %f\n", valorreal);
            for(n=0; n<nmax; n++){
                residuo = n%4;
                switch (residuo){
                    case 0: //cos(x)
                        if (n==0){
                            f = cos(x0);
                            r = -sin(xi)*h;
                        }
                        else {
                            f = f + (cos(x0)*pow(h, n))/fact;
                            r = (-sin(xi)*pow(h, n))/factr;
                        }
                        break;
                    case 1: //-sen(x)
                        f = f + (-sin(x0)*pow(h, n))/fact;
                        r = (-cos(xi)*pow(h, n+1))/factr;
                        break;
                    case 2: //-cos(x)
                        f = f + (-cos(x0)*pow(h, n))/fact;
                        r = (sin(xi)*pow(h, n+1))/factr;
                        break;
                    case 3: //sen(x)
                        f = f + (sin(x0)*pow(h, n))/fact;
                        r = (cos(xi)*pow(h, n+1))/factr;
                        break;
                }
                fact = fact*(n+1);
                factr = fact*(n+2);
                error = valorreal - f;
                printf("Aproximación %i, valor de la función: %f, residuo: %f, diferencia del valor real: %f\n", n, f, r, error);
            }
            break;
            
        case 4: //sqrt(1+x)
            valorreal = sqrt(1+x);
            u = 1+x0;
            c = 0.5;
            if (x0<-1){
                printf("La función no está definida en el punto ingresado\n");
            }
            else {
                for (n=0; n<nmax; n++){
                    if (n==0){
                        f = sqrt(u);
                        r = c*pow(xi+1, c-1)*h;
                    }
                    else {
                        e1 = c-n+1;
                        e2 = c-n;
                        f = f + (e1 * pow(u, e2) * pow(h, n))/fact;
                        r = (e2 * pow(xi+1, e2-1) * pow(h, n+1))/factr;
                    }
                fact = fact*(n+1);
                factr = fact*(n+2);
                error = valorreal - f;
                printf("Aproximación %i, valor de la función: %f, residuo: %f, diferencia del valor real: %f\n", n, f, r, error);
                }
            }
            break;
        
        case 5: //ln(1+x)
            valorreal = log(1+x);
            u = 1+x0;
            if (x0<=-1){
                printf("La función no está definida en el punto ingresado\n");
            }
            else {
                for (n=0; n<nmax; n++){
                    if (n==0){
                        f = log(u);
                        r = pow(xi+1, -1)*h;
                    }
                    else {
                        if (n==1) {
                            f = f + pow(u, -n)*h;
                            r = (-1 * pow(xi+1, -2) * pow(h, 2))/2;
                        }
                        else {
                            f = f + ((1-n) * pow(u, -n) * pow(h, n))/fact;
                            r = (-n * pow(xi+1, -1-n) * pow(h, n+1))/factr;
                        }
                    }
                fact = fact*(n+1);
                factr = fact*(n+2);
                error = valorreal - f;
                printf("Aproximación %i, valor de la función: %f, residuo: %f, diferencia del valor real: %f\n", n, f, r, error);
                }
            }
            break;
            
        default:
            printf("Opción no válida\n");
            break;
    }
}