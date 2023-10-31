#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ingressos.h"
#include "verifica.h"
char cod1[5];
char cpf[12];
char senha[21];
char carrinho[20][5];

void intro_ingressos(void){
    int stop = 0;
    int option;
    while (stop == 0){
        system("clear||cls");
        printf("===============================\n        ~ GRAN C-IRCO ~\n           INGRESSOS\n===============================\n");
        printf("[1]Reservar\n"); printf("[2]Cancelar\n"); printf("[3]Meu Carrinho\n");
        printf("[4]Finalizar\n"); printf("[5]Voltar\n");
        printf("DIGITE A OPCAO DESEJADA: ");
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
    printf("===============================\n        ~ GRAN C-IRCO ~\n            RESERVA\n===============================\n");
    printf("DIGITE O CODIGO DO ESPETACULO QUE VOCE DESEJA RESERVAR O INGRESSO:\n");
    printf("PARA CONSULTAR A LISTA DE ESPETACULOS, DIGITE 'L'.\n");
    fgets(cod1, 4, stdin);
    fflush(stdin);
    printf("\n- PRESSIONE ENTER PARA CONTINUAR.");
    getchar();
    fflush(stdin);
    return;
}

void ingressos_cancelar(void){
    system("clear||cls");
    printf("===============================\n        ~ GRAN C-IRCO ~\n            CANCELAR\n===============================\n");
    printf("DIGITE O CODIGO DO ESPETACULO QUE VOCE DESEJA CANCELAR O INGRESSO:\n");
    printf("PARA CONSULTAR A LISTA DE ESPETACULOS, DIGITE 'L'.\n");
    fgets(cod1, 4, stdin);
    fflush(stdin);
    printf("\n- PRESSIONE ENTER PARA CONTINUAR.");
    getchar();
    fflush(stdin);
    return;
}

void ingressos_carrinho(void){
    system("clear||cls");
    printf("===============================\n        ~ GRAN C-IRCO ~\n            CARRINHO\n===============================\n");
    printf("LISTA DE ITENS DO CARRINHO\n"); // Aqui listará o que o cliente comprou até agora.
    printf("\n- PRESSIONE ENTER PARA CONTINUAR.");
    getchar();
    fflush(stdin);
    return;
}

void ingressos_finalizar(void){
    int op;
    do {
        system("clear||cls");
        printf("===============================\n        ~ GRAN C-IRCO ~\n           FINALIZAR\n===============================\n");
        printf("INFORME SEU CPF (APENAS NUMEROS):\n");
        fgets(cpf, 12, stdin);
        fflush(stdin);
        printf("INFORME SUA SENHA (MAXIMO: 20 CARACTERES)");
        fgets(senha, 20, stdin);
        fflush(stdin);
    } while (validaCPF(cpf) == 0);
    printf("CPF: %s", cpf);
    printf("\nDIGITE 1 PARA FINALIZAR A RESERVA OU OUTRA TECLA PRA SAIR.\n");
    scanf("%d", &op);
    fflush(stdin);
    if (op == 1){
        // Diminuir a quantidade de vagas e cadastrar no relatório de vendas daquele evento.
        printf("\nRESERVA FINALIZADA!\nOBS: PARA VALIDAR SEU INGRESSO, BASTA REALIZAR O PAGAMENTO NA HORA DO SHOW\n");
        printf("\n- PRESSIONE ENTER PARA CONTINUAR.");
        getchar();
        fflush(stdin);
        }
    return;
}

void ingressos_comprados(void){
    do {
        system("clear||cls");
        printf("===============================\n        ~ GRAN C-IRCO ~\n      RESERVAS CONCLUIDAS\n===============================\n");
        printf("DIGITE SEU CPF:\n");
        fgets(cpf, 12, stdin);
        fflush(stdin);
    } while (validaCPF(cpf) == 0);
    // Fazer outra verificação se existe esse CPF cadastrado.
    printf("LISTA DE INGRESSOS RESERVADOS.\n");
    printf("\n- PRESSIONE ENTER PARA CONTINUAR.");
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
    printf("===============================\n        ~ GRAN C-IRCO ~\n        ERRO ENCONTRADO\n===============================\n");
    printf("POR FAVOR, SELECIONE UMA OPCAO VALIDA.\n");
    printf("\n- PRESSIONE ENTER PARA CONTINUAR.");
    getchar();
    fflush(stdin);
    system("clear||cls");
    return;
}
