#ifndef _Contatos_H_
#define _Contatos_H_

#define _NOME_MAX_LEN_    30
#define _Contatos_MAX_ 100


typedef struct {
  int codigo;
  char nome[_NOME_MAX_LEN_];
  int DD;
  int Numero;
  char Email[_NOME_MAX_LEN_];
} Contatos;

typedef struct {
  Contatos vet[_Contatos_MAX_];
  int qtd;
} Agenda;

void lerContatos(Contatos *d);
void mostrarContatos(Contatos d);

void inicializar(Agenda *h);
void inserir(Agenda *h, Contatos d);
int existe(Agenda h, char email[_NOME_MAX_LEN_]);
void remover(Agenda *h, char email[_NOME_MAX_LEN_]);
void alterar(Agenda *h, char email[_NOME_MAX_LEN_], Contatos d);
void listar(Agenda h);
void mostrar(Agenda h);

#endif
