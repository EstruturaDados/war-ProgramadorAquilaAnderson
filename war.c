// ============================================================================
//         PROJETO WAR ESTRUTURADO - DESAFIO DE CÓDIGO

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ===== STRUCT =====
typedef struct {
    char nome[30];
    char cor[15];
    int tropas;
} Territorio;

// ===== CADASTRO =====
void cadastrarTerritorios(Territorio* mapa) {
    printf("\nVamos cadastrar 5 territorios iniciais do nosso jogo WAR.\n");

    for (int i = 0; i < 5; i++) {
        printf("\n--- Territorio %d ---\n", i + 1);

        printf("Nome do Territorio: ");
        scanf(" %[^\n]", mapa[i].nome);

        printf("Cor do Exercito: ");
        scanf(" %[^\n]", mapa[i].cor);

        printf("Quantidade de Tropas: ");
        scanf("%d", &mapa[i].tropas);
    }
}

// ===== EXIBIR MAPA =====
void mostrarMapa(Territorio* mapa) {
    printf("\n===== MAPA DOS TERRITORIOS =====\n\n");

    for (int i = 0; i < 5; i++) {
        printf("%d. %s (Exercito %s, Tropas: %d)\n",
               i+1, mapa[i].nome, mapa[i].cor, mapa[i].tropas);
    }
}

// ===== ATAQUE =====
void atacar(Territorio* atacante, Territorio* defensor) {

    printf("\n---RESULTADO DA BATALHA---\n");

    int dadoAtacante = (rand() % 6) + 1;
    int dadoDefensor = (rand() % 6) + 1;

    printf("O atacante %s rolou um dado e tirou resultado: %d\n",
           atacante->nome, dadoAtacante);

    printf("O defesor %s rolou um dado e tirou: %d\n",
           defensor->nome, dadoDefensor);

    if (dadoAtacante > dadoDefensor) {
        printf("VITORIA DO ATAQUE! O defesor perdeu 1 tropa.\n");
        defensor->tropas--;

        if (defensor->tropas <= 0) {
            defensor->tropas = atacante->tropas / 2;
            strcpy(defensor->cor, atacante->cor);

            printf("O território %s foi CONQUISTADO pelo Exército %s!\n",
                   defensor->nome, atacante->cor);
        }

    } else if (dadoDefensor > dadoAtacante) {
        printf("DEFESA RESISTIU! O atacante perdeu 1 tropa.\n");
        atacante->tropas--;

        if (atacante->tropas < 1)
            atacante->tropas = 1;

    } else {
        printf("EMPATE! Nenhuma tropa foi perdida.\n");
    }

    printf("\nprecione Enter para continuar para o proximo turno...");
    getchar(); // limpa ENTER
    getchar(); // espera ENTER
}

// ===== FASE DE ATAQUE =====
void faseAtaque(Territorio* mapa) {
    int atk, def;

    while (1) {
        mostrarMapa(mapa);

        printf("\n--- FASE DE ATAQUE ---\n");
        printf("Escolha o territorio atacante (1 a 5, ou 0 para sair): ");
        scanf("%d", &atk);

        if (atk == 0) return;

        printf("Escolha o territorio defensor (1 a 5): ");
        scanf("%d", &def);

        if (atk < 1 || atk > 5 || def < 1 || def > 5 || atk == def) {
            printf("\nEscolha inválida!\n");
            continue;
        }

        if (strcmp(mapa[atk-1].cor, mapa[def-1].cor) == 0) {
            printf("\nVocê não pode atacar um território aliado!\n");
            continue;
        }

        atacar(&mapa[atk-1], &mapa[def-1]);
    }
}

// ===== MAIN =====
int main() {
    srand(time(NULL));

    // sempre serão 5 territórios
    Territorio* mapa = (Territorio*) malloc(5 * sizeof(Territorio));

    cadastrarTerritorios(mapa);

    printf("\nCadastro concluído! Segue o mapa inicial:\n");
    mostrarMapa(mapa);

    faseAtaque(mapa);

    free(mapa);

    return 0;
}