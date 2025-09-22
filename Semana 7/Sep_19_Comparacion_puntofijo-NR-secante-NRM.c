//Utiliza el método del punto fijo, Newton-Rapson, Secante y Newton Rapson Modificado para aproximar la raíz de las funciones:
//1. f(x) = exp(-x) - x, con x0 = 0 y h = 0.1
//2. f(x) = x^10 - 1, con x0 = 0.5 y h = 0.1
//3. f(x) = x^3 - 5x^2 - 7x - 3, con x0 = 0, x0 = 4 y h = 0.1
//Considerando un error máximo de 0.000001%

#include <stdio.h>
#include <math.h>

float punto_fijo1();
float Newton_Rapson1();
float secante1();
float NRM1();
float punto_fijo2();
float Newton_Rapson2();
float secante2();
float NRM2();
float punto_fijo3();
float Newton_Rapson3();
float secante3();
float NRM3();
float punto_fijo4();
float Newton_Rapson4();
float secante4();
float NRM4();

int main(){
    printf("f(x) = exp(-x) - x, con x0 = 0 y h = 0.1\n\n");
    printf("Método del punto fijo: \n");
    punto_fijo1();
    
    printf("\n\nMétodo de Newton - Rapson: \n");
    Newton_Rapson1();
    
    printf("\n\nMétodo de la secante: \n");
    secante1();
    
    printf("\n\nMétodo de Newton - Rapson modificado: \n");
    NRM1();
    
    
    printf("\n\n\nf(x) = x^10 - 1, con x0 = 0.5 y h = 0.1\n\n");
    printf("Método del punto fijo: \n");
    punto_fijo2();
    
    printf("\n\nMétodo de Newton - Rapson: \n");
    Newton_Rapson2();
    
    printf("\n\nMétodo de la secante: \n");
    secante2();
    
    printf("\n\nMétodo de Newton - Rapson modificado: \n");
    NRM2();
    
    
    printf("\n\n\nf(x) = x^3 - 5x^2 - 7x - 3, con x0 = 0 y h = 0.1\n\n");
    printf("Método del punto fijo: \n");
    punto_fijo3();
    
    printf("\n\nMétodo de Newton - Rapson: \n");
    Newton_Rapson3();
    
    printf("\n\nMétodo de la secante: \n");
    secante3();
    
    printf("\n\nMétodo de Newton - Rapson modificado: \n");
    NRM3();
    
    
    printf("\n\n\nf(x) = x^3 - 5x^2 - 7x - 3, con x0 = 4 y h = 0.1\n\n");
    printf("Método del punto fijo: \n");
    punto_fijo4();
    
    printf("\n\nMétodo de Newton - Rapson: \n");
    Newton_Rapson4();
    
    printf("\n\nMétodo de la secante: \n");
    secante4();
    
    printf("\n\nMétodo de Newton - Rapson modificado: \n");
    NRM4();
}

float punto_fijo1(){
    double xant=0, g, x, error, errormax=0.000001, fxpost;
    int iter=0, itermax=50;
    
    printf("%-6s %-18s %-18s %-18s\n","Iter","x(i+1)","f(x(i+1))","Error");
    
    do{
        
        g = exp(-xant);
        
        fxpost = exp(-g) - g;
        
        error = (fabs(g-xant)/g)*100;
        
        printf("%-6d %-12.12f %-12.12f %-12.12f\n",
        iter, g, fxpost, error);
        
        xant = g;
        
        iter++;
        
    } while (error>errormax && iter<=itermax);
}

float Newton_Rapson1(){
    double xant=0, g, x, error, errormax=0.000001, fxpost;
    int iter=0, itermax=50;
    
    printf("%-6s %-18s %-18s %-18s\n","Iter","x(i+1)","f(x(i+1))","Error");
    
    do{
        
        g = xant + ((exp(-xant) - xant) / (exp(-xant) + 1));
        
        fxpost = exp(-g) - g;
        
        error = (fabs(g-xant)/g)*100;
        
        printf("%-6d %-12.12f %-12.12f %-12.12f\n",
        iter, g, fxpost, error);
        
        xant = g;
        
        iter++;
        
    } while (error>errormax && iter<=itermax);
}

