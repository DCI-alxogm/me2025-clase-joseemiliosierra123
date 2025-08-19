#include<stdio.h>
#include<math.h>

int main(){
  int m, n;
  float x, elimite;
  double suma;
  printf("Ingresa tu valor x en e^x: ");
  scanf("%f",&x);
  printf("Ingresa el porcentaje límite de error ");
  scanf("%f",&elimite);
  suma=0;
  for (m=0; m<n+1; m++){
    suma=(pow(x,m)/tgamma(m+1))+suma; //Las funciones potencia y factorial se obtuvieron en internet
    
    printf("Aproximación %i = %f\n",m,suma);
  }
}