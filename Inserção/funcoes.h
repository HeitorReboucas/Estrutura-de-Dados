#ifndef FUNCOES_H
#define FUNCOES_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Main.h"



void InsertionSort(int * V, int N){
    int Chave; //Elemento que será inserido na parte ordenada
    int J; // Posição do elemento da parte ordenada comparavel

    for(int I = 1; I < N; I++){
        Chave = V[I];
        J = I - 1;

        while(J >= 0 && V[J] > Chave){
            V[J + 1] = V[J];
            J--;
        }
        V[J + 1] = Chave; // Copiando o Chave no Lugar do ultimo numero

    }


}
void ExibirVetor(int * V, int N){
    for(int I = 0; I <  N; I++){

    printf("%d\t", V[I]);}
}

#endif