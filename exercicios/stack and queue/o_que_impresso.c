/*  
    O que será impresso na tela após a execução do código abaixo? Considere que tanto a pilha quanto a fila começam vazias,
    que as funções push e pop inserem e retiram da pilha respectivamente, 
    e que as funções inserir e remover inserem e retiram da fila respectivamente.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct elementoP{
    int dado;
    struct elementoP *proximo;
} ElementoPilha;

typedef struct elementoF {
    int dado;
    struct elementoF *proximo;
} ElementoFila;

typedef struct pilha{
    ElementoPilha *topo;
} Pilha;

typedef struct fila {
    ElementoFila *inicio;
    ElementoFila *fim;
} Fila;

Pilha *inicializa_pilha(){
    Pilha *p;
    p = (Pilha *)malloc(sizeof(Pilha));
    p->topo = NULL;
    return p;
}

Fila *inicializaFila() {
    Fila *f;
    f = (Fila *)malloc(sizeof(Fila));
    f->inicio = NULL;
    f->fim = NULL;
    return f;
}

// Push e pop - Pilha
void push(int d, Pilha *p){
    ElementoPilha *novo_dado;
    novo_dado = (ElementoPilha *)malloc(sizeof(ElementoPilha));
    novo_dado->dado = d;
    novo_dado->proximo = p->topo;
    p->topo = novo_dado;
}

int pop(Pilha *p){
    int elemento_retirado = p->topo->dado;
    ElementoPilha *aux = p->topo;
    p->topo = p->topo->proximo;
    free(aux);
    aux = NULL;
    return elemento_retirado;
}

// inserir e remover - Fila
void inserir(int d, Fila *f) {
    ElementoFila *novoDado; // 1
    novoDado = (ElementoFila *)malloc(sizeof(ElementoFila)); // 1
    novoDado->dado = d; // 2
    novoDado->proximo = NULL; // 3
    if (f->inicio == NULL) // 4
    {
        f->fim = f->inicio = novoDado; // 4
    }
    else // 5
    {
        f->fim->proximo = novoDado;
        f->fim = novoDado;
    }
}

int remover(Fila *f) {
    int saida = f->inicio->dado;
    ElementoFila *retirado;
    retirado = (ElementoFila *)malloc(sizeof(ElementoFila));
    retirado = f->inicio;
    if (f->fim != f->inicio) {
        f->inicio = f->inicio->proximo;
    }
    else
    {
        f->fim = f->inicio = NULL;
    }
    free(retirado);
    return saida;
}

int main()
{
    Fila *fila = inicializaFila();
    Pilha *pilha = inicializa_pilha();

    push(10 ,pilha); // 1
    inserir(20, fila); // 2
    push(30, pilha); // 3
    inserir(40, fila); // 4
    inserir(pop(pilha), fila); // 5
    push(remover(fila), pilha); // 6
    inserir(remover(fila), fila); // 7
    push(pop(pilha), pilha); // 8

    printf("\n%d %d %d %d\n", remover(fila), pop(pilha), pop(pilha), remover(fila));

    return 0;
}

// pilha: 30(3) 10(1) -> (5) 20 10 -> 20 10 
// fila: 20(2) 40(4) 30(5) -> (6) 40 30 -> (7) 30 40

// prinf: 30, 20, 10, 40