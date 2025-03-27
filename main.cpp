#include "Arvore.h"   
#include <stdio.h>    

int main() {
    Arvore arvore;           
    int opcao, numero;       //variáveis para armazenar a opção do menu e o número da fatura.
    char data[11], status[10];  //arrays para armazenar a data de vencimento e o status da fatura.
    float valor;             

    //loop do menu principal
    do {
        printf("\nSistema de Gerenciamento de Faturas\n");
        printf("1. Inserir Fatura\n2. Exibir Faturas\n3. Buscar Fatura\n");
        printf("4. Remover Fatura\n5. Sair\nOpção: ");
        scanf("%d", &opcao);  
        getchar();

        switch (opcao) {
            case 1: {
                printf("Número: ");
                scanf("%d", &numero);    //lê o número da fatura
                getchar(); // para evitar problemas com fgets após o scanf

                printf("Data (DD/MM/AAAA): ");
                fgets(data, sizeof(data), stdin); 
                if (data[9] == '\n') {
                    data[9] = '\0'; //substitui o caractere '\n' por '\0' para remover a quebra de linha
                }

                printf("Valor: ");
                scanf("%f", &valor);   
                getchar(); //para evitar problemas com fgets após o scanf

                printf("Status (pendente/paga): ");
                fgets(status, sizeof(status), stdin);  
                if (status[9] == '\n') {
                    status[9] = '\0'; 
                }

                //cria uma instância de fatura e atribui os valores inseridos
                Fatura fatura;
                fatura.numero = numero;
                fatura.valor = valor;
    
                //copia os dados de data e status para a fatura
                for (int i = 0; i < 10; i++) {
                    fatura.dataVencimento[i] = data[i];
                    fatura.status[i] = status[i];
                }

                //chama a função para inserir a fatura na árvore
                arvore.inserir(fatura);
                printf("Fatura inserida com sucesso!\n");
                break;
            }

            case 2:
                arvore.exibir(arvore.raiz);   // Chama a função que exibe todas as faturas na árvore
                break;

            case 3: {
                printf("Número da fatura: ");
                scanf("%d", &numero);   //lê o número da fatura que o usuário quer buscar

                TreeNode* resultado = arvore.buscar(numero);   //chama a função de busca na árvore
                if (resultado) {
                    //caso a fatura seja encontrada
                    printf("Fatura encontrada:\n");
                    printf("Número: %d | Data: %s | Valor: %.2f | Status: %s\n",
                           resultado->fatura.numero, resultado->fatura.dataVencimento,
                           resultado->fatura.valor, resultado->fatura.status);
                } else {
                    //caso a fatura não seja encontrada
                    printf("Fatura não encontrada!\n");
                }
                break;
            }

            case 4:
                printf("Número da fatura: ");
                scanf("%d", &numero);   //lê o número da fatura a ser removida
                arvore.remover(numero);  //chama a função para remover a fatura da árvore
                printf("Fatura removida com sucesso!\n");
                break;
        }
    } while (opcao != 5);   //repete o menu até o usuário escolher a opção 5 (sair)

    return 0;   
}
