#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct no {
    int valor;
    struct no* prox;
} Pilha;

void push(Pilha** topo, int valor) {
    Pilha* novo = (Pilha*)malloc(sizeof(Pilha));
    novo->valor = valor;
    novo->prox = *topo;
    *topo = novo;
}

int pop(Pilha** topo) {
    Pilha* temp = *topo;
    int valor = temp->valor;
    *topo = temp->prox;
    free(temp);
    return valor;
}

int main() {
    Pilha* topo = NULL;
    char expressao[100];
    int i = 0;
    int num, a, b;

    printf("Digite a expressao pos-fixa (ex: 3 4 + 5 *): ");
    fgets(expressao, 100, stdin);

    while(expressao[i] != '\0') {
        if(expressao[i] == ' ') {
            i++;
            continue;
        }

        if(isdigit(expressao[i])) {
            num = 0;
            while(isdigit(expressao[i])) {
                num = num * 10 + (expressao[i] - '0');
                i++;
            }
            push(&topo, num);
        } else {
            b = pop(&topo);
            a = pop(&topo);
            switch(expressao[i]) {
                case '+': push(&topo, a + b); break;
                case '-': push(&topo, a - b); break;
                case '*': push(&topo, a * b); break;
                case '/': push(&topo, a / b); break;
            }
            i++;
        }
    }

    printf("Resultado: %d\n", pop(&topo));
    return 0;
}