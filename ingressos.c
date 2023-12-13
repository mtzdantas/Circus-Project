#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "ingressos.h"
#include "verifica.h"
#include "prof_eventos.h"
int cod1 = 0, cod3, carrinho[20], x = 0;
char cpf[12], senha[21];

void intro_ingressos(void){
    int stop = 0;
    int option;
    for (int i = 0; i <= 21; i++) {
        carrinho[i] = 0; 
    } 
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
                stop = 1;
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
    do {
        if (cod1 == 1){
            eventos_listar();
            system("clear||cls");
        }
        printf("===============================\n        ~ GRAN C-IRCO ~\n            RESERVA\n===============================\n");
        printf("DIGITE O CODIGO DO ESPETACULO QUE VOCE DESEJA RESERVAR O INGRESSO:\n");
        printf("PARA CONSULTAR A LISTA DE ESPETACULOS, DIGITE '1'.\n");
        scanf("%d", &cod1);
        fflush(stdin);   
    } while (cod1 == 1);
    FILE *ev; 
    ev = fopen("eventos.dat", "rb");
    if (ev != NULL) {
        cod3 = cod1;
        Eventos cod3;
        int a = 1;
        while(fread(&cod3, sizeof(Eventos), 1, ev)) {
            if (cod1 == cod3.showcod) {
                a++;
                carrinho[x] = cod1;
                x++;
                printf("ESPETACULO ADICIONADO AO CARRINHO!\n");  
                break;
            };
        }
        if (a == 1) {
            printf("NAO TEM NENHUM ESPETACULO COM ESSE CODIGO.");
        }
    fclose(ev);
    }
    printf("\n- PRESSIONE ENTER PARA CONTINUAR.");
    getchar();
    fflush(stdin);
    return;
}

void ingressos_cancelar(void){
    system("clear||cls");
    do {
        if (cod1 == 1){
            ingressos_carrinho();
            system("clear||cls");
        }
        printf("===============================\n        ~ GRAN C-IRCO ~\n            CANCELAR\n===============================\n");
        printf("DIGITE O CODIGO DO ESPETACULO QUE VOCE DESEJA CANCELAR O INGRESSO:\n");
        printf("PARA CONSULTAR O SEU CARRINHO, DIGITE '1'.\n");
        scanf("%d", &cod1);
        fflush(stdin);   
    } while (cod1 == 1);
    FILE *ev; 
    ev = fopen("eventos.dat", "rb");
    if (ev != NULL) {
        cod3 = cod1;
        Eventos cod3;
        int a = 1;
        while(fread(&cod3, sizeof(Eventos), 1, ev)) {
            if (cod1 == cod3.showcod) {
                for (int i = 0; i <= 21; i++) {
                    if (cod1 == carrinho[i]) {
                        a++;
                        carrinho[i] = 0;
                        printf("ESPETACULO CANCELADO DO CARRINHO!\n");  
                        break;
                    }
                }
            };
        }
        if (a == 1) {
            printf("INFORME UM CODIGO VALIDO.");
        }
    fclose(ev);
    }
    printf("\n- PRESSIONE ENTER PARA CONTINUAR.");
    getchar();
    fflush(stdin);
    return;
}