float secante1(){
    double xant=0, g, xi=0.1, xpost, error, errormax=0.000001, fi, fant, fxpost;
    int iter=0, itermax=50;
    
    printf("%-6s %-18s %-18s %-18s\n","Iter","x(i+1)","f(x(i+1))","Error");
    
    do{
        
        fi = exp(-xi) - xi;
        
        fant = exp(-xant) - xant;
        
        xpost = xi - (fi * (xant - xi)) / (fant - fi);
        
        fxpost = exp(-xpost) - xpost;
        
        error = (fabs(xpost-xi)/xpost)*100;
        
        printf("%-6d %-12.12f %-12.12f %-12.12f\n",
        iter, xpost, fxpost, error);
        
        xant = xi;
        
        xi = xpost;
        
        iter++;
        
    } while (error>errormax && iter<=itermax);
}

float NRM1(){
    double g, xi=0, xpost, error, errormax=0.000001, f, fprim, fbiprim, u, uprim, fxpost;
    int iter=0, itermax=50;
    
    printf("%-6s %-18s %-18s %-18s\n","Iter","x(i+1)","f(x(i+1))","Error");
    
    do{
        
        f = exp(-xi) - xi;
        
        fprim = -exp(-xi) - 1;
        
        fbiprim = exp(-xi);
        
        u = f / fprim;
        
        uprim = (pow(fprim , 2) - (f * fbiprim)) / pow(fbiprim, 2);
        
        xpost = xi - (u / uprim);
        
        fxpost = exp(-xpost) - fxpost;
        
        error = (fabs(xpost-xi)/xpost)*100;
        
        printf("%-6d %-12.12f %-12.12f %-12.12f\n",
        iter, xpost, fxpost, error);
        
        xi = xpost;
        
        iter++;
        
    } while (error>errormax && iter<=itermax);
}

float punto_fijo2(){
    double xant=0.5, g, x, error, errormax=0.000001, fxpost;
    int iter=0, itermax=50;
    
    printf("%-6s %-18s %-18s %-18s\n","Iter","x(i+1)","f(x(i+1))","Error");
    
    do{
        
        g = pow(xant, 10) + xant - 1;
        
        fxpost = pow(g, 10) - 1;
        
        error = fabs((g-xant)/g)*100;
        
        printf("%-6d %-12.12f %-12.12f %-12.12f\n",
        iter, g, fxpost, error);
        
        xant = g;
        
        iter++;
        
    } while (error>errormax && iter<=itermax);
}

float Newton_Rapson2(){
    double xant=0.5, g, x, error, errormax=0.000001, fxpost;
    int iter=0, itermax=50;
    
    printf("%-6s %-18s %-18s %-18s\n","Iter","x(i+1)","f(x(i+1))","Error");
    
    do{
        
        g = xant + (pow(xant, 10))/(10 * pow(xant, 9));
        
        fxpost = pow(g, 10) - 1;
        
        error = fabs((g-xant)/g)*100;
        
        printf("%-6d %-12.12f %-12.12f %-12.12f\n",
        iter, g, fxpost, error);
        
        xant = g;
        
        iter++;
        
    } while (error>errormax && iter<=itermax);
}

float secante2(){
    double xant=0.4, g, xi=0.5, xpost, error, errormax=0.000001, fi, fant, fxpost;
    int iter=0, itermax=50;
    
    printf("%-6s %-18s %-18s %-18s\n","Iter","x(i+1)","f(x(i+1))","Error");
    
    do{
        
        fi = pow(xi, 10) - 1;
        
        fant = pow(xant, 10) - 1;
        
        xpost = xi - (fi * (xant - xi)) / (fant - fi);
        
        fxpost = pow(xpost, 10) - 1;
        
        error = (fabs(xpost-xi)/xpost)*100;
        
        printf("%-6d %-12.12f %-12.12f %-12.12f\n",
        iter, xpost, fxpost, error);
        
        xant = xi;
        
        xi = xpost;
        
        iter++;
        
    } while (error>errormax && iter<=itermax);
}

