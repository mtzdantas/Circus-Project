#include <stdio.h>
#include <stdlib.h>
#include "ingressos.h"

void intro_ingressos(void){
    int stop = 0;
    int option;
    while (stop == 0){
        system("clear||cls");
        wprintf(L"===============================\n        ~ GRAN C-IRCO ~\n           INGRESSOS\n===============================\n");
        wprintf(L"[1]Comprar\n"); wprintf(L"[2]Cancelar\n"); wprintf(L"[3]Meu Carrinho\n");
        wprintf(L"[4]Finalizar\n"); wprintf(L"[5]Compras Realizadas\n"); wprintf(L"[6]Voltar\n");
        wprintf(L"DIGITE A OPÇÃO DESEJADA: ");
        scanf("%d", &option);
        fflush(stdin);
        switch (option){
            case 1: 
                ingressos_comprar();
                break;
            case 2:
                ingressos_cancelar();
                break;
            case 3:
                ingressos_carrinho();
                break;
            case 4:
                ingressos_finalizar();
                break;
            case 5:
                ingressos_comprados();
                break;
            case 6:
                ingressos_sair();
                stop = 1;
                break; 
            default:
                opcao_invalida();
                break;
        }
    }
    return;
}

void ingressos_comprar(void){
    system("clear||cls");
    wprintf(L"===============================\n        ~ GRAN C-IRCO ~\n            COMPRAR\n===============================\n");
    wprintf(L"COMPRAR\n"); // Aqui terá que informar o código do show que será consultado ao clicar enter.
    wprintf(L"\n- PRESSIONE ENTER PARA CONTINUAR.");
    getchar();
    fflush(stdin);
    return;
}

void ingressos_cancelar(void){
    system("clear||cls");
    wprintf(L"===============================\n        ~ GRAN C-IRCO ~\n            CANCELAR\n===============================\n");
    wprintf(L"CANCELAR COMPRAS\n"); // Aqui terá que informar o código do show que será consultado ao clicar enter.
    wprintf(L"\n- PRESSIONE ENTER PARA CONTINUAR.");
    getchar();
    fflush(stdin);
    return;
}

void ingressos_carrinho(void){
    system("clear||cls");
    wprintf(L"===============================\n        ~ GRAN C-IRCO ~\n            CARRINHO\n===============================\n");
    wprintf(L"MEU CARRINHO\n"); // Aqui listará o que o cliente comprou até agora.
    wprintf(L"\n- PRESSIONE ENTER PARA CONTINUAR.");
    getchar();
    fflush(stdin);
    return;
}

void ingressos_finalizar(void){
    system("clear||cls");
    wprintf(L"===============================\n        ~ GRAN C-IRCO ~\n           FINALIZAR\n===============================\n");
    wprintf(L"FINALIZAR COMPRA\n"); // Aqui vai gerar um código para pagar e ao ser pago a compra é aprovada,
    wprintf(L"\n- PRESSIONE ENTER PARA CONTINUAR.");
    getchar(); // diminuindo a quantidade de vagas e cadastrando nas vendas daquele evento. Pedir número/CPF/nome.
    fflush(stdin);
    return;
}

void ingressos_comprados(void){
    system("clear||cls");
    wprintf(L"===============================\n        ~ GRAN C-IRCO ~\n       COMPRAS ANTERIORES\n===============================\n");
    wprintf(L"COMPRAS REALIZADAS\n"); // Aqui mostrará ingressos comprados quando for informado nome completo/CPF.
    wprintf(L"\n- PRESSIONE ENTER PARA CONTINUAR.");
    getchar();
    fflush(stdin);
    return;
}

void ingressos_sair(void){
    // Aqui apaga o carrinho do cliente e volta para tela inicial.
    return;
}

void opcao_invalida(void){
    system("clear||cls");
    wprintf(L"===============================\n        ~ GRAN C-IRCO ~\n        ERRO ENCONTRADO\n===============================\n");
    wprintf(L"POR FAVOR, SELECIONE UMA OPÇÃO VÁLIDA.\n");
    wprintf(L"\n- PRESSIONE ENTER PARA CONTINUAR.");
    getchar();
    fflush(stdin);
    system("clear||cls");
    return;
}
