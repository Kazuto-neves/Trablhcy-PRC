#include<stdio.h>

int main() {
 unsigned int num, i, r = 0;
 
 printf("Digite um número: ");
 scanf("%u", &num);
 if(num==1){
     r++;
 }else{
     for (i = 2; i <= num / 2; i++) {
         if(num % i == 0){
             r++;
             break;
         }
     }
 }
 
 if (r == 0)printf("%u é um número primo\n", num);
 else printf("%u não é um número primo\n", num);
 
 return 0;
}