float NRM2(){
    double g, xi=0, xpost, error, errormax=0.000001, f, fprim, fbiprim, u, uprim, fxpost;
    int iter=0, itermax=50;
    
    printf("%-6s %-18s %-18s %-18s\n","Iter","x(i+1)","f(x(i+1))","Error");
    
    do{
        
        f = pow(xi, 10) - 1;
        
        fprim = 10 * pow(xi, 9);
        
        fbiprim = 90 * pow(xi, 8);
        
        u = f / fprim;
        
        uprim = (pow(fprim , 2) - (f * fbiprim)) / pow(fbiprim, 2);
        
        xpost = xi - (u / uprim);
        
        fxpost = pow(xpost, 10) - 1;
        
        error = (fabs(xpost-xi)/xpost)*100;
        
        printf("%-6d %-12.12f %-12.12f %-12.12f\n",
        iter, xpost, fxpost, error);
        
        xi = xpost;
        
        iter++;
        
    } while (error>errormax && iter<=itermax);
}

float punto_fijo3(){
    double xant=0, g, x, error, errormax=0.000001, fxpost;
    int iter=0, itermax=50;
    
    printf("%-6s %-18s %-18s %-18s\n","Iter","x(i+1)","f(x(i+1))","Error");
    
    do{
        
        g = (pow(xant, 3) - 5*pow(xant, 2) - 3)/7;
        
        fxpost = pow(g, 3) - 5*pow(g, 2) - 7*g, - 3;
        
        error = fabs((g-xant)/g)*100;
        
        printf("%-6d %-12.12f %-12.12f %-12.12f\n",
        iter, g, fxpost, error);
        
        xant = g;
        
        iter++;
        
    } while (error>errormax && iter<=itermax);
}

float Newton_Rapson3(){
    double xant=0, g, x, error, errormax=0.000001, fxpost;
    int iter=0, itermax=50;
    
    printf("%-6s %-18s %-18s %-18s\n","Iter","x(i+1)","f(x(i+1))","Error");
    
    do{
        
        g = xant + (pow(xant, 3) - 5*pow(xant, 2) - 7*xant, - 3)/(3*pow(xant, 2) - 10*xant - 7);
        
        fxpost = pow(g, 3) - 5*pow(g, 2) - 7*g, - 3;
        
        error = fabs((g-xant)/g)*100;
        
        printf("%-6d %-12.12f %-12.12f %-12.12f\n",
        iter, g, fxpost, error);
        
        xant = g;
        
        iter++;
        
    } while (error>errormax && iter<=itermax);
}

float secante3(){
    double xant=-0.1, g, xi=0, xpost, error, errormax=0.000001, fi, fant, fxpost;
    int iter=0, itermax=50;
    
    printf("%-6s %-18s %-18s %-18s\n","Iter","x(i+1)","f(x(i+1))","Error");
    
    do{
        
        fi = pow(xi, 3) - 5*pow(xi, 2) - 7*xi, - 3;
        
        fant = pow(xant, 3) - 5*pow(xant, 2) - 7*xant, - 3;
        
        xpost = xi - (fi * (xant - xi)) / (fant - fi);
        
        fxpost = pow(xpost, 3) - 5*pow(xpost, 2) - 7*xpost, - 3;
        
        error = (fabs(xpost-xi)/xpost)*100;
        
        printf("%-6d %-12.12f %-12.12f %-12.12f\n",
        iter, xpost, fxpost, error);
        
        xant = xi;
        
        xi = xpost;
        
        iter++;
        
    } while (error>errormax && iter<=itermax);
}

float NRM3(){
    double g, xi=0, xpost, error, errormax=0.000001, f, fprim, fbiprim, u, uprim, fxpost;
    int iter=0, itermax=50;
    
    printf("%-6s %-18s %-18s %-18s\n","Iter","x(i+1)","f(x(i+1))","Error");
    
    do{
        
        f = pow(xi, 3) - 5*pow(xi, 2) - 7*xi, - 3;
        
        fprim = 3*pow(xi, 2) - 10*xi - 7;
        
        fbiprim = 6*xi - 10;
        
        u = f / fprim;
        
        uprim = (pow(fprim , 2) - (f * fbiprim)) / pow(fbiprim, 2);
        
        xpost = xi - (u / uprim);
        
        fxpost = pow(xpost, 3) - 5*pow(xpost, 2) - 7*xpost, - 3;
        
        error = (fabs(xpost-xi)/xpost)*100;
        
        printf("%-6d %-12.12f %-12.12f %-12.12f\n",
        iter, xpost, fxpost, error);
        
        xi = xpost;
        
        iter++;
        
    } while (error>errormax && iter<=itermax);
}

