#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *esquerda, *direita;
} No;

typedef No* ArvBin;

ArvBin* cria_ArvBin() {
    ArvBin* raiz = (ArvBin*) malloc(sizeof(ArvBin));
    if (raiz != NULL) {
        *raiz = NULL;
    }
    return raiz;
}

int insere_ArvBin(ArvBin* raiz, int valor) {
    if (raiz == NULL) {
        return 0;
    }

    No* novo = (No*) malloc(sizeof(No));
    if (novo == NULL) {
        return 0;
    }

    novo->valor = valor;
    novo->direita = NULL;
    novo->esquerda = NULL;

    if (*raiz == NULL) {
        *raiz = novo;  // Insere na raiz se a árvore estiver vazia
    } else {
        No* atual = *raiz;
        No* ant = NULL;
        while (atual != NULL) {
            ant = atual;
            if (valor == atual->valor) {
                free(novo);  // Valor já existe, não insere
                return 0;
            }
            if (valor > atual->valor) {
                atual = atual->direita;
            } else {
                atual = atual->esquerda;
            }
        }
        if (valor > ant->valor) {
            ant->direita = novo;  // Insere à direita
        } else {
            ant->esquerda = novo;  // Insere à esquerda
        }
    }

    return 1;  // Inserção bem-sucedida
}

void libera_NO(No* no) {
    if (no == NULL) {
        return;
    }
    libera_NO(no->esquerda);
    libera_NO(no->direita);
    free(no);
}

void libera_ArvBin(ArvBin* raiz) {
    if (raiz == NULL || *raiz == NULL) {
        return;
    }
    libera_NO(*raiz);  // Libera os nós da árvore
    free(raiz);        // Libera o ponteiro para a raiz
}

void preOrdem_Arvore(ArvBin* raiz) {
    if (raiz == NULL || *raiz == NULL) {
        return;
    }
    printf("%d\t", (*raiz)->valor);  // Visita o nó atual
    preOrdem_Arvore(&((*raiz)->esquerda));  // Visita a subárvore esquerda
    preOrdem_Arvore(&((*raiz)->direita));   // Visita a subárvore direita
}

void EmOrdem_Arvore(ArvBin* raiz) {
    if (raiz == NULL || *raiz == NULL) {
        return;
    }
    EmOrdem_Arvore(&((*raiz)->esquerda));  // Visita a subárvore esquerda
    printf("%d\t", (*raiz)->valor);        // Visita o nó atual
    EmOrdem_Arvore(&((*raiz)->direita));   // Visita a subárvore direita
}

void PosOrdem_Arvore(ArvBin* raiz) {
    if (raiz == NULL || *raiz == NULL) {
        return;
    }
    PosOrdem_Arvore(&((*raiz)->esquerda));  // Visita a subárvore esquerda
    PosOrdem_Arvore(&((*raiz)->direita));   // Visita a subárvore direita
    printf("%d\t", (*raiz)->valor);         // Visita o nó atual
}

No* remove_atual(No* atual) {
    No *no1, *no2;
    if (atual->esquerda == NULL) {
        no2 = atual->direita;
        free(atual);
        return no2;  // Se o nó tiver apenas o filho direito ou nenhum filho
    }
    no1 = atual;
    no2 = atual->esquerda;
    while (no2->direita != NULL) {
        no1 = no2;
        no2 = no2->direita;
    }
    no2->direita = atual->direita;  // Ajusta a subárvore direita
    free(atual);  // Libera o nó atual
    return no2;  // Retorna o sucessor
}

int remove_ArvBin(ArvBin* raiz, int valor) {
    if (raiz == NULL || *raiz == NULL) {
        return 0;  // Se a árvore estiver vazia, retorna 0
    }

    No* ant = NULL;
    No* atual = *raiz;

    while (atual != NULL) {
        if (valor == atual->valor) {
            if (atual == *raiz) {
                *raiz = remove_atual(atual);  // Remove o nó da raiz
            } else {
                if (ant->direita == atual) {
                    ant->direita = remove_atual(atual);  // Remove à direita
                } else {
                    ant->esquerda = remove_atual(atual);  // Remove à esquerda
                }
            }
            return 1;  // Remoção bem-sucedida
        }

        ant = atual;
        if (valor > atual->valor) {
            atual = atual->direita;  // Vai para a subárvore direita
        } else {
            atual = atual->esquerda;  // Vai para a subárvore esquerda
        }
    }

    return 0;  // Valor não encontrado
}

int main() {
    ArvBin* raiz = cria_ArvBin();
    int N = 8, dados[8] = {50, 100, 30, 20, 40, 45, 35, 37};

    for (int i = 0; i < N; i++) {
        insere_ArvBin(raiz, dados[i]);  // Insere os valores na árvore
    }

    printf("\nPré-Ordem:\n");
    preOrdem_Arvore(raiz);  // Exibe a árvore em pré-ordem

    remove_ArvBin(raiz, 20);  // Remove o nó com valor 20

    printf("\nApós remoção de 20:\n");
    preOrdem_Arvore(raiz);  // Exibe a árvore após a remoção

    libera_ArvBin(raiz);  // Libera a memória alocada para a árvore
    return 0;
}
