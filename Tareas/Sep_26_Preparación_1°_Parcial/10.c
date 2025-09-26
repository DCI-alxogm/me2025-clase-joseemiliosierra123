#include <stdio.h>
#include <math.h>

int main()
{
    float pi = 3.14159, V = 30, h, R = 3, hant, fh, fhprim, errorrel;
    int iter=0, itermax=25;
    
    hant = 3;
    
    printf("%-6s %-12s %-12s %-12s\n",
    "Iter","h","fh","E_rel");
    
    do{
        
        fh = pi*pow(hant, 3) - 3*pi*R*pow(hant, 2) + 3*V;
        fhprim = 3*pi*pow(hant, 2) - 6*pi*R*hant;
        
        h = hant - fh/fhprim;
        
        errorrel = (fabs(h - hant)/h)*100;
        
        printf("%-6d %-12f %-12f %-12f\n",
        iter,h,fh,errorrel);
        
        hant = h;
        
        iter++;
        
    } while(iter<=itermax && errorrel>0.0001);
}
