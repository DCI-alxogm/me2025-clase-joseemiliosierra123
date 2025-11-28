//Método de Runge - Kutta 2° Orden

//El programa plantea un lanzamiento de un proyectil considerando la fricción con el aire
//En la forma de un coeficiente de resistencia.
//Se establecen y muestran las variables de tiempo, posición y velocidad en cada eje para cada iteración

#include <stdio.h>
#include <math.h>

int main(){
    
    float g=9.81, k=0.1, h=0.1, t=0; //Parámetros fijos
    float vx=20, vy=25, vz=15, phi, v_total; //Velocidades iniciales
    float vxn, vyn, vzn; //Aceleraciones y parámetros adicionales
    float vxtemp1, vytemp1, vztemp1, vxtemp2, vytemp2, vztemp2, vxtemp3, vytemp3, vztemp3;//Parámetros temporales
    float k1x, k1y, k1z, k2x, k2y, k2z, k3x, k3y, k3z, k4x, k4y, k4z; //Parámetros del método R-K
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
        vxtemp1 = vx + 0.5 * h * k1x;
        vytemp1 = vy + 0.5 * h * k1y;
        vztemp1 = vz + 0.5 * h * k1z;
        
        k2x = -k * v_total * vxtemp1;
        k2y = -k * v_total * vytemp1 - g;
        k2z = -k * v_total * vztemp1;
        
        //Cálculo de k3
        vxtemp2 = vx + 0.5 * h * k2x;
        vytemp2 = vy + 0.5 * h * k2y;
        vztemp2 = vz + 0.5 * h * k2z;
        
        k3x = -k * v_total * vxtemp2;
        k3y = -k * v_total * vytemp2 - g;
        k3z = -k * v_total * vztemp2;
        
        //Cálculo de k4
        vxtemp3 = vx + h * k3x;
        vytemp3 = vy + h * k3y;
        vztemp3 = vz + h * k3z;
        
        k4x = -k * v_total * vxtemp3;
        k4y = -k * v_total * vytemp3 - g;
        k4z = -k * v_total * vztemp3;
        
        //Cálculo de las nuevas velocidades
        vxn = vx + (k1x + 2 * k2x + 2 * k3x + k4x) * (h / 6);
        vyn = vy + (k1y + 2 * k2y + 2 * k3y + k4y) * (h / 6);
        vzn = vz + (k1z + 2 * k2z + 2 * k3z + k4z) * (h / 6);
        
        printf("%-6d %-6.2f %-10.4f %-10.4f %-10.4f\n",
        iter, t, vx, vy, vz);
        
        vx = vxn;
        vy = vyn;
        vz = vzn;
        
        t = h + t;
        
        iter++;
        
    } while (iter < iter_max);
    
}