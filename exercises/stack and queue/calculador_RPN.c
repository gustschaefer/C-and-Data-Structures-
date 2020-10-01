#include <stdio.h>
#include <stdlib.h>

typedef struct elemento{
    int dado;
    struct elemento *proximo;
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

void push(int d, Pilha *p){
    Elemento *novo_dado;
    novo_dado = (Elemento *)malloc(sizeof(Elemento));
    novo_dado->dado = d;
    novo_dado->proximo = p->topo;
    p->topo = novo_dado;
}

int pop(Pilha *p){
    int elemento_retirado = p->topo->dado;
    Elemento *aux = p->topo;
    p->topo = p->topo->proximo;
    free(aux);
    aux = NULL;
    return elemento_retirado;
}

int top(Pilha *p){
    return p->topo->dado;
}


void RPN() {
	char rpn;
	while(1) {
		
		Pilha *p = inicializa_pilha();
		printf("Apos digitar a string RPN, pressione espaco + enter.\n");
		printf("RPN: ");
		scanf("%c", &rpn);
        if(rpn == 'x' || rpn == 'X')
			break;
	
		while(1) {	
			if(rpn == '\n')
				break;

			// char é um int
			if(rpn >= 48 && rpn <= 57)
			    push((rpn - 48), p); // converte char -> int

			switch(rpn){
				case '+':
					push( (sum( pop(p), pop(p) )), p);
					break;
				case '-':
					push((sub(pop(p), pop(p))), p);
					break;
				case '*':
					push((mul(pop(p), pop(p))), p);
					break;
				case '/':
					push((divi(pop(p), pop(p))), p);
					break;
				case ' ':
					printf("Resultado: %d\n\n", pop(p));
					break;
			}
			scanf("%c", &rpn);
		}
	}
	return 0;
}

int sum(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
int mul(int a, int b) { return a * b; }
int divi(int a, int b) { return a / b; }

int main()
{
    printf("\nDigite 'x' para sair.\n\n");
	RPN();
	return 0;
}