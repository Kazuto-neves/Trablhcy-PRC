#include<stdio.h>
#include<strings.h>
#include<stdlib.h>

#include"brinquedo.h"


void lerString(char str[], int max){
   int tam;
   fflush(stdin);
   fgets(str, max, stdin);
   tam = strlen(str);
   if (str[tam-1]=='\n')
      str[tam-1]='\0';
}

void lerBriquedo(Brinquedo *d){
   printf("Codigo:");		scanf("%d",& (*d).codigo);
   printf("Nome:");		lerString((*d).nome, 30);
   printf("Categoria:");	lerString((*d).cat,20);
   printf("Preco:");		scanf("%f",& (*d).preco);
   printf("quantidade:");		scanf("%d",& (*d).qtd);
}

void mostrarBriquedo(Brinquedo d){
   printf("Codigo:%d\n",d.codigo);
   printf("Nome:%s\n",d.nome);
   printf("Categoria:%s\n",d.Email);
   printf("Preco: R$%.2f\n",d.preco);
   printf("quantidade:%d\n",d.qtd);
}

void inicializar(Brinquedos *h){
   (*h).q=0;
}

void inserir(Brinquedos *h, Brinquedo d){
   (*h).vet[(*h).q] = d;
   (*h).q++;
}
int obterIndice(Brinquedos h, int codigo){
   int achou,i;
   achou=0;
   i=0;
   while (!achou && i<h.qtd)
      if (h.vet[i].codigo==codigo)
         achou = 1;
      else
         i++;
   return achou?i:-1;
}

int existe(Brinquedos h, int codigo){
   return obterIndice(h, codigo)!=-1;
}

void remover(Brinquedos *h,int codigo){
   int pos = obterIndice(*h, codigo);
   if (pos!=-1){
       (*h).vet[pos] = (*h).vet[(*h).q-1];
       (*h).q--;
   }
}

void alterar(Brinquedos *h,int codigo, Brinquedo d){
   int pos = obterIndice(*h, codigo);
   if (pos!=-1)
       (*h).vet[pos] = d;
}

void listar(Brinquedos h){
   int i;
   printf("%-20s %20s %3s %10s\n",
	     "Nome", "categoria", "Preco", "Quantidade");
   for(i=0;i<62;i++)
     printf("-");
   printf("\n");
   for (i=0; i<h.q; i++){
      Brinquedo d = h.vet[i];
      printf("%-20s %20s %.2f %10i\n",
	     d.nome, d.cat, d.preco, d.qtd);
   }
   for(i=0;i<62;i++)
     printf("-");
   printf("\n");
}

void mostrar(Brinquedos h){
   listar(h);
}

void acrecentar (Brinquedos *h, Brinquedo *d, int codigo){
    int pos = obterIndice(*h, codigo);
    int posB;
    int k, acabou=0;
    float inputf,antes;
    if (pos > -1){
       antes=(*h).vet[pos].qtd;
       printf("Insira o nova quantidade:\n");
       limparTela();
       scanf(" %f", &inputf);
       (*h).vet[pos].qtd = inputf+antes;
       }
