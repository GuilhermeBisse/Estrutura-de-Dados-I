#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct pilha {
    char info;
    struct pilha* prox;
} pilha;

void push(pilha** topo, int x) {
    pilha* aux = (pilha*)malloc(sizeof(pilha));
    aux->info = x;
    aux->prox = *topo;
    *topo = aux;
}

char pop(pilha** topo, char* elem) {
    if(*topo == NULL) {
        printf("UNDERFLOW");
        return 0;
    }
    *elem = (*topo)->info;
    pilha* aux = *topo;
    *topo = (*topo)->prox;
    free(aux);
    return *elem;
}

void criar_pilha(pilha** topo){
    *topo = NULL;
}

int esta_vazia(pilha* topo){
    return (topo == NULL);
}

int esta_cheia(pilha* topo){
    return (topo->prox==MAX-1);
}

void retornar_pilha(pilha* topo){
    if(topo == NULL){
        printf("PILHA VAZIA");
        return;
    }
    while(topo != NULL){
        printf("%d ", topo->info);
        topo = topo->prox;
    }
}

int main(){
    pilha* topo;
    criar_pilha(&topo);
    
    char seq[100] = "aabCbaa";
    int i=0;
    int chegouC = 0;
    char valor;
    
    while (seq[i] != 'C' && seq[i] != '\0') {
        push(&topo, seq[i]);
        i++;
    }
    
    if(seq[i] == 'C') {
        i++;
    }
    
    int correto = 1;
    while (seq[i] != '\0' && !esta_vazia(topo)) {
        if(seq[i] != pop(&topo, &valor)) {
            correto = 0;
            break;
        }
        i++;
    }
    
    if(correto && esta_vazia(topo) && seq[i] == '\0') {
        printf("Sequencia correta!");
    } else {
        printf("Sequencia incorreta!");
    }

    


    return 0;
}