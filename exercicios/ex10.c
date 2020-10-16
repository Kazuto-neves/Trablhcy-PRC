#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

char palavra[30],forca[30],erros[30];
int jfLetra = 0,ganhou=1,achou=0,i;

void limparT(){
#ifdef _WIN32 || _WIN64
system("cls");
#else
system("clear");
#endif
}
void limparI(){
#ifdef _WIN32 || _WIN64
fflush(stdin);
#else
fpurge(stdin);
#endif
}

void limparP(char *p, int tam) {
    int i = 0;
    for (i = 0; i < tam; i++) p[i] = 0;
}
void fimP(char *pl) {
    int p;
    for (p = strlen(pl); isspace(pl[p]); p--) pl[p] = 0;
}

int erLetra(char c) {return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');}
char maiuscula(char c) {return (c >= 'a' && c <= 'z') ? (c - 32) : c;}

void start(void) {
    limparP(palavra, 30);
    limparP(forca, 30);
    limparP(erros, 30);
    printf("\nDigite uma palavra: ");
    fgets(palavra, 30, stdin);
    limparI();
    fimP(palavra);
    for (i = 0; palavra[i] != 0; i++) {
        char c = palavra[i];
        forca[i] = erLetra(c) ? '_' : c;
    }
}
int jogo(void) {
    char tentativa;
    int chances=5,letras=0,i;
    for (i = 0; palavra[i] != 0; i++) if (erLetra(palavra[i])) letras++;

    while (chances > 0) {
        limparT();
        printf("\nChances: %d - palavras tem %d letras\n\n", chances, letras);
        printf("%s", forca);
        if (strlen(erros) > 0) printf("\nErros: %s", erros);
        printf("\n\nDigite uma letra: ");
        scanf("%c", &tentativa);
        limparI();
        if (!erLetra(tentativa)) continue;
        for (i = 0; erros[i] != 0; i++) {
            if (erros[i] == maiuscula(tentativa)) {
                jfLetra=1;
                break;
            }
        }

        if (jfLetra) continue;
        for (i = 0; forca[i] != 0; i++) {
            if (maiuscula(forca[i]) == maiuscula(tentativa)) {
                jfLetra=1;
                break;
            }
        }

        if (jfLetra) continue;
        for (i = 0; palavra[i] != 0; i++) {if (!erLetra(palavra[i])) continue;
            if (forca[i] == '_') {
                if (maiuscula(palavra[i]) == maiuscula(tentativa)) {
                    forca[i] = palavra[i];
                    achou= 1;
                } else ganhou=0;
            }
        }

        if (ganhou) return 1;
        if (!achou) {
            chances--;
            erros[strlen(erros)] = maiuscula(tentativa);
        }
    }
    return 0;
}

void mostrarR(int resultado) {
    limparI();
    if (resultado == 0) printf("\nVoce perdeu. \nA palavra era %s", palavra);
    else printf("\nParabens, voce acertou a palavra %s ", palavra);
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    start();
    int resultado = jogo();
    mostrarR(resultado);
    return 0;
}
