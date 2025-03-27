#include <stdio.h>

//definindo a estrutura de Fatura
struct Fatura {
    int numero;
    char dataVencimento[11];
    float valor;
    char status[10];

    void exibir() {
        printf("Número: %d | Vencimento: %s | Valor: R$ %.2f | Status: %s\n",
               numero, dataVencimento, valor, status);
    }
};

//definindo a estrutura TreeNode
struct TreeNode {
    Fatura fatura;
    TreeNode* esquerda;
    TreeNode* direita;

    TreeNode(Fatura f) : fatura(f), esquerda(NULL), direita(NULL) {} //construtor para inicializar
};

//definindo a estrutura Arvore
struct Arvore {
    TreeNode* raiz;

    Arvore() { raiz = NULL; }

    //métodos da árvore binária
    void inserir(Fatura fatura);
    TreeNode* buscar(int numero);
    void exibir(TreeNode* node);
    void remover(int numero);
    
private:
    void inserir(TreeNode*& node, Fatura fatura);
    TreeNode* buscar(TreeNode* node, int numero);
    TreeNode* remover(TreeNode* node, int numero);
};


