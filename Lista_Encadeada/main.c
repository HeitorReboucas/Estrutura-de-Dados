#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "musica.h"

int main(){
    Item * D = criaritem("Aquarela", "Toquinho", 1983);
    Item * E = criaritem("Romaria", "Renato Teixeira", 1978);
    Item * F = criaritem("Eu nasci há dez mil anos atrás", "Raul Seixas", 1976);
    Item * G = criaritem("Cálice", "Chico Buarque", 1978);
    Item * H = criaritem("Tempo Perdido", "Renato Russo", 1986);

        //ENCADEANDO D, E, F, G, H
        D->Anterior = NULL;
        D->Posterior = E;

        E->Anterior = D;
        E->Posterior = F;

        F->Anterior = E;
        F->Posterior = G;

        G->Anterior = F;
        G->Posterior = H;

        H->Anterior = G;
        H->Posterior = NULL;


    /**Exercício:
    
    Item * atual = E;

        atual = atual->Posterior;
        atual = atual->Posterior;
        atual = atual->Posterior;
        atual = atual->Posterior;
    printf("%s", atual->Titulo);
    **/


    //Alocar memória pra lista
    Lista * Playlist = (Lista *) malloc(sizeof(Lista));
    if(Playlist == NULL){
     exit(1);
    }

    //Definindo a Lista
    Playlist->Tamanho = 5;
    Playlist->Inicio = D;
    Playlist->Fim = H;

    ExibirInicio(Playlist);
    printf("\n");
    ExibirFinal(Playlist);

    ExibirMusicas(Playlist);

}