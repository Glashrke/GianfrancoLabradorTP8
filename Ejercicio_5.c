#include <stdio.h>

void ordenarNumeros(int numeros[6]) {
   
    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 6; j++) {
            if (numeros[i] > numeros[j]) {
                
                int temp = numeros[i];
                numeros[i] = numeros[j];
                numeros[j] = temp;
            }
        }
    }
}

void mostrarSorteo(int sorteo[3][6]) {
    for (int i = 0; i < 3; i++) {
        printf("Sorteo %d: ", i + 1);
        ordenarNumeros(sorteo[i]);

        for (int j = 0; j < 6; j++) {
            printf("%d ", sorteo[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int sorteos[3][6];
    int frecuencia[43] = {0};
    int numeroN, repeticionesN = 0;

   
    for (int i = 0; i < 3; i++) {
        printf("Ingrese los 6 números del sorteo %d:\n", i + 1);

        for (int j = 0; j < 6; j++) {
            int numero;

            do {
                printf("Número %d: ", j + 1);
                scanf("%d", &numero);

                if (numero < 0 || numero > 42 || frecuencia[numero] > 0) {
                    printf("Número no válido o ya ingresado. Intente de nuevo.\n");
                }
            } while (numero < 0 || numero > 42 || frecuencia[numero] > 0);

            sorteos[i][j] = numero;
            frecuencia[numero]++;
        }
    }

    mostrarSorteo(sorteos);

    printf("\nIngrese un número N para buscar en los sorteos: ");
    scanf("%d", &numeroN);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 6; j++) {
            if (sorteos[i][j] == numeroN) {
                repeticionesN++;
            }
        }
    }

    if (repeticionesN > 0) {
        printf("\nEl número %d se repite %d veces en los sorteos.\n", numeroN, repeticionesN);
    } else {
        printf("\nEl número %d no se repite en los sorteos.\n", numeroN);
    }

    return 0;
}
