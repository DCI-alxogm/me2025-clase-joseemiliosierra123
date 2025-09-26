// Problema 2:
// Use la expansi´on de la serie de Taylor de cero al cuarto orden para estimar 
// f(3) si f(x) = ln(x)utilizando x = 1 como punto base.

#include<stdio.h>
#include<math.h>

int main(){
    float fx, f, x = 3, x0 = 1, h, u = 1, u1 = -1, fact = 1;
    int iter=0, maxiter=4;
    
    printf("f(x)=Ln(x) en x=3 a partir de x0=1\n");
    
    printf("%-6s %-18s %-18s %-18s %-18s %-18s\n",
    "Iter","f","fx","u","u1","fact");
    
    h = x - x0;
    
    do{
        
        if(iter == 0){
            fx = log(x0);
        }
        else{
            fact = fact * iter;
            
            f = (u * pow(x0, u1)) * (pow(h, iter)/fact);
            
            fx = fx + f;
            
            printf("%-6d %-12.6f %-12.6f %-12.6f %-12.6f %-12.6f\n",
            iter, f, fx, u, u1, fact);
            
            u = u1;
            u1 = u1 - 1;
        }
        
        iter++;
        
    } while (iter<=maxiter);
}

// El código no converge cuando x0=1, pero cuando se le asigna otro valor a x0 más 
// cercano a 3 (como 2.5) si converge en aprox 1.09...