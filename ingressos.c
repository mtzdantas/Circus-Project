#include <stdio.h>
#include <stdlib.h>
#include "ingressos.h"
char cod1[5];
char senha[21];
char cpf[12];

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
    wprintf(L"DIGITE O CÓDIGO DO ESPETÁCULO QUE VOCÊ DESEJA ADQUIRIR O INGRESSO:\n");
    wprintf(L"PARA CONSULTAR A LISTA DE ESPETÁCULOS, DIGITE 'L'.\n");
    fgets(cod1, 4, stdin);
    fflush(stdin);
    wprintf(L"\n- PRESSIONE ENTER PARA CONTINUAR.");
    getchar();
    fflush(stdin);
    return;
}

void ingressos_cancelar(void){
    system("clear||cls");
    wprintf(L"===============================\n        ~ GRAN C-IRCO ~\n            CANCELAR\n===============================\n");
    wprintf(L"DIGITE O CÓDIGO DO ESPETÁCULO QUE VOCÊ DESEJA CANCELAR O INGRESSO:\n");
    wprintf(L"PARA CONSULTAR A LISTA DE ESPETÁCULOS, DIGITE 'L'.\n");
    fgets(cod1, 4, stdin);
    fflush(stdin);
    wprintf(L"\n- PRESSIONE ENTER PARA CONTINUAR.");
    getchar();
    fflush(stdin);
    return;
}

void ingressos_carrinho(void){
    system("clear||cls");
    wprintf(L"===============================\n        ~ GRAN C-IRCO ~\n            CARRINHO\n===============================\n");
    wprintf(L"LISTA DE ITENS DO CARRINHO\n"); // Aqui listará o que o cliente comprou até agora.
    wprintf(L"\n- PRESSIONE ENTER PARA CONTINUAR.");
    getchar();
    fflush(stdin);
    return;
}

void ingressos_finalizar(void){
    int op;
    system("clear||cls");
    wprintf(L"===============================\n        ~ GRAN C-IRCO ~\n           FINALIZAR\n===============================\n");
    wprintf(L"INFORME SEU CPF (APENAS NÚMEROS):\n");
    fgets(cpf, 12, stdin);
    fflush(stdin);
    wprintf(L"INFORME UMA SENHA:\n");
    fgets(senha, 21, stdin);
    fflush(stdin);
    wprintf(L"CPF: %s", cpf);
    wprintf(L"SENHA: %s", senha);
    wprintf(L"\nDIGITE 1 PARA FINALIZAR A COMPRA OU OUTRA TECLA PRA SAIR.\n");
    scanf("%d", &op);
    fflush(stdin);
    if (op == 1){
        // Diminuir a quantidade de vagas e cadastrar no relatório de vendas daquele evento.
        wprintf(L"COMPRA FINALIZADA\n");
        wprintf(L"\n- PRESSIONE ENTER PARA CONTINUAR.");
        getchar();
        fflush(stdin);
        }
    return;
}

void ingressos_comprados(void){
    system("clear||cls");
    wprintf(L"===============================\n        ~ GRAN C-IRCO ~\n       COMPRAS ANTERIORES\n===============================\n");
    wprintf(L"DIGITE SEU CPF:\n");
    gets(cpf);
    fflush(stdin);
    wprintf(L"DIGITE SUA SENHA:\n");
    gets(senha);
    fflush(stdin);
    wprintf(L"LISTA DE INGRESSOS COMPRADOS.\n");
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
