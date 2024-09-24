#include <stdio.h>
#include <stdlib.h>

// Função para adicionar um elemento ao vetor
int* adicionar_elemento_ao_vetor(int* Vetor, int* tamanho, int novo_elemento) 
{
    // Redimensiona o vetor para acomodar o novo elemento
    Vetor = (int*)realloc(Vetor, (*tamanho + 1) * sizeof(int));
    
    // Verifica se o realloc foi bem-sucedido
    if (Vetor == NULL) 
    {
        printf("Erro ao alocar memória para o vetor!\n");
        exit(1);
    }

    // Adiciona o novo elemento e incrementa o tamanho
    Vetor[*tamanho] = novo_elemento;
    (*tamanho)++;

    return Vetor;
}

// Função para adicionar um vetor de dois elementos à matriz
int** adicionar_vetor_a_matriz(int** Matriz, int* linhas, int* novo_vetor, int tamanho_vetor) 
{
    // Redimensiona a matriz para acomodar o novo vetor
    Matriz = (int**)realloc(Matriz, (*linhas + 1) * sizeof(int*));

    if (Matriz == NULL) 
    {// Verifica se o realloc foi bem-sucedido
        printf("Erro ao alocar memória para a matriz!\n");
        exit(1);
    }

    // Adiciona o novo vetor à nova linha da matriz
    Matriz[*linhas] = (int*)malloc(tamanho_vetor * sizeof(int));
    
    for (int i = 0; i < tamanho_vetor; i++) 
    {// Copia cada um dos elementos do vetor para a matriz
        Matriz[*linhas][i] = novo_vetor[i];
    }

    (*linhas)++;

    return Matriz;
}


