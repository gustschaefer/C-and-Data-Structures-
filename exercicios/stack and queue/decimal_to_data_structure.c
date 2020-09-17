#include <stdio.h>
#include <stdlib.h>

typedef struct elemento {
    int dado;
    struct elemento *proximo;
} Elemento;

typedef struct fila {
    Elemento *inicio;
    Elemento *fim;
} Fila;

Fila *inicializaFila() {
    Fila *f;
    f = (Fila *)malloc(sizeof(Fila));
    f->inicio = NULL;
    f->fim = NULL;
    return f;
}

void insert(int d, Fila *f) {
    Elemento *novoDado; 
    novoDado = (Elemento *)malloc(sizeof(Elemento)); 
    novoDado->dado = d; 
    novoDado->proximo = NULL; 
    if (f->inicio == NULL) 
    {
        f->fim = f->inicio = novoDado; 
    }
    else 
    {
        f->fim->proximo = novoDado;
        f->fim = novoDado;
    }
}

void print_queue(Fila *f) {
    Elemento *iterador;
    iterador = (Elemento *)malloc(sizeof(Elemento));
    iterador = f->inicio;
    while (iterador != NULL) {
        printf("%i ",iterador->dado);
        iterador = iterador->proximo;
    }
	printf("\n");
}

int get_decimal(char *string_num) {
    char s_integral[15], s_fractional[15];
    int i, found = 0, count = 1, fractional;

    for (i = 0; string_num[i] != '\0'; i++) {
        if (!found) {
            if (string_num[i] == '.') {
                found = 1;
                s_integral[i] = '\0';
                continue;
             }
            s_integral[i] = string_num[i];
            count++; //1
        }
        else
            s_fractional[i - count] = string_num[i];
    }

    s_fractional[i - count] = '\0';
    fractional = atoi(s_fractional);
    return fractional;
}

void queue_decimal(Fila *f, int num) {
    int factor = 1, temp;

    temp = num;

    while(temp) {
      temp = temp / 10;
      factor = factor * 10;
    }

    while(factor > 1) {
      factor = factor / 10;
      insert(num / factor, f);
      num = num % factor;
  }
}

int main(){

    char *string_num;  
    int decimal;
    Fila *f = inicializaFila();

    printf("num: ");
    scanf("%s", string_num);
    decimal = get_decimal(string_num);

    printf("Fila com decimais separados: ");
    queue_decimal(f, decimal);
    print_queue(f);
  
}

