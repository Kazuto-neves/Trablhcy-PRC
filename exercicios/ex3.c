
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    int i,j=1;
    char f [100];
    printf("Escreva uma frase: ");
    gets(f);                          
    f[0] = toupper (f[0]); 
    printf("%s",f);
    return 0;
}