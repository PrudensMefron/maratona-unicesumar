#include <stdio.h>
#include <stdlib.h>


int main(void) {
    // Declaração de variáveis
    int corredores, i, menorTempo, menorTempoIndex;
    
    // Receber o número de corredores
    printf("Digite o número de corredores: ");
    scanf("%d", &corredores);

    // A idéia é criar um array de ponteiros com o número de corredores e recuperar o nome e tempo pelo index
    char **nomes = (char **)malloc(corredores * sizeof(char *)); // Array de ponteiros de nomes
    for (int i = 0; i < corredores; i++) {
        nomes[i] = (char *)malloc(50 * sizeof(char)); // Assumindo que ninguém vai ter um nome com mais de 50 caracteres hahaha
    }
    int *tempos = (int *)malloc(corredores * sizeof(int)); // Array de ponteiros com os tempos

    // Pedir os nomes e tempos para cada corredor identificando-os por número
    for (i = 0; i < corredores; i++) { // Loop para receber os nomes e tempos
        printf("Digite o nome do corredor %d: ", i + 1); 
        scanf("%s", nomes[i]); // Receber o nome do corredor e alocar no indice correspondente no array de nomes
        printf("Digite o tempo do corredor %d em segundos: ", i + 1);
        scanf("%d", &tempos[i]); // Receber o tempo do corredor e alocar no indice correspondente no array de tempos
    }

    // Inicialização do menor tempo como indice 0 e declaração da variável para calculo de indice
    menorTempo = tempos[0];
    menorTempoIndex = 0;

    // Loop para encontrar o menor tempo
    for (i = 1; i < corredores; i++) { 
        if (tempos[i] < menorTempo) { // Compara o tempo atual com o menor tempo definido acima
            menorTempo = tempos[i]; // Se for menor, ele é o novo menor tempo
            menorTempoIndex = i; // atualiza a variável que serve pra consultar o índice
        }
    }

    // Aqui o index do menor tempo serve para achar o nome do corredor que fez o menor tempo =D
    printf("O recorde da prova foi do %s com %d segundos.\n",nomes[menorTempoIndex], menorTempo);

    // liberação de memória alocada
    for (int i = 0; i < corredores; i++) {
        free(nomes[i]);
    }
    free(nomes);
    free(tempos);

    return 0;
}