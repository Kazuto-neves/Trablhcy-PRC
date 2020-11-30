#include "uteis.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void limparTela(){
    #ifdef __unix__
        system("clear");
    #elif _WIN32
        system("cls");
    #elif _WIN64
        system("cls");
    #endif
}

void limpa(){while ((getchar()) != '\n');}

void pausarTela(){
    #ifdef __unix__
        system("read -r -p \"Pressione qualquer tecla...\" key");
    #elif _WIN32
        system("pause");
    #elif _WIN64
        system("pause");
    #endif
}

void lerString(char var[], int limite){
    int tam;
    fgets( var, limite, stdin ); tam = strlen(var);
    if (var[tam-1] == '\n')
        var[tam-1] = '\0';
}
