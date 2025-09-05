#include<stdio.h>

float fx(float x);

int main(){
    float a=-2, b=2, h=0.25;
    int i, n = (int) ((b-a)/h);
    float x[n+1], fpa[n+1]; //fpa es la aproximación de la primera derivada hacia adelante
    
    
    
    for (i=0; i<n+1; i++){
        x[i]=a+i*h;
        printf("%f\n",x[i]);
    }
    
    printf("\n");
    
    for (i=0; i<n+1; i++){
        fpa[i]= ( fx(x[i+1]) - fx(x[i]) ) / h;
        //Añadir fpb[] y fpc[] aquí
        printf("%f \t %f\n",x[i],fpa[i]);//imprimir al lado las aproximaciones desde atrás y centrada
    }
    
    //En otro ciclo for añadir los cálculos para la segunda derivada
    
}

float fx(float x){
    float f;
    f = x*x*x - 2*x + 4;
    return f;
}