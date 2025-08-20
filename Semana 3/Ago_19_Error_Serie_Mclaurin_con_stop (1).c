#include<stdio.h>
#include<math.h>

int main(){
  int m, n;
  float x, errorlimite, error, aproxact[30], aproxant[30];
  printf("Ingresa tu valor x en e^x: ");
  scanf("%f",&x);
  printf("Ingresa el porcentaje límite de error que quieres alcanzar: ");
  scanf("%f",&errorlimite);
  error=100;
  for (m=0; error>errorlimite; m++){
    if(m==0){
      aproxact[m]=(pow(x,m)/tgamma(m+1));//La función gamma respreta: G(n)=(n-1)!
      printf("Aproximación %i = %f\n",m,aproxact[m]);
    }
    else{
      aproxant[m]=aproxact[m-1];
      aproxact[m]=aproxant[m]+(pow(x,m)/tgamma(m+1));
      error=(100)*((aproxact[m]-aproxant[m])/aproxact[m]);
      printf("Aproximación %i = %f, con un error del %f por ciento\n",m,aproxact[m],error);
    }
  }
}