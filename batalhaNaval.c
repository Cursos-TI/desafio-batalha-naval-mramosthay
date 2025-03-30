#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_HABILIDADE 5

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("    ");
    for (int i = 1; i <= TAMANHO_TABULEIRO; i++) {
        printf(" %d", i);
    }
    printf("\n");

    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("  %c ", 'A' + i);
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            if (tabuleiro[i][j] == 0)
                printf(" 0 ");  // Água
            else if (tabuleiro[i][j] == 3)
                printf(" 3 ");  // Navio
            else if (tabuleiro[i][j] == 5)
                printf(" 5 ");  // Área afetada pela habilidade
        }
        printf("\n");
    }
}

// Função para posicionar o navio em forma de Cone
void posicionarNavioCone(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    // Cone com o ponto de origem no topo
    for (int i = 0; i < 3; i++) {
        for (int j = -i; j <= i; j++) {
            if (linha + i < TAMANHO_TABULEIRO && coluna + j >= 0 && coluna + j < TAMANHO_TABULEIRO) {
                tabuleiro[linha + i][coluna + j] = 3; // Marca a posição do navio
            }
        }
    }
}

// Função para posicionar o navio em forma de Cruz
void posicionarNavioCruz(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    // Cruz com origem no ponto dado
    for (int i = -2; i <= 2; i++) {
        if (linha + i >= 0 && linha + i < TAMANHO_TABULEIRO) {
            tabuleiro[linha + i][coluna] = 3;  // Coluna central
        }
        if (coluna + i >= 0 && coluna + i < TAMANHO_TABULEIRO) {
            tabuleiro[linha][coluna + i] = 3;  // Linha central
        }
    }
}

// Função para posicionar o navio em forma de Octaedro
void posicionarNavioOctaedro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    // Octaedro com origem no ponto dado (forma de losango)
    for (int i = -2; i <= 2; i++) {
        for (int j = -2; j <= 2; j++) {
            if (abs(i) + abs(j) <= 2) {
                if (linha + i >= 0 && linha + i < TAMANHO_TABULEIRO && coluna + j >= 0 && coluna + j < TAMANHO_TABULEIRO) {
                    tabuleiro[linha + i][coluna + j] = 3; // Marca a posição do navio
                }
            }
        }
    }
}

// Função para sobrepor a habilidade Cone
void sobreporHabilidadeCone(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    int cone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE] = {
        {0, 1, 0, 0, 0},
        {1, 1, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 1, 1},
        {0, 0, 0, 1, 0}
    };

    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (cone[i][j] == 1) {
                int x = linha + i - 2; // Ajustando o ponto de origem
                int y = coluna + j - 2;
                if (x >= 0 && x < TAMANHO_TABULEIRO && y >= 0 && y < TAMANHO_TABULEIRO) {
                    tabuleiro[x][y] = 5; // Marca a área afetada
                }
            }
        }
    }
}

// Função para sobrepor a habilidade Cruz
void sobreporHabilidadeCruz(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    int cruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0}
    };

    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (cruz[i][j] == 1) {
                int x = linha + i - 2;
                int y = coluna + j - 2;
                if (x >= 0 && x < TAMANHO_TABULEIRO && y >= 0 && y < TAMANHO_TABULEIRO) {
                    tabuleiro[x][y] = 5; // Marca a área afetada
                }
            }
        }
    }
}

// Função para sobrepor a habilidade Octaedro
void sobreporHabilidadeOctaedro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    int octaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0}
    };

    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (octaedro[i][j] == 1) {
                int x = linha + i - 2;
                int y = coluna + j - 2;
                if (x >= 0 && x < TAMANHO_TABULEIRO && y >= 0 && y < TAMANHO_TABULEIRO) {
                    tabuleiro[x][y] = 5; // Marca a área afetada
                }
            }
        }
    }
}

int main() {
    // Inicializando o tabuleiro 10x10 com água (0)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // Posicionando os navios
    posicionarNavioCone(tabuleiro, 1, 2); // Cone em C2
    posicionarNavioCruz(tabuleiro, 4, 7); // Cruz em E8
    posicionarNavioOctaedro(tabuleiro, 7, 2); // Octaedro em H3

    // Aplicando as habilidades
    sobreporHabilidadeCone(tabuleiro, 2, 2); // Habilidade cone em C3
    sobreporHabilidadeCruz(tabuleiro, 5, 5); // Habilidade cruz em F6
    sobreporHabilidadeOctaedro(tabuleiro, 7, 7); // Habilidade octaedro em H8

    // Exibindo o tabuleiro
    exibirTabuleiro(tabuleiro);

    return 0;
}

