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
        limpar_buffer();
        printf("INFORME A SENHA:\n");
        fgets(trysenha, 9, stdin);
        limpar_buffer();
        checklog = strcmp(entlogin, trylogin);
        checksen = strcmp(entsenha, trysenha);
        if (checklog == 0 && checksen == 0) {
            printf("LOGIN REALIZADO COM SUCESSO.\n");
            printf("\n- PRESSIONE ENTER PARA CONTINUAR.");
            
            limpar_buffer();
            return 1;
        }
        else {
            printf("LOGIN OU SENHA INCORRETOS.\n");
            printf("DIGITE '2' PARA SAIR OU ENTER PARA CONTINUAR.\n");
            scanf("%d", &cancel);
            limpar_buffer();
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
        printf("[2]Relatorio Clientes\n");
        printf("[3]Relatorio Individual do Cliente\n");
        printf("[4]Relatorio Shows\n");
        printf("[5]Relatorio Individual do Show\n");
        printf("[6]Voltar\n");
        printf("DIGITE A OPCAO DESEJADA: ");
        scanf("%d", &option);
        limpar_buffer();
        switch (option){
            case 1:
                profissional_eventos();
                break;
            case 2:
                profissional_relatCliente();
                break;
            case 3:
                profissional_relatClienteInd();
                break;
            case 4:
                profissional_relatShow();
                break;
            case 5:
                profissional_relatShowInd();
                break;
            case 6:
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
        limpar_buffer();
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

void profissional_relatCliente(void){
    int r = 0;
    system("clear||cls");
    printf("===============================\n        ~ GRAN C-IRCO ~\n           RELATORIO\n===============================\n");
    FILE *cl; 
    cl = fopen("clientes.dat", "rb");
    if (cl == NULL) {
        printf("NAO EXISTE CLIENTES CADASTRADOS.\n");
    } else {
    Cliente rel;
    while (fread(&rel, sizeof(Cliente), 1, cl) == 1) {
        r++;
        printf("CPF CLIENTE: %s\n", rel.cpf);
        printf("================================\n");
        printf("ITEM || CODIGO || DATA DA COMPRA\n");
        printf("==== || ====== || ==============\n");
        int b = 0;
        for (int i = 0; i <= 19; i++) {
            if (rel.compras[i] != 0) {
                b++;
                printf(" %02d  ||  %d   ||   %02d/%02d/%4d  \n", b, rel.compras[i], rel.dia, rel.mes, rel.ano);
                }
            }
        printf("================================\n");
        }  
    }
    printf("NUMERO TOTAL DE CLIENTES: %d\n", r);
    printf("================================\n");
    fclose(cl);
    printf("\n- PRESSIONE ENTER PARA CONTINUAR.");
    
    limpar_buffer();
    return;
}

void profissional_relatClienteInd(void){
    char cpf[12];
    do {
        system("clear||cls");
        printf("===============================\n        ~ GRAN C-IRCO ~\n           RELATORIO\n===============================\n");
        printf("DIGITE O CPF DO CLIENTE:\n");
        fgets(cpf, 12, stdin);
        limpar_buffer();
    } while (validaCPF(cpf) == 0);
    system("clear||cls");
    FILE *cl; 
    cl = fopen("clientes.dat", "rb");
    Cliente rel;
    while (fread(&rel, sizeof(Cliente), 1, cl) == 1) {
        if (strcmp(rel.cpf, cpf) == 0) {
            printf("===============================\n        ~ GRAN C-IRCO ~\n           RELATORIO\n===============================\n");
            printf("CPF CLIENTE: %s\n", rel.cpf);
            printf("===============================\n");
            printf("ITEM || CODIGO || DATA DA COMPRA\n");
            printf("==== || ====== || ==============\n");
            int t = 0;
            for (int i = 0; i <= 19; i++) {
                if (rel.compras[i] != 0) {
                    t++;
                    printf(" %02d  ||  %d   ||   %02d/%02d/%4d  \n", t, rel.compras[i], rel.dia, rel.mes, rel.ano);
                }
            }
            printf("================================\n");  
        }
    }
    fclose(cl);
    printf("\n- PRESSIONE ENTER PARA CONTINUAR.");
    
    limpar_buffer();
    return;
}

void profissional_relatShow(void) {
    int total = 0;
    ordenar();
    system("clear||cls");
    printf("===============================\n        ~ GRAN C-IRCO ~\n           RELATORIO\n===============================\n");
    FILE *ev; 
    ev = fopen("eventos.dat", "rb");
    if (ev == NULL) {
        printf("NAO EXISTE EVENTOS CADASTRADOS.\n");
        printf("\n- PRESSIONE ENTER PARA CONTINUAR.");
        
        limpar_buffer();
    } else {
    Eventos cod2;
    int t = 0;
    printf("SHOW || CODIGO || PRECO || VAGAS || VAGAS RESTANTES || VALOR ARRECADADO\n");
    printf("==== || ====== || ===== || ===== || =============== || ================\n");
    while (fread(&cod2, sizeof(Eventos), 1, ev) == 1) {
        if (cod2.status != 'x') {
            t++;
            int resultado;
            resultado = cod2.vendas * cod2.preco;
            printf(" %02d  ||  %d   || R$ %d ||  %d  ||       %d       ||     R$ %d     \n", t, cod2.showcod, cod2.preco, cod2.vagas, cod2.vagas-cod2.vendas, resultado);
            total += resultado;
        }
    }
    printf("========================================================================");
    printf("\nVALOR TOTAL ARRECADADO: %d\n", total);
    printf("========================================================================");
    fclose(ev);
    printf("\n- PRESSIONE ENTER PARA CONTINUAR.");
    limpar_buffer();
    return;
    // Informacões de quantas vendas foram feitas, e quanto foi arrecatado... 
    }
}

void profissional_relatShowInd(void){
    int cod = 0;
    system("clear||cls");
    do {
        if (cod == 1){
            eventos_listar();
            system("clear||cls");
        }
        printf("===============================\n        ~ GRAN C-IRCO ~\n           RELATORIO\n===============================\n");
        printf("DIGITE O CODIGO DO SHOW:\n");
        scanf("%d", &cod);
        limpar_buffer(); 
    } while (validaCod(cod));
    system("clear||cls");
    FILE *ev; 
    ev = fopen("eventos.dat", "rb");
    Eventos cod2;
    while (fread(&cod2, sizeof(Eventos), 1, ev) == 1) {
        if (cod2.showcod == cod) {
            int resultado;
            resultado = cod2.vendas * cod2.preco;
            printf("================================\n        ~ GRAN C-IRCO ~\n           RELATORIO\n===============================\n");
            printf("CODIGO DO SHOW: %d\n", cod2.showcod);
            printf("================================\n");
            printf("PRECO || VAGAS || VAGAS RESTANTES || VALOR ARRECADADO\n");
            printf("===== || ===== || =============== || ================\n");
            printf("R$ %d ||  %d  ||       %d       ||     R$ %d     \n", cod2.preco, cod2.vagas, cod2.vagas-cod2.vendas, resultado);
            printf("=====================================================\n");  
        }
    }
    fclose(ev);
    printf("\n- PRESSIONE ENTER PARA CONTINUAR.");
    limpar_buffer();
    return;
}