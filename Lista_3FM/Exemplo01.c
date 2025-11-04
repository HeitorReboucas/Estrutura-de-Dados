#include <stdio.h>
#include <stdlib.h>

typedef struct item
{
    int Chave;
    struct item *Proximo;
} item;

int main(int argc, char *argv)
{
    item *A = (item *)malloc(sizeof(item));
    A->Chave = 17;

    item *B = (item *)malloc(sizeof(item));
    B->Chave = 29;

    item *C = (item *)malloc(sizeof(item));
    C->Chave = 41;

    item *D = (item *)malloc(sizeof(item));
    D->Chave = 97;

    // Encadeando
    A->Proximo = B;
    B->Proximo = C;
    C->Proximo = D;
    printf("%d\n", A->Chave);
    printf("%d\n", A->Proximo->Chave);
    printf("%d\n", A->Proximo->Proximo->Chave);
    printf("%d\n", A->Proximo->Proximo->Proximo->Chave);    

    return 0;
}