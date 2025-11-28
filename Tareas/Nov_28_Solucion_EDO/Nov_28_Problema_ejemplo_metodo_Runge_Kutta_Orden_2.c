//Método de Runge - Kutta 2° Orden

//El programa plantea un lanzamiento de un proyectil considerando la fricción con el aire
//En la forma de un coeficiente de resistencia.
//Se establecen y muestran las variables de tiempo, posición y velocidad en cada eje para cada iteración

#include <stdio.h>
#include <math.h>

int main(){
    
    float g=9.81, k=0.1, h=0.1, t=0; //Parámetros fijos
    float vx=20, vy=25, vz=15, phi, v_total; //Velocidades iniciales
    float vxn, vyn, vzn, vxtemp, vytemp, vztemp; //Aceleraciones y parámetros adicionales
    float k1x, k1y, k1z, k2x, k2y, k2z; //Parámetros del método R-K
    int iter=0, iter_max=100;
    
    printf("%-6s %-8s %-10s %-10s %-10s\n",
    "Iter","t","vx","vy","vz");
    
    do{
        
        //Velocidad considerando los 3 componenetes
        v_total = sqrt(vx*vx + vy*vy + vz*vz);
        
        //Cálculo de k1 (f)
        k1x = -k * v_total * vx;
        k1y = -k * v_total * vy - g;
        k1z = -k * v_total * vz;
        
        //Cálculo de k2
        vxtemp = vx + 0.5 * h * k1x;
        vytemp = vy + 0.5 * h * k1y;
        vztemp = vz + 0.5 * h * k1z;
        
        vxn = vx + (0.5 * k1x + 0.5 * k2x) * h;
        vyn = vy + (0.5 * k1y + 0.5 * k2y) * h;
        vzn = vz + (0.5 * k1z + 0.5 * k2z) * h;
        
        printf("%-6d %-6.2f %-10.4f %-10.4f %-10.4f\n",
        iter, t, vx, vy, vz);
        
        vx = vxn;
        vy = vyn;
        vz = vzn;
        
        t = h + t;
        
        iter++;
        
    } while (iter < iter_max);
    
}