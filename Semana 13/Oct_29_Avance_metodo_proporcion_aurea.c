//Probar el programa con la función x^3-5x^2-7x-3=0
#include <stdio.h>
#include <math.h>

int main(){
    float xl, xu, x1, x2, fx1, fx2, xmax, xmax_ant, d, error, errormax;
    int iter=0, maxiter=100;
    
    d = (sqrt(5) - 1)/2;
    
    errormax = 0.0001;

    printf("\n%-6s %-12s %-12s %-12s %-12s %-12s %-12s %-12s %-12s\n",
    "Iter","x_l","x_1","x_2","x_u","f(x_1)","f(x_2)","x_max","Error");
    
    x1 = xl + d * (xu - xl);
    
    x2 = xu - d * (xu - xl);
    
    xmax_ant = (x1 + x2)/2;
    
    do{
        
        if(fx1 > fx2){
            
            xmax = x1;
            
            xl = x1;
            
            x1 = xl + d * (xu - xl);
        }
        else{
            xmax = x2;
            
            xu = x2;
            
            x2 = xu - d * (xu - xl);
        }
        
        error = (xmax - xmax_ant)/xmax;
        
        printf("%-6d %-12f %-12f %-12f %-12f %-12f %-12f %-12f %-12f\n",
        iter,xl,x1,x2,xu,fxi,fx2,xmax,error);
        
        iter++;

    } while (error > errormax && iter < maxiter);
}