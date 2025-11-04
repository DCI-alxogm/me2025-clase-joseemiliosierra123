//Optimización de la función y - x - 2x^2 - 2xy - y^2
//Mediante el método de malla

#include<stdio.h>
#include<math.h>

int main(){
    float x, y, fxy, fxy_max, xmax, ymax;
    int a, b, c, d, i, j, iter=0;
    
    a = -2;
    b = 2;
    c = 1;
    d = 3;
    
    xmax = 0;
    ymax = 0;
    fxy_max = -1000;
    
    printf("%-6s %-12s %-12s %-12s %-12s %-12s %-12s\n"
    ,"Iter","x","y","f(x,y)","x_max","y_max","f(x_max,y_max)");
    
    for (x=a; x<=b; x=x+0.25){
        for (y=c; y<=d; y=y+0.25){
            
            fxy = y - x - 2*pow(x,2) - 2*x*y - pow(y,2);
            
            if (fxy > fxy_max){//Si la función evaluada en esos valores es mayor, se definen los mayores x, y
                
                xmax = x;
                ymax = y;
                fxy_max = fxy;
                
            }
            iter++;
            
            printf("%-6d %-12.6f %-12.6f %-12.6f %-12.6f %-12.6f %-12.6f\n",
            iter, x, y, fxy, xmax, ymax, fxy_max);
        }
    }
    
    printf("\nx_max = %f\ny_max = %f\nf(x_max,y_max) = %f",xmax,ymax,fxy_max);
}