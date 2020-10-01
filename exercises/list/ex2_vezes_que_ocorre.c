/*
    Escreva uma função que recebe duas listas simplesmente encadeadas, lista1 e lista2. Esta função deve retornar uma terceira lista, 
    lista3. Esta lista deve conter, para cada elemento de lista2, o número de vezes que este elemento ocorre em lista1. Por exemplo,
    considerando lista1={9,4,6,2,2,3,1,5,5,0,7} e lista2={3,2,8,5,0}, a lista retornada pela função deve ter os números {1,2,0,2,1}. 
    NÃO É PERMITIDO UTILIZAR NENHUMA FUNÇÃO PRONTA DA LISTA. É permitido implementar suas próprias funções, 
    ou resolver tudo no corpo da função pedida.
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

ListaSimples *num_ocorre(ListaSimples *L1, ListaSimples *L2){
    ListaSimples *L = inicializaLista();
    int count = 0, pos = 0;

    Elemento *iterador1, *iterador2;
    iterador1 = L1->inicio;
    iterador2 = L2->inicio;

    for(int i = 0; i < L2->tamanho; i++) {
        count = 0;
        for(int j=0; j < L1->tamanho; j++){
            if(iterador1->dado == iterador2->dado){
                count++;
            }
            iterador1 = iterador1->proximo;
        }
        colocaDado(count, L, pos);
        pos++;
        iterador1 = L1->inicio;
        iterador2 = iterador2->proximo;
    }

    return L;
}

int main(){
    //lista1={9,4,6,2,2,3,1,5,5,0,7} e lista2={3,2,8,5,0}
    //lista retornada pela função {1,2,0,2,1}.

    ListaSimples *L1 = inicializaLista();
    ListaSimples *L2 = inicializaLista();
    ListaSimples *occ = inicializaLista();

    colocaDado(9, L1, 0);
    colocaDado(4, L1, 1);
    colocaDado(6, L1, 2);
    colocaDado(2, L1, 3);
    colocaDado(2, L1, 4);
    colocaDado(3, L1, 5);
    colocaDado(1, L1, 6);
    colocaDado(5, L1, 7);
    colocaDado(5, L1, 8);
    colocaDado(0, L1, 9);
    colocaDado(7, L1, 10);

    
    colocaDado(3, L2, 0);
    colocaDado(2, L2, 1);
    colocaDado(8, L2, 2);
    colocaDado(5, L2, 3);
    colocaDado(0, L2, 4);

    printf("Lista 1: ");
    imprimeListaSimples(L1);
    printf("\n");
    printf("Lista 2: ");
    imprimeListaSimples(L2);
    printf("\n");

    occ = num_ocorre(L1, L2);
    printf("Lista occ: ");
    imprimeListaSimples(num_ocorre(L1, L2));
    printf("\n");

    return 0;
}