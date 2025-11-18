#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char Chave;

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
    n->Direita = NULL;
    //for (int I = 0; I = 3; I++) F[I] = NULL;
}

int main(){
    No * A = CriarNo('A');
    No * B = CriarNo('B');
    No * C = CriarNo('C');
    No * D = CriarNo('D');

    A->Esquerda = B;
    A->Direita = C;
    C->Direita = D;
    
}
