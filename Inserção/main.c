#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Main.h"
#include "funcoes.h"

//Principal

int main(){
    int Conjunto[] = {1, 9, 7, 8, 5, 2};
    int Tamanho = sizeof(Conjunto) / sizeof(int);
    InsertionSort(Conjunto, Tamanho);
    ExibirVetor(Conjunto, Tamanho);

    return 0;
}

