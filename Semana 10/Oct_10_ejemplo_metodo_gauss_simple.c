#include <stdio.h>

int main()
{
    int m=3, n=3, i, j, k=0;
    float A[m][n], b[m], h;
    
    A[0][0] = 3;
    A[0][1] = -0.1;
    A[0][2] = -0.2;
    b[0] = 7.85;
    A[1][0] = 0.1;
    A[1][1] = 7;
    A[1][2] = -0.3;
    b[1] = -19.3;
    A[2][0] = 0.3;
    A[2][1] = 0.2;
    A[2][2] = 10;
    b[2] = 71.4;
    
    for (k=0; k<m-1; k++){ //Cambio de factor de multiplicación
        
        for (j=k+1; j<m; j++){ //Cambio de filas
            
            h = A[j][k] / A[k][k]; //El factor de cambio se matiene constante durante la modificación de toda la fila
            
            for (i=0; i<n; i++){ //Cambio de columna en la misma fila
                
                A[j][i] = A[j][i] - (h * A[k][i]);
                
            }
            
            b[j] = b[j] - (h * b[k]); //Definira valor de b
            
            printf("%f\n",h);
        }
    }
    
    for (j=0; j<m; j++){
        printf("%.4f     %.4f     %.4f     %.4f\n",
        A[j][0], A[j][1], A[j][2], b[j]);
    }
    
}
