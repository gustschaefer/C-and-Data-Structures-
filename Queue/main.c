#include <stdio.h>
#include <stdlib.h>

typedef struct elemento {
    int dado;
    struct elemento *proximo;
} Elemento;

typedef struct fila {
    Elemento *inicio;
    Elemento *fim;
} Fila;

Fila *inicializaFila() {
    Fila *f;
    f = (Fila *)malloc(sizeof(Fila));
    f->inicio = NULL;
    f->fim = NULL;
    return f;
}

void colocaDado(int d, Fila *f) {
    Elemento *novoDado; // 1
    novoDado = (Elemento *)malloc(sizeof(Elemento)); // 1
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

int retiraDado(Fila *f) {
    int saida = f->inicio->dado;
    Elemento *retirado;
    retirado = (Elemento *)malloc(sizeof(Elemento));
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
    Elemento *iterador;
    iterador = (Elemento *)malloc(sizeof(Elemento));
    iterador = f->inicio;
    while (iterador != NULL) {
        printf("%i ",iterador->dado);
        iterador = iterador->proximo;
    }
	printf("\n");
}


int main(void)
{
    Fila *f = inicializaFila();
    colocaDado(1,f);
    colocaDado(2,f);
    colocaDado(3,f);
    colocaDado(4,f);
    imprimeFila(f);
    retiraDado(f);
    imprimeFila(f);
    retiraDado(f);
    imprimeFila(f);
    colocaDado(5,f);
    imprimeFila(f);
    return 0;
}
