#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó da árvore AVL
struct NO{
    int info;           // Valor armazenado no nó
    int altura;         // Altura do nó na árvore
    struct NO *esq;     // Ponteiro para o nó da subárvore esquerda
    struct NO *dir;     // Ponteiro para o nó da subárvore direita
};

typedef struct NO* ArvAVL;  // Definição do tipo ArvAVL como ponteiro para o nó

// Função para criar uma árvore AVL (inicializa a raiz como NULL)
ArvAVL* cria_ArvAVL(){
    ArvAVL* raiz = (ArvAVL*) malloc(sizeof(ArvAVL));  // Aloca memória para a raiz da árvore
    if(raiz != NULL)
        *raiz = NULL;  // Inicializa a raiz como NULL (árvore vazia)
    return raiz;
}

// Função recursiva para liberar a memória de um nó e seus filhos
void libera_NO(struct NO* no){
    if(no == NULL)    // Se o nó for NULL, retorna
        return;
    libera_NO(no->esq);  // Libera a subárvore esquerda
    libera_NO(no->dir);  // Libera a subárvore direita
    free(no);           // Libera a memória do nó atual
    no = NULL;          // Aponta o nó para NULL (não afeta o ponteiro original)
}

// Função para liberar a árvore inteira
void libera_ArvAVL(ArvAVL* raiz){
    if(raiz == NULL)   // Se a raiz for NULL, retorna
        return;
    libera_NO(*raiz);  // Libera todos os nós da árvore
    free(raiz);        // Libera a memória da raiz
}

// Função para calcular a altura de um nó
int altura_NO(struct NO* no){
    if(no == NULL)    // Se o nó for NULL, retorna -1 (indicando uma árvore vazia)
        return -1;
    else
        return no->altura;  // Retorna a altura do nó
}

// Função para calcular o fator de balanceamento de um nó
int fatorBalanceamento_NO(struct NO* no){
    return labs(altura_NO(no->esq) - altura_NO(no->dir));  // Diferença entre as alturas das subárvores
}

// Função para retornar o maior valor entre dois inteiros
int maior(int x, int y){
    if(x > y)
        return x;  // Se x for maior, retorna x
    else
        return y;  // Caso contrário, retorna y
}

// Função para verificar se a árvore está vazia
int estaVazia_ArvAVL(ArvAVL *raiz){
    if(raiz == NULL)
        return 1;  // Se a raiz for NULL, a árvore está vazia
    if(*raiz == NULL)
        return 1;  // Se a raiz apontar para NULL, a árvore está vazia
    return 0;  // Caso contrário, a árvore não está vazia
}

// Função para contar o número total de nós na árvore
int totalNO_ArvAVL(ArvAVL *raiz){
    if (raiz == NULL)
        return 0;  // Se a raiz for NULL, não há nós
    if (*raiz == NULL)
        return 0;  // Se a árvore estiver vazia, não há nós
    int alt_esq = totalNO_ArvAVL(&((*raiz)->esq));  // Conta os nós na subárvore esquerda
    int alt_dir = totalNO_ArvAVL(&((*raiz)->dir));  // Conta os nós na subárvore direita
    return(alt_esq + alt_dir + 1);  // Retorna a soma dos nós das subárvores e o nó atual
}

// Função para calcular a altura da árvore (a partir da raiz)
int altura_ArvAVL(ArvAVL *raiz){
    if (raiz == NULL)
        return 0;  // Se a raiz for NULL, a altura é 0
    if (*raiz == NULL)
        return 0;  // Se a árvore estiver vazia, a altura é 0
    int alt_esq = altura_ArvAVL(&((*raiz)->esq));  // Calcula a altura da subárvore esquerda
    int alt_dir = altura_ArvAVL(&((*raiz)->dir));  // Calcula a altura da subárvore direita
    if (alt_esq > alt_dir)
        return (alt_esq + 1);  // Se a altura da subárvore esquerda for maior, retorna a altura da esquerda
    else
        return(alt_dir + 1);  // Caso contrário, retorna a altura da direita
}

