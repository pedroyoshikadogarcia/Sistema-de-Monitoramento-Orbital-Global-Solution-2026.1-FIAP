#include <stdio.h>
#include <stdlib.h>

#define RESET "\033[0m"
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define GREEN "\033[32m"
#define CYAN "\033[36m"


float temperaturas[100];
int energias[100];
int comunicacoes[100];
int total_leituras = 0;

void inserirDados() {
    if (total_leituras >= 100) {
        printf(RED "\n[!] Memoria de bordo cheia. Nao e possivel armazenar mais dados.\n" RESET);
        return;
    }
    printf(CYAN "\n--- Inserir Dados dos Sensores ---\n" RESET);
    printf("Temperatura atual (C): ");
    scanf("%f", &temperaturas[total_leituras]);
    
    printf("Nivel de energia (%%): ");
    scanf("%d", &energias[total_leituras]);
    
    printf("Status da comunicacao (1=OK, 0=Falha): ");
    scanf("%d", &comunicacoes[total_leituras]);

    if (energias[total_leituras] < 0 || energias[total_leituras] > 100) {
        printf(YELLOW "[!] Energia invalida (0-100). Dado descartado.\n" RESET);
        return;
    }
    if (comunicacoes[total_leituras] != 0 && comunicacoes[total_leituras] != 1) {
        printf(YELLOW "[!] Comunicacao invalida (0 ou 1). Dado descartado.\n" RESET);
        return;
    }
    total_leituras++;
    printf(GREEN "Dados salvos com sucesso na base de registro!\n" RESET);
}
