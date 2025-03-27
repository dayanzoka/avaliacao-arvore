#include "Arvore.h"

//método para inserir uma nova fatura na árvore
void Arvore::inserir(Fatura fatura) {
    inserir(raiz, fatura);
}

void Arvore::inserir(TreeNode*& node, Fatura fatura) {
    if (node == NULL) {
        node = new TreeNode(fatura);
    } else if (fatura.numero < node->fatura.numero) {
        inserir(node->esquerda, fatura);
    } else {
        inserir(node->direita, fatura);
    }
}

//método para buscar uma fatura pelo número
TreeNode* Arvore::buscar(int numero) {
    return buscar(raiz, numero);
}

TreeNode* Arvore::buscar(TreeNode* node, int numero) {
    if (node == NULL || node->fatura.numero == numero) {
        return node;
    }

    if (numero < node->fatura.numero) {
        return buscar(node->esquerda, numero);
    } else {
        return buscar(node->direita, numero);
    }
}

//método para exibir todas as faturas em ordem
void Arvore::exibir(TreeNode* node) {
    if (node != NULL) {
        exibir(node->esquerda);
        node->fatura.exibir();
        exibir(node->direita);
    }
}

//método para remover uma fatura pela chave
void Arvore::remover(int numero) {
    raiz = remover(raiz, numero);
}

TreeNode* Arvore::remover(TreeNode* node, int numero) {
    if (node == NULL) return node;

    if (numero < node->fatura.numero) {
        node->esquerda = remover(node->esquerda, numero);
    } else if (numero > node->fatura.numero) {
        node->direita = remover(node->direita, numero);
    } else {  
        if (node->esquerda == NULL) {
            TreeNode* temp = node->direita;
            delete node;
            return temp;
        } else if (node->direita == NULL) {
            TreeNode* temp = node->esquerda;
            delete node;
            return temp;
        } else {
            //nó com dois filhos: pega o menor da subárvore direita
            TreeNode* temp = node->direita;
            while (temp && temp->esquerda != NULL)
                temp = temp->esquerda;

            //substitui o valor do nó a ser removido pelo sucessor
            node->fatura = temp->fatura;
            node->direita = remover(node->direita, temp->fatura.numero);
        }
    }
    return node;
}
