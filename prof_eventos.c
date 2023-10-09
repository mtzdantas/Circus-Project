#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prof_eventos.h"
char data[11], local[51], horario[6], preco[7], cod2[5];
int vagas;

void eventos_listar(void){
    system("clear||cls");
    printf("===============================\n        ~ GRAN C-IRCO ~\n          ESPETACULOS\n===============================\n");
    printf("LISTA DE EVENTOS.\n");
    printf("\n- PRESSIONE ENTER PARA CONTINUAR.");
    getchar();
    fflush(stdin);
    return;
}

void eventos_cadastrar(void){
    system("clear||cls");
    printf("===============================\n        ~ GRAN C-IRCO ~\n           CADASTRAR\n===============================\n");
    printf("DATA DO EVENTO:\n");
    fgets(data, 10, stdin);
    fflush(stdin);
    printf("LOCALIZACAO:\n");
    fgets(local, 50, stdin);
    fflush(stdin);
    printf("HORARIO:\n");
    fgets(horario, 5, stdin);
    fflush(stdin);
    printf("PRECO DO INGRESSO:\n");
    fgets(preco, 6, stdin);
    fflush(stdin);
    printf("VAGAS DISPONIBILIZADAS:\n");
    scanf("%d", &vagas);
    fflush(stdin);
    printf("CODIGO DE ESPETACULO:\n");
    fgets(cod2, 4, stdin);
    fflush(stdin);
    printf("CADASTRO REALIZADO COM SUCESSO!\n");
    printf("\n- PRESSIONE ENTER PARA CONTINUAR.");
    getchar();
    fflush(stdin);
    return;
}

void eventos_cancelar(void){
    system("clear||cls");
    printf("===============================\n        ~ GRAN C-IRCO ~\n            CANCELAR\n===============================\n");
    printf("DIGITE O CODIGO DO ESPETACULO QUE VOCE DESEJA CANCELAR:\n");
    printf("PARA CONSULTAR A LISTA DE ESPETACULOS, DIGITE 'L'.\n");
    fgets(cod2, 4, stdin);
    fflush(stdin);
    printf("ESPETACULO CANCELADO COM SUCESSO!\n");
    printf("\n- PRESSIONE ENTER PARA CONTINUAR.");
    getchar();
    fflush(stdin);
    return;
}

void eventos_alterar(void){
    int option;
    system("clear||cls");
    printf("===============================\n        ~ GRAN C-IRCO ~\n            ALTERAR\n===============================\n");
    printf("DIGITE O CODIGO DO EVENTO QUE DESEJA ALTERAR: \n");
    fgets(cod2, 4, stdin);
    fflush(stdin);
    system("clear||cls");
    printf("===============================\n        ~ GRAN C-IRCO ~\n            ALTERAR\n===============================\n");
    printf("[1]Data\n"); printf("[2]Localizacao\n"); printf("[3]Horario\n");
    printf("[4]Preco\n"); printf("[5]Vagas\n"); printf("[6]Voltar\n");
    printf("DIGITE QUAL DADO DESEJA ALTERAR: ");
    scanf("%d", &option);
        fflush(stdin);
        switch (option){
            case 1: 
                printf("NOVA DATA DO EVENTO:\n");
                fgets(data, 10, stdin);
                fflush(stdin);
                printf("DATA DO EVENTO ALTERADA.\n");
                printf("\n- PRESSIONE ENTER PARA CONTINUAR.");
                getchar();
                fflush(stdin);
                break;
            case 2:
                printf("NOVA LOCALIZACAO:\n");
                fgets(local, 50, stdin);
                fflush(stdin);
                printf("LOCALIZACAO ALTERADA.\n");
                printf("\n- PRESSIONE ENTER PARA CONTINUAR.");
                getchar();
                fflush(stdin);
                break;
            case 3:
                printf("NOVO HORARIO:\n");
                fgets(horario, 5, stdin);
                fflush(stdin);
                printf("HORARIO ALTERADO.\n");
                printf("\n- PRESSIONE ENTER PARA CONTINUAR.");
                getchar();
                fflush(stdin);
                break;
            case 4:
                printf("NOVO PRECO DO INGRESSO:\n");
                fgets(preco, 6, stdin);
                fflush(stdin);
                printf("PRECO DO INGRESSO ALTERADO.\n");
                printf("\n- PRESSIONE ENTER PARA CONTINUAR.");
                getchar();
                fflush(stdin);
                break;
            case 5:
                printf("NOVA QUANTIDADE DE VAGAS:\n");
                scanf("%d", &vagas);
                fflush(stdin);
                printf("QUANTIDADE DE VAGAS ALTERADA.\n");
                printf("\n- PRESSIONE ENTER PARA CONTINUAR.");
                getchar();
                fflush(stdin);
                break;
            case 6:
                return;
                printf("\n- PRESSIONE ENTER PARA CONTINUAR.");
                getchar();
                fflush(stdin);
                break; 
            default:
                opcao_invalida();
                break;
        }
    return;
}
