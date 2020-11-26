#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include"Contatos.h"


void lerString(char str[], int max){
   int tam;
   fflush(stdin);
   fgets(str, max, stdin);
   tam = strlen(str);
   if (str[tam-1]=='\n')
      str[tam-1]='\0';
}

void lerContatos(Contatos *d){
   printf("Codigo:");		scanf("%d",& (*d).codigo);
   printf("Nome:");		lerString((*d).nome, _NOME_MAX_LEN_);
   printf("Email:");	lerString((*d).Email, _NOME_MAX_LEN_);
   printf("DD:");		scanf("%d",& (*d).DD);
   printf("Numero:");		scanf("%d",& (*d).Numero);
}

void mostrarContatos(Contatos d){
   printf("Codigo:%d\n",d.codigo);
   printf("Nome:%s\n",d.nome);
   printf("Email:%s\n",d.Email);
   printf("Numero:(%d) %d\n",d.DD,d.Numero);
}

void inicializar(Agenda *h){
   (*h).qtd=0;
}

void inserir(Agenda *h, Contatos d){
   (*h).vet[(*h).qtd] = d;
   (*h).qtd++;
}

int obterIndice(Agenda h, int codigo){
   int achou,i;
   achou=0;
   i=0;
   while (!achou && i<h.qtd)
      if (h.vet[i].codigo == codigo)
         achou = 1;
      else
         i++;
   return achou?i:-1;
}

int existe(Agenda h, int codigo){
   return obterIndice(h, codigo)!=-1;
}

void remover(Agenda *h, int codigo){
   int pos = obterIndice(*h, codigo);
   if (pos!=-1){
       (*h).vet[pos] = (*h).vet[(*h).qtd-1];
       (*h).qtd--;
   }
}

void alterar(Agenda *h, int codigo, Contatos d){
   int pos = obterIndice(*h, codigo);
   if (pos!=-1)
       (*h).vet[pos] = d;
}

void listar(Agenda h){
   int i;
   printf("%-20s %20s %3s %10s\n",
	     "Nome", "email", "DD", "Numero");
   for(i=0;i<62;i++)
     printf("-");
   printf("\n");
   for (i=0; i<h.qtd; i++){
      Contatos d = h.vet[i];
      printf("%-20s %20s (%i)%10i\n",
	     d.nome, d.Email, d.DD, d.Numero);
   }
   for(i=0;i<62;i++)
     printf("-");
   printf("\n");
}

void mostrar(Agenda h){
   listar(h);
}
