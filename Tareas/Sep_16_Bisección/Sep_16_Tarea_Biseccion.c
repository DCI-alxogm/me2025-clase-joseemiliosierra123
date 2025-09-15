//Función f(x)=sen(10x)-cos(3x) en el rango [3,5] con un error relativo de 0.0001.
//Determinar si la relación Ea=Δx/2^n
#include <stdio.h>
#include <math.h>

int main(){
    float a=3, b=5, fa, fb, erel, errormax=0.0001, k, fk, kant, ea, erelp;
    float g=9.81, m=68.1, v=40, t=10;
    int iter=0, maxiter=100;

    printf("\n%-6s %-12s %-12s %-12s %-12s %-12s %-12s %-12s %-12s\n","Iter","a","b","f(a)","f(b)","E_relativo","Δx/2^n","E_absoluto","f(k)");
    
    kant=a;

    do{
        
        k=(a+b)/2;

        fa=sin(10*a)-cos(3*a);

        fb=sin(10*b)-cos(3*b);

        fk=sin(10*k)-cos(3*k);

        ea=k-kant;

        //erel y erelp deben coincidir para comprobar si Ea=Δx/2^n es correcto
        erel=((fabs(ea))/k)*100;

        if(fa*fk<0){
            b=k;
        }
        else{
            a=k;
        }

        if(fk==0){
            break;
        }

        erelp=2/pow(2,(iter+1));

        printf("%-6d %-12f %-12f %-12f %-12f %-12f %-12f %-12f %-12f\n",iter,a,b,fa,fb,erel,erelp,ea,fk);

        kant=k;
        iter=iter+1;

    } while (erel > errormax && iter < maxiter);
}