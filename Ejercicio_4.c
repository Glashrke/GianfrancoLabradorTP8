#include <stdio.h>

void ordenarMatriz(int matriz[3][3]) {
    int temp[9];
    int k = 0;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            temp[k++] = matriz[i][j];

    for (int i = 0; i < 9 - 1; i++) {
        for (int j = 0; j < 9 - i - 1; j++) {
            if (temp[j] > temp[j + 1]) {
                int tempSwap = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = tempSwap;
            }
        }
    }

    k = 0;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            matriz[i][j] = temp[k++];
}

void mostrarMatriz(int matriz[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matriz[3][3];

    printf("Ingrese valores para la matriz de 3x3:\n");
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            scanf("%d", &matriz[i][j]);

    ordenarMatriz(matriz);
    printf("Matriz ordenada:\n");
    mostrarMatriz(matriz);

    return 0;
}
