#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "profissional.h"
#include "prof_eventos.h"
#include "ingressos.h"
#include "verifica.h"

int verificar_profissional(){
    char entlogin[] = "circo", entsenha[] = "circo123";
    char trylogin[6], trysenha[9];
    int checklog = 1, checksen = 1, cancel = 1;
    while (checklog != 0 || checksen != 0){
        system("clear||cls");
        printf("===============================\n        ~ GRAN C-IRCO ~\n       LOGIN EMPRESARIAL\n===============================\n");
        printf("INFORME O LOGIN:\n");
        fgets(trylogin, 6, stdin);
        fflush(stdin);
        printf("INFORME A SENHA:\n");
        fgets(trysenha, 9, stdin);
        fflush(stdin);
        checklog = strcmp(entlogin, trylogin);
        checksen = strcmp(entsenha, trysenha);
        if (checklog == 0 && checksen == 0) {
            printf("LOGIN REALIZADO COM SUCESSO.\n");
            printf("\n- PRESSIONE ENTER PARA CONTINUAR.");
            getchar();
            fflush(stdin);
            return 1;
        }
        else {
            printf("LOGIN OU SENHA INCORRETOS.\n");
            printf("DIGITE '2' PARA SAIR OU ENTER PARA CONTINUAR.\n");
            scanf("%d", &cancel);
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
        printf("===============================\n        ~ GRAN C-IRCO ~\n     BEM VINDO FUNCIONARIO\n===============================\n");
        printf("[1]Eventos\n"); 
        printf("[2]Relatorios\n");
        printf("[3]Voltar\n");
        printf("DIGITE A OPCAO DESEJADA: ");
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
    return;    
}            

void profissional_eventos(void){
    int option;
    int stop = 1;
    while (stop == 1){
        system("clear||cls");
        printf("===============================\n        ~ GRAN C-IRCO ~\n            EVENTOS\n===============================\n");
        printf("[1]Listar\n"); printf("[2]Cadastrar\n"); printf("[3]Cancelar\n");
        printf("[4]Alterar\n"); printf("[5]Voltar\n");
        printf("DIGITE A OPCAO DESEJADA: ");
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
    return;
}

void profissional_relatorios(void){
    system("clear||cls");
    printf("===============================\n        ~ GRAN C-IRCO ~\n           RELATORIO\n===============================\n");
    FILE *ev; 
    ev = fopen("clientes.dat", "rb");
    if (ev == NULL) {
        printf("NAO EXISTE CLIENTES CADASTRADOS.\n");
        printf("\n- PRESSIONE ENTER PARA CONTINUAR.");
        getchar();
        fflush(stdin);
    } else {
    Cliente rel;
    while (fread(&rel, sizeof(Cliente), 1, ev) == 1) {
        printf("CPF CLIENTE: %s\nSENHA: %s\n", rel.cpf, rel.senha);
        printf("CODIGO(S) DA(S) COMPRA(S):");
        for (int i = 0; i <= 20; i++) {
            if (validaCod(rel.compras[i])){
                printf("%d\n", rel.compras[i]);
            }
        }
        printf("===============================\n");  
    }
    fclose(ev);
    printf("\n- PRESSIONE ENTER PARA CONTINUAR.");
    getchar();
    fflush(stdin);
    return;
    // Informacões de quantas vendas foram feitas, e quanto foi arrecatado... 
    }
}