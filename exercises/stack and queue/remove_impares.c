/*
    Escreva uma função que receba uma pilha e retire todos os elementos ímpares da mesma. NÃO É PERMITIDO ACESSAR OS ELEMENTOS DIRETAMENTE. 
    Só é possível modificar a pilha utilizando as funções de inserção e remoção. É permitido utilizar estruturas de dados auxiliares.
    A ordem original dos elementos deve ser preservada. Por exemplo, uma pilha que começa com os valores (8,3,5,2,1,4) 
    deve ficar com os valores (8,2,4) nesta ordem.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct elementoP{
    int dado;
    struct elementoP *proximo;
} ElementoPilha;

typedef struct pilha{
    ElementoPilha *topo;
} Pilha;

Pilha *inicializa_pilha(){
    Pilha *p;
    p = (Pilha *)malloc(sizeof(Pilha));
    p->topo = NULL;
    return p;
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

void print_stack(Pilha *p){
    ElementoPilha *iterador;
    iterador = p->topo;
    printf("topo -> base\n");
    while(iterador != NULL){
        printf("%d ",iterador->dado);
        iterador = iterador->proximo;
    }
}

void retira_impar(Pilha *p) {
    Pilha *aux = inicializa_pilha();

    ElementoPilha *iteradoraux;
    ElementoPilha *iteradorPilha;
    iteradoraux = (ElementoPilha *)malloc(sizeof(ElementoPilha));
    iteradorPilha = (ElementoPilha *)malloc(sizeof(ElementoPilha));

    iteradorPilha = p->topo;
    while(iteradorPilha != NULL){
        if(iteradorPilha->dado % 2 == 0)
            push(iteradorPilha->dado, aux);
        iteradorPilha = iteradorPilha->proximo;
        pop(p);
    }

    iteradoraux = aux->topo;
    while (iteradoraux != NULL) {
        push(iteradoraux->dado, p);
        iteradoraux = iteradoraux->proximo;
        pop(aux);
    }

}

int main() {
    Pilha *org = inicializa_pilha();
    Pilha *par = inicializa_pilha();

    push(4, org);
    push(1, org);
    push(2, org);
    push(5, org);
    push(3, org);
    push(8, org);

    print_stack(org);

    retira_impar(org);
    printf("\n\n");
    print_stack(org);

    return 0;
}