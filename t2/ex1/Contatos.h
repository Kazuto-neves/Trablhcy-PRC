#ifndef _ContatosS_H_
#define _ContatosS_H_

#define _NOME_MAX_LEN_    30
#define _ContatosS_MAX_ 100


typedef struct {
  int codigo;
  char nome[_NOME_MAX_LEN_];
  int DD;
  int Numero;
  char Email[_NOME_MAX_LEN_];
} Contatos;

typedef struct {
  Contatos vet[_ContatosS_MAX_];
  int qtd;
} Agenda;

float mediaContatos(Contatos d);
void lerContatos(Contatos *d);
void mostrarContatos(Contatos d);

void inicializar(Agenda *h);
void inserir(Agenda *h, Contatos d);
int existe(Agenda h, int codigo);
void remover(Agenda *h, int codigo);
void alterar(Agenda *h, int codigo, Contatos d);
void listar(Agenda h);
float CR(Agenda h);
void mostrar(Agenda h);

#endif
