#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prof_eventos.h"
char data[11], local[51], horario[6], preco[7], cod2[5];
int vagas;

void eventos_listar(void){
    system("clear||cls");
    wprintf(L"===============================\n        ~ GRAN C-IRCO ~\n          ESPETÁCULOS\n===============================\n");
    wprintf(L"LISTA DE EVENTOS.\n");
    wprintf(L"\n- PRESSIONE ENTER PARA CONTINUAR.");
    getchar();
    fflush(stdin);
    return;
}

void eventos_cadastrar(void){
    system("clear||cls");
    wprintf(L"===============================\n        ~ GRAN C-IRCO ~\n           CADASTRAR\n===============================\n");
    wprintf(L"DATA DO EVENTO:\n");
    fgets(data, 10, stdin);
    fflush(stdin);
    wprintf(L"LOCALIZAÇÃO:\n");
    fgets(local, 50, stdin);
    fflush(stdin);
    wprintf(L"HORÁRIO:\n");
    fgets(horario, 5, stdin);
    fflush(stdin);
    wprintf(L"PREÇO DO INGRESSO:\n");
    fgets(preco, 6, stdin);
    fflush(stdin);
    wprintf(L"VAGAS DISPONIBILIZADAS:\n");
    scanf("%d", &vagas);
    fflush(stdin);
    wprintf(L"CÓDIGO DE ESPETÁCULO:\n");
    fgets(cod2, 4, stdin);
    fflush(stdin);
    wprintf(L"CADASTRO REALIZADO COM SUCESSO!\n");
    wprintf(L"\n- PRESSIONE ENTER PARA CONTINUAR.");
    getchar();
    fflush(stdin);
    return;
}

void eventos_cancelar(void){
    system("clear||cls");
    wprintf(L"===============================\n        ~ GRAN C-IRCO ~\n            CANCELAR\n===============================\n");
    wprintf(L"DIGITE O CÓDIGO DO ESPETÁCULO QUE VOCÊ DESEJA CANCELAR:\n");
    wprintf(L"PARA CONSULTAR A LISTA DE ESPETÁCULOS, DIGITE 'L'.\n");
    fgets(cod2, 4, stdin);
    fflush(stdin);
    wprintf(L"ESPETÁCULO CANCELADO COM SUCESSO!\n");
    wprintf(L"\n- PRESSIONE ENTER PARA CONTINUAR.");
    getchar();
    fflush(stdin);
    return;
}

void eventos_alterar(void){
    int option;
    system("clear||cls");
    wprintf(L"===============================\n        ~ GRAN C-IRCO ~\n            ALTERAR\n===============================\n");
    wprintf(L"DIGITE O CÓDIGO DO EVENTO QUE DESEJA ALTERAR: \n");
    fgets(cod2, 4, stdin);
    fflush(stdin);
    system("clear||cls");
    wprintf(L"===============================\n        ~ GRAN C-IRCO ~\n            ALTERAR\n===============================\n");
    wprintf(L"[1]Data\n"); wprintf(L"[2]Localização\n"); wprintf(L"[3]Horário\n");
    wprintf(L"[4]Preço\n"); wprintf(L"[5]Vagas\n"); wprintf(L"[6]Voltar\n");
    wprintf(L"DIGITE QUAL DADO DESEJA ALTERAR: ");
    scanf("%d", &option);
        fflush(stdin);
        switch (option){
            case 1: 
                wprintf(L"NOVA DATA DO EVENTO:\n");
                fgets(data, 10, stdin);
                fflush(stdin);
                wprintf(L"DATA DO EVENTO ALTERADA.\n");
                wprintf(L"\n- PRESSIONE ENTER PARA CONTINUAR.");
                getchar();
                fflush(stdin);
                break;
            case 2:
                wprintf(L"NOVA LOCALIZAÇÃO:\n");
                fgets(local, 50, stdin);
                fflush(stdin);
                wprintf(L"LOCALIZAÇÃO ALTERADA.\n");
                wprintf(L"\n- PRESSIONE ENTER PARA CONTINUAR.");
                getchar();
                fflush(stdin);
                break;
            case 3:
                wprintf(L"NOVO HORÁRIO:\n");
                fgets(horario, 5, stdin);
                fflush(stdin);
                wprintf(L"HORÁRIO ALTERADO.\n");
                wprintf(L"\n- PRESSIONE ENTER PARA CONTINUAR.");
                getchar();
                fflush(stdin);
                break;
            case 4:
                wprintf(L"NOVO PREÇO DO INGRESSO:\n");
                fgets(preco, 6, stdin);
                fflush(stdin);
                wprintf(L"PREÇO DO INGRESSO ALTERADO.\n");
                wprintf(L"\n- PRESSIONE ENTER PARA CONTINUAR.");
                getchar();
                fflush(stdin);
                break;
            case 5:
                wprintf(L"NOVA QUANTIDADE DE VAGAS:\n");
                scanf("%d", &vagas);
                fflush(stdin);
                wprintf(L"QUANTIDADE DE VAGAS ALTERADA.\n");
                wprintf(L"\n- PRESSIONE ENTER PARA CONTINUAR.");
                getchar();
                fflush(stdin);
                break;
            case 6:
                return;
                wprintf(L"\n- PRESSIONE ENTER PARA CONTINUAR.");
                getchar();
                fflush(stdin);
                break; 
            default:
                opcao_invalida();
                break;
        }
    return;
}
