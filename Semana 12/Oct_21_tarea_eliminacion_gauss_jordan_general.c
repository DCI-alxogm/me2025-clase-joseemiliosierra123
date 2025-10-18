#include <stdio.h>
#include <stdlib.h>

int leerDesdeArchivo(int m, int n, float A[m][n], float b[m], const char* nombreArchivo);

int main()
{
    int m, n, i, j, k=0;
    float  h, detA=1;
    
    //Definir tamaño de la matriz
    printf("Ingresar numero de filas y columnas:\n");
    scanf("%d %d",&m, &n);
    
    float A[m][n], b[m], pivote[m], x[m]; //m-i es filas, n-j es columnas
    
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
    
    //Eliminación Gaussiana
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
    
    //Se imprime la matriz diagonal resultante
    printf("\nMatriz diagonal resultante (Gauss):\n");
    for (i=0; i<m; i++){
        for (j=0; j<n; j++){
            printf("%8.4f ", A[i][j]);
        }
        printf(" | %8.4f\n", b[i]);
    }
    
    //Eliminación Gauss-Jordan
    printf("\nFactores de multiplicación:\n"); //Cambio de factor de multiplicación
    for (k=m-1; k>0; k--){
        
        for (i=k-1; i>=0; i--){ //Cambio de filas
            
            h = A[i][k] / A[k][k]; //El factor de cambio se matiene constante durante la modificación de toda la fila
            
            printf("%f\n",h);
            
            for (j=n-1; j>=0; j--){ //Cambio de columna en la misma fila
                
                A[i][j] = A[i][j] - (h * A[k][j]);
                
            }
            
            b[i] = b[i] - (h * b[k]); //Definira valor de b
            
        }
    }
    
     //Se imprime la matriz diagonal resultante
    printf("\nMatriz diagonal resultante (Gauss-Jordan):\n");
    for (i=0; i<m; i++){
        for (j=0; j<n; j++){
            printf("%8.4f ", A[i][j]);
        }
        printf(" | %8.4f\n", b[i]);
    }
    
    //Se determina si el sistema está bien condicionado
    for(i=0; i<m; i++){
        detA = detA * A[i][i];
    }
    if(detA<=0.1){
        printf("\nEl sistema está mal condicionado, det(A) = %.3f\n",detA);
    }
    else{
        printf("\nEl sistema está bien condicionado, det(A) = %.3f\n",detA);
    }
    
    //Resultados
    //Definir elementos del vector x como 0
    for(i=0; i<m; i++){
        x[i] = 0;
    }
    
    //Comenzar desde la última ecuación hacia la primera
    for(i = m-1; i >= 0; i--){
        x[i] = b[i];  // Empezar con el valor del vector b
        
        //Restar los términos ya calculados (de i+1 hasta n-1)
        for(j = i+1; j < n; j++){
            x[i] = x[i] - A[i][j] * x[j];
        }
        
        //Dividir por el coeficiente diagonal
        x[i] = x[i] / A[i][i];
    }
    
    //Se imprimen los resultados
    printf("\nResultados:\n");
    for (j=0; j<m; j++){
        printf("x[%d] = %.4f\n",j+1, x[j]);
    }
    
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