/*
    Escreva um método que inverta uma fila. Para manipular a fila, apenas as operações de inserção e retirada podem ser utilizadas. 
    Outras estruturas de dados podem ser usadas como apoio. Obs.: considere os métodos de inserção e retirada da fila 
    (e da pilha, caso use uma) já implementados.

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
    ElementoFila *novoDado; 
    novoDado = (ElementoFila *)malloc(sizeof(ElementoFila)); 
    novoDado->dado = d; 
    novoDado->proximo = NULL; 
    if (f->inicio == NULL) 
    {
        f->fim = f->inicio = novoDado; 
    }
    else 
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

void imprimeFila(Fila *f) {
    ElementoFila *iterador;
    iterador = (ElementoFila *)malloc(sizeof(ElementoFila));
    iterador = f->inicio;
    while (iterador != NULL) {
        printf("%i ",iterador->dado);
        iterador = iterador->proximo;
    }
	printf("\n");
}

void inverteFila(Fila *f) {
    Pilha *aux = inicializa_pilha();

    ElementoFila *iteradorFila;
    ElementoPilha *iteradorPilha;

    iteradorFila = f->inicio;
    while (iteradorFila != NULL) {
        push(iteradorFila->dado, aux);
        iteradorFila = iteradorFila->proximo;
        remover(f);
    }

    iteradorPilha = aux->topo;
    while(iteradorPilha != NULL){
        inserir(iteradorPilha->dado, f);
        iteradorPilha = iteradorPilha->proximo;
        pop(aux);
    }
}

int main()
{
    Fila *f = inicializaFila();

    int num_dados = 15;
    for(int i=0; i<num_dados; i++){
        inserir(i, f);
    }

    printf("original: ");
    imprimeFila(f);

    inverteFila(f);
    printf("invertida: ");
    imprimeFila(f);

    return 0;
}