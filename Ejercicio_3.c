#include <stdio.h>

int main() {
    int matriz[5][5];

    printf("Ingrese valores para la diagonal principal:\n");
    for (int i = 0; i < 5; i++) {
        printf("Ingrese valor para la posición [%d][%d]: ", i, i);
        scanf("%d", &matriz[i][i]);
    }

    printf("Ingrese valores para el triángulo superior:\n");
    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 5; j++) {
            printf("Ingrese valor para la posición [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("Ingrese valores para el triángulo inferior:\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < i; j++) {
            printf("Ingrese valor para la posición [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
    
    printf("\nMatriz ingresada:\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}
