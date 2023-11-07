#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "prof_eventos.h"
char data[12], local[51], horario[6];
int vagas = 0, preco = 0, cod2, cod, list = 0;

void eventos_listar(void){
    system("clear||cls");
    printf("===============================\n        ~ GRAN C-IRCO ~\n          ESPETACULOS\n===============================\n");
    FILE *ev; 
    ev = fopen("eventos.dat", "rb");
    if (ev == NULL) {
        printf("NAO EXISTE EVENTOS CADASTRADOS.\n");
        printf("\n- PRESSIONE ENTER PARA CONTINUAR.");
        getchar();
        fflush(stdin);
    } else {
    Eventos cod2;
    while (fread(&cod2, sizeof(Eventos), 1, ev) == 1) {
        if (cod2.status != 'x') {
            printf("EVENTO DE CODIGO: %d\nDATA: %sLOCAL: %sHORARIO: %s\nPRECO: %d\nVAGAS DISPONIVEIS: %d\n", cod2.showcod, cod2.data, cod2.local, cod2.horario, cod2.preco, cod2.vagas);
            printf("===============================\n");  
        }
    }
    fclose(ev);
    printf("\n- PRESSIONE ENTER PARA CONTINUAR.");
    getchar();
    fflush(stdin);
    return;
    }
}

void eventos_cadastrar(void){
    system("clear||cls");
    printf("===============================\n        ~ GRAN C-IRCO ~\n           CADASTRAR\n===============================\n");
    printf("CODIGO DE ESPETACULO:\n");
    scanf("%d", &cod);
    fflush(stdin);
    cod2 = cod;
    Eventos cod2;
    cod2.status = 'v';
    cod2.showcod = cod;
    printf("DATA DO EVENTO:\n");
    fgets(data, 12, stdin);
    fflush(stdin);
    strncpy(cod2.data, data, 12);
    printf("LOCALIZACAO:\n");
    fgets(local, 61, stdin);
    fflush(stdin);
    strncpy(cod2.local, local, 61);
    printf("HORARIO:\n");
    fgets(horario, 6, stdin);
    fflush(stdin);
    strncpy(cod2.horario, horario, 6);
    printf("PRECO DO INGRESSO:\n");
    scanf("%d", &preco);
    fflush(stdin);
    cod2.preco = preco;
    printf("VAGAS DISPONIBILIZADAS:\n");
    scanf("%d", &vagas);
    fflush(stdin);
    cod2.vagas = vagas;
    FILE *ev; 
    ev = fopen("eventos.dat", "ab");
    if (ev == NULL) {
        printf("ERRO AO ABRIR O ARQUIVO.\n");
    } else {
        fwrite(&cod2, sizeof(Eventos), 1, ev);
        printf("CADASTRO REALIZADO COM SUCESSO!\n");
    }
    fclose(ev);
    printf("\n- PRESSIONE ENTER PARA CONTINUAR.");
    getchar();
    fflush(stdin);
    return;
}

void eventos_cancelar(void){
    system("clear||cls");
    do {
        if (cod2 == 1){
            eventos_listar();
            system("clear||cls");
        }
        printf("===============================\n        ~ GRAN C-IRCO ~\n            CANCELAR\n===============================\n");
        printf("DIGITE O CODIGO DO ESPETACULO QUE VOCE DESEJA CANCELAR:\n");
        printf("PARA CONSULTAR A LISTA DE ESPETACULOS, DIGITE '1'.\n");
        scanf("%d", &cod2);
        fflush(stdin);
    } while (cod2 == 1);
    FILE *ev; 
    ev = fopen("eventos.dat", "r+b");
    if (ev == NULL) {
        printf("ERRO AO ABRIR O ARQUIVO.\n");
    } else {
        cod = cod2;
        Eventos cod2;
        off_t tamanho = sizeof(Eventos);
        int a = 1;
        while(fread(&cod2, sizeof(Eventos), 1, ev)) {
            if (cod == cod2.showcod) {
                a++;
                cod2.status = 'x';
                fseek(ev, -tamanho, SEEK_CUR);
                fwrite(&cod2, sizeof(Eventos), 1, ev);
                printf("ESPETACULO CANCELADO COM SUCESSO!\n");  
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

void eventos_alterar(void){
    int option;
    system("clear||cls");
    do {
        if (list == 1) {
            eventos_listar();
            system("clear||cls");
        }
        printf("===============================\n        ~ GRAN C-IRCO ~\n            ALTERAR\n===============================\n");
        printf("DIGITE O CODIGO DO EVENTO QUE DESEJA ALTERAR: \n");
        printf("PARA CONSULTAR A LISTA DE ESPETACULOS, DIGITE '1'.\n");
        scanf("%d", &list);
        fflush(stdin);
    } while (list == 1);
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
                scanf("%d", &preco);
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
