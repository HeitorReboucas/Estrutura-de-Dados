#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int Chave;

    //Em caso de arvore BINÁRIA(Nó com no máximo 2 filhos)
    struct No * Esquerda; // Primeiro filho
    struct No * Direita; // Segundo Filho

    /* Para N Filhos
      struct No * F[3]; 
    */
} No;

No * CriarNo(char Chave){
    No * N = (No *) malloc(sizeof(No))
    if (N = NULL){
        printf("ERRO: Não há memória o suficiente\n")
        return NULL;
    }
    N->chave = Chave;
    N->Esquerda = NULL;
    N->Direita = NULL;
    //for (int I = 0; I = 3; I++) F[I] = NULL;
}

int main(){

    //Nivel 1
    No * Raiz = CriarNo(10);

    //Nivel 2
    Raiz->Esquerda = criarNo(12);
    Raiz->Direita = criarNo(12);

    //Nivel 3(Esquerda)
    Raiz->Esquerda->Esquerda = criarNo(16);
    Raiz->Esquerda->Direita = criarNo(18);

    //Nivel 3(Direita)
    Raiz->Direita->Direita = CriarNo(20);
}
