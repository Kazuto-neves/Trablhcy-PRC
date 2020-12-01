#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "brinquedo.h"
#include "Historico.h"
#include "uteis.h"

int main (){
    Brinquedo Brinquedo;
    Historico a;
    Brinquedos b;
    int k=1, codigo;
    inicializarHistorico(&a); inicializarBriquendos(&b);
    while ( k != 0 )
    {
        limparTela();
        printf("\tBem vindo a Loja de Briquedos do Mozar O que deseja fazer?\n\n");
        printf("1. Adicionar uma Brinquedo.\n2. Inserir Brinquedo no historico.\n3. Mostrar dados de uma Brinquedo.\n"
            "4. Remover uma Brinquedo.\n5. Alterar os dados de uma Brinquedo.\n6. Listar todas as Brinquedos disponiveis.\n7. Listar historico atual.\n"
            "0. Encerrar programa.\n");
        scanf(" %d", &k); limpa();
        switch (k)
        {
            case 1: limparTela(); lerBriquendo (&Brinquedo); adicionarBrinquedo(&b, Brinquedo); break;
            case 2: limparTela(); printf("Insira o ID referente a Brinquedo:\n"); scanf(" %d", &codigo); inserirBrinquedo(&a, b, codigo); break;
            case 3: limparTela(); printf("Insira o ID referente a Brinquedo:\n"); scanf(" %d", &codigo); mostrarBrinquedo(b, codigo); pausarTela(); break;
            case 4: limparTela(); printf("Insira o ID referente a Brinquedo:\n"); scanf(" %d", &codigo); removerBrinquedo(&a, &b, codigo); break;
            case 5: limparTela(); printf("Insira o ID referente a Brinquedo:\n"); scanf(" %d", &codigo); alterarBrinquedo(&a, &b, codigo); break;
            case 6: limparTela(); listarBrinquedo(b); pausarTela(); break;
            case 7: limparTela(); listarHistorico(a); pausarTela(); break;
            case 0: printf("Encerrando programa...\n"); break;
            default: printf("Opcao invalida! Tente novamente.\n"); pausarTela(); break;
        }
    }
    return 0;
}
