#include <stdio.h>
#include <stdlib.h>

#include "pilha.h"


item * criaritem(int Chave){
    item * X = (item *) malloc(sizeof(item));
    if(X == NULL){
        printf("ERRO: Impossivel alocar memoria para o item");
        return NULL;
    }

    item->Chave = 0;
    item->Anterior = NULL

    return X;
}

pilha * criarPilha(){
   pilha * P = (item *) malloc(sizeof(item));
    if(P == NULL){
        printf("ERRO: Impossivel alocar memoria para a pilha");
        return NULL;
    }

    P->Tamanho = 0;
    P->Topo = 0;

    return P;
}

void empilhar(pilha * P, item * X){ 
    I->Anterior = P->Topo;
    P->Topo = X
    P->Tamanho++;
}

void desempilhar(pilha * P){
    if(P->Tamanho == 0){
printf("Erro: Pilha Vazia")
return ;}
item * x = P->Topo
p->topo = X->anterior;
free(x)
p->tamanho--;

}