#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int valor;
    struct no *proximo;
} no;

void troca(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int i,j;
    // Ponteiros devem sempre ser inicializados como nulos
    int *pi1 = NULL;
    int *pi2 = NULL;

    i = 6;
    // pi1 recebe o endereço de memória de i
    pi1 = &i;
    pi2 = pi1;
    // j dereferencia o valor de pi2 (acessa o valor de i) e soma 2
    j = *pi2 + 2;
    *pi2 = 7;
    j = i + 2;
    // pi1 recebe o endereço de memória de j
    pi2 = &j;
    troca(&i,&j);
    printf("%i \n",j);

    int ii;
    int k[4];
    k[0] = 1;
    k[1] = 2;
    k[2] = 3;
    // as duas linhas seguintes acessam o mesmo elemento do vetor,
    // já que vetor é um tipo de ponteiro em C
    k[3] = 4;
    *(k+3) = 5;
    for (ii = 0; ii < 4; ii++)
    {
        printf("%i \n",k[ii]);
    }

    // as duas trocas abaixo acessam os mesmos elementos,
    // demonstrando duas maneiras diferentes de acessar vetores
    // (uma explorando a aritmética de ponteiros)
    troca(&(k[0]),&(k[2]));
    for (ii = 0; ii < 4; ii++)
    {
        printf("%i \n",k[ii]);
    }

    troca(k,k+2);
    for (ii = 0; ii < 4; ii++)
    {
        printf("%i \n",k[ii]);
    }

    // outra maneira de se criar um vetor: criando um ponteiro
    // para o primeiro elemento e alocando a memória necessária
    int *l;
    l = malloc(sizeof(int*)*2);
    l[0] = 11;
    l[1] = 22;
    for (ii = 0; ii < 2; ii++)
    {
        printf("%i \n",l[ii]);
    }
    troca(l,l+1);
    for (ii = 0; ii < 2; ii++)
    {
        printf("%i \n",l[ii]);
    }

    // a aritmética de ponteiros permite esta operação, mas quando
    // o código dereferencia (acessa) o valor do endereço de memória
    // contido no ponteiro não há nada nele (vetor de apenas duas
    // posições)
    troca(l,l+3);
    for (ii = 0; ii < 2; ii++)
    {
        printf("%i \n",l[ii]);
    }

    // no C o gerenciamento de memória é manual, não esquecer de limpá-la
    // após o uso
    //free(l);
    //l = NULL; //para não ter uso acidental de l (o programa trava ao invés
    //de um endereço de memória não especificado ser acessado)

    // o programa imprime lixo na tela pois não há nenhum valor no endereço
    // de memória aleatório do ponteiro jkl
    int *jkl;
    printf("%i \n",*jkl);

    int *mno = NULL;
    //*mno = 6; // trava o programa, tentativa de dereferenciar um ponteiro vazio!

    no *pT1 = NULL;
    no *pT2 = NULL;
    // utilizando aqui a mesma lógica do vetor feito anteriormente
    pT1 = malloc(sizeof(no));
    pT2 = malloc(sizeof(no));
    (*pT1).valor = 2;
    printf("%i \n",(*pT1).valor);

    // como este acesso é bastante comum no C, -> é uma notação da linguagem
    pT1->valor = 3;
    printf("%i \n",pT1->valor);
    pT2->valor = 4;
    pT1->proximo = pT2;
    pT2->proximo = NULL;
    return 0;
}