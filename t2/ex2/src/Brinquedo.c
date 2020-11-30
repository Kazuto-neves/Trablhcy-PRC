#include<stdio.h>
#include<string.h>

#include"briquedo.h"
#include"uteis.h"

void lerBriquendo (Brinquedo *a){
    printf("Entre com o codigo da briquedo: "); scanf(" %d", &(*a).codigo);
    limpa();
    printf("Entre com o nome do brinquedo: "); lerString( (*a).nome, _TAM_NOME_ );
    printf("Entre com o catgoria do briquedo: "); lerString( (*a).cat, _TAM_NOME_ );
    printf("Entre com o Preco do briquedo: "); scanf(" %lf", &(*a).Preco);
    printf("Entre com a quantidade  do brinquedo: "); scanf(" %d", &(*a).qtd);
    limpa();
    printf("Brinquedo lida com sucesso!\n"); pausarTela();
}
int obterIndiceBriquendo (Brinquedos a, int codigo){
    int i = 0;
    int achou = 0;
    while (achou == 0 && i<a.q){
        if (a.v[i].codigo == codigo)achou = 1;
        else i++;
    }
    return achou==1 ? i : -1;
}

void mostrarBrinquedo (Brinquedos a, int codigo){
    int psc = obterIndiceBriquendo(a, codigo);
    if (psc > -1){
        printf(".----------\n");
        printf("|Codigo: %d\tNome: %s|\n", a.v[psc].codigo, a.v[psc].nome);
        printf("|Catgoria: %s\tPreco: %d\tQuantidade: %d|\n", a.v[psc].cat, a.v[psc].Preco, a.v[psc].qtd);
        printf(".----------\n");
        /*pausartela();*/
    }else {printf("Brinquedo nao encontrada!\n");}
        /*pausartela();*/
}
