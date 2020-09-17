/*
    Escreva uma função para verificar se uma lista simplesmente encadeada de números inteiros está ordenada (em ordem crescente).
    Ela deve retornar 1 se esta afirmação for verdadeira e 0 se for falsa. Considere que elementos repetidos podem existir na lista,
    e isto não invalida a ordem. Por exemplo, uma lista {1,3,5,6,6,8,10} está ordenada.
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
    printf("\n");
}

int check_order(ListaSimples *l){
    Elemento *iterador = l->inicio;
    int aux, i = 0; 

    while(i < (l->tamanho - 1)){
        aux = iterador->dado;
        if(aux <= iterador->proximo->dado){
            iterador = iterador->proximo;
            i++;
        }
        else 
            return 0;
    }
  
  return 1;
}

int main(void)
{
    // {1,3,5,6,6,8,10} está ordenada.

    ListaSimples *l = inicializaLista();
    colocaDado(1, l, 0);
    colocaDado(2, l, 1);
    colocaDado(3, l, 2);
    colocaDado(4, l, 3);
    colocaDado(5, l, 4);
    colocaDado(6, l, 5);
    colocaDado(10, l, 6);

    imprimeListaSimples(l);
    int check = check_order(l);
    printf("ordem: %i", check);

    return 0;
}