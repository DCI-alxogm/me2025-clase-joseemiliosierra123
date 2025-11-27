//Método de Runge Kutta de 2° Orden

#include <stdio.h>
#include <math.h>

int main(){
    
    float c = 12.5, m = 68.1, a = 8.3, b = 2.2, v_max = 46, g = 9.81, h = 0.1, t = 0; //Parámetros fijos
    float v, v_ant = 0, v_temp,  k1, k2; //Parámetros a determinar
    int iter = 0, iter_max = 200;
    
    printf("%-6s %-14s %-18s\n",
    "Iter","t","v(t)");
    
    do{
        
        k1 = g - (c / m) * (v_ant + a * pow((v_ant / v_max), b));
        
        v_temp = v_ant + 0.5 * h * k1;
        
        k2 = g - (c / m) * (v_temp + a * pow((v_temp / v_max), b));
        
        v = (0.5 * k1 + 0.5 * k2) * h + v_ant;
        
        printf("%-6d %-12.2f %-12.12f\n",
        iter, t, v);
        
        v_ant = v;
        t = t + h;
        iter++;
        
    } while (iter < iter_max);
    
}