#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>

void pare(){
#ifdef _WIN32 || _WIN64
    system("pause");
#else 
     //printf("pressione qualquer tecla para finalizar");
     //getchar();
     system("read -r -p \"pressione qualquer tecla para finalizar: \" key");
#endif
}
void limpa(){
#ifdef _WIN32 || _WIN64 
   system("cls");
#else
   system("clear");
#endif
}
int loop(int n){
    int denovo;
	while(1){
		printf("opção inválida\n");
	    printf("tente novamente\n");
	    printf("digite o numero do seu pedido: ");
		scanf("%d", &denovo);
		if((0<=denovo) && (denovo<=5)) break;
        }
    return denovo;
    }
int main(void){    
	char t[10],d[10];
    int n,n1,i,l;
    int n2=1;
    double k;
    setlocale(LC_ALL, "Portuguese");
    while(1){
        printf("bem-vindo ao McMozar\n");
        printf("\n");
        printf("1 - Misto Quente    R$ 4.50\n");
        printf("2 - Queijo Quente   R$ 4.00\n");
        printf("3 - Hamburguer      R$ 6.00\n");
        printf("4 - Eggburguer      R$ 7.00\n");
        printf("5 - Podrão          R$ 9.00\n");
        printf("0 - Sair\n");
        printf("\n");
        printf("digite seus pedidos:\n");
        printf("número:");
        scanf("%d", &n);
        if(n>5||n<0){
		   n=loop(n);
		}
		if(n==0)break;
        printf("qtd:");
        scanf("%d", &n1);
        switch(n){
                case 1: k+=4.50*n1;
                        break;
                case 2: k+=4.00*n1;
                        break;
                case 3: k+=6.00*n1;
                        break;
                case 4: k+=7.00*n1;
                        break;
                case 5: k+=9.00*n1;
                        break;
                default:break;
        
        }
        printf("Finalizando o pedido\n");
        printf("Total: R$%0.2lf\n", k);
        k=0;
        pare();
        limpa();
     }
    printf("Obrigado e volte sempre\n");
return 0;
}