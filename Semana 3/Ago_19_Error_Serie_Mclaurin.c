#include<stdio.h>
#include<math.h>

int main(){
  int m, n;
  float x;
  double suma;
  printf("Ingresa tu valor x en e^x: ");
  scanf("%f",&x);
  printf("Ingresa número de aproximaciones(comenzando en 0): ");
  scanf("%i",&n);
  suma=0;
  for (m=0; m<n+1; m++){
    suma=(pow(x,m)/tgamma(m+1))+suma; //Las funciones potencia y factorial se obtuvieron en internet
    printf("Aproximación %i = %f\n",m,suma);
  }
}