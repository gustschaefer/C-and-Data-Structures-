
/* 
Escrever função para pilha de inteiros que só aceite inserir um novo elemento
se a pilha estiver vazia, ou se o novo elemento for par e o elemento do fundo da pilha
tambem for par, ou se o novo elemento for impar e o elemento do fundo for impar.

Se as condicoes forem atendidas, a funçao insere o novo elemento e retorna 0, senao a funçao nao
modifica a pilha e retorna 1.

Não é permitid0 percorrer a pilha nem usar laçoes, incluindo recursão.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct elemento{
    int dado;
    struct elemento *proximo;
}Elemento;

typedef struct pilha{
    Elemento *topo;
}Pilha;

Pilha *init_stack(){
    Pilha *p;
    p = (Pilha *)malloc(sizeof(Pilha));
    p->topo = NULL;
    return p;
}

void push(int d, Pilha *p){
    if (p != NULL){
        Elemento *novo;
        novo = (Elemento *)malloc(sizeof(Elemento));
        novo->dado = d;
        novo->proximo = p->topo;
        p->topo = novo;
    }
}

int base;
int filter_push(int d, Pilha *p){
    
    if(p->topo == NULL){
        push(d, p);
        base = d;
        return 0;
    }
    if ((base % 2 == 1 && d % 2 == 1) || (base % 2 == 0 && d % 2 == 0)){
        push(d, p);
        return 0;
    }

    return -1;
}

void print_stack(Pilha *p){
    Elemento *iterador;
    iterador = p->topo;
    while( iterador != NULL){
        printf("%d ", iterador->dado);
        iterador = iterador->proximo;
    }
    printf("\n");
}

int main(){

    Pilha *p = init_stack();
    printf("\n%d \n", filter_push(3,p));
    printf("%d \n", filter_push(4,p));
    printf("%d \n", filter_push(6,p));
    printf("%d \n", filter_push(15,p));
    printf("%d \n", filter_push(14,p));

    printf("\n");
    print_stack(p);
}