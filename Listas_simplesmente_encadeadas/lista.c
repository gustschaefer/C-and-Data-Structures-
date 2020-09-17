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

int retiraDado(ListaSimples *l, int pos)
{
    if (l != NULL && pos <= l->tamanho)
    {
        if (l->inicio == NULL)
        {
            printf("A lista esta vazia, nao ha o que retirar! \n");
            return 0;
        }
        else
        {

            Elemento *andarilho = l->inicio;
            Elemento *anterior = NULL;
            Elemento *retirado;
            retirado = (Elemento *)malloc(sizeof(Elemento));

            int i = 0;
            while (i < pos)
            {
                anterior = andarilho;
                andarilho = andarilho->proximo;
                i++;
            }

            retirado = andarilho;
            int saida = retirado->dado;

            if (anterior == NULL)
            {
                l->inicio = andarilho->proximo;
            }
            else
            {
                anterior->proximo = andarilho->proximo;
            }
            free(retirado);
            return saida;
        }
    }
    l->tamanho--;
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

void limpaListaSimples(ListaSimples *l)
{
    Elemento *iterador, *anterior;
    iterador = l->inicio;
    anterior = NULL;

    if (iterador == NULL)
    {
        printf("Lista vazia!");
    }
    else
    {
        while (iterador != NULL)
        {
            anterior = iterador;
            iterador = iterador->proximo;
            free(anterior);
        }
    }
    l->inicio = NULL;
}

int main(void)
{
    ListaSimples *l = inicializaLista();
    colocaDado(1, l, 0);
    imprimeListaSimples(l);
    colocaDado(2, l, 1);
    imprimeListaSimples(l);
    colocaDado(3, l, 1);
    imprimeListaSimples(l);
    colocaDado(4, l, 2);
    imprimeListaSimples(l);
    retiraDado(l, 0);
    imprimeListaSimples(l);
    retiraDado(l, 0);
    imprimeListaSimples(l);
    colocaDado(5, l, 0);
    imprimeListaSimples(l);
    colocaDado(6, l, 0);
    imprimeListaSimples(l);
    retiraDado(l, 0);
    imprimeListaSimples(l);
    retiraDado(l, 2);
    imprimeListaSimples(l);
    retiraDado(l, 1);
    imprimeListaSimples(l);
    retiraDado(l, 0);
    imprimeListaSimples(l);
    retiraDado(l, 0);
    return 0;
}