#include <stdio.h>

struct Fatura {
    int numero;
    char dataVencimento[11]; // "DD/MM/AAAA" + '\0'
    float valor;
    char status[10]; //"pendente" ou "paga"

    //função exibir definida diretamente na struct
    void exibir() {
        printf("Número: %d | Vencimento: %s | Valor: R$ %.2f | Status: %s\n",
               numero, dataVencimento, valor, status);
    }
};

