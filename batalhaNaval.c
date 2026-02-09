#include <stdio.h>
#include <stdlib.h> // Necessário para a função abs()

// Definições de constantes para facilitar a manutenção
#define TAM_TABULEIRO 10
#define TAM_HABILIDADE 5
#define CENTRO_HABILIDADE 2 // O centro de uma matriz 5x5 é o índice 2

// Códigos visuais
#define AGUA 0
#define NAVIO 3
#define AFETADO 5

int main() {
    // 1. Definição do Tabuleiro e Matrizes de Habilidade
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];
    int matrizCone[TAM_HABILIDADE][TAM_HABILIDADE];
    int matrizCruz[TAM_HABILIDADE][TAM_HABILIDADE];
    int matrizOctaedro[TAM_HABILIDADE][TAM_HABILIDADE];

    // Inicializando o tabuleiro com Água (0)
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // --- CONSTRUÇÃO DINÂMICA DAS MATRIZES DE HABILIDADE ---

    // Loops aninhados para preencher as matrizes de habilidade
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            
            // Lógica do CONE (Triângulo)
            // A lógica aqui é: desenhar um triângulo com o topo na primeira linha
            // Condição: Se a distância da coluna central for menor ou igual à linha atual
            // Ex: Linha 0 aceita dist 0 (só o centro). Linha 1 aceita dist 1 (centro +/- 1).
            if (abs(j - CENTRO_HABILIDADE) <= i && i < 3) { 
                matrizCone[i][j] = 1;
            } else {
                matrizCone[i][j] = 0;
            }

            // Lógica da CRUZ
            // Condição: Se estiver na linha central OU na coluna central
            if (i == CENTRO_HABILIDADE || j == CENTRO_HABILIDADE) {
                matrizCruz[i][j] = 1;
            } else {
                matrizCruz[i][j] = 0;
            }

            // Lógica do OCTAEDRO (Losango)
            // Condição: A soma das distâncias absolutas até o centro deve ser <= raio (2)
            // Isso cria a forma de diamante baseada na geometria de táxi (Manhattan Distance)
            if (abs(i - CENTRO_HABILIDADE) + abs(j - CENTRO_HABILIDADE) <= 2) {
                matrizOctaedro[i][j] = 1;
            } else {
                matrizOctaedro[i][j] = 0;
            }
        }
    }

    // --- APLICAÇÃO DAS HABILIDADES NO TABULEIRO ---
    
    // Definição dos pontos de origem (centros de impacto) no tabuleiro 10x10
    // Vamos espalhar as habilidades para não se sobreporem muito na visualização
    int origemConeL = 1, origemConeC = 2;       // Topo esquerda
    int origemCruzL = 5, origemCruzC = 5;       // Meio
    int origemOctaL = 8, origemOctaC = 8;       // Canto inferior direito

    // Variáveis auxiliares para o cálculo de posição
    int linhaReal, colunaReal;

    // 1. Aplicando o CONE
    printf("Aplicando Habilidade Cone em (%d, %d)...\n", origemConeL, origemConeC);
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (matrizCone[i][j] == 1) {
                // Calcula onde a célula da habilidade cai no tabuleiro principal
                // Fórmula: Origem + (Índice Habilidade - Centro da Habilidade)
                linhaReal = origemConeL + (i - CENTRO_HABILIDADE);
                colunaReal = origemConeC + (j - CENTRO_HABILIDADE);

                // Verificação de limites (Boundary Check)
                if (linhaReal >= 0 && linhaReal < TAM_TABULEIRO && 
                    colunaReal >= 0 && colunaReal < TAM_TABULEIRO) {
                    tabuleiro[linhaReal][colunaReal] = AFETADO;
                }
            }
        }
    }

    // 2. Aplicando a CRUZ
    printf("Aplicando Habilidade Cruz em (%d, %d)...\n", origemCruzL, origemCruzC);
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (matrizCruz[i][j] == 1) {
                linhaReal = origemCruzL + (i - CENTRO_HABILIDADE);
                colunaReal = origemCruzC + (j - CENTRO_HABILIDADE);

                if (linhaReal >= 0 && linhaReal < TAM_TABULEIRO && 
                    colunaReal >= 0 && colunaReal < TAM_TABULEIRO) {
                    tabuleiro[linhaReal][colunaReal] = AFETADO;
                }
            }
        }
    }

    // 3. Aplicando o OCTAEDRO
    printf("Aplicando Habilidade Octaedro em (%d, %d)...\n", origemOctaL, origemOctaC);
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (matrizOctaedro[i][j] == 1) {
                linhaReal = origemOctaL + (i - CENTRO_HABILIDADE);
                colunaReal = origemOctaC + (j - CENTRO_HABILIDADE);

                if (linhaReal >= 0 && linhaReal < TAM_TABULEIRO && 
                    colunaReal >= 0 && colunaReal < TAM_TABULEIRO) {
                    tabuleiro[linhaReal][colunaReal] = AFETADO;
                }
            }
        }
    }

    // --- EXIBIÇÃO DO TABULEIRO FINAL ---
    
    printf("\n--- TABULEIRO FINAL ---\n\n");
    printf("Legenda: 0 = Agua, 3 = Navio, 5 = Atingido por Habilidade\n\n");

    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            // Exibição simples com espaço para melhor visualização
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}