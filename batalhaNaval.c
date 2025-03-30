#include <stdio.h>

// Trabalho - Batalha Naval - Nível Novato
// Aluno: Thaynara Ramos

int main() {
    // Tamanho do tabuleiro e dos navios
    int tamanhoTabuleiro = 10;
    int tamanhoNavio = 3;

    // Array para letras de linha (A-J)
    char linha[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

    // Tabuleiro inicializado com 0 (água)
    int tabuleiro[10][10];
    for (int i = 0; i < tamanhoTabuleiro; i++) {
        for (int j = 0; j < tamanhoTabuleiro; j++) {
            tabuleiro[i][j] = 0;  // Água (0) no tabuleiro
        }
    }

    // Definindo as coordenadas para os navios
    int linha_h = 4, coluna_h = 2; // Navio horizontal (novo posicionamento)
    int linha_v = 6, coluna_v = 6; // Navio vertical (novo posicionamento)

    // Posiciona o navio horizontal
    if (coluna_h + tamanhoNavio <= tamanhoTabuleiro) {
        for (int i = 0; i < tamanhoNavio; i++) {
            tabuleiro[linha_h][coluna_h + i] = 3; // Marca a posição do navio
        }
    }

    // Posiciona o navio vertical
    if (linha_v + tamanhoNavio <= tamanhoTabuleiro) {
        for (int i = 0; i < tamanhoNavio; i++) {
            tabuleiro[linha_v + i][coluna_v] = 3; // Marca a posição do navio
        }
    }

    // Exibe o tabuleiro
    printf("   1 2 3 4 5 6 7 8 9 10\n");
    for (int i = 0; i < tamanhoTabuleiro; i++) {
        printf("%c  ", linha[i]); // Exibe a letra da linha
        for (int j = 0; j < tamanhoTabuleiro; j++) {
            printf("%d ", tabuleiro[i][j]); // Exibe o valor da célula do tabuleiro
        }
        printf("\n");
    }

    return 0;
}

