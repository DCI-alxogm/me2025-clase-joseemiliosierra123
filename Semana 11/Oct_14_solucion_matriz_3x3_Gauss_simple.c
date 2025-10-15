#include <stdio.h>

int lecturamatriz(float A[3][3], float b[3]);

int main()
{
    int m=3, n=3, i, j, k=0;
    float A[m][n], b[m], pivote[m], x[m], h; //m-i es filas, n-j es columnas
    
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
    
    //Se imprime la matriz ingresada
    printf("\nMatriz inicial:\n");
    for (j=0; j<n; j++){
        printf("%.4f     %.4f     %.4f     %.4f\n",
        A[j][0], A[j][1], A[j][2], b[j]);
    }
    
    //Se busca que el primer factor no sea 0 para evitar división entre 0
    for(i=0; i<m; i++){
        
        for(j=0; j<n; j++){
            
            if(i==j){
                
                if(A[i][j]==0){
                    
                    //Se intercambia la fila que contiene al 0 en su primer término
                    for(k=0; k<m; k++){
                        pivote[k] = A[i][k];
                        
                        A[i][k] = A[i+1][k];
                        
                        A[i+1][k] = pivote[k];
                    }
                }
            }
        }
    }
    
    //Se imprime la matriz modificada
    printf("\nMatriz modificada:\n");
    for (j=0; j<n; j++){
        printf("%.4f     %.4f     %.4f     %.4f\n",
        A[j][0], A[j][1], A[j][2], b[j]);
    }
    
    printf("\nFactores de multiplicación:\n"); //Cambio de factor de multiplicación
    for (k=0; k<m-1; k++){
        
        for (i=k+1; i<m; i++){ //Cambio de filas
            
            h = A[i][k] / A[k][k]; //El factor de cambio se matiene constante durante la modificación de toda la fila
            
            printf("%f\n",h);
            
            for (j=0; j<n; j++){ //Cambio de columna en la misma fila
                
                A[i][j] = A[i][j] - (h * A[k][j]);
                
            }
            
            b[i] = b[i] - (h * b[k]); //Definira valor de b
            
            
        }
    }
    
    printf("\nMatriz resultante:\n");
    for (j=0; j<m; j++){
        printf("%.4f     %.4f     %.4f     %.4f\n",
        A[j][0], A[j][1], A[j][2], b[j]);
    }
    
    //Resultados
    x[2] = b[2] / A[2][2];
    x[1] = (b[1] + (A[1][3] * x[2])) / A[1][1];
    x[0] = (b[0] + (A[0][3] * x[2]) + (A[0][1] * x[1])) / A[0][0];
    
    //Se imprimen los resultados
    printf("\nResultados:\n");
    for (j=0; j<m; j++){
        printf("%.4f\n", x[j]);
    }
    
}

int lecturamatriz(float A[3][3], float b[3]){
    int m=3, n=3, i, j, k=0; //m-i es filas, n-j es columnas
    
    printf("Ingresa los términos de tu matriz 3x3:\n");
    
    //Lectura de los elementos de la matriz
    for (i=0; i<m; i++){
        
        for (j=0; j<n; j++){
            
            printf("Elemento A[%d][%d]: ", i+1, j+1);
            
            scanf("%f", &A[i][j]);
            
        }
        
    }
    
    //Lectura del vector b
    for (i=0; i<m; i++){
        
        printf("Elemento b[%d]: ", i+1);
            
            scanf("%f", &b[i]);
            
    }
}