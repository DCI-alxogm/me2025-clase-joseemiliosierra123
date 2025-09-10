#include <stdio.h>
#include <math.h>

int main(){
    float a, b, fa, fb, erroraprox=100, erroresp, k, fk, kant;
    float g=9.81, m=68.1, v=40, t=10;
    int iter=0, maxiter=100;

    printf("Ingrese rango: a, b.\n");
    scanf("%f",&a,&b);
    printf("Ingresar error máximo en porcentaje: \n");
    scanf("%f",&erroresp);

    while (erroraprox > erroresp && iter<maxiter){
        
        k=(a+b)/2;

        fa=(g*m/a)*(1-exp(-a*t/m))-v;

        fb=(g*m/b)*(1-exp(-b*t/m))-v;

        fk=(g*m/k)*(1-exp(-k*t/m))-v;

        erroraprox=((fabs(k-kant))/k)*100;

        printf("Iteración %i, a=%f, b=%f, f(a)=%f, f(b)=%f, Error=%f\n",iter,a,b,fa,fb,erroraprox);

        if(fa*fk<0){
            b=k;
        }
        else{
            a=k;
        }

        kant=k;
        iter=iter+1;
    }
}