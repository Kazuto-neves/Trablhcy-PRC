#ifndef _HISTORICO_H_
#define _HISTORICO_H_

#include "brinquedo.h"
#include "uteis.h"

#define _MAX_HISTORICO_


typedef struct{
    Brinquedo v[20];
    int qtd;
} Historico;

void inicializarHistorico (Historico *a);
void inicializarBriquendos (Brinquedos *a);
void adicionarBriquedos (Brinquedos *a, Brinquedo b);
void inserirBrinquedo (Historico *a, Brinquedos b, int codigo);
int obterIndiceHistorico (Historico a, int codigo);
void removerBrinquedos(Historico *a, Brinquedos *b, int codigo);
void alterarBrinquedo (Historico *a, Brinquedos *b, int codigo);
void listarBrinquedo(Brinquedos a);
void listarHistorico (Historico a);
#endif

