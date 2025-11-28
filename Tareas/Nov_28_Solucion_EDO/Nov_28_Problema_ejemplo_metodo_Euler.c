//Método de Euler

//El programa plantea un lanzamiento de un proyectil considerando la fricción con el aire
//En la forma de un coeficiente de resistencia.
//Se establecen y muestran las variables de tiempo, posición y velocidad en cada eje para cada iteración

#include <stdio.h>
#include <math.h>

int main(){
    
    float g=9.81, k=0.1, h=0.01, t=0; //Parámetros fijos
    float x=0, y=0, z=0, vx=20, vy=25, vz=15, phi, v_total; //Posiciones y velocidades iniciales
    float ax, ay, az, xn, yn, zn, vxn, vyn, vzn; //Aceleraciones y parámetros adicionales
    int iter=0, iter_max=600;
    
    printf("%-6s %-8s %-10s %-10s %-10s %-10s %-10s %-10s\n",
    "Iter","t","x","y","z","vx","vy","vz");
    
    do{
        
        //Velocidad considerando los 3 componenetes
        v_total = sqrt(vx*vx + vy*vy + vz*vz);
        
        //Cálculo de las acelereaciones
        ax = -k * v_total * vx;
        ay = -k * v_total * vy - g;
        az = -k * v_total * vz;
        
        //Método de Euler para la velocidad
        vxn = ax * h + vx;
        vyn = ay * h + vy;
        vzn = az * h + vz;
        
        //Se repite el método de Euler para la posición
        xn = vx*h + x;
        yn = vy*h + y;
        zn = vz*h + z;
        
        printf("%-6d %-6.2f %-10.4f %-10.4f %-10.4f %-10.4f %-10.4f %-10.4f\n",
        iter, t, x, y, z, vx, vy, vz);
        
        x = xn;
        y = yn;
        z = zn;
        vx = vxn;
        vy = vyn;
        vz = vzn;
        
        t = h + t;
        
        iter++;
        
        //El programa se detiene cuando el proyectil llegue al suelo
        if (y<0){
        break;
        }
        
    } while (iter < iter_max);
    
}