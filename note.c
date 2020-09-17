#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *proximo;
} no;

int main(void)
{
    no *e1,*e2,*e3;
    e1 = (no *)malloc(sizeof(no));
    e2 = (no *)malloc(sizeof(no));
    e3 = (no *)malloc(sizeof(no));
    e1->valor = 1;
    e2->valor = 2;
    e3->valor = 3;
    e1->proximo = e2;
    e2->proximo = e3;
    e3->proximo = NULL;
    no *iterador = e1;
    while (iterador != NULL) {
        printf("%i \n",iterador->valor);
        iterador = iterador->proximo;
    }    
}