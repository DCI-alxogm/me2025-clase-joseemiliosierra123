#include<stdio.h>
#include<math.h>

int main(){
  int n=0, fact=1;
  float x, error=100, errorlim, aproxant, aproxact;
  printf("Ingresa tu valor de x: ");
  scanf("%f",&x);
  printf("Ingresa el porcentaje de error máximo que permites: ");
  scanf("%f",&errorlim);
  while(error>errorlim){
    if(n==0){
      aproxact=1;
      printf("La aproximación %i es: %f\n", n, aproxact);
    }
    else{
      aproxant=aproxact;
      aproxact=pow(x, n)/fact+aproxant;
      error=100*((aproxact-aproxant)/aproxact);
      fact=fact*(n+1);
      printf("La aproximación %i es: %f, con un error del %f por ciento\n", n, aproxact, error);
    }
    printf("%i",fact);
    n=n+1;
  }
}