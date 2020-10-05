#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    int i;
    char f [100];
    printf("Escreva uma frase: ");
    gets(f);
    for(i=0;i<strlen(f);i++){
        if (isalpha (f[0])){
            f[0] = toupper (f[0]);
            for(i=1;i<strlen(f);i++){
                if(islower(f[i])&&(isspace (f[i-1]) || ispunct(f[i-1]))){
                    f[i] = toupper (f[i]);
                }
            }
        }else{
            for(i=0;i<strlen(f);i++){
                if(islower(f[i])&&(isspace (f[i-1]) || ispunct(f[i-1]))){
                    f[i] = toupper (f[i]);
                }
            }
        }
    }
    printf("%s",f);
    return 0;
}