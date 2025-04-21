#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.


int main() {
    // Nível Novato - Posicionamento dos Navios
    
    // Declarando os arrays e matrizes
    char linha[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int navio_vertical[3] = {3, 3 ,3};
    int navio_horizontal[3] = {3, 3, 3};

    int matriz_cone[3][5];
    int matriz_cruz[3][5];
    int matriz_octaedro[3][5];
    
    int tabuleiro[10][10] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    // Posicionando o navio horizontal C5 D5 E5
    for (int i = 0; i < 3; i++) {
        tabuleiro[4][1 + i] = navio_horizontal[i];
    }
    
    // Posicionando o navio vertical F7 F8 F9
    for (int i = 0; i < 3; i++) {
        tabuleiro[0 + i][4] = navio_vertical[i];
    }

    // Posicinando o navio diagonal A1 B2 C3
    for (int i = 0; i < 3; i++) {
        tabuleiro[i][i] = 3;
    }

    // Posicionando o navio diagonal J10 I9 H8
    for (int i = 0; i < 3; i++) {
        int linha = i;
        int coluna = 8 - i;
        tabuleiro[linha][coluna] = 3;
    }

    // Definindo a matriz do ataque em cone
    for (int linha = 0; linha < 3; linha++) {
        for (int coluna = 0; coluna < 5; coluna++) {
            if (linha == 0 && coluna == 2) {
                matriz_cone[linha][coluna] = 1;
            } else if (linha == 1 && (coluna >= 1 && coluna <=3)) {
                matriz_cone[linha][coluna] = 1;
            } else if (linha == 2) {
                matriz_cone[linha][coluna] = 1;
            } else {
                matriz_cone[linha][coluna] = 0;
            }
        }
    }

    // Definindo a matriz do ataque em cruz
    for (int linha = 0; linha < 3; linha++) {
        for (int coluna = 0; coluna < 5; coluna++) {
            if (linha == 0 && coluna == 2) {
                matriz_cruz[linha][coluna] = 1;
            } else if (linha == 1) {
                matriz_cruz[linha][coluna] = 1;
            } else if (linha == 2 && coluna == 2) {
                matriz_cruz[linha][coluna] = 1;
            } else {
                matriz_cruz[linha][coluna] = 0;
            }
        }
    }

    // Definindo a matriz do ataque em octaedro
    for (int linha = 0; linha < 3; linha++) {
        for (int coluna = 0; coluna < 5; coluna++) {
            if (linha == 0 && coluna == 2) {
                matriz_octaedro[linha][coluna] = 1;
            } else if (linha == 1 && (coluna >= 1 && coluna <=3)) {
                matriz_octaedro[linha][coluna] = 1;
            } else if (linha == 2 && coluna == 2) {
                matriz_octaedro[linha][coluna] = 1;
            } else {
                matriz_octaedro[linha][coluna] = 0;
            }
        }
    }

    // Aplicando o ataque em cone
    int linha_ataque = 0;
    int coluna_ataque = 0;
    for(int linha = 0; linha < 10; linha++) {
        if (linha >= 7 && linha <= 9) {
            for(int coluna = 0; coluna < 10; coluna++) {             
                if (linha_ataque < 3 && coluna_ataque < 5 && coluna >= 5 && coluna <= 9) {                    
                    tabuleiro[linha][coluna] = matriz_cone[linha_ataque][coluna_ataque];
                    coluna_ataque++;
                    if (coluna_ataque == 5) {
                        coluna_ataque = 0;
                    }
                }                        
            }
            linha_ataque++;      
        }  
    }

    // Aplicando o ataque em cruz
    linha_ataque = 0;
    coluna_ataque = 0;
    for(int linha = 0; linha < 10; linha++) {
        if (linha >= 6 && linha <= 8) {
            for(int coluna = 0; coluna < 10; coluna++) {             
                if (linha_ataque < 3 && coluna_ataque < 5 && coluna < 5) {                    
                    tabuleiro[linha][coluna] = matriz_cruz[linha_ataque][coluna_ataque];
                    coluna_ataque++;
                    if (coluna_ataque == 5) {
                        coluna_ataque = 0;
                    }
                }                        
            }
            linha_ataque++;      
        }  
    }

    // Aplicando o ataque em oc
    linha_ataque = 0;
    coluna_ataque = 0;
    for(int linha = 0; linha < 10; linha++) {
        if (linha >= 3 && linha <= 5) {
            for(int coluna = 0; coluna < 10; coluna++) {             
                if (linha_ataque < 3 && coluna_ataque < 5 && coluna >= 5 && coluna <= 9) {                    
                    tabuleiro[linha][coluna] = matriz_octaedro[linha_ataque][coluna_ataque];
                    coluna_ataque++;
                    if (coluna_ataque == 5) {
                        coluna_ataque = 0;
                    }
                }                        
            }
            linha_ataque++;      
        }  
    }

    //Imprimindo o tabuleiro 
    printf("TABULEIRO BATALHA NAVAL\n");
    
    printf("  ");
    for(int l = 0; l < 10; l++) {
        printf(" %c", linha[l]);
    }

    printf("\n");

    for(int coluna = 0; coluna < 10; coluna++) {
        printf("%2d ", coluna+1);
        for(int linha = 0; linha < 10; linha++) {
            printf("%d ", tabuleiro[coluna][linha]);
        }
        printf("\n");
    }

    return 0;
}