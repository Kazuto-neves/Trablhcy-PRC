#include<stdio.h>
#include<stdlib.h>

#include"brinquedo.h"

void limparTela(){
   system("cls");
}

void pausar(char msg[]){
   if (msg!=NULL)
     printf("%s\n",msg);
   system("pause");
}

int menu(){
  int opc;
  do {
    limparTela();
    printf("1-Inserir\n");
    printf("2-Remover\n");
    printf("3-Alterar\n");
    printf("4-Listar\n");
    printf("5-Sair\n");
    printf("\nEntre com a sua opcao:");
    scanf("%d", &opc);
  } while (opc<1 || opc>5);
  fflush(stdin);
  limparTela();
  return opc;
}


int main(){
   Brinquedos   hist;
   Brinquedo disc;
   int  fim,cod;

   fim = 0;
   inicializar(&hist);
   while(!fim){
     switch(menu()){
        case 1: /*inserir*/
    	   lerBrinquedo(&disc);
          inserir(&hist, disc);

           pausar("Inserido com sucesso!");
           break;
        case 2: /*remover*/
           printf("Entre com o codigo da Brinquedo para remover:");
           scanf("%d", &cod);
           if (existe(hist, cod)){
              remover(&hist, cod);
              pausar("Removido com sucesso!");
           } else
              pausar("Codigo nao encontrado!");
           break;
        case 3: /*alterar*/
           printf("Entre com o codigo da Brinquedo para alterar:");
           scanf("%d", &cod);
           if (existe(hist, cod)){
              lerBrinquedo(&disc);
              alterar(&hist, cod, disc);
              pausar("Alterado com sucesso!");
           } else
              pausar("Codigo nao encontrado!");
           break;
        case 4: /*Agenda*/
           mostrar(hist);
           pausar(NULL);
           break;
        case 5:/*fim*/
           fim=1;
           break;
     }
   }
   return 0;
}
