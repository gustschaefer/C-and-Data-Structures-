/*
    Escreva uma função que receba um vetor de inteiros de 10 posições, e retorne uma lista simplesmente encadeada de inteiros
    contendo os valores do vetor. É permitido utilizar as funções prontas da lista.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct elemento {
    int dado;
    struct elemento *proximo;
} Elemento;

typedef struct listasimples {
    Elemento *inicio;
    int tamanho;
} ListaSimples;

ListaSimples *inicializaLista() {
    ListaSimples *l;
    l = (ListaSimples *)malloc(sizeof(ListaSimples));
    l->inicio = NULL;
    l->tamanho = 0;
    return l;
}

void colocaDado(int d, ListaSimples *l, int pos) 
{
    if (l != NULL && pos <= l->tamanho)
    {
        Elemento *andarilho = l->inicio;
        Elemento *anterior = NULL;

        Elemento *novoDado;
        novoDado = (Elemento *)malloc(sizeof(Elemento));
        novoDado->dado = d;

        int i = 0;
        while (andarilho != NULL && i < pos)
        {
            anterior = andarilho;
            andarilho = andarilho->proximo;
            i++;
        }

        if (anterior == NULL)
        {
            novoDado->proximo = l->inicio;
            l->inicio = novoDado;
        }
        else
        {
            anterior->proximo = novoDado;
            novoDado->proximo = andarilho;
        }

        l->tamanho++;
    }
}

void imprimeListaSimples(ListaSimples *l)
{
    Elemento *iterador;
    iterador = l->inicio;

    if (iterador == NULL)
    {
        printf("Lista vazia!\n");
    }
    else
    {
        while (iterador != NULL)
        {
            printf("%i ", iterador->dado);
            iterador = iterador->proximo;
        }

        printf("\nTamanho da lista: %i", l->tamanho);
    }
}

ListaSimples *vect2list(int vet[10]){
    ListaSimples *l = inicializaLista();

    for(int i; i < 10; i++)
    {
        colocaDado(vet[i], l, i);
    }

    return l;
}

int main()
{
    ListaSimples *l = inicializaLista();
    int vet[10] = {1,2,3,4,5,6,7,8,9,10};

    imprimeListaSimples(l); // antes
    l = vect2list(vet);
    imprimeListaSimples(l); // depois (vetor -> lista)
 
    return 0;
}