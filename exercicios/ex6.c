#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>


int loop(int n){
    int denovo;
	while(1){
	    printf("digite novamente o numero do seu pedido: ");
		scanf("%d", &denovo);
		if((0<=denovo) && (denovo<=5)) break;	
	}
    return denovo;
}
int main(void){    
    setlocale(LC_ALL, "Portuguese");
	char t[10],d[10];
    int n,n1,i,l;
    int n2=1;
    double k;
    printf("bem-vindo ao McMozar\n\n");
    printf("1 - Misto Quente    R$ 4.50\n");
    printf("2 - Queijo Quente   R$ 4.00\n");
    printf("3 - Hamburguer      R$ 6.00\n");
    printf("4 - Eggburguer      R$ 7.00\n");
    printf("5 - Podrão          R$ 9.00\n");
    printf("0 - Sair\n\n");
    while(1){
    printf("digite seu pedido:\n");
    printf("número:");
    scanf("%d", &n);
    if(n>5||n<0){
		  printf("opção inválida\n");
		  n=loop(n);
	}
	if(n==0)break;
        printf("digite a quantidade:");
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
        printf("Obrigado e volte sempre\n");
        printf("----------------------------------------------------------------------\n\n");
        k=0;       
     }  
    printf("Obrigado e volte sempre\n");
return 0;
}