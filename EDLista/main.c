#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tarefa.h"

int main(){ 
    Tarefa T1 = {"Trabalho de Matematica", "Ana Maria", EM_ANDAMENTO, 0.75, 5};
    Tarefa T2 = {"Revisão do código do sistema", "Carlos Henrique", FEITO, 1.00, 5};
    Tarefa T3 = {"Criação de mockups para o app", "Juliana Ribeiro", EM_ANDAMENTO, 0.40, 3};
    Tarefa T4 = {"Levantamento de requisitos", "Rafael Souza", A_FAZER, 0.00, 2};
    Tarefa T5 = {"Treinamento da equipe", "Fernanda Lima", EM_ANDAMENTO, 0.60, 4};
    Tarefa T6 = {"Testes automatizados", "Lucas Martins", A_FAZER, 0.00, 5};
    Tarefa T7 = {"Atualização da documentação técnica", "Mariana Alves", A_FAZER, 0.00, 3};
    Tarefa T8 = {"Integração com API externa", "Pedro Rocha", EM_ANDAMENTO, 0.50, 4};
    Tarefa T9 = {"Apresentação para o cliente", "Bianca Torres", FEITO, 1.00, 5};
    Tarefa T10 = {"Correção de bugs críticos", "João Victor", EM_ANDAMENTO, 0.30, 5};

    Lista * P = CriarLista(200);

    AdicionarTarefa(P, T1);
    AdicionarTarefa(P, T2);
    AdicionarTarefa(P, T3);
    AdicionarTarefa(P, T4);
    AdicionarTarefa(P, T5);
    AdicionarTarefa(P, T6);
    AdicionarTarefa(P, T7);
    AdicionarTarefa(P, T8);
    AdicionarTarefa(P, T9);
    AdicionarTarefa(P, T10);


    for(int i = 0; i < P->Tamanho; i++ ){
        printf("%d\t %s\n", i, P->Dados[i].Titulo);
    }

    GerarHTMLTabela(P, "TabelaTarefas.html");

    return 0;
}