#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    wprintf(L"CADASTRAR EVENTOS\n");
    wprintf(L"\n- PRESSIONE ENTER PARA CONTINUAR.");
    getchar();
    fflush(stdin);
    // Usar no cadastro a localização, horário, data, preço, vagas disponibilizadas e código de show.
    return;
}

void eventos_cancelar(void){
    system("clear||cls");
    wprintf(L"===============================\n        ~ GRAN C-IRCO ~\n            CANCELAR\n===============================\n");
    wprintf(L"CANCELAR EVENTO.\n");
    wprintf(L"\n- PRESSIONE ENTER PARA CONTINUAR.");
    getchar();
    fflush(stdin);
    return;
}

void eventos_alterar(void){
    system("clear||cls");
    wprintf(L"===============================\n        ~ GRAN C-IRCO ~\n            ALTERAR\n===============================\n");
    wprintf(L"ALTERAR DADOS DO EVENTO.\n");
    wprintf(L"\n- PRESSIONE ENTER PARA CONTINUAR.");
    getchar();
    fflush(stdin);
    return;
}