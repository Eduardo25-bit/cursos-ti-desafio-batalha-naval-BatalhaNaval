#include <stdio.h>

// Desafio Batalha Naval - MateCheck
#include <stdio.h>

// Definições globais para facilitar a manutenção
#define TAM_TABULEIRO 10
#define TAM_NAVIO 3
#define AGUA 0
#define NAVIO 3

int main() {
    // Nível Novato - Posicionamento dos Navios
    // -------------------------------------------------------------------------
    
    // 1. Declarar a matriz bidimensional (Tabuleiro 10x10)
    // Inicializamos tudo com 0 (AGUA)
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];
    
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // 2. Declarar os vetores dos navios (tamanho 3)
    int navioHorizontal[TAM_NAVIO] = {NAVIO, NAVIO, NAVIO};
    int navioVertical[TAM_NAVIO] = {NAVIO, NAVIO, NAVIO};

    // Coordenadas iniciais definidas diretamente (Hardcoded)
    int linhaH = 2, colunaH = 4; // Navio Horizontal começa em [2][4]
    int linhaV = 5, colunaV = 8; // Navio Vertical começa em [5][8]

    // 3. Posicionar os navios no tabuleiro
    // Copiando do vetor para a matriz
    
    // Posiciona Navio Horizontal
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linhaH][colunaH + i] = navioHorizontal[i];
    }

    // Posiciona Navio Vertical
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linhaV + i][colunaV] = navioVertical[i];
    }

    // 4. Exibir o tabuleiro e as coordenadas
    printf("\n--- Batalha Naval: Tabuleiro (Nivel Novato) ---\n\n");
    
    // Cabeçalho das colunas
    printf("   ");
    for(int k = 0; k < TAM_TABULEIRO; k++) printf("%d ", k);
    printf("\n");

    for (int i = 0; i < TAM_TABULEIRO; i++) {
        printf("%d  ", i); // Número da linha
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    printf("\nCoordenadas dos Navios:\n");
    printf("Navio Horizontal: Linha %d, Colunas %d a %d\n", linhaH, colunaH, colunaH + TAM_NAVIO - 1);
    printf("Navio Vertical: Coluna %d, Linhas %d a %d\n", colunaV, linhaV, linhaV + TAM_NAVIO - 1);

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}
