#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(int argc, char* argv[]) {
    int i, j, k, n = 10000;
    int **matrizA;
    int **matrizB;
    int **matrizC;
    int **matrizD;
    int **matrizE;
    int **matrizF;
    int **matrizG;
    int **matrizH;
    double E1, E2;

    // Inicializando matrices
    matrizA = (int **)malloc(n * sizeof(int *));
    matrizB = (int **)malloc(n * sizeof(int *));
    matrizC = (int **)malloc(n * sizeof(int *));
    matrizD = (int **)malloc(n * sizeof(int *));
    matrizE = (int **)malloc(n * sizeof(int *));
    matrizF = (int **)malloc(n * sizeof(int *));
    matrizG = (int **)malloc(n * sizeof(int *));
    matrizH = (int **)malloc(n * sizeof(int *));

    for (i = 0; i < n; i++) {
        matrizA[i] = (int *)malloc(n * sizeof(int));
        matrizB[i] = (int *)malloc(n * sizeof(int));
        matrizC[i] = (int *)malloc(n * sizeof(int));
        matrizD[i] = (int *)malloc(n * sizeof(int));
        matrizE[i] = (int *)malloc(n * sizeof(int));
        matrizF[i] = (int *)malloc(n * sizeof(int));
        matrizG[i] = (int *)malloc(n * sizeof(int));
        matrizH[i] = (int *)malloc(n * sizeof(int));
    }

    printf("N= %d\n", n);

    clock_t inicio = clock();
    // Llenando matrices
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            matrizA[i][j] = rand() % 6;
            matrizB[i][j] = rand() % 6;
            matrizC[i][j] = 0;
            matrizD[i][j] = 0;
            matrizE[i][j] = 0;
            matrizF[i][j] = 0;
            matrizG[i][j] = 0;
            matrizH[i][j] = 0;
        }
    }
    clock_t fin = clock();
    double tiempo = (double)(fin - inicio) / CLOCKS_PER_SEC;
    printf("Tiempo de llenado de las matrices: %f s\n", tiempo);

    //**************************************************************************************************************************************
    // Tiempo antes de la operación
    inicio = clock();
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            for (k = 0; k < n; ++k) {
                matrizC[i][j] += matrizA[i][k] * matrizB[k][j];
            }
        }
    }
    // Tiempo después de la operación
    fin = clock();
    //Diferencia de tiempo:
    tiempo = (double)(fin - inicio) / CLOCKS_PER_SEC;
    printf("Tiempo transcurrido (ijk): %f s\n", tiempo);
    //**************************************************************************************************************************************

    //**************************************************************************************************************************************
    // Tiempo antes de la operación
    inicio = clock();
    for (i = 0; i < n; ++i) {
        for (k = 0; k < n; ++k) {
            for (j = 0; j < n; ++j) {
                matrizD[i][j] += matrizA[i][k] * matrizB[k][j];
            }
        }
    }
    // Tiempo después de la operación
    fin = clock();
    //Diferencia de tiempo:
    tiempo = (double)(fin - inicio) / CLOCKS_PER_SEC;
    printf("Tiempo transcurrido (ikj): %f s\n", tiempo);
    //**************************************************************************************************************************************

    //**************************************************************************************************************************************
    // Tiempo antes de la operación
    inicio = clock();
    for (j = 0; j < n; ++j) {
        for (i = 0; i < n; ++i) {
            for (k = 0; k < n; ++k) {
                matrizE[i][j] += matrizA[i][k] * matrizB[k][j];
            }
        }
    }
    // Tiempo después de la operación
    fin = clock();
    //Diferencia de tiempo:
    tiempo = (double)(fin - inicio) / CLOCKS_PER_SEC;
    printf("Tiempo transcurrido (jik): %f s\n", tiempo);
    //**************************************************************************************************************************************

    //**************************************************************************************************************************************
    // Tiempo antes de la operación
    inicio = clock();
    for (j = 0; j < n; ++j) {
        for (k = 0; k < n; ++k) {
            for (i = 0; i < n; ++i) {
                matrizC[i][j] += matrizA[i][k] * matrizB[k][j];
            }
        }
    }
    // Tiempo después de la operación
    fin = clock();
    //Diferencia de tiempo:
    tiempo = (double)(fin - inicio) / CLOCKS_PER_SEC;
    printf("Tiempo transcurrido (jki): %f s\n", tiempo);
    //**************************************************************************************************************************************

    //**************************************************************************************************************************************
    // Tiempo antes de la operación
    inicio = clock();
    for (k = 0; k < n; ++k) {
        for (i = 0; i < n; ++i) {
            for (j = 0; j < n; ++j) {
                matrizG[i][j] += matrizA[i][k] * matrizB[k][j];
            }
        }
    }
    // Tiempo después de la operación
    fin = clock();
    //Diferencia de tiempo:
    tiempo = (double)(fin - inicio) / CLOCKS_PER_SEC;
    printf("Tiempo transcurrido (kij): %f s\n", tiempo);
    //**************************************************************************************************************************************

    //**************************************************************************************************************************************
    // Tiempo antes de la operación
    inicio = clock();
    for (k = 0; k < n; ++k) {
        for (j = 0; j < n; ++j) {
            for (i = 0; i < n; ++i) {
                matrizH[i][j] += matrizA[i][k] * matrizB[k][j];
            }
        }
    }
    // Tiempo después de la operación
    fin = clock();
    //Diferencia de tiempo:
    tiempo = (double)(fin - inicio) / CLOCKS_PER_SEC;
    printf("Tiempo transcurrido (kji): %f s\n", tiempo);
    //**************************************************************************************************************************************

    // Liberando memoria
    for (i = 0; i < n; i++) {
        free(matrizA[i]);
        free(matrizB[i]);
        free(matrizC[i]);
        free(matrizD[i]);
        free(matrizE[i]);
        free(matrizF[i]);
        free(matrizG[i]);
        free(matrizH[i]);

    }
    free(matrizA);
    free(matrizB);
    free(matrizC);
    free(matrizD);
    free(matrizE);
    free(matrizF);
    free(matrizG);
    free(matrizH);

    return 0;
}
