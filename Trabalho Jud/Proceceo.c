#include <stdio.h>                 // Funções de E/S (FILE, fopen, fgets, fprintf, etc.).
#include <stdlib.h>                // Funções utilitárias (malloc, free, etc.).
#include <string.h>                // Manipulação de strings (strcmp, sscanf, etc.).
#include <time.h>                  // (Reservado) caso você use datas com struct tm, mktime, etc.
#include "processo.h"              // Inclui os protótipos e o struct Processo.

// --------------- carregar_processos ----------------
int carregar_processos(const char *filename, Processo **processos) {   // Recebe o caminho do CSV e um ponteiro duplo para vetor.
    FILE *file = fopen(filename, "r");                                 // Abre o arquivo em modo leitura texto.
    if (!file) return 0;                                               // Se falhar ao abrir, retorna 0 (não carregou nada).

    char linha[1024];                                                  // Buffer para ler cada linha do CSV.
    int count = 0;                                                     // Contador de linhas totais (inclui o cabeçalho).

    // Conta quantas linhas existem no arquivo
    while (fgets(linha, sizeof(linha), file)) count++;                 // Lê linha a linha até EOF, incrementando count.
    rewind(file);                                                      // Volta o cursor para o início do arquivo.

    *processos = malloc((count - 1) * sizeof(Processo));               // Aloca memória p/ todas as linhas de dados (exclui o cabeçalho).
    fgets(linha, sizeof(linha), file);                                 // Lê e descarta a primeira linha (cabeçalho).

    int i = 0;                                                         // Índice de escrita no vetor *processos.
    while (fgets(linha, sizeof(linha), file)) {                        // Loop pelas linhas de dados.
        // Extrai campos separados por ';' usando sscanf com “não consumir ;” (%[^;])
        sscanf(linha,
               "%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%d;%d;%d;%[^;];%d;%d;%d;%d;%d;%d;%d;%[^;];%[^;];%d;%d;%d;%d;%d;%d;%d;%d",
               (*processos)[i].id_processo,                            // 1: texto até ';'
               (*processos)[i].numero_sigilo,                          // 2
               (*processos)[i].sigla_grau,                             // 3
               (*processos)[i].procedimento,                           // 4
               (*processos)[i].ramo_justica,                           // 5
               (*processos)[i].sigla_tribunal,                         // 6
               &(*processos)[i].id_tribunal,                           // 7: inteiro
               &(*processos)[i].recurso,                               // 8: inteiro
               &(*processos)[i].id_ultimo_oj,                          // 9: inteiro
               (*processos)[i].dt_recebimento,                         // 10: texto (data)
               &(*processos)[i].id_ultima_classe,                      // 11: inteiro
               &(*processos)[i].flag_violencia_domestica,              // 12: inteiro
               &(*processos)[i].flag_feminicidio,                      // 13: inteiro
               &(*processos)[i].flag_ambiental,                        // 14: inteiro
               &(*processos)[i].flag_quilombolas,                      // 15: inteiro
               &(*processos)[i].flag_indigenas,                        // 16: inteiro
               &(*processos)[i].flag_infancia,                         // 17: inteiro
               (*processos)[i].decisao,                                // 18: texto
               (*processos)[i].dt_resolvido,                           // 19: texto (data)
               &(*processos)[i].cnm1,                                  // 20: inteiro
               &(*processos)[i].primeirasentm1,                        // 21: inteiro
               &(*processos)[i].baixm1,                                // 22: inteiro
               &(*processos)[i].decm1,                                 // 23: inteiro
               &(*processos)[i].mpum1,                                 // 24: inteiro
               &(*processos)[i].julgadom1,                             // 25: inteiro
               &(*processos)[i].desm1,                                 // 26: inteiro
               &(*processos)[i].susm1                                  // 27: inteiro
        );
        i++;                                                           // Avança para o próximo elemento do vetor.
    }

    fclose(file);                                                      // Fecha o arquivo.
    return count - 1;                                                  // Retorna a qtde de registros carregados (sem o cabeçalho).
}

// --------------- contar_processos ------------------
int contar_processos(Processo *processos, int n) {                     // Recebe o vetor e a qtde n.
    return n;                                                          // Apenas retorna n (já é o total de processos).
}

// ----------- buscar_id_ultimo_oj -------------------
int buscar_id_ultimo_oj(Processo *processos, int n, const char *id_processo) {
    for (int i = 0; i < n; i++) {                                      // Percorre todos os processos.
        if (strcmp(processos[i].id_processo, id_processo) == 0) {      // Compara o ID desejado com o ID do elemento.
            return processos[i].id_ultimo_oj;                          // Se achou, retorna o id_ultimo_oj correspondente.
        }
    }
    return -1;                                                         // Se não achou, retorna -1 (indicando não encontrado).
}

// ---------------- salvar_julgados ------------------
void salvar_julgados(Processo *processos, int n, const char *filename) {
    FILE *file = fopen(filename, "w");                                 // Abre/Cria o arquivo de saída em modo escrita.
    if (!file) return;                                                 // Se não conseguiu abrir, apenas retorna.

    fprintf(file, "id_processo;julgadom1\n");                          // Escreve o cabeçalho do CSV de saída.
    for (int i = 0; i < n; i++) {                                      // Percorre todos os processos.
        if (processos[i].julgadom1 > 0) {                              // Mantém apenas os com julgados de mérito (>0).
            fprintf(file, "%s;%d\n",                                   // Escreve linha com id_processo;julgadom1.
                    processos[i].id_processo,
                    processos[i].julgadom1);
        }
    }

    fclose(file);                                                      // Fecha o arquivo de saída.
}
