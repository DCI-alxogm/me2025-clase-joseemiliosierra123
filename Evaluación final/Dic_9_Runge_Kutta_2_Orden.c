//Método de Runge Kutta de 2° Orden
//Aplicado a la ecuación cinética dC/dt= k C(t) (Cmax - C(t))

#include <stdio.h>
#include <math.h>

int main(){
    
    float k = 0.45, Cmax = 1, Ci = 0.02, h = 0.1, t = 0; //Parámetros fijos
    float Ctemp1, k1, k2, C; //Parámetros a determinar
    
    int iter = 0;
    
    printf("%-6s %-14s %-18s\n",
    "Iter","t","C(t)");
    
    do{
        
        k1 = k * Ci * (Cmax - Ci);
        
        Ctemp1 = Ci + 0.5 * h * k1;
        
        k2 = k * Ctemp1 * (Cmax - Ctemp1);
        
        C = (0.5 * k1 + 0.5 * k2) * h + Ci;
        
        printf("%-6d %-12.2f %-12.12f\n",
        iter, t, C);
        
        Ci = C;
        t = t + h;
        iter++;
        
    } while (t <= 25.1);
    
}