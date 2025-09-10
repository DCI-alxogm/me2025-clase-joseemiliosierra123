#include<stdio.h>

int main(){
    //vv se refiere al valor verdadero de la derivada, ef, eb y ec se refieren al error en cada aprox.
    float xi=0.5, ximas=1, ximen=0, fxi=0.925, fximas=0.2, fximen=1.2, aproxf, aproxb, aproxc, vv=-0.9125, ef, eb, ec;
    
    printf("f(0)=1.2\nf(0.5)=0.925\nf(1)=0.2\n\n");
    
    aproxf=(fximas-fxi)/(ximas-xi);
    aproxb=(fxi-fximen)/(xi-ximen);
    aproxc=(fximas-fximen)/(ximas-ximen);
    
    printf("Aprox. hacia adelante: %f\n",aproxf);
    printf("Aprox. hacia atras: %f\n",aproxb);
    printf("Aprox. centrada: %f\n\n",aproxc);
    
    ef=100*((vv-aproxf)/vv);
    eb=100*((vv-aproxb)/vv);
    ec=100*((vv-aproxc)/vv);
    
    printf("Considerando que el valor verdadero de la derivada es: %f\n",vv);
    printf("Error de la aprox. hacia adelante: %f\n",ef);
    printf("Error de la aprox. hacia atras: %f\n",eb);
    printf("Error de la aprox. centrada: %f\n\n",ec);
    
    //A partir de este punto se agregan las variables y ecuaciones para el cálculo de la segunda derivada
    //Segaprox se refiere a segunda aproximación, referente a la segunda derivada
    float h=0.5, fximasdos, fximendos, segaproxf, segaproxb, segaproxc;
    
    fximasdos = fxi + aproxc*h + 2*h*h;
    fximendos = fxi - aproxc*h - 2*h*h;
    
    segaproxf = (fximasdos - 2*fximas + fxi)/(h*h);
    segaproxb = (fximendos - 2*fximen + fxi)/(h*h);
    segaproxc = (fximen - 2*fxi + fximen)/(2*h*h);
    
    printf("Aprox. segunda derivada hacia adelante: %f\n",segaproxf);
    printf("Aprox. segunda derivada hacia atras: %f\n",segaproxb);
    printf("Aprox. segunda derivada centrada: %f\n\n",segaproxc);
}