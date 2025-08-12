/*Programa que imprima 5 numeros flotantes y el valor de las funciones:
f(x)=x²
f(x)=log(x+1)
f(x)=exp(x)+cos(x)*/

#include<stdio.h>
#include<math.h>

int main(){
  float a, b, c, d, e;
  a=5.28;
  b=700.2984;
  c=0.0004;
  d=58.1;
  e=7445.333;

  printf("Números originales \n%f, %f, %f, %f, %f\n\nCuadrados de los números\n",a,b,c,d,e);

  //Generamos el arreglo
  float x[5]={a,b,c,d,e};
  
  //Función f(x)=x²
  float cuadrado[5];
  
  for (int c=0; c<5; c++){
    cuadrado[c]=x[c]*x[c];
    printf("%f, ",cuadrado[c]);
  }

  //Función f(x)=log(x+1)
  float logaritmo[5];

  printf("\n\nlog(x+1)\n");

  for (int c=0; c<5; c++){
    logaritmo[c]=log(x[c]+1);
    printf("%f, ",logaritmo[c]);
  }

  //Función f(x)=exp(x)+cos(x)
  float exponente[5];

  printf("\n\nexp(x)+cos(x)\n");

  for (int c=0; c<5; c++){
    exponente[c]=exp(x[c]+cos(x[c]));
    printf("%f, ",exponente[c]);
  }

}