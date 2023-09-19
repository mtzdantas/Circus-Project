#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "profissional.h"

int verificar_profissional(){
    char entrar[2][9] = {"circo", "circo123"};
    char tryentrar[2][9];
    int checklog = 1, checksen = 1, cancel = 1;
    while (checklog != 0 || checksen != 0){
        system("clear||cls");
        wprintf(L"===============================\n        ~ GRAN C-IRCO ~\n       LOGIN EMPRESARIAL\n===============================\n");
        wprintf(L"INFORME O LOGIN:\n");
        gets(tryentrar[0]);
        fflush(stdin);
        wprintf(L"INFORME A SENHA:\n");
        gets(tryentrar[1]);
        fflush(stdin);
        checklog = strcmp(entrar[0], tryentrar[0]);
        checksen = strcmp(entrar[1], tryentrar[1]);
        if (checklog == 0 && checksen == 0) {
            wprintf(L"LOGIN REALIZADO COM SUCESSO.\n");
            wprintf(L"\n- PRESSIONE ENTER PARA CONTINUAR.");
            getchar();
            fflush(stdin);
            return 1;
        }
        else {
            wprintf(L"LOGIN OU SENHA INCORRETOS.\n");
            wprintf(L"DIGITE '2' PARA SAIR OU ENTER PARA CONTINUAR.\n");
            cancel = getchar();
            fflush(stdin);
            if (cancel == 2){
                return 0;
            }
        }
    }   
    return 0;     
}

void intro_profissional(void){
    int option;
    int stop = 0;
    while (stop == 0){
        system("clear||cls");
        wprintf(L"===============================\n        ~ GRAN C-IRCO ~\n     BEM VINDO FUNCIONÁRIO\n===============================\n");
        wprintf(L"[1]Eventos\n"); // Usar no cadastro a localização, horário, data, preço
        wprintf(L"[2]Relatórios\n"); // vagas disponibilizadas e código de show (para acessar informações facilmente).
        wprintf(L"[3]Voltar\n");
        wprintf(L"DIGITE A OPÇÃO DESEJADA: ");
        scanf("%d", &option);
        fflush(stdin);
        switch (option){
            case 1:
                profissional_eventos();
                break;
            case 2:
                profissional_relatorios();
                break;
            case 3:
                stop = 1;
                break;
            default:
                opcao_invalida();
                break;
        }
    }
    return 0;    
}            

void profissional_eventos(void){
    int option;
    int stop = 1;
    while (stop == 1){
        system("clear||cls");
        wprintf(L"===============================\n        ~ GRAN C-IRCO ~\n            EVENTOS\n===============================\n");
        wprintf(L"[1]Listar\n"); wprintf(L"[2]Cadastrar\n"); wprintf(L"[3]Cancelar\n");
        wprintf(L"[4]Alterar\n"); wprintf(L"[5]Voltar\n");
        wprintf(L"DIGITE A OPÇÃO DESEJADA: ");
        scanf("%d", &option);
        fflush(stdin);
        switch (option){
            case 1:
                eventos_listar();
                break;
            case 2:
                eventos_cadastrar();
                break;
            case 3:
                eventos_cancelar();
                break;
            case 4:
                eventos_alterar();
                break;
            case 5:
                stop = 0;
                break;
            default:
                opcao_invalida();
                break;
        }
    }
    return 0;
}

void eventos_listar(void){
    system("clear||cls");
    wprintf(L"===============================\n        ~ GRAN C-IRCO ~\n          ESPETÁCULOS\n===============================\n");
    wprintf(L"LISTA DE EVENTOS.\n");
    wprintf(L"\n- PRESSIONE ENTER PARA CONTINUAR.");
    getchar();
    fflush(stdin);
    return 0;
}

void eventos_cadastrar(void){
    system("clear||cls");
    wprintf(L"===============================\n        ~ GRAN C-IRCO ~\n           CADASTRAR\n===============================\n");
    wprintf(L"CADASTRAR EVENTOS\n");
    wprintf(L"\n- PRESSIONE ENTER PARA CONTINUAR.");
    getchar();
    fflush(stdin);
    // Usar no cadastro a localização, horário, data, preço, vagas disponibilizadas e código de show.
    return 0;
}

void eventos_cancelar(void){
    system("clear||cls");
    wprintf(L"===============================\n        ~ GRAN C-IRCO ~\n            CANCELAR\n===============================\n");
    wprintf(L"CANCELAR EVENTO.\n");
    wprintf(L"\n- PRESSIONE ENTER PARA CONTINUAR.");
    getchar();
    fflush(stdin);
    return 0;
}

void eventos_alterar(void){
    system("clear||cls");
    wprintf(L"===============================\n        ~ GRAN C-IRCO ~\n            ALTERAR\n===============================\n");
    wprintf(L"ALTERAR DADOS DO EVENTO.\n");
    wprintf(L"\n- PRESSIONE ENTER PARA CONTINUAR.");
    getchar();
    fflush(stdin);
    return 0;
}

void profissional_relatorios(void){
    system("clear||cls");
    wprintf(L"===============================\n        ~ GRAN C-IRCO ~\n           RELATÓRIO\n===============================\n");
    wprintf(L"GERANDO RELATÓRIOS...\n"); // Informações de quantas vendas foram feitas, e quanto foi arrecatado.
    wprintf(L"\n- PRESSIONE ENTER PARA CONTINUAR.");
    getchar();
    fflush(stdin);
    return 0;
}