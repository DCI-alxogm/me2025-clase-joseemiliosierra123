#include <stdio.h>
#include <math.h>

int main(){
  int indx;
  float resultados[5];
  int numeros [5];
  float pif=3.14159265358979;
  double pid=3.14159265358979;
  numeros[0]=1;
  numeros[1]=2;
  numeros[2]=3;
  numeros[3]=4;
  numeros[4]=5;

  printf("x\t x^2\t log(x+1)\t exp(x)+cos(x)\n");

  for (indx=0; indx<5; indx++){

    printf("%d %d\n", numeros[indx], numeros[indx]%2);

    if(numeros[indx]%2==0){ //La función es par
      printf("x=%d\n log(x+1)=%f\n", numeros[indx], resultados[indx]=log10(numeros[indx]+1));
    }
    else{
      printf("x^2=%d\n e^x+cos(x)=%f\n", numeros[indx]*numeros[indx], resultados[indx]=exp(numeros[indx])+cos(numeros[indx]));
    }

    //printf("%f %f %f %f\n", numeros[indx], numeros[indx]*numeros[indx], log10(numeros[indx]+1), exp(numeros[indx])+cos(numeros[indx]));
  }
  printf("\nResultados:\n");
  for (indx=0; indx<5; indx++){
    printf("%f\n", resultados[indx]);
  }

  printf("\nEn float: Pi+Pi=%f\n", pif+pif);
  printf("\nEn double: Pi+Pi=%f\n", pid+pid);
}