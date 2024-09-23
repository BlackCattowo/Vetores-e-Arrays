#include <stdio.h>
#include <stdlib.h>

int main()
{
    int Variavel = 8;       // Variável Int
    int* Vetor = malloc(sizeof(int)); // Aloca memória para um vetor de 1 elemento
    int** Matriz = malloc(sizeof(int*)); // Aloca memória para uma "matriz" de 1 elemento (um vetor de ponteiros)


    Vetor[0] = Variavel; // Atribuir o endereço de Variavel ao primeiro elemento de Vetor
    Matriz[0] = Vetor; // Atribuir o ponteiro do vetor ao primeiro elemento da "matriz"

    // Imprimir os valores e endereços
    printf("&Variavel: %d (Valor correspondente ao armazenamento da variavel)\n", &Variavel);
    printf("(void*)&Variavel): %p (Local do armazenamento da variavel)\n\n", (void*)&Variavel);
    printf("Variavel: %d (Valor da variavel)", Variavel);

    printf("\n\n---------\n\n");

    printf("Vetor: %d (Valor correspondente ao armazenamento do vetor)\n", Vetor);
    printf("(void*)Vetor: %p (Local do armazenamento do vetor)\n\n", (void*)Vetor);
    printf("Vetor[0]: %d (Conteudo do vetor)\n", Vetor[0]);
    printf("*Vetor: %d (Conteudo do vetor via apontamento direto)", *Vetor);

    printf("\n\n---------\n\n");

    printf("Matriz: %d (Valor correspondente ao armazenamento da matriz)\n", Matriz);
    printf("(void*)Matriz: %p (Local do armazenamento da matriz)\n\n", (void*)Matriz);
    printf("Matriz[0]: %d (Valor correspondente ao armazenamento do vetor)\n", Matriz[0]);
    printf("(void*)Matriz[0]: %p (Local do armazenamento do vetor)\n\n", (void*)Matriz[0]);
    printf("Matriz[0][0]: %d (Conteudo do vetor a partir da matriz)\n", Matriz[0][0]);
    printf("**Matriz: %d (Conteudo do vetor via apontamento direto)\n", **Matriz);

    // Liberar a memória alocada
    free(Vetor);
    free(Matriz);

    return 0;
}
