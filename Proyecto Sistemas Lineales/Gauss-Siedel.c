#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int leerDesdeArchivo(int m, int n, float A[m][n], float b[m], const char* nombreArchivo);

int main()
{
    int m, n, i, j, k=0;
    float  h, detA=1;
    
    //Definir tamaño de la matriz
    printf("Ingresar numero de filas y columnas:\n");
    scanf("%d %d",&m, &n);
    
    float A[m][n], b[m], pivote[m], x[m]; //m-i es filas, n-j es columnas
    float N[m][n], P[m][n], x_ant[m], suma;
    float error, errormax = 0.0001;
    int iter=0, itermax = 50;
    
    //Lectura del documento de texto con el contenido de la matriz
    leerDesdeArchivo(m, n, A, b, "matriz.txt");
    
    //Se imprime la matriz ingresada
    printf("\nMatriz inicial:\n");
    for (i=0; i<n; i++){
        for (j=0; j<n; j++){
            printf("%8.4f ", A[i][j]);
        }
        printf(" | %8.4f\n", b[i]);
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
    
    //Se imprime la matriz modificada al evitar división entre 0
    printf("\nMatriz modificada:\n");
    for (i=0; i<n; i++){
        for (j=0; j<n; j++){
            printf("%8.4f ", A[i][j]);
        }
        printf(" | %8.4f\n", b[i]);
    }
    
    //Se definen las matrices N y P
    for(i=0; i<m; i++){
        
        for (j=0; j<n; j++){
            
            if(i<=j){
                N[i][j] = A[i][j];
                
                P[i][j] = 0;
            }
            else{
                N[i][j] = 0;
                
                P[i][j] = -A[i][j];
            }
        }
    }
    
    //Se imprimen matrices N y P
    printf("\nMatriz N:\n");
    for (i=0; i<n; i++){
        for (j=0; j<n; j++){
            printf("%8.4f ", N[i][j]);
        }
        printf("\n");
    }
    printf("\nMatriz P:\n");
    for (i=0; i<n; i++){
        for (j=0; j<n; j++){
            printf("%8.4f ", P[i][j]);
        }
        printf("\n");
    }
    
    
    //Se definen como 0 los valores en el vector x
    for(i=0; i<m; i++){
        x[i] = 0;
    }
    
    //Iteración para calcular x
    printf("\nIteraciones Gauss-Seidel\n");
    printf("%-6s %-12s","Iter","Error");
    for(i=1; i<m+1; i++){
        printf(" x%-11d", i);
    }
    printf("\n");
    
    do{
        error = 0;
        
        //Se actualizan los valores del vector x
        for(i=0; i<m; i++){
            x_ant[i] = x[i];
        }
        
        for(i=0; i<m; i++){
            suma = 0;
            
            for(j=0; j<i; j++){
                suma = suma + A[i][j] * x[j];
            }
            
            for(j=i+1; j<n; j++){
                suma = suma + A[i][j] * x_ant[j];
            }
            
            x[i] = (b[i] - suma) / A[i][i];
            
            error = fabs(x[i] - x_ant[i]);
        }
        
        printf("%-6d %-12f",
        iter, error);
        for(i=0; i<m; i++){
            printf(" %-12f",
            x[i]);
        }
        printf("\n");
        
        iter++;
        
    } while(error > errormax && iter < itermax);
    
}

//Función que lee un archivo de texto (obtenida de internet)
int leerDesdeArchivo(int m, int n, float A[m][n], float b[m], const char* nombreArchivo)
{
    FILE *archivo;
    int i, j;
    
    archivo = fopen(nombreArchivo, "r");
    if (archivo == NULL) {
        printf("\nNo se pudo abrir el archivo: %s\n", nombreArchivo);
        return -1;
    }
    
    // Leer la matriz A
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (fscanf(archivo, "%f", &A[i][j]) != 1) {
                printf("\nError leyendo elemento A[%d][%d]\n", i, j);
                fclose(archivo);
                return -1;
            }
        }
    }
    
    // Leer el vector b
    for (i = 0; i < m; i++) {
        if (fscanf(archivo, "%f", &b[i]) != 1) {
            printf("\nError leyendo elemento b[%d]\n", i);
            fclose(archivo);
            return -1;
        }
    }
    
    fclose(archivo);
    printf("\nMatriz leída exitosamente desde: %s\n", nombreArchivo);
    return 0;
}