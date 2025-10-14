#ifndef TAREFA_H
#define TAREFA_H

#define TAM_TITULO 96
#define TAM_NOME 48

//typedef enum{A_FAZER, EM_ANDAMENTO, FEITO} tipoStatus;
#define A_FAZER 0
#define EM_ANDAMENTO 1
#define FEITO 2

//Estrutura de um elemento
typedef struct{
    char Titulo[TAM_TITULO];
    char Responsavel[TAM_NOME];
    int Status; 
    /**
    0- A fazer 
    1- Fazendo 
    2- Feito
    **/
   float Progresso; // Porcentagem 
   int Avaliacao; 
} Tarefa;

//Estrutura da lista de Tarefas
typedef struct {
    Tarefa * Dados;
    int Capacidade;
    int Tamanho;
} Lista;

//Declarando as funções
Lista * CriarLista(int C);
void DestruirLista(Lista * L);
void AdicionarTarefa(Lista * L, Tarefa T);
void GerarHTMLTabela(Lista *Lista, char *CaminhoArquivo);

#endif