// Função para realizar o percurso em pré-ordem e imprimir os dados de cada nó
void preOrdem_ArvAVL(ArvAVL *raiz){
    if(raiz == NULL)    // Se a árvore estiver vazia, retorna
        return;
    if(*raiz != NULL){  // Se o nó não for NULL, imprime o nó
        printf("No %d: H(%d) fb(%d)\n",(*raiz)->info,altura_NO(*raiz),fatorBalanceamento_NO(*raiz));  // Imprime o valor do nó, altura e fator de balanceamento
        preOrdem_ArvAVL(&((*raiz)->esq));  // Chama recursivamente para a subárvore esquerda
        preOrdem_ArvAVL(&((*raiz)->dir));  // Chama recursivamente para a subárvore direita
    }
}

// Função para realizar o percurso em ordem e imprimir os dados de cada nó
void emOrdem_ArvAVL(ArvAVL *raiz){
    if(raiz == NULL)    // Se a árvore estiver vazia, retorna
        return;
    if(*raiz != NULL){  // Se o nó não for NULL, faz o percurso em ordem
        emOrdem_ArvAVL(&((*raiz)->esq));  // Chama recursivamente para a subárvore esquerda
        printf("No %d: H(%d) fb(%d)\n",(*raiz)->info,altura_NO(*raiz),fatorBalanceamento_NO(*raiz));  // Imprime o valor do nó, altura e fator de balanceamento
        emOrdem_ArvAVL(&((*raiz)->dir));  // Chama recursivamente para a subárvore direita
    }
}

// Função para realizar o percurso em pós-ordem e imprimir os dados de cada nó
void posOrdem_ArvAVL(ArvAVL *raiz){
    if(raiz == NULL)    // Se a árvore estiver vazia, retorna
        return;
    if(*raiz != NULL){  // Se o nó não for NULL, faz o percurso em pós-ordem
        posOrdem_ArvAVL(&((*raiz)->esq));  // Chama recursivamente para a subárvore esquerda
        posOrdem_ArvAVL(&((*raiz)->dir));  // Chama recursivamente para a subárvore direita
        printf("No %d: H(%d) fb(%d)\n",(*raiz)->info,altura_NO(*raiz),fatorBalanceamento_NO(*raiz));  // Imprime o valor do nó, altura e fator de balanceamento
    }
}

// Função para consultar um valor na árvore (busca binária)
int consulta_ArvAVL(ArvAVL *raiz, int valor){
    if(raiz == NULL)    // Se a árvore estiver vazia, retorna 0 (não encontrado)
        return 0;
    struct NO* atual = *raiz;  // Começa pela raiz
    while(atual != NULL){  // Enquanto o nó atual não for NULL
        if(valor == atual->info){
            return 1;  // Se o valor for encontrado, retorna 1
        }
        if(valor > atual->info)
            atual = atual->dir;  // Se o valor for maior, vai para a subárvore direita
        else
            atual = atual->esq;  // Se o valor for menor, vai para a subárvore esquerda
    }
    return 0;  // Se o valor não for encontrado, retorna 0
}

// Função para procurar o nó com o menor valor em uma subárvore
struct NO* procuraMenor(struct NO* atual){
    struct NO *no1 = atual;
    struct NO *no2 = atual->esq;
    while(no2 != NULL){  // Vai para a esquerda até encontrar o nó com o menor valor
        no1 = no2;
        no2 = no2->esq;
    }
    return no1;  // Retorna o nó com o menor valor
}

// Funções de rotação para balancear a árvore após inserção
void RotacaoLL(ArvAVL * A){
    printf("Rotação LL\n");
    struct NO* B = (*A)->esq;  // Subárvore esquerda de A
    (*A)->esq = B->dir;  // Faz A apontar para a subárvore direita de B
    B->dir = *A;  // Faz B apontar para A
    (*A)->altura = maior(altura_NO((*A)->esq), altura_NO((*A)->dir)) + 1;  // Atualiza a altura de A
    B->altura = maior(altura_NO(B->esq), (*A)->altura) + 1;  // Atualiza a altura de B
    (*A) = B;  // A árvore A é agora B
}

