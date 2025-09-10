#include <stdio.h>
#include <math.h>

int main(){
    float a, b, fa, fb, erroraprox=100, errormax, k, fk, kant, ea;
    float g=9.81, m=68.1, v=40, t=10;
    int iter=0, maxiter=100;

    printf("Ingrese rango: a, b.\n");
    scanf("%f %f",&a,&b);
    printf("Ingresar error máximo en porcentaje: \n");
    scanf("%f",&errormax);

    printf("\n%-6s %-12s %-12s %-12s %-12s %-12s %-12s %-12s\n","Iter","a","b","f(a)","f(b)","E_rel","E_abs","f(k)");

    do{
        
        k=(a+b)/2;

        fa=(g*m/a)*(1-exp(-a*t/m))-v;

        fb=(g*m/b)*(1-exp(-b*t/m))-v;

        fk=(g*m/k)*(1-exp(-k*t/m))-v;

        ea=k-kant;

        erroraprox=((fabs(ea))/k)*100;

        printf("%-6d %-12f %-12f %-12f %-12f %-12f %-12f %-12f\n",iter,a,b,fa,fb,erroraprox,ea,fk);

        if(fa*fk<0){
            b=k;
        }
        else{
            a=k;
        }

        if(fk=0){
            break;
        }
        kant=k;
        iter=iter+1;

    } while (erroraprox > errormax && iter < maxiter);
}