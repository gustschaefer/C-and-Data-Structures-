/* Programa para resolver o problema das
n-rainhas utilizando backtracking */
#define N 4
#include<stdio.h>

/* Função para imprimir a solução */
void imprimeSolucao(int tabuleiro[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf(" %d ", tabuleiro[i][j]);
        printf("\n");
    }
}

/* Função que verifica se uma rainha pode ser colocada
   em tabuleiro[fila][coluna]. Note que esta função é chamada
   quando rainhas já estão posicionadas das colunas 0 até
   coluna - 1. Por este motivo, precisamos verificar se
   existem rainhas que podem atacar apenas nas colunas do
   lado esquerdo.
    */
int eSeguro(int tabuleiro[N][N], int fila, int coluna)
{
    int i, j;

    /* Verifica esta fila no lado esquerdo */
    for (i = 0; i < coluna; i++)
        if (tabuleiro[fila][i])
            return 0;

    /* Verifica a diagonal superior no lado esquerdo */
    for (i=fila, j=coluna; i>=0 && j>=0; i--, j--)
        if (tabuleiro[i][j])
            return 0;

    /* Verifica diagonal inferior no lado esquerdo */
    for (i=fila, j=coluna; j>=0 && i<N; i++, j--)
        if (tabuleiro[i][j])
            return 0;

    return 1;
}

/* Função utilitária recursiva para resolver o problema
das n-rainhas */
int resolveNRainhasUtil(int tabuleiro[N][N], int coluna)
{
    // todas as rainhas estao posicionadas
    if (coluna >= N) 
        return 1; 
  
    for (int i = 0; i < N; i++) { 
        if (eSeguro(tabuleiro, i, coluna)) { 
            tabuleiro[i][coluna] = 1; 
  
            if (resolveNRainhasUtil(tabuleiro, coluna + 1)) 
                return 1; 
  
            // nao ha soluçao, retira a rainha e tenta novamente
            tabuleiro[i][coluna] = 0;
        } 
    } 
  
    // rainha nao pode ser colocada em qualquer linha da coluna
    return 0; 
}

/* Pode haver mais de uma solução para este problema;
Este programa apenas retorna a primeira que ele achar.*/
int resolveNRainhas()
{
    int tabuleiro[N][N] = { 
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };

    if ( resolveNRainhasUtil(tabuleiro, 0) == 0 )
    {
      printf("Uma solucao nao existe");
      return 0;
    }

    imprimeSolucao(tabuleiro);
    return 1;
}

int main()
{
    resolveNRainhas();
    return 0;
}