#include <stdio.h>
#include <stdlib.h>

typedef struct elemento{
    int dado;
    struct elemento *proximo;
} Elemento;

typedef struct pilha{
    Elemento *topo;
} Pilha;

Pilha *inicializa_pilha(){
    Pilha *p;
    p = (Pilha *)malloc(sizeof(Pilha));
    p->topo = NULL;
    return p;
}

void push(int d, Pilha *p){
    Elemento *novo_dado;
    novo_dado = (Elemento *)malloc(sizeof(Elemento));
    novo_dado->dado = d;
    novo_dado->proximo = p->topo;
    p->topo = novo_dado;
}

int pop(Pilha *p){
    int elemento_retirado = p->topo->dado;
    Elemento *aux = p->topo;
    p->topo = p->topo->proximo;
    free(aux);
    aux = NULL;
    return elemento_retirado;
}

void print_stack(Pilha *p){
    Elemento *iterador;
    iterador = p->topo;
    while(iterador != NULL){
        printf("%d ",iterador->dado);
        iterador = iterador->proximo;
    }
}

int top(Pilha *p){
    return p->topo->dado;
}

int main()
{
    Pilha *p = inicializa_pilha();
    int num_dados = 10;
    for(int i=0; i<num_dados; i++){
        push(i,p);
    }
    print_stack(p);
    pop(p);
    printf("\n");
    print_stack(p);
    printf("\n\n");

    printf("%d", &p);

    return 0;
}
