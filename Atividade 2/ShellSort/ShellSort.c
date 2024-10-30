/* Implementação do código de shellsort
    Coloquei coisas extras, como o tempo que levou para executar a organização e o conteúdo do array é sorteado.
    Ta ai:
    
    Nome: Matheus Endlich Silveira
    Matricula: 202305392
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função de ordenação Shellsort que recebe o tamanho do array e um ponteiro para o array
void shellsort(int size, int *v){
    int i, j, h = 1, aux;
    
    // Define o valor inicial de 'h' usando a sequência 3x + 1 de Knuth
    for(; h < size; h = h * 3 + 1);
    
    // Loop principal do Shellsort, onde 'h' é reduzido a cada iteração
    do {
        h /= 3; // Reduz o intervalo 'h'
        
        // Realiza a ordenação por inserção para elementos espaçados por 'h'
        for(i = h; i < size; i++){
            aux = v[i]; // Guarda o elemento atual
            j = i;
            
            // Move os elementos do array para criar espaço para o 'aux' na posição correta
            while (j >= h && v[j - h] > aux) {
                v[j] = v[j - h];
                j -= h; // Ajusta o índice com o intervalo 'h'
            }
            v[j] = aux; // Coloca o elemento 'aux' na posição correta
        }
    } while (h != 1); // Continua até que 'h' seja 1 (última iteração)
    
    /*
    Nome: Matheus Endlich Silveira
    Matricula: 202305392
    */
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
    shellsort(size, v); // Chama a função de ordenação
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
