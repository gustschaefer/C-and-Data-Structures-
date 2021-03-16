#include <stdio.h>
#include <stdlib.h>

typedef struct arv {
    int info;
    struct arv* esq;
    struct arv* dir;
} Arv;

Arv* abb_cria (void);

Arv* abb_busca (Arv* r, int v);

Arv* abb_insere (Arv* a, int v);

Arv* abb_cria (void)
{
    return NULL;
}


void abb_imprime (Arv* a)
{
    if (a != NULL) {
        abb_imprime(a->esq);
        printf("%d\n",a->info);
        abb_imprime(a->dir);
    }
}

Arv* abb_busca (Arv* r, int v)
{
    if (r == NULL) return NULL;
    else if (r->info > v) return abb_busca (r->esq, v);
    else if (r->info < v) return abb_busca (r->dir, v);
    else return r;
}

Arv* abb_insere (Arv* a, int v)
{
    if (a==NULL) {
        a = (Arv*)malloc(sizeof(Arv));
        a->info = v;
        a->esq = a->dir = NULL;
    }
    else if (v < a->info)
        a->esq = abb_insere(a->esq,v);
    else /* v < a->info */
        a->dir = abb_insere(a->dir,v);
    return a;
}

Arv* abb_retira (Arv* r, int v)
{
    if (r == NULL)
        return NULL;
    else if (r->info > v)
        r->esq = abb_retira(r->esq, v);
    else if (r->info < v)
        r->dir = abb_retira(r->dir, v);
    else { /* achou o nó a remover */
        /* nó sem filhos */
        if (r->esq == NULL && r->dir == NULL) {
        free (r);
        r = NULL;
        }

    /* nó só tem filho à direita */
    else if (r->esq == NULL) {
        Arv* t = r;
        r = r->dir;
        free (t);
    }

    /* só tem filho à esquerda */
        else if (r->dir == NULL) {
        Arv* t = r;
        r = r->esq;
        free (t);
    }

    /* nó tem os dois filhos */
    else {
        Arv* f = r->esq;
        while (f->dir != NULL) {
            f = f->dir;
        }
        r->info = f->info; /* troca as informações */
        f->info = v;
        r->esq = abb_retira(r->esq,v);
        }
    }
    return r;
}

void printDecrescente(Arv *r){
    if(r != NULL){
        printDecrescente(r->dir);
        printf("%d\n", r->info);
        printDecrescente(r->esq);
    }
}

int main(void)
{
    Arv* a=(Arv*)malloc(sizeof(Arv));
    a = abb_insere(NULL,2);
    a = abb_insere(a,1);
    a = abb_insere(a,3);
    a = abb_insere(a,4);

    printDecrescente(a);
    //abb_imprime(a);
    return 0;
}