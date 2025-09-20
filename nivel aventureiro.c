#include <stdio.h>

int main() {

    int tabuleiro[10][10];

    // Preenche o tabuleiro com 0s (água)
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

 

    // Navio 1: Horizontal 
    int navio1_linha_inicio = 2;
    int navio1_coluna_inicio = 4;

    for (int i = 0; i < 3; i++) {
        // Validação: Checa se a posição está dentro do tabuleiro
        if (navio1_coluna_inicio + i < 10 && tabuleiro[navio1_linha_inicio][navio1_coluna_inicio + i] == 0) {
            tabuleiro[navio1_linha_inicio][navio1_coluna_inicio + i] = 3;
        } else {
            printf("Erro: Navio 1 fora dos limites ou sobreposto.\n");
         
            break;
        }
    }

    // Navio 2: Vertical 
    int navio2_linha_inicio = 5;
    int navio2_coluna_inicio = 7;

    for (int i = 0; i < 3; i++) {
        if (navio2_linha_inicio + i < 10 && tabuleiro[navio2_linha_inicio + i][navio2_coluna_inicio] == 0) {
            tabuleiro[navio2_linha_inicio + i][navio2_coluna_inicio] = 3;
        } else {
            printf("Erro: Navio 2 fora dos limites ou sobreposto.\n");
            break;
        }
    }

    // Navio 3: Diagonal 
    int navio3_linha_inicio = 0;
    int navio3_coluna_inicio = 0;

    for (int i = 0; i < 3; i++) {
        // A linha e a coluna aumentam juntas
        if (navio3_linha_inicio + i < 10 && navio3_coluna_inicio + i < 10 && tabuleiro[navio3_linha_inicio + i][navio3_coluna_inicio + i] == 0) {
            tabuleiro[navio3_linha_inicio + i][navio3_coluna_inicio + i] = 3;
        } else {
            printf("Erro: Navio 3 fora dos limites ou sobreposto.\n");
            break;
        }
    }
    
    // Navio 4: Diagonal 
    int navio4_linha_inicio = 7;
    int navio4_coluna_inicio = 0;

    for (int i = 0; i < 3; i++) {
        // A linha diminui e a coluna aumenta
        if (navio4_linha_inicio - i >= 0 && navio4_coluna_inicio + i < 10 && tabuleiro[navio4_linha_inicio - i][navio4_coluna_inicio + i] == 0) {
            tabuleiro[navio4_linha_inicio - i][navio4_coluna_inicio + i] = 3;
        } else {
            printf("Erro: Navio 4 fora dos limites ou sobreposto.\n");
            break;
        }
    }

    // 3. Exibir o Tabuleiro
    
 
    printf("  "); 
    for (char c = 'A'; c <= 'J'; c++) {
        printf(" %c", c);
    }
    printf("\n"); 

    for (int i = 0; i < 10; i++) {
        printf("%2d", i + 1); 
        for (int j = 0; j < 10; j++) {
            printf(" %d", tabuleiro[i][j]); 
        }
        printf("\n");
    }

    return 0;
}