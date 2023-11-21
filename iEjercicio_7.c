#include <stdio.h>

#define MAX_CLIENTES 100
#define MAX_TRANSACCIONES 1000

int obtenerIndiceCliente(int cliente, int clientes[], int cantidadClientes) {
    for (int i = 0; i < cantidadClientes; i++) {
        if (clientes[i] == cliente) {
            return i;
        }
    }
    
    return -1;
}


void imprimirListado(int clientes[], int totalDepositos[], int totalExtracciones[], int totalComisiones[], int totalIntereses[], int saldo[]) {
    printf("N° De Cliente\tTotal Depósitos\tTotal Extracciones\tTotal Comisiones\tTotal Intereses\tSaldo\n");
    for (int i = 0; i < MAX_CLIENTES; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", clientes[i], totalDepositos[i], totalExtracciones[i], totalComisiones[i], totalIntereses[i], saldo[i]);
    }
}

int main() {
    int clientes[MAX_CLIENTES];
    int totalDepositos[MAX_CLIENTES] = {0};
    int totalExtracciones[MAX_CLIENTES] = {0};
    int totalComisiones[MAX_CLIENTES] = {0};
    int totalIntereses[MAX_CLIENTES] = {0};
    int saldo[MAX_CLIENTES] = {0};

    int transacciones[MAX_TRANSACCIONES][4];
    int cantidadTransacciones = 0;

    int cliente, tipoTransaccion, monto;

    printf("Ingrese los datos de la transacción (cliente, tipo de transacción, monto):\n"
           "Use 0 para cliente cuando quiera finalizar.\n");

  
    while (1) {
        scanf("%d", &cliente);
        if (cliente == 0) {
            break;
        }

        scanf("%d", &tipoTransaccion);
        scanf("%d", &monto);

        int indiceCliente = obtenerIndiceCliente(cliente, clientes, MAX_CLIENTES);

        switch (tipoTransaccion) {
            case 1:
                totalDepositos[indiceCliente] += monto;
                saldo[indiceCliente] += monto;
                break;
            case 2: 
                totalExtracciones[indiceCliente] += monto;
                saldo[indiceCliente] -= monto;
                break;
            case 3: 
                totalComisiones[indiceCliente] += monto;
                saldo[indiceCliente] -= monto;
                break;
            case 4: 
                totalIntereses[indiceCliente] += monto;
                saldo[indiceCliente] += monto;
                break;
            default:
                printf("Tipo de transacción no válido.\n");
                break;
        }

        
        if (indiceCliente == -1) {
            clientes[cantidadTransacciones] = cliente;
            cantidadTransacciones++;
        }
    }
    
    imprimirListado(clientes, totalDepositos, totalExtracciones, totalComisiones, totalIntereses, saldo);

    int maxDeposito = 0;

    for (int i = 0; i < MAX_CLIENTES; i++) {
        if (totalDepositos[i] > maxDeposito) {
            maxDeposito = totalDepositos[i];
        }
    }

    printf("\nClientes con la mayor cantidad depositada (%d):\n", maxDeposito);
    for (int i = 0; i < MAX_CLIENTES; i++) {
        if (totalDepositos[i] == maxDeposito) {
            printf("Cliente %d\n", clientes[i]);
        }
    }

    return 0;
}