// Função de rotação à direita (RR)
void RotacaoRR(ArvAVL * A){
    printf("Rotação RR\n");
    struct NO* B = (*A)->dir;  // Subárvore direita de A
    (*A)->dir = B->esq;  // Faz A apontar para a subárvore esquerda de B
    B->esq = *A;  // Faz B apontar para A
    (*A)->altura = maior(altura_NO((*A)->esq), altura_NO((*A)->dir)) + 1;  // Atualiza a altura de A
    B->altura = maior(altura_NO(B->dir), (*A)->altura) + 1;  // Atualiza a altura de B
    (*A) = B;  // A árvore A é agora B
}

// Função de rotação LR (esquerda-direita)
void RotacaoLR(ArvAVL *A){
    RotacaoRR(&(*A)->esq);  // Primeira rotação à direita na subárvore esquerda
    RotacaoLL(A);  // Depois rotação à esquerda no nó atual
}

// Função de rotação RL (direita-esquerda)
void RotacaoRL(ArvAVL *A){
    RotacaoRR(&(*A)->dir);  // Primeira rotação à direita na subárvore direita
    RotacaoLL(A);  // Depois rotação à esquerda no nó atual
}

// Função para inserir um valor na árvore AVL
int insere_ArvBina(ArvAVL *raiz, int valor){
    int res;
    if(*raiz == NULL){  // Se o nó atual for NULL, cria um novo nó
        struct NO *novo =  (struct NO*)  malloc(sizeof(struct NO));
        if(novo == NULL){
            return 0;  // Se não houver memória, retorna 0
        }
        novo->info = valor;  // Atribui o valor ao nó
        novo->altura = 0;  // A altura do nó é 0
        novo->esq = NULL;  // Não há filhos ainda
        novo->dir = NULL;  // Não há filhos ainda
        *raiz = novo;  // Atualiza a raiz para apontar para o novo nó
        return 1;  // Inserção bem-sucedida
    }

    struct NO *atual = *raiz;  // Começa pela raiz
    if(valor < atual->info){  // Se o valor for menor, insere à esquerda
        if((res = insere_ArvBina(&(atual->esq), valor) == 1)){
            if(fatorBalanceamento_NO(atual) >= 2){  // Se a árvore ficou desbalanceada
                if(valor < (*raiz)->esq->info){  // Caso de rotação LL
                    RotacaoLL(raiz);
                }
                else{  // Caso de rotação LR
                    RotacaoLR(raiz);
                }
            }
        }
    }else if (valor > atual->info){  // Se o valor for maior, insere à direita
        if((res = insere_ArvBina(&(atual->dir), valor) == 1)){
            if(fatorBalanceamento_NO(atual) >= 2){  // Se a árvore ficou desbalanceada
                if(valor > (*raiz)->dir->info){  // Caso de rotação RR
                    RotacaoRR(raiz);
                }
                else{  // Caso de rotação RL
                    RotacaoRL(raiz);
                }
            }
        }
    }
    else{
        printf("Valor Duplicado!!!!\a");  // Se o valor já existir, não insere
        return 0; 
    }
    
    atual->altura = maior(altura_NO(atual->esq), altura_NO(atual->dir))+1;  // Atualiza a altura do nó após a inserção
    return res;
}

int main(void) {
    ArvAVL* raiz = cria_ArvAVL();  // Cria a árvore AVL
    int N = 8, dados[8] = {50, 100, 30, 20, 40, 45, 35, 37};
    
    for(int i=0; i<N; i++){  // Insere os dados na árvore
        insere_ArvBina(raiz, dados[i]);
    }

    // liberação de memória (comentada para evitar que o programa seja finalizado prematuramente)
    // libera_ArvAVL(raiz);

    int altura = altura_ArvAVL(raiz);  // Calcula e imprime a altura da árvore
    printf("\nAltura: %d ", altura);

    // Impressão dos percursos da árvore
    printf("\nPréOrdem:\n");
    preOrdem_ArvAVL(raiz);  // Percurso pré-ordem
    printf("\nEmOrdem:");
    emOrdem_ArvAVL(raiz);  // Percurso em-ordem
    printf("\nPosOrdem:");
    posOrdem_ArvAVL(raiz);  // Percurso pós-ordem
    printf("\nFinalizou.");
    return 0;
}
