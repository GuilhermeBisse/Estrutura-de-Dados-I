#include <stdio.h>
#include <stdlib.h>

typedef struct Arvore{
	int valor;
	Arvore* esquerda;
	Arvore* direita;
}Arvore;

Arvore* criar_no(int v){
	Arvore* pai = (Arvore*)malloc(sizeof(Arvore));
	pai->valor = v;
	pai->esquerda = pai->direita = NULL;
	return pai;
}

Arvore* inserir(Arvore* a, int v){
	if(a == NULL){
		return criar_no(v);
	}
	
	if(a->valor > v){
		a->esquerda = inserir(a->esquerda, v);
	}
	else{
		a->direita = inserir(a->direita, v);
	}
	return a;
}

int soma(Arvore* a){
	if (a == NULL) {
		return 0;
	}
	int cont = 0;
	cont += soma(a->esquerda);
	cont += a->valor;
	cont += soma(a->direita);
	return cont;
}

int pares(Arvore* a){
	if (a == NULL) {
		return 0;
	}
	int cont = 0;
	
	if(a->valor%2==0){
		cont=1;
	}
	
	cont += pares(a->esquerda);
	cont += pares(a->direita);
	
	return cont;
	
}

int nos_maiores(Arvore* a, int v){
	if (a==NULL){
		return 0;
	}
	int cont=0;
	
	if(a->valor > v){
		cont=1;
	}
	
	cont += nos_maiores(a->esquerda, v);
	cont += nos_maiores(a->direita, v);
	return cont;
}


void imprimir(Arvore* a){
	if(a!=NULL){
		imprimir(a->esquerda);
		printf("%d ", a->valor);
		imprimir(a->direita);
	}
}

void free_arvore(Arvore* a){
		if(a!=NULL){
		free_arvore(a->esquerda);
		free_arvore(a->direita);
		free(a);
	}
}

int menor_no(Arvore* a){
	if(a->esquerda==NULL){
		return a->valor;
	}else{
		return menor_no(a->esquerda);
	}
}

int maior_no(Arvore* a){
	if(a->direita==NULL){
		return a->valor;
	}else{
		return maior_no(a->direita);
	}
}

Arvore* remover_menor_no(Arvore* a) {
	if (a == NULL) return NULL;

	if(a->esquerda==NULL){
		Arvore* temp = a->direita;
		free(a);
		return temp;
	}
	a->esquerda = remover_menor_no(a->esquerda);
	return a;
}


int main(){
	
	Arvore* pai = criar_no(18);
	int valor;
	for(int i=0; i<5; i++){
		printf("Valor %d: ", i+1);
		scanf("%d", &valor);
		inserir(pai, valor);
	}
	
	imprimir(pai);
	printf("A soma dos nos da arvore e: %d ", soma(pai));
	printf("Menor no e: %d ", menor_no(pai));
	printf("Maior no e: %d ", maior_no(pai));
	printf("Qtd de nos pares: %d ", pares(pai));
	printf("Qtd de nos maiores que 10: %d ", nos_maiores(pai, 10));
	printf("\n");
	pai = remover_menor_no(pai);
	imprimir(pai);
	free_arvore(pai);
	
	
	return 0;
}
