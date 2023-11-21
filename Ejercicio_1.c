#include <stdio.h>

int main() {
    int matriz[6][5] = {0}; 
    int fila, columna, valor;

    printf("Ingrese la fila (1-6) -----------------------------> (0 en fila para salir):\n");
    scanf("%d", &fila);

    while (fila != 0) {
        if (fila >= 1 && fila <= 6) {
            printf("Ingrese la columna (1-5): ");
            scanf("%d", &columna);

            if (columna >= 1 && columna <= 5) {
                printf("Ingrese el valor a cargar: ");
                scanf("%d", &valor);
                matriz[fila - 1][columna - 1] = valor; 
            } else {
                printf("La columna debe estar en el rango de 1 a 5.\n");
            }
        } else {
            printf("La fila debe estar en el rango de 1 a 6.\n");
        }

        printf("Ingrese la fila (1-6) y columna (1-5) para cargar un valor (0 en fila para salir):\n");
        scanf("%d", &fila);
    }

    
    printf("Matriz por filas:\n");
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }

    printf("Matriz por columnas:\n");
    for (int j = 0; j < 5; j++) {
        for (int i = 0; i < 6; i++) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}
