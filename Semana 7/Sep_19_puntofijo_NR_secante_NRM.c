//Tomando x0=0, encontrar la raiz de f(x)=exp(-x)-x con el método de punto fijo, el método de Newton-Rapson, método de la secante y N-R modificado
//Hasta un error máximo de 0.000001%

#include <stdio.h>
#include <math.h>

float punto_fijo();
float Newton_Rapson();
float secante();
float NRM();

int main(){
    printf("Método del punto fijo: \n");
    punto_fijo();
    
    printf("\n\nMétodo de Newton - Rapson: \n");
    Newton_Rapson();
    
    printf("\n\nMétodo de la secante: \n");
    secante();
    
    printf("\n\nMétodo de Newton - Rapson modificado: \n");
    NRM();
}

float punto_fijo(){
    double xant=0, g, x, error, errormax=0.000001;
    int iter=0, itermax=50;
    
    printf("%-6s %-18s %-18s\n","Iter","x(i+1)","Error");
    
    do{
        
        g = exp(-xant);
        
        error = (fabs(g-xant)/g)*100;
        
        printf("%-6d %-12.12f %-12.12f\n",
        iter, g, error);
        
        xant = g;
        
        iter++;
        
    } while (error>errormax && iter<=itermax);
}

float Newton_Rapson(){
    double xant=0, g, x, error, errormax=0.000001;
    int iter=0, itermax=50;
    
    printf("%-6s %-18s %-18s\n","Iter","x(i+1)","Error");
    
    do{
        
        g = xant + ((exp(-xant) - xant) / (exp(-xant) + 1));
        
        error = (fabs(g-xant)/g)*100;
        
        printf("%-6d %-12.12f %-12.12f\n",
        iter, g, error);
        
        xant = g;
        
        iter++;
        
    } while (error>errormax && iter<=itermax);
}

float secante(){
    double xant=0, g, xi=0.1, xpost, error, errormax=0.000001, fi, fant;
    int iter=0, itermax=50;
    
    printf("%-6s %-18s %-18s\n","Iter","x(i+1)","Error");
    
    do{
        
        fi = exp(-xi) - xi;
        
        fant = exp(-xant) - xant;
        
        xpost = xi - (fi * (xant - xi)) / (fant - fi);
        
        error = (fabs(xpost-xi)/xpost)*100;
        
        printf("%-6d %-12.12f %-12.12f\n",
        iter, xpost, error);
        
        xant = xi;
        
        xi = xpost;
        
        iter++;
        
    } while (error>errormax && iter<=itermax);
}

float NRM(){
    double g, xi=0, xpost, error, errormax=0.000001, f, fprim, fbiprim, u, uprim;
    int iter=0, itermax=50;
    
    printf("%-6s %-18s %-18s\n","Iter","x(i+1)","Error");
    
    do{
        
        f = exp(-xi) - xi;
        
        fprim = -exp(-xi) - 1;
        
        fbiprim = exp(-xi);
        
        u = f / fprim;
        
        uprim = (pow(fprim , 2) - (f * fbiprim)) / pow(fbiprim, 2);
        
        xpost = xi - (u / uprim);
        
        error = (fabs(xpost-xi)/xpost)*100;
        
        printf("%-6d %-12.12f %-12.12f\n",
        iter, xpost, error);
        
        xi = xpost;
        
        iter++;
        
    } while (error>errormax && iter<=itermax);
}