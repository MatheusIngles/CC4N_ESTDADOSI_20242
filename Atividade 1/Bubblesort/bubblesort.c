/* Implementação do código de shellsort
    Coloquei coisas extras, como o tempo que levou para executar a organização e o conteúdo do array é sorteado.
    Ta ai:
    
    Nome: Matheus Endlich Silveira
    Matricula: 202305392
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void bubblesort(int size, int *v){
    for(int i = 0; i <size; i++){ // Laço externo percorre todo o array
        for(int j = 0; j < size-1; j++){ // Laço interno compara e troca elementos adjacentes
            if(v[j] > v[j+1]){ // Se o elemento atual é maior que o próximo
                int aux = v[j]; // Armazena o valor de v[j] em uma variável auxiliar
                v[j] = v[j+1]; // Troca v[j] pelo valor de v[j+1]
                v[j+1] = aux; // Atribui o valor original de v[j] a v[j+1]
            }
        }
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
    bubblesort(size, v); // Chama a função de ordenação
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
