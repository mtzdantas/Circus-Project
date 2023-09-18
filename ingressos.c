#include <stdio.h>
#include <stdlib.h>
#include "ingressos.h"

void ingressos_comprar(void){
    system("clear||cls");
    wprintf(L"===============================\n        ~ GRAN C-IRCO ~\n            COMPRAR\n===============================\n");
    wprintf(L"COMPRAR\n"); // Aqui terá que informar o código do show que será consultado ao clicar enter.
    wprintf(L"\n- PRESSIONE ENTER PARA CONTINUAR.");
    getchar();
    fflush(stdin);
}

void ingressos_cancelar(void){
    system("clear||cls");
    wprintf(L"===============================\n        ~ GRAN C-IRCO ~\n            CANCELAR\n===============================\n");
    wprintf(L"CANCELAR COMPRAS\n"); // Aqui terá que informar o código do show que será consultado ao clicar enter.
    wprintf(L"\n- PRESSIONE ENTER PARA CONTINUAR.");
    getchar();
    fflush(stdin);
}

void ingressos_carrinho(void){
    system("clear||cls");
    wprintf(L"===============================\n        ~ GRAN C-IRCO ~\n            CARRINHO\n===============================\n");
    wprintf(L"MEU CARRINHO\n"); // Aqui listará o que o cliente comprou até agora.
    wprintf(L"\n- PRESSIONE ENTER PARA CONTINUAR.");
    getchar();
    fflush(stdin);
}

void ingressos_finalizar(void){
    system("clear||cls");
    wprintf(L"===============================\n        ~ GRAN C-IRCO ~\n           FINALIZAR\n===============================\n");
    wprintf(L"FINALIZAR COMPRA\n"); // Aqui vai gerar um código para pagar e ao ser pago a compra é aprovada,
    wprintf(L"\n- PRESSIONE ENTER PARA CONTINUAR.");
    getchar(); // diminuindo a quantidade de vagas e cadastrando nas vendas daquele evento. Pedir número/CPF/nome.
    fflush(stdin);
}

void ingressos_comprados(void){
    system("clear||cls");
    wprintf(L"===============================\n        ~ GRAN C-IRCO ~\n       COMPRAS ANTERIORES\n===============================\n");
    wprintf(L"COMPRAS REALIZADAS\n"); // Aqui mostrará ingressos comprados quando for informado nome completo/CPF.
    wprintf(L"\n- PRESSIONE ENTER PARA CONTINUAR.");
    getchar();
    fflush(stdin);
}

void ingressos_sair(void){
    // Aqui apaga o carrinho do cliente e volta para tela inicial.
}

void opcao_invalida(void){
    system("clear||cls");
    wprintf(L"===============================\n        ~ GRAN C-IRCO ~\n        ERRO ENCONTRADO\n===============================\n");
    wprintf(L"POR FAVOR, SELECIONE UMA OPÇÃO VÁLIDA.\n");
    wprintf(L"\n- PRESSIONE ENTER PARA CONTINUAR.");
    getchar();
    fflush(stdin);
    system("clear||cls");
}
