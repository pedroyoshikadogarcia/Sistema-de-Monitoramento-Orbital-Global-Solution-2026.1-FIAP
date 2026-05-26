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

void visualizarStatus() {
    printf(CYAN "\n--- Historico de Leituras ---\n" RESET);
    if (total_leituras == 0) {
        printf(YELLOW "Nenhum dado registrado ainda. O historico esta vazio.\n" RESET);
        return;
    }
    
    for (int i = 0; i < total_leituras; i++) {
        printf("Leitura %02d | Temp: %.2fC | Energia: %d%% | Comms: %s\n", 
               i + 1, 
               temperaturas[i], 
               energias[i], 
               comunicacoes[i] == 1 ? "OK" : "FALHA");
    }
}

void analisarCondicoes() {
    if (total_leituras == 0) {
        printf(YELLOW "\nNenhum dado para analisar. Insira dados primeiro, comandante!\n" RESET);
        return;
    }
    
    for (int i = 0; i < total_leituras; i++) {
        printf(CYAN "\n--- Analise da Leitura %d ---\n" RESET, i + 1);
        int tudo_ok = 1;
 
        if (temperaturas[i] > 80) {
            printf(RED "[!] ALERTA DE SUPERAQUECIMENTO: %.2fC\n" RESET, temperaturas[i]);
            tudo_ok = 0;
        }
        if (energias[i] < 20) {
            printf(YELLOW "[!] ECONOMIA DE ENERGIA  : %d%%\n" RESET, energias[i]);
            tudo_ok = 0;
        }
        if (comunicacoes[i] == 0) {
            printf(RED "[!] FALHA DE COMUNICACAO!\n" RESET);
            tudo_ok = 0;
        }
        if (tudo_ok)
            printf(GREEN "[OK] Sistemas nominais.\n" RESET);
    }  
}
