#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_MATRIX 1000

void otimizarMultiplicacao(int quantidade, int linhas[], int colunas[], int **custo, int **divisao) {
    for (int i = 1; i <= quantidade; i++) {
        custo[i][i] = 0;
    }

    for (int tamanho = 2; tamanho <= quantidade; tamanho++) {
        for (int inicio = 1; inicio <= quantidade - tamanho + 1; inicio++) {
            int fim = inicio + tamanho - 1;
            custo[inicio][fim] = INT_MAX;

            for (int div = inicio; div < fim; div++) {
                long calculo = (long)custo[inicio][div] + (long)custo[div + 1][fim] +
                                (long)linhas[inicio] * (long)colunas[div] * (long)colunas[fim];

                if (calculo < custo[inicio][fim]) {
                    custo[inicio][fim] = calculo;
                    divisao[inicio][fim] = div;
                } else if (calculo == custo[inicio][fim]) {
                    divisao[inicio][fim] = -1;
                }
            }
        }
    }
}

void exibirOrdem(int inicio, int fim, int **divisao) {
    if (inicio == fim) {
        printf("A%d", inicio);
        return;
    }
    if (divisao[inicio][fim] == -1) {
        printf("%d", 0);
        return;
    }
    printf("(");
    exibirOrdem(inicio, divisao[inicio][fim], divisao);
    exibirOrdem(divisao[inicio][fim] + 1, fim, divisao);
    printf(")");
}

int main() {
    int numMatrizes;

    while (scanf("%d", &numMatrizes) && numMatrizes != 0) {
        int *dimLinhas = (int *)malloc((numMatrizes + 1) * sizeof(int));
        int *dimColunas = (int *)malloc((numMatrizes + 1) * sizeof(int));

        for (int i = 1; i <= numMatrizes; i++) {
            scanf("%d %d", &dimLinhas[i], &dimColunas[i]);
        }

        int **matCusto = (int **)malloc((numMatrizes + 1) * sizeof(int *));
        int **matDivisao = (int **)malloc((numMatrizes + 1) * sizeof(int *));
        for (int i = 0; i <= numMatrizes; i++) {
            matCusto[i] = (int *)malloc((numMatrizes + 1) * sizeof(int));
            matDivisao[i] = (int *)malloc((numMatrizes + 1) * sizeof(int));
        }

        otimizarMultiplicacao(numMatrizes, dimLinhas, dimColunas, matCusto, matDivisao);

        if (numMatrizes == 1) {
            printf("A1\n");
        } else {
            int solucoesIguais = 0;
            for (int i = 1; i <= numMatrizes && !solucoesIguais; i++) {
                for (int j = i; j <= numMatrizes && !solucoesIguais; j++) {
                    if (matDivisao[i][j] == -1) {
                        solucoesIguais = 1;
                    }
                }
            }

            if (solucoesIguais) {
                printf("%d\n", matCusto[1][numMatrizes]);
            } else {
                exibirOrdem(1, numMatrizes, matDivisao);
                printf("\n");
            }
        }

        for (int i = 0; i <= numMatrizes; i++) {
            free(matCusto[i]);
            free(matDivisao[i]);
        }
        free(matCusto);
        free(matDivisao);
        free(dimLinhas);
        free(dimColunas);
    }

    return 0;
}
