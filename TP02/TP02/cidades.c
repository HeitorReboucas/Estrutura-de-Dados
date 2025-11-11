#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include "cidades.h"

// Função auxiliar para criar uma nova cidade
Cidade* criarCidade(int posicao, const char* nome) {
    Cidade* novaCidade = (Cidade*)malloc(sizeof(Cidade));
    if (novaCidade == NULL) return NULL;
    
    strcpy(novaCidade->Nome, nome);
    novaCidade->Posicao = posicao;
    novaCidade->Proximo = NULL;
    
    return novaCidade;
}

// Função auxiliar para inserir cidade ordenada por posição
void inserirCidadeOrdenada(Estrada* estrada, Cidade* novaCidade) {
    if (estrada->Inicio == NULL) {
        estrada->Inicio = novaCidade;
        return;
    }
    
    Cidade* atual = estrada->Inicio;
    Cidade* anterior = NULL;
    
    while (atual != NULL && atual->Posicao < novaCidade->Posicao) {
        anterior = atual;
        atual = atual->Proximo;
    }
    
    if (anterior == NULL) {
        novaCidade->Proximo = estrada->Inicio;
        estrada->Inicio = novaCidade;
    } else {
        anterior->Proximo = novaCidade;
        novaCidade->Proximo = atual;
    }
}

// Função auxiliar para liberar a memória da lista de cidades
void liberarCidades(Cidade* inicio) {
    Cidade* atual = inicio;
    while (atual != NULL) {
        Cidade* proximo = atual->Proximo;
        free(atual);
        atual = proximo;
    }
}
int main()
    {
Estrada *getEstrada(const char *nomeArquivo) {
    FILE* arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        return NULL;
    }
    
    // Ler T (comprimento total da estrada)
    int T;
    if (fscanf(arquivo, "%d", &T) != 1) {
        fclose(arquivo);
        return NULL;
    }
    
    // Verificar restrição de T
    if (T < 3 || T > 1000000) {
        fclose(arquivo);
        return NULL;
    }
    
    // Ler N (número de cidades)
    int N;
    if (fscanf(arquivo, "%d", &N) != 1) {
        fclose(arquivo);
        return NULL;
    }
    
    // Verificar restrição de N
    if (N < 2 || N > 10000) {
        fclose(arquivo);
        return NULL;
    }
    
    // Alocar e inicializar a estrutura Estrada
    Estrada* estrada = (Estrada*)malloc(sizeof(Estrada));
    if (estrada == NULL) {
        fclose(arquivo);
        return NULL;
    }
    
    estrada->T = T;
    estrada->N = N;
    estrada->Inicio = NULL;
    
    // Ler as cidades
    for (int i = 0; i < N; i++) {
        int posicao;
        char nome[256];
        
        if (fscanf(arquivo, "%d", &posicao) != 1) {
            liberarCidades(estrada->Inicio);
            free(estrada);
            fclose(arquivo);
            return NULL;
        }
        
        // Ler o nome (pode conter espaços)
        if (fscanf(arquivo, " %255[^\n]", nome) != 1) {
            liberarCidades(estrada->Inicio);
            free(estrada);
            fclose(arquivo);
            return NULL;
        }
        
        // Verificar restrição da posição
        if (posicao <= 0 || posicao >= T) {
            liberarCidades(estrada->Inicio);
            free(estrada);
            fclose(arquivo);
            return NULL;
        }
        
        // Verificar se já existe cidade na mesma posição
        Cidade* atual = estrada->Inicio;
        while (atual != NULL) {
            if (atual->Posicao == posicao) {
                liberarCidades(estrada->Inicio);
                free(estrada);
                fclose(arquivo);
                return NULL;
            }
            atual = atual->Proximo;
        }
        
        // Criar e inserir a cidade
        Cidade* novaCidade = criarCidade(posicao, nome);
        if (novaCidade == NULL) {
            liberarCidades(estrada->Inicio);
            free(estrada);
            fclose(arquivo);
            return NULL;
        }
        
        inserirCidadeOrdenada(estrada, novaCidade);
    }
    
    fclose(arquivo);
    return estrada;
}

