#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct elemento {
    int dado;
    char tipo;
    struct elemento *proximo;
} Elemento;

typedef struct fila {
    Elemento *inicio;
    Elemento *fim;
} Fila_especial;

Fila_especial *inicializaFila() {
    Fila_especial *f;
    f = (Fila_especial *)malloc(sizeof(Fila_especial));
    f->inicio = NULL;
    f->fim = NULL;
    return f;
}

void colocaDado(char t, int d, Fila_especial *f) {
    Elemento *novoDado;
    novoDado = (Elemento *)malloc(sizeof(Elemento));
    novoDado->dado = d;
    novoDado ->tipo = t;
    novoDado->proximo = NULL;
    if (f->inicio == NULL && f->fim == NULL)
    {
        f->fim = f->inicio = novoDado;
    }
    else
    {
        f->fim->proximo = novoDado;
        f->fim = novoDado;
    }
}

typedef struct elementoN {
    int dado;
    char tipo;
    struct elementoN *proximo;
} ElementoN;

typedef struct filan {
    ElementoN *inicio;
    ElementoN *fim;
} Fila_normal;

Fila_normal *inicializaFilan() {
    Fila_normal *f;
    f = (Fila_normal *)malloc(sizeof(Fila_normal));
    f->inicio = NULL;
    f->fim = NULL;
    return f;
}

void colocaDadon(char t, int d, Fila_normal *f) {
    ElementoN *novoDado;
    novoDado = (ElementoN *)malloc(sizeof(ElementoN));
    novoDado->dado = d;
    novoDado->tipo = t;
    novoDado->proximo = NULL;
    if (f->inicio == NULL && f->fim == NULL)
    {
        f->fim = f->inicio = novoDado;
    }
    else
    {
        f->fim->proximo = novoDado;
        f->fim = novoDado;
    }
}

void imprimeFila(Fila_normal *fn, Fila_especial *fe) {
    ElementoN *iteradorN;
    Elemento  *iteradorE;
    iteradorN = (ElementoN *)malloc(sizeof(ElementoN));
    iteradorN = fn->inicio;
    iteradorE = (Elemento *)malloc(sizeof(Elemento));
    iteradorE = fe->inicio;
    while (iteradorE != NULL) {
        printf("%c%i - ",iteradorE->tipo, iteradorE->dado);
        iteradorE = iteradorE->proximo;
    }
    while (iteradorN != NULL) {
        printf("%c%i - ",iteradorN->tipo,iteradorN->dado);
        iteradorN = iteradorN->proximo;
    }
	printf("\n");
}

int main()
{
    Fila_especial *fe = inicializaFila();
    Fila_normal *fn = inicializaFila();

    int senhaE = 0, senhaN = 0;
    char tipo;

    do{
        int idade, fila_especial = 0;
        char gravida = 'n', portador, sexo;
        printf("idade: ");
        scanf("%i",&idade);
        fflush(stdin);
        printf("sexo[h/m]: ");
        scanf("%c",&sexo);
        fflush(stdin);
        if(sexo == 'm'){
            printf("gravida[s/n]: ");
            scanf("%c",&gravida);
            fflush(stdin);
        }
        printf("portador de necessidades especiais[s/n]: ");
        scanf("%c",&portador);
        fflush(stdin);

        if(idade>= 60 || gravida == 's' || portador == 's'){
            senhaE++;
            fila_especial = 1;
            tipo = 'E';
            colocaDado(tipo,senhaE,fe);
            printf("senha: %c%d\n",tipo,senhaE);
        } else{
            senhaN++;
            tipo = 'N';
            colocaDadon(tipo,senhaN,fn);
            printf("senha: %c%d\n",tipo,senhaN);
        }

        printf("\nFila: ");
        imprimeFila(fn, fe);
        printf("\n");
    }while(fe || fn);

    return 0;
}



