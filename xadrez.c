#include <stdio.h>

#define SIZE 8

// Verifica se a posição está dentro do tabuleiro
int dentro_do_tabuleiro(int x, int y) {
    return x >= 0 && x < SIZE && y >= 0 && y < SIZE;
}

// Mostra a posição (linha, coluna) se for válida
void mostrar_posicao(int x, int y) {
    if (dentro_do_tabuleiro(x, y)) {
        printf("-> (%d, %d)\n", x, y);
    }
}

// -------------------------
// Peças e Movimentos
// -------------------------

// Recursividade: Torre
void mover_torre(int x, int y) {
    printf("Movimentos da Torre:\n");
    for (int i = 0; i < SIZE; i++) {
        if (i != x) mostrar_posicao(i, y); // Movimentos verticais
        if (i != y) mostrar_posicao(x, i); // Movimentos horizontais
    }
}

// Recursividade + Loops Aninhados: Bispo
void mover_bispo(int x, int y) {
    printf("Movimentos do Bispo:\n");
    for (int i = 1; i < SIZE; i++) {
        mostrar_posicao(x + i, y + i); // ↘
        mostrar_posicao(x - i, y - i); // ↖
        mostrar_posicao(x + i, y - i); // ↙
        mostrar_posicao(x - i, y + i); // ↗
    }
}

// Recursividade: Rainha (Torre + Bispo)
void mover_rainha(int x, int y) {
    printf("Movimentos da Rainha:\n");
    mover_torre(x, y);
    mover_bispo(x, y);
}

// Loops Complexos: Cavalo
void mover_cavalo(int x, int y) {
    printf("Movimentos do Cavalo:\n");
    int movs[8][2] = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };
    for (int i = 0; i < 8; i++) {
        int nx = x + movs[i][0];
        int ny = y + movs[i][1];
        mostrar_posicao(nx, ny);
    }
}

// -------------------------
// Função Principal
// -------------------------

int main() {
    int linha, coluna, opcao;

    printf("=== XADREZ: Movimentos das Peças ===\n");
    printf("Digite a linha da peça (0 a 7): ");
    scanf("%d", &linha);
    printf("Digite a coluna da peça (0 a 7): ");
    scanf("%d", &coluna);

    if (!dentro_do_tabuleiro(linha, coluna)) {
        printf("Posição inválida no tabuleiro!\n");
        return 1;
    }

    printf("\nEscolha a peça:\n");
    printf("1 - Torre\n");
    printf("2 - Bispo\n");
    printf("3 - Rainha\n");
    printf("4 - Cavalo\n");
    printf("Opção: ");
    scanf("%d", &opcao);
    printf("\n");

    switch (opcao) {
        case 1: mover_torre(linha, coluna); break;
        case 2: mover_bispo(linha, coluna); break;
        case 3: mover_rainha(linha, coluna); break;
        case 4: mover_cavalo(linha, coluna); break;
        default: printf("Opção inválida!\n");
    }

    return 0;
}