#include <stdio.h>                 // printf, etc.
#include <stdlib.h>                // free, etc.
#include "processo.h"              // Importa o TAD e protótipos.

int main() {                       // Ponto de entrada do programa.
    Processo *processos;           // Ponteiro para o vetor dinâmico de Processos.
    int n = carregar_processos("TJDFT_amostra.csv", &processos);
                                    // Carrega os processos do CSV; n recebe a quantidade carregada.

    printf("Total de processos: %d\n", contar_processos(processos, n));
                                    // Imprime o total de processos usando a função do TAD.

    int id = buscar_id_ultimo_oj(processos, n, "12345");               // Exemplo de busca por um id_processo específico.
    if (id != -1) printf("Ultimo órgão julgador: %d\n", id);           // Se achou, imprime o id_ultimo_oj.

    salvar_julgados(processos, n, "julgados.csv");                     // Gera o CSV com processos julgados (mérito).

    free(processos);               // Libera a memória alocada para o vetor de Processos.
    return 0;                      // Encerra o programa com status OK.
}
