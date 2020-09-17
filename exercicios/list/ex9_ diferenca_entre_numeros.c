/*
    Escreva uma função que recebe uma lista duplamente encadeada contendo números float, 
    e que retorne uma segunda lista duplamente encadeada contendo a diferença entre os números da primeira lista. 
    Por exemplo, ao receber uma lista contendo {8; 5; 7; 3; 2; 10; 5}, a lista retornada conteria {-3; 2; -4; -1; 8; -5}. 
    Não é permitido utilizar nenhuma função das listas, apenas manipulá-las diretamente pelos ponteiros dos elementos.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct elementoduplo
{
    float dado;
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

void colocaDado(float d, ListaDupla *l, int pos)
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

float retiraDado(ListaDupla *l, int pos)
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
            float saida = retirado->dado;

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
            printf("%.1f ", iterador->dado);
            iterador = iterador->proximo;
        }
    }
    printf("\nO tamanho da lista e: %i ", l->tamanho);
    printf("\n");
}

ListaDupla *sub_list(ListaDupla *l){
    ListaDupla *sub = inicializaListaDupla();
    ElementoDuplo *iterador =  l->inicio;
    float aux;

    for(int i = 0; i < l->tamanho - 1; i++){
        aux = iterador->dado;
        aux = (aux - iterador->proximo->dado) * -1;
        colocaDado(aux, sub, i);
        iterador = iterador->proximo;
    }

    return sub;
}

int main(void)
{
    // {8; 5; 7; 3; 2; 10; 5}, lista retornada {-3; 2; -4; -1; 8; -5}. 

    ListaDupla *l = inicializaListaDupla();
    ListaDupla *sub = inicializaListaDupla();

    colocaDado(8, l, 0);
    colocaDado(5, l, 1);
    colocaDado(7, l, 2);
    colocaDado(3, l, 3);
    colocaDado(2, l, 4);
    colocaDado(10, l, 5);
    colocaDado(5, l, 6);

    printf("original: ");
    imprimeListaDupla(l);

    sub = sub_list(l);
    printf("\nsub: ");
    imprimeListaDupla(sub);

    return 0;
}