#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "musica.h"

Item * criaritem(char * Titulo, char * Autor, int Ano){

    //Alocação de Memória
    Item * X = (Item *)malloc(sizeof(Item));

    if(X == NULL){
        printf("ERRO: Impossivel alocar memoria para o item");
        return NULL;
    }

    strcpy(X->Titulo, Titulo);
    strcpy(X->Autor, Autor);
    X->Ano = Ano;
    X->Anterior = NULL;
    X->Posterior = NULL;

    return X;
}

void ExibirInicio(Lista * L){

    Item * Atual = L->Inicio;
    for(int i = 0; i < L->Tamanho; i++){
        printf("%d\t %s\n", i, Atual->Titulo);
        Atual = Atual->Posterior;
    }

    printf("\n");
}

void ExibirFinal(Lista * L){

    Item * Atual = L->Fim;
    for(int i = 0; i < L->Tamanho; i++){
        printf("%d\t %s\n", i, Atual->Titulo);
        Atual = Atual->Anterior;
    }

printf("\n");
}

void ExibirMusicas(Lista * L, int Ano){
     
    Item * Atual = L->Inicio;

     for(int i = 0; i < L->Tamanho; i++){
        if(Atual->Ano == Ano){
        printf("%d\t %s\n", i, Atual->Titulo);
          }
          Atual = Atual->Posterior;
    }

    printf("\n");
}