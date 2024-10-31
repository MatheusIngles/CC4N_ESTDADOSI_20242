/* Implementação do código de quickSort
    Coloquei coisas extras, como o tempo que levou para executar a organização e o conteúdo do array é sorteado.
    Ta ai:
    
    Nome: Matheus Endlich Silveira
    Matricula: 202305392
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função Merge para combinar as duas metades ordenadas
int particiona(int *V, int inicio, int final) {
    int esq, dir, pivo, aux;
    esq = inicio; // Define o índice da esquerda como o início do vetor
    dir = final; // Define o índice da direita como o final do vetor
    pivo = V[inicio]; // Seleciona o elemento inicial como pivô

    while (esq < dir) { // Loop até que os ponteiros da esquerda e direita se encontrem
        while (esq <= final && V[esq] <= pivo) // Avança o ponteiro da esquerda enquanto o elemento for menor ou igual ao pivô
            esq++;
        while (dir >= 0 && V[dir] > pivo) // Recua o ponteiro da direita enquanto o elemento for maior que o pivô
            dir--;
        
        if (esq < dir) { // Se os ponteiros não se cruzaram, troca os elementos nas posições 'esq' e 'dir'
            aux = V[esq];
            V[esq] = V[dir];
            V[dir] = aux;
        }
    }
    
    // Posiciona o pivô em seu lugar correto no vetor
    V[inicio] = V[dir];
    V[dir] = pivo;
    return dir; // Retorna a posição final do pivô
}


void quickSort(int *V, int inicio, int fim) {
    int pivo;
    if (fim > inicio) { // Condição de parada: se o fim é maior que o início, ainda há elementos para ordenar
        pivo = particiona(V, inicio, fim); // Encontra a posição do pivô e organiza os elementos em torno dele
        quickSort(V, inicio, pivo - 1); // Chama recursivamente o Quicksort para a metade esquerda
        quickSort(V, pivo + 1, fim); // Chama recursivamente o Quicksort para a metade direita
    }
}


// Função que imprime o conteúdo do array
void printarVetor(int size, int *v){
    printf("Vetor %d:\n", size); // Imprime o tamanho do array
    for(int i = 0; i < size; i++){
         printf("%d \t", v[i]); // Imprime cada elemento seguido de uma tabulação
    }
    printf("\n"); // Adiciona uma nova linha ao final para facilitar a leitura
    /*
    Nome: Matheus Endlich Silveira
    Matricula: 202305392
    */
}

int main()
{
    int size = 50; // Define o tamanho do array
    int v[size]; // Declara o array de inteiros
    srand(time(NULL)); // Inicializa o gerador de números aleatórios com o tempo atual
    
    // Preenche o array com valores aleatórios entre 1 e 20
    for(int i = 0 ; i < size; i++){
        v[i] = rand() % 20 + 1;
    }
    
    // Imprime o array antes da ordenação
    printarVetor(size, v);
    
    // Captura o tempo inicial antes da ordenação
    int segundos = clock();
    quickSort(v, 0, size - 1); // Chama a função de ordenação
    int segundos_Passados = clock(); // Captura o tempo após a ordenação
    
    // Imprime o array após a ordenação
    printarVetor(size, v);
    
    // Calcula e imprime o tempo de execução da ordenação em clocks do processador
    printf("Tempo para implementar: %0.1f", difftime(segundos_Passados, segundos));
    
    /*
    Nome: Matheus Endlich Silveira
    Matricula: 202305392
    */

    return 0;
}