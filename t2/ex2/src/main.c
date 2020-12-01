#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "brinquedo.h"
#include "Historico.h"
#include "uteis.h"

int main (){
    Brinquedo a;
    Historico b;
    Brinquedos c;
    int k=1, codigo;
    inicializarHistorico(&b); inicializarBriquendos(&c);
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
            case 1: limparTela(); lerBriquendo (&a); adicionarBrinquedo(&c, b); break;
            case 2: limparTela(); printf("Insira o ID referente a Brinquedo:\n"); scanf(" %d", &codigo); inserirBrinquedo(&b, c, codigo); break;
            case 3: limparTela(); printf("Insira o ID referente a Brinquedo:\n"); scanf(" %d", &codigo); mostrarBrinquedo(c, codigo); pausarTela(); break;
            case 4: limparTela(); printf("Insira o ID referente a Brinquedo:\n"); scanf(" %d", &codigo); removerBrinquedo(&b, &c, codigo); break;
            case 5: limparTela(); printf("Insira o ID referente a Brinquedo:\n"); scanf(" %d", &codigo); alterarBrinquedo(&b, &c, codigo); break;
            case 6: limparTela(); listarBrinquedo(c); pausarTela(); break;
            case 7: limparTela(); listarHistorico(b); pausarTela(); break;
            case 0: printf("Encerrando programa...\n"); break;
            default: printf("Opcao invalida! Tente novamente.\n"); pausarTela(); break;
        }
    }
    return 0;
}