int main()
{   //Observação 1
    int Variavel = 8, Tamanho_Vetor = 1, Tamanho_Matriz = 1; // Variável Int original e Tamanho originais do vetor e matriz.
    int* Vetor = (int*)malloc(sizeof(int)); // Aloca memória para um vetor de 1 elemento
    int** Matriz = (int**)malloc(sizeof(int*)); // Aloca memória para uma "matriz" de 1 elemento (um vetor de ponteiros)


    Vetor[0] = Variavel; // Atribuir o endereço de Variavel ao primeiro elemento de Vetor
    Matriz[0] = Vetor; // Atribuir o ponteiro do vetor ao primeiro elemento da "matriz"

    printf("\n\n<>--------------<>--------------<>\n");
    printf("<>     *Declarar e apontar*     <>\n");
    printf("<>--------------<>--------------<>\n\n");

    printf("=> Declarando inteiros e arrays:");
    printf("\n--------------------------------------------------\n");
    printf("int Variavel = 8, Tamanho_Vetor = 1, Tamanho_Matriz = 1;\n");
    printf("int* Vetor = (int*)malloc(sizeof(int));\n");
    printf("int** Matriz = (int**)malloc(sizeof(int*));\n\n");
    printf("Vetor[0] = Variavel;\n");
    printf("Matriz[0] = Vetor;");
    printf("\n--------------------------------------------------\n");

    printf("\n=> Apontando para a Variavel:");
    printf("\n--------------------------------------------------\n");
    printf("&Variavel: %d (Valor correspondente ao armazenamento da variavel)\n", &Variavel);
    printf("(void*)&Variavel): %p (Local do armazenamento da variavel)\n\n", (void*)&Variavel);
    printf("Variavel: %d (Valor da variavel)", Variavel);
    printf("\n--------------------------------------------------\n");

    printf("\n=> Apontando para o Vetor:");
    printf("\n--------------------------------------------------\n");
    printf("Vetor: %d (Valor correspondente ao armazenamento do vetor)\n", Vetor);
    printf("(void*)Vetor: %p (Local do armazenamento do vetor)\n\n", (void*)Vetor);
    printf("Vetor[0]: %d (Conteudo do vetor)\n", Vetor[0]);
    printf("*Vetor: %d (Conteudo do vetor via apontamento direto)", *Vetor);
    printf("\n--------------------------------------------------\n");

    printf("\n=> Apontando para a Matriz:");
    printf("\n--------------------------------------------------\n");
    printf("Matriz: %d (Valor correspondente ao armazenamento da matriz)\n", Matriz);
    printf("(void*)Matriz: %p (Local do armazenamento da matriz)\n\n", (void*)Matriz);
    printf("Matriz[0]: %d (Valor correspondente ao armazenamento do vetor)\n", Matriz[0]);
    printf("(void*)Matriz[0]: %p (Local do armazenamento do vetor)\n\n", (void*)Matriz[0]);
    printf("Matriz[0][0]: %d (Conteudo do vetor a partir da matriz)\n", Matriz[0][0]);
    printf("**Matriz: %d (Conteudo do vetor via apontamento direto)", **Matriz);
    printf("\n--------------------------------------------------\n");


    printf("\n\n<>--------------<>--------------<>\n");
    printf("<>     *Alterando a Matriz*     <>\n");
    printf("<>--------------<>--------------<>\n\n");

    // Adicionando um novo elemento (7) ao vetor
    Vetor = adicionar_elemento_ao_vetor(Vetor, &Tamanho_Vetor, 7);
    // Atualiza a matriz com o vetor expandido
    Matriz[0] = Vetor;

    printf("=> Adicionando elemento 7 no vetor original:");
    printf("\n--------------------------------------------------\n");
    printf("*Cria funcao adicionar_elemento_ao_vetor*\n");
    printf("// Funcao para adicionar um elemento ao vetor:\n");
    printf("int* adicionar_elemento_ao_vetor(int* Vetor, int* tamanho, int novo_elemento)\n\n");
    printf("    // Redimensiona o vetor para acomodar o novo elemento\n");
    printf("    Vetor = (int*)realloc(Vetor, (*tamanho + 1) * sizeof(int));\n\n");
    printf("    // Adiciona o novo elemento\n");
    printf("    Vetor[*tamanho] = novo_elemento;\n\n");
    printf("    // Incrementa o tamanho\n");
    printf("    (*tamanho)++;\n\n");

    printf("*Chama a funcao*\n");
    printf("Vetor = adicionar_elemento_ao_vetor(Vetor, &Tamanho_Vetor, 7);\n");
    printf("*Atualiza a matriz com o vetor expandido*\n");
    printf("Matriz[0] = Vetor;");
    printf("\n--------------------------------------------------\n");

    // Adicionando um vetor de dois elementos (2, 5) à matriz
    int Tamanho_NovoVetor = 2;
    int Novo_Vetor[2] = {2, 5}; //Observação 2
    Matriz = adicionar_vetor_a_matriz(Matriz, &Tamanho_Matriz, Novo_Vetor, 2);

    printf("\n=> Adicionando um Novo Vetor na Matriz:");
    printf("\n--------------------------------------------------\n");
    printf("*Cria novo vetor*\n");
    printf("int Tamanho_NovoVetor = 2;\n");
    printf("int Novo_Vetor[2] = {2, 5};\n\n");
    printf("*Cria funcao adicionar_vetor_a_matriz*\n");
    printf("// Funcao para adicionar um vetor de dois elementos a matriz:\n");
    printf("int** adicionar_vetor_a_matriz(int** Matriz, int* tamanho, int* novo_vetor, int tamanho_vetor)\n\n");
    printf("    // Redimensiona a matriz para acomodar o novo vetor\n");
    printf("    Matriz = (int**)realloc(Matriz, (*tamanho + 1) * sizeof(int*));\n\n");
    printf("    // Adiciona o novo vetor a nova linha da matriz\n");
    printf("    Matriz[*tamanho] = (int*)malloc(tamanho_vetor * sizeof(int));\n\n");
    printf("    // Copia cada um dos elementos do vetor para a matriz\n");
    printf("    for (int i = 0; i < tamanho_vetor; i++) {Matriz[*tamanho][i] = novo_vetor[i];}\n\n");
    printf("    // Atualiza o tamanho da matriz\n");
    printf("    (*tamanho)++;;\n\n");

    printf("*Chama a funcao*\n");
    printf("Matriz = adicionar_vetor_a_matriz(Matriz, &Tamanho_Matriz, Novo_Vetor, 2);\n");
    printf("*Atualiza a matriz com o vetor expandido*\n");
    printf("Matriz[0] = Vetor;");
    printf("\n--------------------------------------------------\n");


    printf("\n\n<>--------------<>--------------<>\n");
    printf("<>    *Checar valores novos*    <>\n");
    printf("<>--------------<>--------------<>\n\n");
    printf("=> Vetores atualizados:");
    printf("\n--------------------------------------------------\n");
    printf("Tamanho do Vetor: %d\n", Tamanho_Vetor);
    printf("Vetor:");
    for (int i = 0; i < Tamanho_Vetor; i++) 
    {
        if(i != (Tamanho_Vetor - 1))
        {// Imprime os elementos do vetor desde que não sejam o ultimo
            printf("Vetor[%d] = %d, ", i, Vetor[i]);
        }
        else
        {// Imprime o ultimo elemento do vetor
            printf("Vetor[%d] = %d\n", i, Vetor[i]);
            
        }
    }

    printf("\nTamanho do Novo Vetor: %d\n", Tamanho_NovoVetor);
    printf("Novo Vetor: ");
    for (int i = 0; i < Tamanho_NovoVetor; i++) 
    {
        if(i != (Tamanho_NovoVetor - 1))
        {// Imprime os elementos do vetor desde que não sejam o ultimo
            printf("Vetor[%d] = %d, ", i, Novo_Vetor[i]);
        }
        else
        {// Imprime o ultimo elemento do vetor
            printf("Vetor[%d] = %d", i, Novo_Vetor[i]);
        }
        
    }
    printf("\n--------------------------------------------------\n");


    printf("\n=> Matriz atualizada:");
    printf("\n--------------------------------------------------\n");
    printf("Tamanho da Matriz: %d\n", Tamanho_Matriz);
    printf("Matriz: ");
    for (int i = 0; i < Tamanho_Matriz; i++) 
    {
        printf("Matriz[%d] = {", i); //Imprime o vetor em questão da Matriz
        
        if (i == 0) 
        {// Checa se é o primeiro vetor da matriz
            for (int j = 0; j < Tamanho_Vetor; j++)
            {// Percorre o vetor
                if (j != (Tamanho_Vetor - 1))
                { //Imprime os elementos que não seja o ultimo
                    printf("%d ; ", Matriz[i][j]);
                }
                else
                {// Imprime o ultimo elemento
                    printf("%d} ", Matriz[i][j]);
                }
            }
        }
        
        else if (i == 1) 
        {// Checa se é o segundo vetor da matriz
            for (int j = 0; j < Tamanho_NovoVetor; j++)
            {// Percorre o vetor
                if (j != (Tamanho_NovoVetor - 1))
                { //Imprime os elementos que não seja o ultimo
                    printf("%d ; ", Matriz[i][j]);
                }
                else
                {// Imprime o ultimo elemento
                    printf("%d}", Matriz[i][j]);
                }
            }
        }
        
    }
    printf("\n--------------------------------------------------\n");


    //Liberação de memória
    for (int i = 0; i < Tamanho_Matriz; i++) 
    {// Observação 3
        free(Matriz[i]);
    }
    free(Matriz);

    return 0;
}

/*
Observação 1: deve se declarar o tipo da variavel ao usar malloc quando se trabalha apenas em C, ou seja
se usa int* Vetor = (int*)malloc(sizeof(int)); ao invés de int* Vetor = malloc(sizeof(int));

Observação 2: Embora seja tentador declarar o vetor com tamanho dependente de uma variavél, nós não podemos
fazer isso em C, ou seja, se usa int Novo_Vetor[2] = {2, 5}; ao invés de Novo_Vetor[Tamanho_NovoVetor] = {2, 5};
mesmo que Tamanho_NovoVetor já tenha sido declarado préviamente. A única forma de fazer isso seria ou usando 
#define previamente para transformar Tamanho_NovoVetor em uma constante através do pre-compilador, ou declarar o
Novo_Vetor da seguinte forma: int* Novo_Vetor = (int*)malloc(Tamanho_NovoVetor * sizeof(int));

Observação 3: Cada vetor precisa ter a memória liberada separadamente, então ao invés de escrevermos free(Vetor)
nós usamos o for e liberamos todos os vetores dentro da matriz usando free(Matriz[i]);
Logo após isso liberamos a Matriz como um todo usando free(Matriz);
*/