float punto_fijo4(){
    double xant=4, g, x, error, errormax=0.000001, fxpost;
    int iter=0, itermax=50;
    
    printf("%-6s %-18s %-18s %-18s\n","Iter","x(i+1)","f(x(i+1))","Error");
    
    do{
        
        g = (pow(xant, 3) - 5*pow(xant, 2) - 3)/7;
        
        fxpost = pow(g, 3) - 5*pow(g, 2) - 7*g, - 3;
        
        error = fabs((g-xant)/g)*100;
        
        printf("%-6d %-12.12f %-12.12f %-12.12f\n",
        iter, g, fxpost, error);
        
        xant = g;
        
        iter++;
        
    } while (error>errormax && iter<=itermax);
}

float Newton_Rapson4(){
    double xant=4, g, x, error, errormax=0.000001, fxpost;
    int iter=0, itermax=50;
    
    printf("%-6s %-18s %-18s %-18s\n","Iter","x(i+1)","f(x(i+1))","Error");
    
    do{
        
        g = xant + (pow(xant, 3) - 5*pow(xant, 2) - 7*xant, - 3)/(3*pow(xant, 2) - 10*xant - 7);
        
        fxpost = pow(g, 3) - 5*pow(g, 2) - 7*g, - 3;
        
        error = fabs((g-xant)/g)*100;
        
        printf("%-6d %-12.12f %-12.12f %-12.12f\n",
        iter, g, fxpost, error);
        
        xant = g;
        
        iter++;
        
    } while (error>errormax && iter<=itermax);
}

float secante4(){
    double xant=3.9, g, xi=4, xpost, error, errormax=0.000001, fi, fant, fxpost;
    int iter=0, itermax=50;
    
    printf("%-6s %-18s %-18s %-18s\n","Iter","x(i+1)","f(x(i+1))","Error");
    
    do{
        
        fi = pow(xi, 3) - 5*pow(xi, 2) - 7*xi, - 3;
        
        fant = pow(xant, 3) - 5*pow(xant, 2) - 7*xant, - 3;
        
        xpost = xi - (fi * (xant - xi)) / (fant - fi);
        
        fxpost = pow(xpost, 3) - 5*pow(xpost, 2) - 7*xpost, - 3;
        
        error = (fabs(xpost-xi)/xpost)*100;
        
        printf("%-6d %-12.12f %-12.12f %-12.12f\n",
        iter, xpost, fxpost, error);
        
        xant = xi;
        
        xi = xpost;
        
        iter++;
        
    } while (error>errormax && iter<=itermax);
}

float NRM4(){
    double g, xi=4, xpost, error, errormax=0.000001, f, fprim, fbiprim, u, uprim, fxpost;
    int iter=0, itermax=50;
    
    printf("%-6s %-18s %-18s %-18s\n","Iter","x(i+1)","f(x(i+1))","Error");
    
    do{
        
        f = pow(xi, 3) - 5*pow(xi, 2) - 7*xi, - 3;
        
        fprim = 3*pow(xi, 2) - 10*xi - 7;
        
        fbiprim = 6*xi - 10;
        
        u = f / fprim;
        
        uprim = (pow(fprim , 2) - (f * fbiprim)) / pow(fbiprim, 2);
        
        xpost = xi - (u / uprim);
        
        fxpost = pow(xpost, 3) - 5*pow(xpost, 2) - 7*xpost, - 3;
        
        error = (fabs(xpost-xi)/xpost)*100;
        
        printf("%-6d %-12.12f %-12.12f %-12.12f\n",
        iter, xpost, fxpost, error);
        
        xi = xpost;
        
        iter++;
        
    } while (error>errormax && iter<=itermax);
}