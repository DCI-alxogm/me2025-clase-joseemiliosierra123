#include<stdio.h>
#include<math.h>

int main(){
    float a=5, b=7, fa, fb, errorabs, errorver, k, fk, kant, xver;
    int iter=0, maxiter=3;
    
    xver = 6.405124837953327;

    printf("\n%-6s %-12s %-12s %-12s %-12s %-12s %-12s %-12s\n"
    ,"Iter","a","b","f(a)","f(b)","E_abs","E_ver","f(k)");
    
    kant=a;

    do{
        
        k=(a+b)/2;

        fa = -0.5 * pow(a, 2) + 2.5 * a + 4.5;

        fb = -0.5 * pow(b, 2) + 2.5 * b + 4.5;

        fk = -0.5 * pow(k, 2) + 2.5 * k + 4.5;

        errorabs = fabs(k - kant);
        
        errorver = fabs(xver - k);

        if(fa*fk<0){
            b=k;
        }
        else{
            a=k;
        }

        if(fk==0){
            break;
        }

        printf("%-6d %-12f %-12f %-12f %-12f %-12f %-12f %-12f\n"
        ,iter,a,b,fa,fb,errorabs,errorver,fk);

        kant=k;
        iter=iter+1;

    } while (iter <= maxiter);
}