double calcularMenorVizinhanca(const char *nomeArquivo) {
    Estrada* estrada = getEstrada(nomeArquivo);
    if (estrada == NULL) {
        return -1.0;
    }
    
    if (estrada->N < 2) {
        liberarCidades(estrada->Inicio);
        free(estrada);
        return -1.0;
    }
    
    double menorVizinhanca = DBL_MAX;
    Cidade* atual = estrada->Inicio;
    
    // Calcular vizinhança para cada cidade
    while (atual != NULL) {
        double vizinhanca = 0.0;
        
        if (atual == estrada->Inicio) {
            // Primeira cidade
            vizinhanca = atual->Posicao;
            if (atual->Proximo != NULL) {
                vizinhanca += (atual->Proximo->Posicao - atual->Posicao) / 2.0;
            } else {
                vizinhanca = estrada->T - atual->Posicao;
            }
        } else if (atual->Proximo == NULL) {
            // Última cidade
            Cidade* anterior = estrada->Inicio;
            while (anterior->Proximo != atual) {
                anterior = anterior->Proximo;
            }
            vizinhanca = (atual->Posicao - anterior->Posicao) / 2.0 + (estrada->T - atual->Posicao);
        } else {
            // Cidade do meio
            Cidade* anterior = estrada->Inicio;
            while (anterior->Proximo != atual) {
                anterior = anterior->Proximo;
            }
            vizinhanca = (atual->Posicao - anterior->Posicao) / 2.0 + (atual->Proximo->Posicao - atual->Posicao) / 2.0;
        }
        
        if (vizinhanca < menorVizinhanca) {
            menorVizinhanca = vizinhanca;
        }
        
        atual = atual->Proximo;
    }
    
    liberarCidades(estrada->Inicio);
    free(estrada);
    
    return menorVizinhanca;
}

char *cidadeMenorVizinhanca(const char *nomeArquivo) {
    Estrada* estrada = getEstrada(nomeArquivo);
    if (estrada == NULL) {
        return NULL;
    }
    
    if (estrada->N < 2) {
        liberarCidades(estrada->Inicio);
        free(estrada);
        return NULL;
    }
    
    double menorVizinhanca = DBL_MAX;
    Cidade* cidadeMenor = NULL;
    Cidade* atual = estrada->Inicio;
    
    // Encontrar a cidade com menor vizinhança
    while (atual != NULL) {
        double vizinhanca = 0.0;
        
        if (atual == estrada->Inicio) {
            // Primeira cidade
            vizinhanca = atual->Posicao;
            if (atual->Proximo != NULL) {
                vizinhanca += (atual->Proximo->Posicao - atual->Posicao) / 2.0;
            } else {
                vizinhanca = estrada->T - atual->Posicao;
            }
        } else if (atual->Proximo == NULL) {
            // Última cidade
            Cidade* anterior = estrada->Inicio;
            while (anterior->Proximo != atual) {
                anterior = anterior->Proximo;
            }
            vizinhanca = (atual->Posicao - anterior->Posicao) / 2.0 + (estrada->T - atual->Posicao);
        } else {
            // Cidade do meio
            Cidade* anterior = estrada->Inicio;
            while (anterior->Proximo != atual) {
                anterior = anterior->Proximo;
            }
            vizinhanca = (atual->Posicao - anterior->Posicao) / 2.0 + (atual->Proximo->Posicao - atual->Posicao) / 2.0;
        }
        
        if (vizinhanca < menorVizinhanca) {
            menorVizinhanca = vizinhanca;
            cidadeMenor = atual;
        }
        
        atual = atual->Proximo;
    }
    
    if (cidadeMenor == NULL) {
        liberarCidades(estrada->Inicio);
        free(estrada);
        return NULL;
    }
    
    // Alocar e copiar o nome da cidade
    char* nomeCidade = (char*)malloc(strlen(cidadeMenor->Nome) + 1);
    if (nomeCidade != NULL) {
        strcpy(nomeCidade, cidadeMenor->Nome);
    }
    
    liberarCidades(estrada->Inicio);
    free(estrada);
    
    return nomeCidade;
}  
    return 0;
    }