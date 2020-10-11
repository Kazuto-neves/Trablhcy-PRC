#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>

int main()
{  
   setlocale(LC_ALL, "Portuguese");
   int i,j,c,p,m,m2, valor;
   char palavra[1001], copia[1001], nova[1001], inversa[1001];
   printf("digite uma palavra\n");
   fgets(palavra, 1000, stdin);
   j=strlen(palavra);
   for(i=j-1,m2=0;i>=0;i--,m2++){
        inversa[m2]=palavra[i];
       
    }inversa[m2]='\0';
   for(i=0,m=0;i<j;i++){
    if(isalpha(palavra[i]))
    {
        copia[m]=palavra[i];
        m++;
    }if(isdigit(palavra[i]))
    {
        copia[m]=palavra[i];
        m++;
    }
 }
  
copia[j]='\0';
p=strlen(copia);
for (i=p-1,j=0;i>=0;i--,j++)nova[j] = copia[i];
nova[p] = '\0';
if (strcmp(copia,nova) == 0) printf("É palindromo\n",palavra);
else printf("Não é palindromo!\n", palavra);
printf("A frase|palavra fica como:%s\n",inversa);
return 0;
}