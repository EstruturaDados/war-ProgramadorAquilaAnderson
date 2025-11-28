// ============================================================================
//         PROJETO WAR ESTRUTURADO - DESAFIO DE CÓDIGO

#include <stdio.h>
#include <string.h>

/*
    Struct Territorio:
    Armazena as informações básicas de um território:
    - nome
    - cor do exército
    - quantidade de tropas
*/
typedef struct {
    char nome[30];
    char cor[20];
    int tropas;
} Territorio;

int main() {

    Territorio t[5];

    printf("\nVamos cadastrar 5 territorios iniciais do nosso jogo WAR.\n");

    // ========== CADASTRO ==========
    for (int i = 0; i < 5; i++) {
        printf("\n--- Cadastrando Terriorio %d ---\n", i + 1);

        printf("Nome do Territorio: ");
        scanf("%s", t[i].nome);

        printf("Cor do Exercito (ex: Azul, Verde, etc.): ");
        scanf("%s", t[i].cor);

        printf("Numero de Tropas: ");
        scanf("%d", &t[i].tropas);
    }

    // ========== EXIBIÇÃO FINAL ==========
    printf("\n============================================\n");
    printf("        MAPA DOS TERRITORIOS\n");
    printf("============================================\n\n");

    for (int i = 0; i < 5; i++) {
        printf("TERRITORIO %d:\n", i + 1);
        printf(" - Nome: %s\n", t[i].nome);
        printf(" - Dominado por: Exercito %s\n", t[i].cor);
        printf(" - Tropas: %d\n\n", t[i].tropas);
    }

    return 0;
}