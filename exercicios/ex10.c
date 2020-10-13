#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char palavra[20];
char forca[20];
char erros[27];

#ifdef _WIN32 || _WIN64 
#define limpar_input() fflush(stdin)
#define limpar_tela() system("cls")
#else
#define limpar_input() __fpurge(stdin)
#define limpar_tela() system("clear")
#endif


void limparP(char *buf, int tamanho) {
    int i = 0;
    for (i = 0; i < tamanho; i++) buf[i] = 0;
}
void fimp(char *str) {
    int p;
    for (p = strlen(str); isspace(str[p]); p--) str[p] = 0;
}
int erLetra(char c) {return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');}
char maiuscula(char c) {return (c >= 'a' && c <= 'z') ? (c - 32) : c;}

void start(void) {
    limparP(palavra, 20);
    limparP(forca, 20);
    limparP(erros, 27);
    printf("\nDigite uma palavra: ");
    fgets(palavra, 20, stdin);
    limpar_input();
    fimp(palavra);
    int i;
    for (i = 0; palavra[i] != 0; i++) {
        char c = palavra[i];
        forca[i] = erLetra(c) ? '_' : c;
    }
}
int jogo(void) {
    char tentativa;
    int chances = 5;
    int letras = 0;
    int i;
    for (i = 0; palavra[i] != 0; i++) {
        if (erLetra(palavra[i])) letras++;
    }
    while (chances > 0) {
        limpar_tela();
        printf("\nChances: %d - palavras tem %d letras\n\n", chances, letras);
        printf("%s", forca);
        if (strlen(erros) > 0) printf("\nErros: %s", erros);
        printf("\n\nDigite uma letra: ");
        scanf("%c", &tentativa);
        limpar_input();
        if (!erLetra(tentativa)) continue;
        int jaTentou = 0;
        for (i = 0; erros[i] != 0; i++) {
            if (erros[i] == maiuscula(tentativa)) {
                jaTentou = 1;
                break;
            }
        }
        if (jaTentou) continue;
        for (i = 0; forca[i] != 0; i++) {
            if (maiuscula(forca[i]) == maiuscula(tentativa)) {
                jaTentou = 1;
                break;
            }
        }
        if (jaTentou) continue;
        int ganhou = 1;
        int achou = 0;
        for (i = 0; palavra[i] != 0; i++) {if (!erLetra(palavra[i])) continue;
            if (forca[i] == '_') {
                if (maiuscula(palavra[i]) == maiuscula(tentativa)) {
                    forca[i] = palavra[i];
                    achou = 1;
                } else ganhou = 0;
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
void mostrarResultado(int resultado) {
    limpar_input();
    if (resultado == 0) printf("\nVoce perdeu. \nA palavra era %s", palavra);
    else printf("\nParabens, voce acertou a palavra %s ", palavra);
}
int main() {
    start();
    int resultado = jogo();
    mostrarResultado(resultado);
    return 0;
}