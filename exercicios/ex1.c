#include<stdio.h>
#include <locale.h>


int main() {
	 setlocale(LC_ALL, "Portuguese");
	 int num, i, r = 0;
	 
	 printf("Digite um número: ");
	 scanf("%d", &num);
	   if(num<0)num*=-1;
	   if(num==1)r++;
	   else for (i = 2; i <= num / 2; i++)
	   if(num % i == 0){
	       r++;
	       break;
	       }
	 if (r == 0)printf("%d é um número primo\n", num);
	 else printf("%d não é um número primo\n", num);
	 return 0;
}