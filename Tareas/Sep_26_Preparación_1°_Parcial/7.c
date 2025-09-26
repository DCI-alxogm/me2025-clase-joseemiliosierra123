//Problema 7
// Error en la expresión escrita en al tarea: La función de temperatura ya está corregida en este código

#include <stdio.h>
#include <math.h>

int main()
{
    double a, b, k, fa, fb, fk, kant, O, TC;
    int iter=0, itermax=100;
    
    a = 273.15;
    b = 313.15;
    
    O = 10;
    
    kant = a;
    
    printf("%-6s %-12s %-12s %-12s %-12s %-12s %-12s %-12s\n",
    "Iter","a","b","fa","fb","k","fk","T_°C");
    
    do{
        k=(a+b)/2;
        
        fa = - log(O) - 139.34 + ((1.575701*pow(10, 5))/a) - ((6.642309*pow(10, 7))/pow(a, 2)) + ((1.2438*pow(10, 10))/pow(a, 3)) - ((8.621949*pow(10, 11))/pow(a, 4));
        fb = - log(O) - 139.34 + ((1.575701*pow(10, 5))/b) - ((6.642309*pow(10, 7))/pow(b, 2)) + ((1.2438*pow(10, 10))/pow(b, 3)) - ((8.621949*pow(10, 11))/pow(b, 4));
        
        fk = - log(O) - 139.34 + ((1.575701*pow(10, 5))/k) - ((6.642309*pow(10, 7))/pow(k, 2)) + ((1.2438*pow(10, 10))/pow(k, 3)) - ((8.621949*pow(10, 11))/pow(k, 4));;
        
        TC = k - 273.15;
        
        printf("%-6d %-12f %-12f %-12f %-12f %-12f %-12f %-12f\n",
        iter,a,b,fa,fb,k,fk,TC);
        
        if(fa*fk<0){
            b = k;
        }
        else{
            a = k;
        }
        
        kant = k;
        
        iter++;
        
    } while(iter<=itermax && fabs(b-a)>0.00001);
}
