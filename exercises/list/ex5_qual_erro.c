/*
A função abaixo faz parte de uma lista simplesmente encadeada circular. 
Explique qual o objetivo dela, qual o erro em sua implementação, e como corrigi-lo.

int f1(ListaCircular *lista)
{
    Elemento *and = lista->inicio;
    int x = 0;
    while(and!=NULL)
    {
        if(and->dado%2==0)
        x++;
        and = and->proximo;
    }
    return x;
}

*/

/* 
Resposta:

    O objetivo da funçao é retornar a quantidade de numeros pares uma dada lista (ListaCircular *lista) contem.

    O erro é que, como se trata de uma lista circula, o proximo elemento do ultime elemento a lista nao é nulo, e
    sim o primeiro elemento da lista, logo como and = and->proximo é executado até and != NULL e and nunca é igual a NULL,
    o loop while se torna infinito.

    Abaixo o codigo consertando a função.

    int f1(ListaCircular *lista)
    {
        Elemento *and = lista->inicio;
        and = and->proximo;

        int x = 0;
        while(and != lista->inicio)
        {
            if(and->dado%2==0)
            x++;
            and = and->proximo;
        }
        return x;
    }

*/



// ---------------------------------------------------------------------------------------------------------------------

// Codigo completo utilizando a funcao convert_to_circula (exercicio 1) para tranformar uma lista dupla nao circular
// em circular para poder demonstrar o funcionamento da função f1.

/*
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

void convert_to_circular(ListaDupla *l){
    // l->inicio->anterior = l->fim
    // l->fim->proximo = l->inicio

    ElementoDuplo *andarilho = l->inicio;
    ElementoDuplo *anterior = NULL;

    int i = 0;
    while (i < l->tamanho)
    {
        anterior = andarilho;
        andarilho = andarilho->proximo;
        i++;
    }
    l->inicio->anterior = andarilho;
    anterior->proximo = l->inicio;
}

void imprimeListaCircular(ListaDupla *l)
{
    if ((l->tamanho == 0) || (l == NULL))
        return;
    ElementoDuplo *iterador = l->inicio;
    //imprime o primeiro
    printf("%d ", iterador->dado);
    iterador = iterador->proximo;
    while (iterador != l->inicio)
    {
        printf("%d ", iterador->dado);
        iterador = iterador->proximo;
    }

    printf("\nO tamanho da lista circular e: %i \n", l->tamanho);
    printf("\n");
}

int f1(ListaDupla *lista)
{
        ElementoDuplo *and = lista->inicio;
        and = and->proximo;

        int x = 0;
        while(and != lista->inicio)
        {
            if(and->dado%2==0)
            x++;
            and = and->proximo;
        }
        return x;
}

int main()
{
    ListaDupla l = inicializaListaDupla();
    colocaDado(1, &l, 0);
    colocaDado(2, &l, 1);
    colocaDado(3, &l, 2);
    colocaDado(4, &l, 3);
    colocaDado(5, &l, 4);
    colocaDado(6, &l, 5);
    colocaDado(7, &l, 6);
    colocaDado(8, &l, 7);

    convert_to_circular(&l);
    imprimeListaCircular(&l);
    printf("\nA funcao f1 retornou: %i", f1(&l));
    
    return 0;
}
*/

/*
Output:
    1 2 3 4 5 6 7 8
    O tamanho da lista circular e: 8

    A funcao f1 retornou: 4
*/

