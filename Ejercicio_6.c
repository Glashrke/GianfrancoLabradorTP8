#include <stdio.h>

void ordenarPorEdad(int edades[], int socios[], int cantidad) {
    for (int i = 0; i < cantidad - 1; i++) {
        for (int j = 0; j < cantidad - i - 1; j++) {
            if (edades[j] > edades[j + 1]) {
                int tempEdad = edades[j];
                edades[j] = edades[j + 1];
                edades[j + 1] = tempEdad;
                int tempSocio = socios[j];
                socios[j] = socios[j + 1];
                socios[j + 1] = tempSocio;
            }
        }
    }
}

int main() {
    int socios[10];
    int edades[10];
    int cantidad = 0;

    printf("Ingrese el número de socio y la edad (separados por espacio).\n"
           "La carga finaliza cuando se ingresan 10 personas o cuando el número de socio es 0.\n");

    while (cantidad < 10) {
        printf("Ingrese datos para la persona %d: ", cantidad + 1);
        scanf("%d", &socios[cantidad]);

        if (socios[cantidad] == 0) {
            break;
        }

        scanf("%d", &edades[cantidad]);
        cantidad++;
    }

    ordenarPorEdad(edades, socios, cantidad);

    printf("\nLista ordenada por edad:\n");
    printf("Número de Socio\tEdad\n");
    for (int i = 0; i < cantidad; i++) {
        printf("%d\t\t%d\n", socios[i], edades[i]);
    }

    return 0;
}