void ingressos_carrinho(void){
    system("clear||cls");
    int a = 1;
    printf("===============================\n        ~ GRAN C-IRCO ~\n            CARRINHO\n===============================\n");
    for (int i = 0; i <= 21; i++) {
        if (carrinho[i] != 0) {
            a++;
        }
    }
    if (a == 1) {
        printf("CARRINHO VAZIO.");
        printf("\n- PRESSIONE ENTER PARA CONTINUAR.");
        getchar();
        fflush(stdin);
        return; 
    }   
    FILE *ev; 
    ev = fopen("eventos.dat", "rb");
    if (ev == NULL) {
        printf("ERRO AO ABRIR O ARQUIVO.\n");
    } else {
        Eventos codcar;
        int t = 0;
        printf("ITEM || CODIGO || DATA       || LOCAL                                                        || HORARIO || PRECO || VAGAS\n");
        printf("==== || ====== || ========== || ============================================================ || ======= || ===== || =====\n");
        for (int i = 0; i <= 21; i++) {
            fseek(ev, 0, SEEK_SET);
            while (fread(&codcar, sizeof(Eventos), 1, ev) == 1) {
                if (codcar.showcod == carrinho[i]){
                    t++;
                    printf(" %02d  ||  %d   || %02d/%02d/%4d || %-60s ||  %s  || R$ %d || %d\n", t, codcar.showcod, codcar.dia, codcar.mes, codcar.ano, codcar.local, codcar.horario, codcar.preco, codcar.vagas);            
                }
            }
        }
        printf("=========================================================================================================================");
    }
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
        fgets(cpf, sizeof(cpf), stdin);
        fflush(stdin);
    } while (validaCPF(cpf) == 0);
    printf("INFORME SUA SENHA (ATE 20 CARACTERES):\n");
    fgets(senha, sizeof(senha), stdin);
    fflush(stdin);
    printf("CPF: %s", cpf);
    printf("\nSENHA: %s", senha);
    printf("\nDIGITE 1 PARA FINALIZAR A RESERVA OU OUTRA TECLA PRA SAIR.\n");
    scanf("%d", &op);
    fflush(stdin);
    if (op == 1) {
        // Cadastrar vendas daquele evento.
        Cliente cad;
        cpf[strcspn(cpf, "\n")] = '\0'; senha[strcspn(senha, "\n")] = '\0';
        strncpy(cad.cpf, cpf, sizeof(cpf)); strncpy(cad.senha, senha, sizeof(cpf));
        for (int i = 0; i <= 21; i++) {
            if (validaIngresso(carrinho[i])) {
                cad.compras[i] = carrinho[i];
            } else {
                cad.compras[i] = 0;
            }         
        }
        time_t t = time(NULL);
        struct tm tm_info = *localtime(&t);
        cad.dia = tm_info.tm_mday;
        cad.mes = tm_info.tm_mon + 1;
        cad.ano = tm_info.tm_year + 1900;

        FILE *cl; 
        cl = fopen("clientes.dat", "ab");
        if (cl == NULL) {
            printf("ERRO AO ABRIR O ARQUIVO.\n");
        } else {
            fwrite(&cad, sizeof(Cliente), 1, cl);
            printf("\nCADASTRO REALIZADO COM SUCESSO!");
        }
        fclose(cl);
        for (int i = 0; i <= x; i++) {
            carrinho[i] = 0; 
        }
        printf("\nRESERVA FINALIZADA!\nOBS: PARA VALIDAR SEU INGRESSO, BASTA REALIZAR O PAGAMENTO NA HORA DO SHOW\n");
        printf("\n- PRESSIONE ENTER PARA CONTINUAR.");
        getchar();
        fflush(stdin);
    }
    return;
}

void ingressos_comprados(void){
    ordenar();
    do {
        system("clear||cls");
        printf("===============================\n        ~ GRAN C-IRCO ~\n      RESERVAS CONCLUIDAS\n===============================\n");
        printf("DIGITE SEU CPF:\n");
        fgets(cpf, 12, stdin);
        fflush(stdin);
    } while (validaCPF(cpf) == 0);
    system("clear||cls");
    FILE *cl; 
    FILE *ev;
    ev = fopen("eventos.dat", "rb");
    cl = fopen("clientes.dat", "rb");
    Cliente rel;
    Eventos cod2;
    while (fread(&rel, sizeof(Cliente), 1, cl) == 1) {
        if (strcmp(rel.cpf, cpf) == 0) {
            printf("===============================\n        ~ GRAN C-IRCO ~\n      RESERVAS CONCLUIDAS\n===============================\n");
            printf("CPF CLIENTE: %s\n", rel.cpf);
            printf("===============================\n");
            printf("ITEM || DATA       || LOCAL                                                        || HORARIO\n");
            printf("==== || ========== || ============================================================ || =======\n");
            int t = 0;
            for (int i = 0; i <= 19; i++) {
                if (rel.compras[i] != 0) {
                    rewind(ev);
                    while (fread(&cod2, sizeof(Eventos), 1, ev) == 1) {
                        if (rel.compras[i] == cod2.showcod) {
                            t++;
                            printf(" %02d  || %02d/%02d/%4d || %-60s || %s\n", t, cod2.dia, cod2.mes, cod2.ano, cod2.local, cod2.horario);
                        }
                    }
                }
            }
            printf("=============================================================================================\n");  
        }
    }
    fclose(ev);
    fclose(cl);
    printf("\n- PRESSIONE ENTER PARA CONTINUAR.");
    getchar();
    fflush(stdin);
    return;
}

void ingressos_sair(void){
    for (int i = 0; i <= x; i++) {
        carrinho[i] = 0; 
    }         
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