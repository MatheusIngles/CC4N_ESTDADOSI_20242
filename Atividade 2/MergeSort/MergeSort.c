/* Implementação do código de mergeSort
    Coloquei coisas extras, como o tempo que levou para executar a organização e o conteúdo do array é sorteado.
    Ta ai:
    
    Nome: Matheus Endlich Silveira
    Matricula: 202305392
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função Merge para combinar as duas metades ordenadas
void merge(int *V, int inicio, int meio, int fim) {
    int *temp, pl, p2, tamanho, i, j, k;
    int fim1 = 0, fim2 = 0; // Indicadores de fim de cada metade
    tamanho = fim - inicio + 1; // Tamanho do vetor a ser ordenado
    pl = inicio; // Ponteiro para o início da primeira metade
    p2 = meio + 1; // Ponteiro para o início da segunda metade
    temp = (int *) malloc(tamanho * sizeof(int)); // Vetor temporário para armazenar a combinação

    if (temp != NULL) { // Verifica se a memória foi alocada
        for (i = 0; i < tamanho; i++) { // Loop para preencher o vetor temporário
            if (!fim1 && !fim2) { // Nenhuma metade chegou ao fim
                if (V[pl] < V[p2]) // Compara elementos das duas metades
                    temp[i] = V[pl++]; // Copia o elemento da primeira metade
                else
                    temp[i] = V[p2++]; // Copia o elemento da segunda metade
                if (pl > meio) fim1 = 1; // Verifica se a primeira metade terminou
                if (p2 > fim) fim2 = 1; // Verifica se a segunda metade terminou
            } else {
                if (!fim1) // Caso a primeira metade ainda tenha elementos
                    temp[i] = V[pl++];
                else // Caso a segunda metade ainda tenha elementos
                    temp[i] = V[p2++];
            }
        }
        for (j = 0, k = inicio; j < tamanho; j++, k++) // Copia os elementos de volta para o vetor original
            V[k] = temp[j];
        free(temp); // Libera a memória alocada para o vetor temporário
    }
}

void mergeSort(int *V, int inicio, int fim) {
    int meio;
    if (inicio < fim) { // Verifica se o vetor tem mais de um elemento
        meio = (inicio + fim) / 2; // Calcula o meio do vetor
        mergeSort(V, inicio, meio); // Chama recursivamente para a primeira metade
        mergeSort(V, meio + 1, fim); // Chama recursivamente para a segunda metade
        merge(V, inicio, meio, fim); // Combina as duas metades ordenadas
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
        v[i] = rand() % 100 + 1;
    }
    
    // Imprime o array antes da ordenação
    printarVetor(size, v);
    
    // Captura o tempo inicial antes da ordenação
    int segundos = clock();
    mergeSort(v, 0, size - 1); // Chama a função de ordenação
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