#ifndef MUSICA_H
#define MUSICA_H

typedef struct Item{
    char Titulo[50];
    char Autor[100];
    int Ano;

    struct Item * Anterior;
    struct Item * Posterior;
}Item;
Item * criaritem(char * Titulo, char * Autor, int Ano);


typedef struct Lista{
    int Tamanho; 
    struct Item * Inicio;
    struct Item * Fim;
}Lista;
void ExibirInicio(Lista * L);
void ExibirFinal(Lista * L);

void ExibirMusicas(Lista * L, int Ano);

#endif
