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
    float U[m][n], L[m][n], y[m];
    
    //Lectura del documento de texto con el contenido de la matriz
    leerDesdeArchivo(m, n, A, b, "matriz.txt");
    
    //L se define como 0 (excepto la diagonal), y U como A
    for (i=0; i<n; i++){
        for (j=0; j<n; j++){
            U[i][j] = A[i][j];
            
            if(i==j){
                L[i][j] = 1;
            }
            else{
                L[i][j] = 0;
            }
        }
    }
    
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
    for (k=0; k<m-1; k++){
        
        for (i=k+1; i<m; i++){ //Cambio de filas
            
            //Se llena la matriz L con los factores de multiplicación
            L[i][k] = U[i][k] / U[k][k]; //El factor de cambio se matiene constante durante la modificación de toda la fila
            
            for (j=0; j<n; j++){ //Cambio de columna en la misma fila
                
                U[i][j] = U[i][j] - (L[i][k] * U[k][j]);
                
            }
            
        }
    }
    
    //Se imprimen la matrices U y L resultantes
    printf("\nMatriz U resultante:\n");
    for (i=0; i<m; i++){
        for (j=0; j<n; j++){
            printf("%8.4f ", U[i][j]);
        }
        printf("\n");
    }
    printf("\nMatriz L resultante:\n");
    for (i=0; i<m; i++){
        for (j=0; j<n; j++){
            printf("%8.4f ", L[i][j]);
        }
        printf("\n");
    }
    
    //Definimos los valores del vector y
    for (i=0; i<m; i++){
        y[i] = b[i];
        
        if(i==0){
            continue;
        }
        else{
            for(j=i-1; j>=0; j--){
                y[i] = y[i] - L[i][j]*y[j];
            }
        }
        //No es necesario dividir entre el coeficiente diagonal, ya que es 1
    }
    
    //Se imprime vector y
    printf("\nVector y:\n");
    for(i=0; i<m; i++){
        printf("y[%d] = %.4f\n",i+1, y[i]);
    }
    
    //Definimos los valores del vector x
    for(i=m-1; i>=0; i--){
        x[i]=y[i];  // Empezar con el valor del vector b
        
        //Restar los términos ya calculados (de i+1 hasta n-1)
        for(j=i+1; j<n; j++){
            x[i] = x[i] - U[i][j] * x[j];
        }
        
        //Dividir por el coeficiente diagonal
        x[i] = x[i] / U[i][i];
    }
    
    //Se imprime vector x
    printf("\nVector x:\n");
    for(i=0; i<m; i++){
        printf("x[%d] = %.4f\n",i+1, x[i]);
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