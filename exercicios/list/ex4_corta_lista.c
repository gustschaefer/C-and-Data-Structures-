/*
    Escreva uma função que recebe uma lista duplamente encadeada não circular, E um número inteiro X. 
    A função deve “cortar” a lista na posição X, de forma que a lista original tenha todos os membros das posições menores que X, 
    e retornar uma lista que contenha todos os membros da lista original a partir posição X (inclusive). 
    NÃO É PERMITIDO ALOCAR NOVAS ESTRUTURAS, NEM UTILIZAR FUNÇÕES PRONTAS. Obs.: Assuma que a posição pedida é sempre válida, isto é,
    não-negativa e menor que o tamanho da lista
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

ListaDupla *corta_lista(ListaDupla *l, int cut){
    ListaDupla *cortada = inicializaListaDupla();
    
    ElementoDuplo *iterador;
    iterador = l->inicio;

    int i = 0, j = 0;
    while (i < l->tamanho){
        if(i >= cut){
            while(cut < l->tamanho){
                colocaDado(retiraDado(l, i), cortada, j);
                iterador = iterador->proximo;
                j++;  
            }
            break;
        }
        iterador = iterador->proximo;
        i++;
    }

    return cortada;
}

int main(){
    ListaDupla *l = inicializaListaDupla();
    ListaDupla *cut = inicializaListaDupla();

    colocaDado(1, l, 0);
    colocaDado(2, l, 1);
    colocaDado(3, l, 2);
    colocaDado(4, l, 3);
    colocaDado(5, l, 4);
    colocaDado(6, l, 5);
    colocaDado(7, l, 6);
    colocaDado(8, l, 7);
    colocaDado(9, l, 8);
    colocaDado(10, l, 9);

    imprimeListaDupla(l);
    cut = corta_lista(l, 3);
    printf("\n\n");
    printf("org: ");
    imprimeListaDupla(l);
    printf("\n");
    printf("cut: ");
    imprimeListaDupla(cut);

    return 0;
}