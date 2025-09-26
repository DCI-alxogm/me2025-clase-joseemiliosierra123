//Suponga que est´a dise˜nando un tanque esf´erico para almacenar agua para un poblado peque˜no en
//un pa´ıs en desarrollo. El volumen de l´ıquido que puede contener se calcula con
//V = πh2 3R−h
//          3
//donde V es el volumen [m3], h la profundidad del agua en el tanque [m], y R el radio del tanque [m].
//Si R = 3m, ¿a qu´e profundidad debe llenarse el tanque de modo que contenga 30 m3? Haga tres
//iteraciones con el m´etodo de la falsa posici´on a fin de obtener la respuesta. Determine el error
//relativo aproximado despu´es de cada iteraci´on.
#include <stdio.h>
#include <math.h>

int main()
{
    float pi=3.14159, V=30, h, R = 3, a, b, hant, fa, fb, fh, errorrel;
    int iter=0, itermax=25;
    
    a = 1;
    b = 10;
    
    hant = a;
    
    printf("%-6s %-12s %-12s %-12s %-12s %-12s %-12s %-12s\n",
    "Iter","a","b","fa","fb","h","fh","E_rel");
    
    do{
        
        fa = pi*pow(a, 3) - 3*pi*R*pow(a, 2) + 3*V;
        fb = pi*pow(b, 3) - 3*pi*R*pow(b, 2) + 3*V;
        
        h = (a*fb - b*fa)/(fb-fa);
        
        fh = pi*pow(h, 3) - 3*pi*R*pow(h, 2) + 3*V;
        
        errorrel = (fabs(h - hant)/h)*100;
        
        printf("%-6d %-12f %-12f %-12f %-12f %-12f %-12f %-12f\n",
        iter,a,b,fa,fb,h,fh,errorrel);
        
        if(fa*fh<0){
            b = h;
        }
        else{
            a = h;
        }
        
        hant = h;
        
        iter++;
        
    } while(iter<=itermax);
}
