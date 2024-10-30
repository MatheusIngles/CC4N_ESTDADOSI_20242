/* Implementação do código de shellsort
    Coloquei coisas extras, como o tempo que levou para executar a organização e o conteúdo do array é sorteado.
    Ta ai:
    
    Nome: Matheus Endlich Silveira
    Matricula: 202305392
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void SelectionSort(int size, int *v) {
    // Loop externo percorre cada posição do array para garantir que cada elemento seja posicionado corretamente.
    for(int i = 0; i < size; i++) {
        // Assume que o menor elemento é o atual (v[i]) e armazena sua posição.
        int menor_atual = v[i], posicao_do_menor = i;
        
        // Loop interno busca o menor elemento na sublista que vai da posição 'i' até o final.
        for(int j = i; j < size; j++) {
            // Se encontrar um elemento menor que o 'menor_atual', atualiza 'menor_atual' e sua posição.
            if(v[j] < menor_atual) {
                menor_atual = v[j];
                posicao_do_menor = j;
            }
        }
        
        // Troca o elemento atual (v[i]) pelo menor elemento encontrado na sublista.
        int aux = v[i];
        v[i] = v[posicao_do_menor];
        v[posicao_do_menor] = aux;
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
    SelectionSort(size, v); // Chama a função de ordenação
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
