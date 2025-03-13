#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct no {
    int info, prox;
};

struct no lista[MAX];
int dispo = 0;

void liberaNo(int p) {
    lista[p].prox = dispo;
    dispo = p;
}

int primeiroNo() {
    if (dispo == -1) {
        printf("Erro: Lista cheia, não há nós disponíveis.\n");
        return -1;
    }
    int p = dispo;
    dispo = lista[dispo].prox;
    return p;
}

void inserir(int p, int valor) {
    if (p == -1) {
        printf("Erro: Índice inválido para inserção.\n");
        return;
    }
    
    int q = primeiroNo();
    if (q == -1) return;

    lista[q].info = valor;
    lista[q].prox = lista[p].prox;
    lista[p].prox = q;
}

void deletar(int vi, int vf) {
    if (vi >= vf) {
        printf("Erro: Vi deve ser menor que Vf.\n");
        return;
    }

    int anterior = 0;
    int atual = lista[anterior].prox;

    while (atual != -1 && lista[atual].info < vi) {
        anterior = atual;
        atual = lista[atual].prox;
    }

    if (atual == -1 || lista[atual].info > vf) {
        printf("Erro: Nenhum nó encontrado no intervalo [%d, %d].\n", vi, vf);
        return;
    }

    while (atual != -1 && lista[atual].info <= vf) {
        int proxNo = lista[atual].prox;
        liberaNo(atual);
        atual = proxNo;
    }

    lista[anterior].prox = atual;
}

void printarLista(int head) {  
    int atual = lista[head].prox;  
    printf("Lista: ");
    int count = 0;

    while (atual != -1 && count < MAX) {
        printf("%d -> ", lista[atual].info);
        atual = lista[atual].prox;
        count++;
    }

    printf("NULL\n");
}

int main() {
    for (int i = 0; i < MAX - 1; i++) {
        lista[i].prox = i + 1;
    }
    lista[MAX - 1].prox = -1;
    dispo = 0;
    
    int head = primeiroNo();
    lista[head].info = -1;
    lista[head].prox = -1;

    inserir(head, 60);
    inserir(head, 50);
    inserir(head, 40);
    inserir(head, 30);
    inserir(head, 20);
    inserir(head, 10);

    printf("Lista antes da deleção:\n");
    printarLista(head);


    deletar(20, 40);

    printf("Lista depois da deleção:\n");
    printarLista(head);

    return 0;
}
