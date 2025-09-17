#include <stdio.h>

int main() {
    int tabuleiro[10][10];
    
   
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Posicionar os Navios
    int navio_horizontal[3] = {3, 3, 3};
    int navio_vertical[3] = {3, 3, 3};

 
    int inicio_navio_horizontal_linha = 2; 
    int inicio_navio_horizontal_coluna = 4; 

    int inicio_navio_vertical_linha = 5; 
    int inicio_navio_vertical_coluna = 2; 


    for (int i = 0; i < 3; i++) {
        tabuleiro[inicio_navio_horizontal_linha][inicio_navio_horizontal_coluna + i] = navio_horizontal[i];
    }
    

    for (int i = 0; i < 3; i++) {
        tabuleiro[inicio_navio_vertical_linha + i][inicio_navio_vertical_coluna] = navio_vertical[i];
    }

  
    
 
    printf("  "); 
    for (char c = 'A'; c <= 'J'; c++) {
        printf(" %c", c);
    }
    printf("\n"); 

    // Loops aninhados para percorrer e imprimir cada elemento
    for (int i = 0; i < 10; i++) {
 
        printf("%2d", i + 1); 
        for (int j = 0; j < 10; j++) {
            printf(" %d", tabuleiro[i][j]); 
        }
        printf("\n"); 
    }

    return 0;
}