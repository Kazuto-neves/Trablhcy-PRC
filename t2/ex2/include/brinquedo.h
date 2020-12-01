#ifndef _BRINQUEDO_H_
#define _BRINQUEDO_H_

#include"uteis.h"

#define _TAM_NOME_	 30
#define _TAM_NOME_2  20

typedef struct{
    char nome[_TAM_NOME_], cat[_TAM_NOME_2];
    int codigo,qtd;
    double Preco;
} Brinquedo;

typedef struct{
  Brinquedo v[_TAM_NOME_2];
  int    q;
} Brinquedos;

void lerBriquendo (Brinquedo *a);
int obterIndiceBriquendo (Brinquedos a, int codigo);
void mostrarBrinquedo (Brinquedos a, int codigo);


#endif
