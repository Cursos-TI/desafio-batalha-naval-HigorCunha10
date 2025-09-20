#include <stdio.h>
#include <stdlib.h>

// Definimos o tamanho das matrizes 
#define HABILIDADE_TAMANHO 7

// Função para construir a matriz de habilidade de Cone
void construir_cone(int matriz_habilidade[HABILIDADE_TAMANHO][HABILIDADE_TAMANHO]) {
    int centro = HABILIDADE_TAMANHO / 2;
    for (int i = 0; i < HABILIDADE_TAMANHO; i++) {
        for (int j = 0; j < HABILIDADE_TAMANHO; j++) {
            if (i > 0 && j >= centro - i && j <= centro + i) {
                matriz_habilidade[i][j] = 1;
            } else {
                matriz_habilidade[i][j] = 0;
            }
        }
    }
    matriz_habilidade[0][centro] = 1;
}

// Função para construir a matriz de habilidade de Cruz
void construir_cruz(int matriz_habilidade[HABILIDADE_TAMANHO][HABILIDADE_TAMANHO]) {
    int centro = HABILIDADE_TAMANHO / 2;
    for (int i = 0; i < HABILIDADE_TAMANHO; i++) {
        for (int j = 0; j < HABILIDADE_TAMANHO; j++) {
            if (i == centro || j == centro) {
                matriz_habilidade[i][j] = 1;
            } else {
                matriz_habilidade[i][j] = 0;
            }
        }
    }
}

// Função para construir a matriz de habilidade de Octaedro
void construir_octaedro(int matriz_habilidade[HABILIDADE_TAMANHO][HABILIDADE_TAMANHO]) {
    int centro = HABILIDADE_TAMANHO / 2;
    int raio = HABILIDADE_TAMANHO / 2;
    for (int i = 0; i < HABILIDADE_TAMANHO; i++) {
        for (int j = 0; j < HABILIDADE_TAMANHO; j++) {
            if ((abs(i - centro) + abs(j - centro)) <= raio) {
                matriz_habilidade[i][j] = 1;
            } else {
                matriz_habilidade[i][j] = 0;
            }
        }
    }
}

// Função para sobrepor a matriz de habilidade no tabuleiro principal
void aplicar_habilidade(int tabuleiro[10][10], int matriz_habilidade[HABILIDADE_TAMANHO][HABILIDADE_TAMANHO], int origem_linha, int origem_coluna) {
    int centro_habilidade = HABILIDADE_TAMANHO / 2;
    for (int i = 0; i < HABILIDADE_TAMANHO; i++) {
        for (int j = 0; j < HABILIDADE_TAMANHO; j++) {
            if (matriz_habilidade[i][j] == 1) {
                int tabuleiro_linha = origem_linha + (i - centro_habilidade);
                int tabuleiro_coluna = origem_coluna + (j - centro_habilidade);
                if (tabuleiro_linha >= 0 && tabuleiro_linha < 10 && tabuleiro_coluna >= 0 && tabuleiro_coluna < 10) {
                    if (tabuleiro[tabuleiro_linha][tabuleiro_coluna] != 3) {
                         tabuleiro[tabuleiro_linha][tabuleiro_coluna] = 5;
                    }
                }
            }
        }
    }
}

int main() {
    // 1. Definição do Tabuleiro e das Matrizes de Habilidade
    int tabuleiro[10][10];
    int cone[HABILIDADE_TAMANHO][HABILIDADE_TAMANHO];
    int cruz[HABILIDADE_TAMANHO][HABILIDADE_TAMANHO];
    int octaedro[HABILIDADE_TAMANHO][HABILIDADE_TAMANHO];
    
    // 2. Preencher o Tabuleiro com 0s (água)
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // 3. Posicionar os Navios
    tabuleiro[2][4] = 3; tabuleiro[2][5] = 3; tabuleiro[2][6] = 3;
    tabuleiro[5][7] = 3; tabuleiro[6][7] = 3; tabuleiro[7][7] = 3;
    tabuleiro[0][0] = 3; tabuleiro[1][1] = 3; tabuleiro[2][2] = 3;
    tabuleiro[7][0] = 3; tabuleiro[6][1] = 3; tabuleiro[5][2] = 3;
    
    // 4. Construir as Matrizes de Habilidade
    construir_cone(cone);
    construir_cruz(cruz);
    construir_octaedro(octaedro);
    
    // 5. Aplicar as Habilidades no Tabuleiro
    aplicar_habilidade(tabuleiro, cruz, 2, 5);
    aplicar_habilidade(tabuleiro, cone, 7, 2);
    aplicar_habilidade(tabuleiro, octaedro, 5, 5);

    // 6. Exibir o Tabuleiro Completo com Navios e Habilidades
    printf("  ");
    for (char c = 'A'; c <= 'J'; c++) {
        printf(" %c", c);
    }
    printf("\n");

    for (int i = 0; i < 10; i++) {
        printf("%2d", i + 1);
        for (int j = 0; j < 10; j++) {
            // Imprime o número que está na posição da matriz
            printf(" %d", tabuleiro[i][j]); 
        }
        printf("\n");
    }

    return 0;
}