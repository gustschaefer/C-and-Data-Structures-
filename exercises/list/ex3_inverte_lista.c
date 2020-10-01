/*
    Escreva uma função que receba uma lista duplamente encadeada não circular e inverta a ordem de seus elementos, 
    SEM ALOCAR NOVOS ELEMENTOS, NEM LIBERAR MEMÓRIA DOS EXISTENTES.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct elementoduplo
{
    int dado;
    struct elementoduplo *proximo;
    struct elementoduplo *anterior;
} ElementoDuplo;

typedef struct listadupla
{
    ElementoDuplo *inicio;
    int tamanho;
} ListaDupla;

ListaDupla *inicializaListaDupla()
{
    ListaDupla *l;
    l = (ListaDupla *)malloc(sizeof(ListaDupla));
    l->inicio = NULL;
    l->tamanho = 0;
    return l;
}

void colocaDado(int d, ListaDupla *l, int pos)
{

    ElementoDuplo *andarilho = l->inicio;
    ElementoDuplo *anterior = NULL;

    ElementoDuplo *novoDado;
    novoDado = (ElementoDuplo *)malloc(sizeof(ElementoDuplo));
    novoDado->dado = d;

    // inserção no início da lista
    if (pos == 0)
    {
        novoDado->proximo = l->inicio;
        novoDado->anterior = NULL;
        l->inicio = novoDado;
    }
    else
    {
        // inserção no final da lista
        if (pos == l->tamanho)
        {
            while (andarilho->proximo != NULL)
            {
                andarilho = andarilho->proximo;
            }
            andarilho->proximo = novoDado;
            novoDado->anterior = andarilho;
            novoDado->proximo = NULL;
        }
        else
        {
            // outros casos
            int i = 0;
            while (i < pos)
            {
                anterior = andarilho;
                andarilho = andarilho->proximo;
                i++;
            }

            novoDado->anterior = anterior;
            anterior->proximo = novoDado;
            novoDado->proximo = andarilho;
            andarilho->anterior = novoDado;
        }
    }

    l->tamanho++;
}

void imprimeListaDupla(ListaDupla *l)
{
    ElementoDuplo *iterador;
    iterador = l->inicio;

    if (iterador == NULL)
    {
        printf("Lista vazia!");
    }
    else
    {
        while (iterador != NULL)
        {
            printf("%i ", iterador->dado);
            iterador = iterador->proximo;
        }
    }
}

void inverte_lista(ListaDupla *l){
    ElementoDuplo *aux = NULL;   
    ElementoDuplo *iterador = l->inicio; 

    while (iterador !=  NULL){ 
       aux = iterador->anterior; 
       iterador->anterior = iterador->proximo; 
       iterador->proximo = aux;               
       iterador = iterador->anterior; 
    }       
       
    if(aux != NULL ) 
        l->inicio = aux->anterior; 
}

int main()
{
    ListaDupla *l = inicializaListaDupla();
    colocaDado(0, l, 0);
    colocaDado(1, l, 1);
    colocaDado(2, l, 2);
    colocaDado(3, l, 3);
    colocaDado(4, l, 4);

    printf("Original: ");
    imprimeListaDupla(l);

    printf("\nInversa: ");
    inverte_lista(l);
    imprimeListaDupla(l);
  
    return 0;
}