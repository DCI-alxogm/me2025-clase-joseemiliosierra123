#include<stdio.h>

int main(){
  char valor='\0'; //Valor no definido
  do{
    int n;
    printf("Ingrese un número entero\n");
    scanf("%d",&n);
    if (n%2==0) {
      printf("El número %d es par\n",n);
    }
    else{
      printf("El número %d es impar\n",n);
    }
    printf("¿Desea ingresar otro número? (S/N)\n");
    scanf(" %c",&valor);
  } while (valor!='N'); 
}