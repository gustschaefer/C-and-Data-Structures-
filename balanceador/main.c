#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct elemento{
    char dado;
    struct elemento *prox;
} Elemento;

typedef struct pilha{
    Elemento *topo;
} Pilha;

Pilha *inicializa_pilha(){
    Pilha *p;
    p = (Pilha *)malloc(sizeof(Pilha));
    p->topo = NULL;
    return p;
}

void push(char d, Pilha *p){
    Elemento *novo_dado;
    novo_dado = (Elemento *)malloc(sizeof(Elemento));
    novo_dado->dado = d;
    novo_dado->prox = p->topo;
    p->topo = novo_dado;
}

char pop(Pilha *p){
    char saida = p->topo->dado;
    Elemento *aux = p->topo;
    p->topo = p->topo->prox;
    free(aux);
    aux = NULL;
    return saida;
}
// testa se ha um balanceamento entre os delimitadores, 1 para balanceado e 0 para nao balanceado
// retorna 1 para balanceado e 0 para nao balanceado
int teste_balanceamento(char char1, char char2){
    if (char1 == '(' && char2 == ')')
        return 1;
    else if (char1 == '{' && char2 == '}')
        return 1;
    else if (char1 == '[' && char2 == ']')
        return 1;
    else
        return 0;
}

int confirma_balanceamento(char caract[]){
    int i = 0;
    Pilha *p = inicializa_pilha();
    while (caract[i])
    {
        if (caract[i] == '{' || caract[i] == '(' || caract[i] == '[')
            // adiciona um elemento na pilha se ele for o delimitador 'inicial'
            push(caract[i], p);
        // se algum caracter for um delimitador 'final'
        if (caract[i] == '}' || caract[i] == ')' || caract[i] == ']')
        {
            if (p == NULL)
                return 0;
            // retira o ultimo elemento da pilha e verifica se ele esta balanceado com o delimitador 'final'
            else if (teste_balanceamento(pop(p), caract[i]) == 0)
                return 0;
        }
        i++;
    }

    if (p == NULL)
        return 0;
    else
        return 1;
}

int main()
{
    char str[100];
    printf("Digite uma frase: \n");
    fgets(str, 100, stdin);
    if (confirma_balanceamento(str) == 1)
        printf("\nBalanceado \n");
    else
        printf("\nNao Balanceado \n");
    return 0;
}

