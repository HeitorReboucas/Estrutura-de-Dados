#ifndef PROCESSO_H                 // Evita inclusão múltipla do cabeçalho no mesmo build (include guard).
#define PROCESSO_H                 // Define a macro para indicar que este cabeçalho já foi incluído.

typedef struct {                   // Declaração de um Tipo Abstrato de Dados (TAD) chamado Processo.
    char id_processo[50];          // Identificador único do processo (texto).
    char numero_sigilo[50];        // Número processual, possivelmente mascarado (texto).
    char sigla_grau[10];           // Grau de jurisdição (ex.: G1, G2).
    char procedimento[100];        // Procedimento / classe processual (texto).
    char ramo_justica[10];         // Ramo da Justiça (JE, JT, JF, JM, etc.).
    char sigla_tribunal[20];       // Sigla do tribunal (ex.: TJDFT).
    int id_tribunal;               // ID numérico do tribunal.
    int recurso;                   // Flag numérica indicando se há recurso (0/1).
    int id_ultimo_oj;              // Último órgão julgador (ID numérico).
    char dt_recebimento[20];       // Data de recebimento do processo (texto).
    int id_ultima_classe;          // ID da última classe processual.
    int flag_violencia_domestica;  // Flag temática: violência doméstica (0/1).
    int flag_feminicidio;          // Flag temática: feminicídio (0/1).
    int flag_ambiental;            // Flag temática: ambiental (0/1).
    int flag_quilombolas;          // Flag temática: quilombolas (0/1).
    int flag_indigenas;            // Flag temática: indígenas (0/1).
    int flag_infancia;             // Flag temática: infância e juventude (0/1).
    char decisao[50];              // Registro de decisão (texto curto / data).
    char dt_resolvido[20];         // Data em que o processo foi resolvido (texto).
    int cnm1;                      // Casos novos (Meta 1).
    int primeirasentm1;            // Primeira sentença (Meta 1).
    int baixm1;                    // Baixas (Meta 1).
    int decm1;                     // Decisões (Meta 1).
    int mpum1;                     // Recorte MPU (Meta 1).
    int julgadom1;                 // Julgados de mérito (Meta 1).
    int desm1;                     // Desmembrados (Meta 1).
    int susm1;                     // Suspensos (Meta 1).
} Processo;                         // Fecha a definição do struct e nomeia o tipo como Processo.

// ---- Protótipos das funções (contrato do TAD) ----
int carregar_processos(const char *filename, Processo **processos);    // Lê o CSV e carrega em memória.
int contar_processos(Processo *processos, int n);                       // Retorna n (quantidade).
int buscar_id_ultimo_oj(Processo *processos, int n, const char *id_processo); // Busca id_ultimo_oj por id_processo.
char* processo_mais_antigo(Processo *processos, int n);                // (A implementar) ID do processo com dt_recebimento mais antiga.
int contar_flag(Processo *processos, int n, const char *tipo);         // (A implementar) Conta por flag temática.
int dias_entre(const char *data1, const char *data2);                  // (A implementar) Dias entre duas datas (yyyy-mm-dd).
double cumprimento_meta1(Processo *processos, int n);                  // (A implementar) % de cumprimento da Meta 1.
void salvar_julgados(Processo *processos, int n, const char *filename);// Gera CSV só com processos julgados (mérito) na Meta 1.

#endif                             // Fecha o include guard.
