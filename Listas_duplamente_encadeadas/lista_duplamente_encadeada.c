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

ListaDupla inicializaListaDupla()
{
    ListaDupla *l;
    l = (ListaDupla *)malloc(sizeof(ListaDupla));
    l->inicio = NULL;
    l->tamanho = 0;
    return *l;
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

int retiraDado(ListaDupla *l, int pos)
{
    // lista vazia
    if (l->inicio == NULL)
    {
        printf("A lista esta vazia, nao ha o que retirar! \n");
        return;
    }
    else
    {
        // posição maior que o tamanho da lista

        if (pos > l->tamanho)
        {
            printf("Posicao invalida! \n");
            return;
        }

        else
        {

            ElementoDuplo *andarilho = l->inicio;
            ElementoDuplo *anterior = NULL;
            ElementoDuplo *retirado;
            retirado = (ElementoDuplo *)malloc(sizeof(ElementoDuplo));

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
                if (andarilho->proximo == NULL)
                {
                    l->inicio = NULL;
                }
                else
                {
                    l->inicio = andarilho->proximo;
                    l->inicio->anterior = NULL;
                }
            }
            else
            {
                anterior->proximo = andarilho->proximo;
                andarilho->anterior = anterior;
            }
            free(retirado);
            l->tamanho--;
            return saida;
        }
    }
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
            printf(" %i ", iterador->dado);
            iterador = iterador->proximo;
        }
    }
    printf("\nO tamanho da lista e: %i \n", l->tamanho);
    printf("\n");
}

void limpaListaDupla(ListaDupla *l)
{
    ElementoDuplo *iterador, *anterior;
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
    ListaDupla l = inicializaListaDupla();
    colocaDado(1, &l, 0);
    imprimeListaDupla(&l);
    colocaDado(2, &l, 1);
    imprimeListaDupla(&l);
    colocaDado(3, &l, 2);
    imprimeListaDupla(&l);
    colocaDado(4, &l, 3);
    imprimeListaDupla(&l);
    retiraDado(&l, 0);
    imprimeListaDupla(&l);
    colocaDado(5, &l, 2);
    imprimeListaDupla(&l);
    colocaDado(6, &l, 3);
    imprimeListaDupla(&l);
    colocaDado(7, &l, 5);
    imprimeListaDupla(&l);
    return 0;
}