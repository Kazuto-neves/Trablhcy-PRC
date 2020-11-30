#include<stdio.h>
#include<strings.h>

#include "Historico.h"
#include "uteis.h"

void inicializarHistorico (Historico *a){(*a).qtd=0;}
void inicializarBriquendos (Brinquedos *a){(*a).q=0;}

void adicionarBrinquedo (Brinquedos *a, Brinquedo b){
    (*a).v[(*a).q] = b;
    (*a).q++;
}

void inserirBrinquedo (Historico *a, Brinquedos b, int codigo){
    int psc = obterIndiceBriquendo(b, codigo);
    if (psc > -1){
        (*a).v[(*a).qtd] = b.v[psc];
        (*a).qtd++;
        printf("Brinquedo inserida no historico com sucesso!\n"); pausarTela();
    }else {
        printf("Brinquedo nao encontrada!\n");
        pausarTela();
    }
}
void removerBrinquedo(Historico *a, Brinquedos *b, int codigo){
   int psc = obterIndiceBriquendo(*b, codigo);
   if (psc>-1) {
      (*a).v[psc] = (*a).v[ (*a).qtd-1 ];
      (*a).qtd--;
   }
}
void alterarBrinquedo (Historico *a, Brinquedos *b, int codigo){
    int psc = obterIndiceBriquendo(*b, codigo);
    int poHistorico;
    int k, acabou=0;
    char inputstr[_TAM_NOME_];
    int inputn;
    double inputf;
    if (psc > -1){
        while (acabou == 0){
            limparTela();
            printf("O que deseja alterar?\n");
            printf("1. Nome\n2. Categoria\n3. Preco\n4. Quatidade\n0. Sair\n");
            scanf(" %d", &k);
            limpa();
            switch (k){
                case 1:
                    limparTela();
                    printf("Insira o novo nome da Brinquedo:\n");
                    lerString(inputstr, _TAM_NOME_ );
                    strcpy( (*b).v[psc].nome, inputstr);
                    poHistorico = obterIndiceHistorico(*a, codigo);
                    if (poHistorico > -1)
                        strcpy( (*a).v[poHistorico].nome, inputstr);
                    break;
                case 2:
                    limparTela();
                    printf("Insira o novo Categoria do Brinquedo:\n");
                    lerString(inputstr, _TAM_NOME_-10);
                    strcpy( (*b).v[psc].cat, inputstr);
                    poHistorico = obterIndiceHistorico(*a, codigo);
                    if (poHistorico > -1)
                        strcpy( (*a).v[poHistorico].nome, inputstr);
                    break;
                case 3:
                    limparTela();
                    printf("Insira o novo valor para preco:\n");
                    scanf(" %lf", &inputf);
                    (*b).v[psc].Preco = inputf;
                    poHistorico = obterIndiceHistorico(*a, codigo);
                    if (poHistorico > -1)
                        (*a).v[poHistorico].Preco = inputn;
                    break;
                case 4:
                    limparTela();
                    printf("Insira o novo valor para quantidade:\n");
                    scanf(" %d", &inputn);
                    (*b).v[psc].qtd = inputn;
                    poHistorico = obterIndiceHistorico(*a, codigo);
                    if (poHistorico > -1)
                        (*a).v[poHistorico].codigo = inputn;
                    break;
                case 0:
                    acabou=1; break;
                default:
                    printf("Opcao invalida! Tente novamente."); pausarTela();
            }
            if (k != 0) { printf ("Dado alterado com sucesso!\n"); pausarTela(); }
        }
    }else {
        printf("Brinquedo nao encontrada!\n");
        pausarTela();
    }
}
void listarBrinquedo(Brinquedos a){
    int i=0;
    if ( a.q == 0 )
        printf("Nenhuma Brinquedo disponivel.\n");
    else {
        for (i = 0 ; i < a.q ; i++ ){
            printf("------------Brinquedo %d---------------\n", i+1);
            printf("Nome: %s - Catgoria: %s - Preco: %lf - quantidade: %d \n", a.v[i].nome, a.v[i].cat, a.v[i].Preco, a.v[i].qtd);
            printf("----------------------------------------\n");
        }
    }
}
void listarHistorico (Historico a){
    int i=0;
    if ( a.qtd == 0 )printf("Nenhuma Brinquedo consta no historico.\n");
    else {
        for (i = 0 ; i < a.qtd ; i++ ){
            printf("------------Brinquedo %d---------------\n", i+1);
            printf("Nome: %s - Catgoria: %s - Preco: %lf - quantidade: %d \n", a.v[i].nome, a.v[i].cat, a.v[i].Preco, a.v[i].qtd);
            printf("----------------------------------------\n");
        }
    }
}
int obterIndiceHistorico (Historico a, int codigo){
    int i = 0;
    int achou = 0;
    while (achou == 0 && i<a.qtd){
        if (a.v[i].codigo == codigo)achou = 1;
        else i++;
    }
    return achou==1 ? i : -1;
}
