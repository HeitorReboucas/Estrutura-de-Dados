#ifndef PILHA_H
#define PILHA_H

typedef struct item
{
    int Chave;
    struct item * Anterior;
} item;

typedef struct pilha
{
    int Tamanho;
    item *Topo;
} pilha;

pilha * CriarPilha();
item * CriarItem(int Chave);

void empilhar(pilha * P, item * X);
void desempilhar(pilha * P, item * X);

#endif