#include<stdio.h>
#include<math.h>

int main(){
  char contador='\0';
  do{
    float x1, x2, xi1, xi2, a, b, c, discr;
    printf("Ingresa a, b, c");
    scanf("%f %f %f", &a, &b, &c);
    if (a==0){
      if (b!=0){
        x1=-(c/b);
        printf("x = %f\n", x1);
      }
      else{
        printf("Solución trivial\n");
      }
    }
    else{
      discr=b*b-4*a*c;
      if (discr>0){
        x1=(-b+sqrt(discr))/(2*a);
        x2=(-b-sqrt(discr))/(2*a);
        printf("x1 = %f, x2 = %f\n", x1, x2);
      }
      else{
        x1=-b/(2*a);
        x2=x1;
        xi1=sqrt(fabs(discr))/(2*a);//fabs sale de math.h
        xi2=-xi1;
        printf("x1 = %f + %fi\n", x1, xi1);
        printf("x2 = %f - %fi\n", x2, xi2);
      }
    }
    printf("¿Quiéres ingresar otro número? (S/N)\n");
    scanf(" %c", &contador);
  } while (contador!='N');
}