#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>

char pala[20],espa[20],letra,leter[20];
int i,vidas,acertou,win=0,er,tam;

//void boneco(int er);

int main(){
    setlocale(LC_ALL, "Portuguese");
	printf("Digite a palavra chave: ");
	gets(pala);
   tam = strlen(pala);
    system("CLS");
   er = 0;
   vidas = 1;
	for (i = 0; i < tam; i++){
	  if(isspace(pala[i])||ispunct(pala[i])){
	      espa[i] = ' ';
	  }else{
	      espa[i] = '-';
	  }
 	}
 	while (vidas < (tam + 6)) {
   		win = 1;
   		acertou = 0;
        //boneco(er);
   		for (i =  0; i < tam; i++){
       		printf("%c", espa[i]);
   		}
   		printf("\n");
   		printf("Digite a letra: ");
   		scanf("%s", &letra);
   		for (i = 0; i < tam; i++){
      		if (pala[i] == letra ){
         		acertou = 1;
         		espa[i] = letra;
      		}/*else{
      		    leter[i]=letra;
      		    printf("letras erradas %s\n",leter);
      		}*/
    	}
   		if (acertou == 0){
      		er+=1;
    	}
   		for (i = 0; i < tam; i++){
      		if (pala[i] != espa[i] ){
         		win = 0;
      		}
    	}
   		if (win == 1) {
       		printf("Parabens! Você ganhou!\n");
       		printf("a palavra/frase digitada é:%s", pala);
       		break;
    	}
    	if (er == 6){
    		printf("Você perdeu!");
    		break;
    	}
		vidas+=1;
	}
	return 0;
}
/*void boneco(int er){
	switch(er){
		case 0:
			printf("+---+\n");
    		printf("|   |\n");
    		printf("    |\n");
   			printf("    |\n");
   			printf("    |\n");
   			printf("    |\n");
   			printf("=========\n");
		break;

		case 1:
			printf("+---+\n");
    		printf("|   |\n");
    		printf("0   |\n");
    		printf("    |\n");
    		printf("    |\n");
    		printf("    |\n");
    		printf("=========\n");
		break;

		case 2:
			printf("+---+\n");
    		printf("|   |\n");
		    printf("0   |\n");
		    printf("|   |\n");
		    printf("    |\n");
		    printf("    |\n");
		    printf("=========\n");
		break;

		case 3:
			printf(" +---+\n");
		    printf(" |   |\n");
		    printf(" 0   |\n");
		    printf("´|   |\n");
		    printf("     |\n");
		    printf("     |\n");
		    printf("=========\n");
		break;

		case 4:
		   printf(" +---+\n");
		   printf(" |   |\n");
		   printf(" 0   |\n");
		   printf("´|`  |\n");
		   printf("     |\n");
		   printf("     |\n");
		   printf("=========\n");
		break;

		case 5:
		   printf(" +---+\n");
		   printf(" |   |\n");
		   printf(" 0   |\n");
		   printf("´|`  |\n");
		   printf("´    |\n");
		   printf("     |\n");
		   printf("=========\n");
		break;

		case 6:
		   printf(" +---+\n");
		   printf(" |   |\n");
		   printf(" 0   |\n");
		   printf("´|`  |\n");
		   printf("´ `  |\n");
		   printf("     |\n");
		   printf("=========\n");
	}
}*/

