#include <stdio.h>

int main() {
    int matriz[3][3];
    int fila, columna;

    printf("Ingrese los valores de la matriz:\n");

    printf("Ingresando valores en columnas pares:\n");
    for (fila = 0; fila < 3; fila++) {
        for (columna = 0; columna < 3; columna += 2) {
            printf("Ingrese un valor para la fila %d, columna %d: ", fila+1, columna+1);
            scanf("%d", &matriz[fila][columna]);
        }
    }

    printf("Ingresando valores en columnas impares:\n");
    for (fila = 0; fila < 3; fila++) {
        for (columna = 1; columna < 3; columna += 2) {
            printf("Ingrese un valor para la fila %d, columna %d: ", fila+1, columna+1);
            scanf("%d", &matriz[fila][columna]);
        }
    }
    printf("\nMatriz:\n");
    for (fila = 0; fila < 3; fila++) {
        for (columna = 0; columna < 3; columna++) {
            printf("%d\t", matriz[fila][columna]);
        }
        printf("\n");
    }

    return 0;
}
