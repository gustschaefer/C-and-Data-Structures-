/*
    Escreva uma função ListaInt* numFaixa(ListaInt *listaOriginal, int inicioFaixa, int fimFaixa) 
    que recebe uma lista simplesmente encadeada de números inteiros, um inteiro “inicioFaixa” e outro inteiro chamado “fimFaixa”. 
    Esta função deve criar uma segunda lista simplesmente encadeada contendo os elementos da lista original cujo valor está contido no 
    intervalo fechado [inicioFaixa, fimFaixa]. Não é permitido utilizar as funções prontas da lista. A lista original não está ordenada, 
    e deve ser preservada. É permitido alocar memória. Não é necessário que os números estejam na lista final na mesma ordem em que 
    estavam na lista original.
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

ListaSimples* numFaixa(ListaSimples *listaOriginal, int inicioFaixa, int fimFaixa){
    ListaSimples *Intervalo = inicializaLista();
    Elemento *iterador;
    iterador = listaOriginal->inicio;

    int i = 0, j = 0;
    while (i < listaOriginal->tamanho){
        if(i >= inicioFaixa && i <= fimFaixa){
            colocaDado(iterador->dado, Intervalo, j);
            j++;  
        }
        iterador = iterador->proximo;
        i++;
    }

    return Intervalo;
}

int main(void)
{
    ListaSimples *original = inicializaLista();
    ListaSimples *intervalo = inicializaLista();

    colocaDado(1, original, 0);
    colocaDado(2, original, 1);
    colocaDado(3, original, 2);
    colocaDado(4, original, 3);
    colocaDado(5, original, 4);
    colocaDado(6, original, 5);
    colocaDado(7, original, 6);
    colocaDado(8, original, 7);
    colocaDado(9, original, 8);
    colocaDado(10, original, 9);

    imprimeListaSimples(original);
    printf("\nIntervalo: ");

    intervalo = numFaixa(original, 3, 6);
    imprimeListaSimples(intervalo);
    printf("\nOriginal: ");
    imprimeListaSimples(original);

    return 0;
}

